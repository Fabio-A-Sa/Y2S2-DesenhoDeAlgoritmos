#include "Utils.h"

bool readGivenPaths(vector<vector<int>> *paths, int *groupSize) {

    string fileName;
    cout << "File: "; cin >> fileName;

    fstream file;
    file.open("../input/" + fileName, ios::in);
    if (!file)
    {
        cerr << "Error: file " << fileName << " not found" << endl;
        return false;
    }
    if (file.is_open())
    {   
        string group, line;
        int node;
        getline(file, group);
        *groupSize = stoi(group);

        while (!file.eof())
        {
            vector<int> path;
            getline(file, line);
            if (line.empty()) break;
            stringstream l(line);
            try {
                while (l >> node) {
                    path.push_back(node);
                }
            } catch (const exception &e) {
                cerr << "Invalid input" << endl;
            }
            paths->push_back(path);
        }
        file.close();
    }
    
    return true;
}