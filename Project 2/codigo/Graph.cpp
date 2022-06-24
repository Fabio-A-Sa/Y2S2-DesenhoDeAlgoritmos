#ifndef PROJECT_DA_PT2_GRAPH_CPP
#define PROJECT_DA_PT2_GRAPH_CPP

#include "Graph.h"

Graph::Graph() {}

void Graph::initialize(const string &filename) {

    fstream file;
    file.open("../input/" + filename, ios::in);
    if (!file)
    {
        cerr << "Error: file " << filename << " not found" << endl;
        return;
    }
    if (file.is_open())
    {   
        string numNodes, InitialNode, DestinyNode, capacity, duration;
        getline(file, numNodes, ' ');
        this->nodes = vector<Node>(stoi(numNodes)+1);
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (!file.eof())
        {
            getline(file, InitialNode, ' ');
            getline(file, DestinyNode, ' ');
            getline(file, capacity, ' ');
            getline(file, duration);
            try {
                this->addEdge(stoi(InitialNode), stoi(DestinyNode), stoi(capacity), stoi(duration));
            } catch (const exception &e) {
                return;
            }
        }
        file.close();
    }
}

void Graph::reset() {
    for (int i = 1 ; i < nodes.size() ; i++) {
        nodes[i].parent = -1;
        nodes[i].capacity = 0;
        nodes[i].visited = false;
        nodes[i].degreeE = 0;
        nodes[i].earliestArrival = INF;
        nodes[i].earliestStart = 0;
    }
}

bool Graph::isValid(int node) {
    return node > 0 && node < nodes.size();
}

void Graph::addEdge(int origin, int destiny, int capacity, int duration) {
    if (!isValid(origin) || !isValid(destiny)) return;
    nodes[origin].adjacent.push_back({destiny, capacity, duration});
}

void Graph::showPathCase1(int origin, int destiny) {

    list<int> path;
    int currentNode = destiny;
    while (nodes[currentNode].parent != -1) { 
        path.push_front(currentNode);
        currentNode = nodes[currentNode].parent;
    }
    if (currentNode != origin) {
        cerr << "Error: There is no path between node " << origin << " and node " << destiny << endl;
        return;
    } else path.push_front(currentNode);

    int maxCapacity = INF;
    int transbordos = 0;
    cout << *path.begin();
    path.erase(path.begin());
    while (!path.empty()) {
        cout << " --(" << nodes[*path.begin()].capacity << ")--> " << *path.begin();
        maxCapacity = min(maxCapacity, nodes[*path.begin()].capacity);
        path.erase(path.begin());
        transbordos++;
    }
    cout << "\nMaximum capacity: " << maxCapacity << endl;
    cout << "Bus changes: " << transbordos << endl;
}

void Graph::case1(int mode, int origin, int destiny) {

    if (!isValid(origin) || !isValid(destiny)) {
        cerr << "Error: Invalid node number. Max is " << nodes.size()-1 << endl;
        return;
    }

    switch (mode) {
        case 1:
            case1_a(origin, destiny);
            break;
        case 2:
            case1_a(origin, destiny);
            case1_b(origin, destiny);
            break;
        default:
            cerr << "Invalid mode for scenario 1" << endl;
            exit(-1);
            break;
    }
}

void Graph::case2(int mode, int origin, int destiny, int groupSize) {

    if (!isValid(origin) || !isValid(destiny)) {
        cerr << "Error: Invalid node number. Max is " << nodes.size()-1 << endl;
        return;
    }

    vector<vector<int>> paths;
    int oldGroupSize;

    switch (mode) {
        case 1:
            case2_a(origin, destiny, groupSize);
            break;
        case 2:
            readGivenPaths(&paths, &oldGroupSize);
            case2_b(origin, destiny, paths, oldGroupSize, groupSize);
            break;
        case 3:
            case2_c(origin, destiny);
            break;
        case 4:
            readGivenPaths(&paths, &oldGroupSize);
            case2_d(origin, destiny, paths);
            break;
        case 5:
            readGivenPaths(&paths, &oldGroupSize);
            case2_e(origin, destiny, paths);
            break;
        default:
            cerr << "Invalid mode for scenario 2" << endl;
            exit(-1);
            break;
    }
}

int Graph::BFS(int origin, int destiny) {

    reset();
    int capacity = INF;
    queue<int> visitedNodes = {};
    visitedNodes.push(origin);              
    nodes[origin].visited = true;           

    while (!visitedNodes.empty()) {

        int node = visitedNodes.front();
        visitedNodes.pop();          

        for (Edge e : nodes[node].adjacent) { 
            int n = e.dest;              
            if (!nodes[n].visited && e.capacity > 0) {           
                visitedNodes.push(n);           
                nodes[n].visited = true; 
                nodes[n].capacity = e.capacity;   
                nodes[n].parent = node;  
                capacity = min(capacity, e.capacity);
            }
        }
    }
    return capacity;
}

int Graph::showPathCase2(const vector<vector<int>> &pathList, vector<int> &capacities) {
    int totalCapacity = 0;
    for (int i = 0 ; i < pathList.size() ; i++) {
        cout << pathList[i][0];
        for (int j=1; j<pathList[i].size(); j++){
            cout << "--->" << pathList[i][j];
        }
        cout << " Capacity: " << capacities[i] << endl;
        totalCapacity += capacities[i];
    }
    return totalCapacity;
}

int Graph::pathBuild(int origin, int destiny, vector<int> &path, int capacity){

    int currentNode = destiny;
    while (nodes[currentNode].parent != -1) { 
        path.push_back(currentNode);
        for (Edge &e : nodes[nodes[currentNode].parent].adjacent){
            if (e.dest == currentNode) {
                e.capacity -= capacity;
            }
        }
        currentNode = nodes[currentNode].parent;
    }
    if (currentNode != origin) {
        return 1;
    } else path.push_back(currentNode);
    reverse(path.begin(), path.end());
    return 0;
}

int Graph::verifyFoundPath(vector<vector<int>> &pathList, vector<int> &path, vector<int> &capacities, int &capacity, int remainderSize){
    bool pathExited = false;
        for(int i = 0; i<pathList.size(); i++){
            if(path == pathList[i]){
                capacities[i]+= min(capacity,remainderSize);
                pathExited = true;
            }
        }
        if (!pathExited) {
            pathList.push_back(path);
            capacities.push_back(min(capacity,remainderSize));
        }
        remainderSize -= capacity;
    return remainderSize;
}

void Graph::getEarliestStart(){
    stack<int> S;
    for(int i = 1 ; i < nodes.size() ; i++){
        if(nodes[i].visited && nodes[i].degreeE==0){
            S.push(i);
        }
    }
    int minDuration = -1;
    int vFinal;

    while(!S.empty()){
        int v = S.top();
        S.pop();

        if(minDuration < nodes[v].earliestStart){
            minDuration = nodes[v].earliestStart;
            vFinal = v;
        }

        for(auto &w: nodes[v].adjacent){
            if( nodes[w.dest].earliestStart < nodes[v].earliestStart + w.duration){
                nodes[w.dest].earliestStart = nodes[v].earliestStart + w.duration;   
            }
            nodes[w.dest].degreeE--;
            if(nodes[w.dest].degreeE==0){
                S.push(w.dest);
            }
        }
    }
}

void Graph::getEarliestArrival(){
    for (int i = 1 ; i < nodes.size() ; i++) {
        if (nodes[i].visited) {
            for (Edge e : nodes[i].adjacent) {
                if (nodes[e.dest].visited && e.visit) {
                    nodes[e.dest].earliestArrival = min(nodes[e.dest].earliestArrival, e.duration + nodes[i].earliestStart);
                }
            }
        }
    }
}

void Graph::case1_a(int origin, int destiny) {

    cout << "Maximum number of passengers for the trip" << endl;

    set<pair<int, int>> capacities;

    reset();
    for (int i = 1 ; i < nodes.size() ; i++) {
        capacities.insert(make_pair(0, i));
    }

    nodes[origin].capacity = INF;
    capacities.erase(make_pair(0, origin));
    capacities.insert(make_pair(INF, origin));

    while (!capacities.empty()) {

        int currentNodeIndex = capacities.begin()->second;
        int currentNodeCapacity = capacities.begin()->first;
        capacities.erase(capacities.begin());

        for (Edge e : nodes[currentNodeIndex].adjacent) {
            if (min(currentNodeCapacity, e.capacity) > nodes[e.dest].capacity) {
                int oldCapacity = nodes[e.dest].capacity;
                nodes[e.dest].capacity = min(currentNodeCapacity, e.capacity);
                nodes[e.dest].parent = currentNodeIndex;
                capacities.erase(make_pair(oldCapacity, e.dest));
                capacities.insert(make_pair(nodes[e.dest].capacity, e.dest));
            }
        }    
    }
    showPathCase1(origin, destiny);
}

void Graph::case1_b(int origin, int destiny) {

    cout << "Minimizing number of bus changes" << endl;
    BFS(origin, destiny);
    showPathCase1(origin, destiny);
}

void Graph::case2_a(int origin, int destiny, int groupSize) {
    
    vector<vector<int>> pathList;
    int remainderSize = groupSize;
    vector<int> capacities;
    vector<int> path;

    while (remainderSize>0){ 

        path.clear();
        int capacity = BFS(origin, destiny);
        if(pathBuild(origin, destiny, path, capacity)) {
            cerr << "Error: There is no path between node " << origin << " and node " << destiny << " with desired capacity ("<< groupSize << ")" << endl;
            return;
        }
        remainderSize = verifyFoundPath(pathList, path, capacities, capacity, remainderSize);
    }
    showPathCase2(pathList, capacities);
}

void Graph::case2_b(int origin, int destiny, vector<vector<int>> pathList, int oldGroupSize, int newGroupSize) {
    
    int remainderSize = newGroupSize - oldGroupSize;
    vector<int> capacities;
    vector<int> path;

    for(vector<int> curPath: pathList){
        
        int pathCapacity = INF;
        for(int i=0; i<curPath.size()-1; i++){
            for(auto j: nodes[curPath[i]].adjacent){
                if(j.dest == curPath[i+1]){
                   pathCapacity = min(pathCapacity, j.capacity);
                }
            }
        }

        for(int i=0; i<curPath.size()-1; i++){
            for(auto &j: nodes[curPath[i]].adjacent){
                if(j.dest == curPath[i+1]){
                   j.capacity -= min(pathCapacity, oldGroupSize);
                }
            }
        }
        capacities.push_back(min(pathCapacity, oldGroupSize));
        oldGroupSize -= pathCapacity;
    }

    if(newGroupSize > oldGroupSize){
        while (remainderSize>0){ 

            path.clear();
            int capacity = BFS(origin, destiny);
            if(pathBuild(origin, destiny, path, capacity)) {
                cerr << "Error: There is no path between node " << origin << " and node " << destiny << " with desired capacity ("<< newGroupSize << ")" << endl;
                return;
            }
            remainderSize = verifyFoundPath(pathList, path, capacities, capacity, remainderSize);
        }
    }
    showPathCase2(pathList, capacities);
}

void Graph::case2_c(int origin, int destiny) {
    
    vector<vector<int>> pathList;
    vector<int> capacities;
    vector<int> path;

    while (true){ 

        path.clear();
        int capacity = BFS(origin, destiny);
        if(pathBuild(origin, destiny, path, capacity)) {
            break;
        }
        verifyFoundPath(pathList, path, capacities, capacity);
    }

    int totalCapacity = showPathCase2(pathList, capacities);
    cout << "Total capacity: " << totalCapacity << endl;
}

void Graph::case2_d(int origin, int destiny, vector<vector<int>> pathList){
    
    if(pathList.empty()) return;
    int endTime = 0;

    for(vector<int> curPath: pathList){
        
        int groupTime = 0;
        for(int i=0; i<curPath.size()-1; i++){
            for(auto j: nodes[curPath[i]].adjacent){
                if(j.dest == curPath[i+1]){
                  groupTime += j.duration;
                }
            }
        }
        endTime = max(endTime,groupTime);
    }
    cout << "Minimum amount of time for the arrival of the whole group: " << endTime << " hours" << endl; 
}

void Graph::case2_e(int origin, int destiny, vector<vector<int>> pathList){

    reset();
    
    for (vector<int> path : pathList) {
        for (int i = 0 ; i < path.size() -1 ; i++) {
            for (Edge &e : nodes[path[i]].adjacent) {
                if (e.dest == path[i+1]) {
                    e.visit = true;
                    nodes[e.dest].visited = true;
                    nodes[e.dest].degreeE++;
                }
                nodes[path[i]].visited = true;
            }
        }
    }

    getEarliestStart();
    getEarliestArrival();

    for (int i = 1 ; i < nodes.size() ; i++) {
        int waiting = nodes[i].earliestStart - nodes[i].earliestArrival;
        if (nodes[i].visited && waiting > 0)
            cout << "Node: " << i << " can have a waiting time of " << waiting << " hours" << endl; 
    }
}

#endif /* PROJECT_DA_PT2_GRAPH_CPP */