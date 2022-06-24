/**
 * @file Graph.h
 * @brief This file contains the implementation of the graph and all its methods
 * 
 * @author Fábio Araújo de Sá, Marcos William Ferreira Pinto
 *
 * @date 31/05/2022
 */

#ifndef PROJECT_DA_PT2_GRAPH_H
#define PROJECT_DA_PT2_GRAPH_H

#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include "Utils.h"
#include <stdexcept>
#include <limits>
#include <typeinfo>
#include <exception>

using namespace std;

/**
 * Class that represents a Graph and its entire structure
 */
class Graph {

    private:

        /**
         * @param nodes - a vector containing Node type struct that includes all nodes of current Graph
         */
        vector<Node> nodes;

        /**
         * @brief Function that adds an Edge between two nodes
         * 
         * @param origin - an integer value representing the index of origin Node
         * @param destiny - an integer value representing the index of destiny Node
         * @param capacity - an integer value representing capacity of current Edge
         * @param duration - an integer value representing duration of traveling to one node to another
         */
        void addEdge(int origin, int destiny, int capacity, int duration);

        /**
         * @brief Function that put all attributes for all nodes to default values
         */
        void reset();
        
        /**
         * @brief Function that determines if node is valid in current graph
         * 
         * @param node - an integer value representing the node
         * @return true - if node belongs to the graph
         * @return false - otherwise
         */
        bool isValid(int node);

        /**
         * @brief Function that prints a path from the origin to destination for case 1
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         */
        void showPathCase1(int origin, int destiny);

        /**
         * @brief Function that prints a path from the origin to destination for case 2
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         */
        int showPathCase2(const vector<vector<int>> &pathList, vector<int> &capacities);

        /**
         * @brief Function that calculates the largest group size and the path for it without dividing
         * the group into subgroups with diferrent paths
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         */
        void case1_a(int origin, int destiny);

        /**
         * @brief Function that calculates the path that allows for the largest group size and the least
         * number of bus changes (prints both routes)
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         */
        void case1_b(int origin, int destiny);

        /**
         * @brief Function that finds travel routes for a group, allowing division into subgroups with
         * different paths
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         * @param groupSize - an integer value representing the desired group size
         */
        void case2_a(int origin, int destiny, int groupSize);

         /**
         * @brief Function that receives travel routes and the group size for it, then corrects the routes
         * to accommodate for a different group size (if new group size is smaller or the same as before
         * it returns the existing paths)
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         * @param pathList - a list of integer lists representing the user's input paths
         * @param oldGroupSize - an integer value representing the desired group size
         * @param newGroupSize - an integer value representing the desired group size
         */
        void case2_b(int origin, int destiny, vector<vector<int>> pathList, int oldGroupSize, int newGroupSize);

        /**
         * @brief Function that calculates the largest group size and travel routes between origin and destination,
         * allowing group to divide into different paths
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         */
        void case2_c(int origin, int destiny);

        /**
         * @brief Function that calculates the minimum travel time for the arrival off the whole group to the end 
         * destination (taking into account the different paths traveled)
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         * @param pathList - a list of integer lists representing the user's input paths
         */
        void case2_d(int origin, int destiny, vector<vector<int>> pathList);

        /**
         * @brief Function that calculates all the waiting times (for subgroup that arrives first) between bus 
         * changes that occurs in the give travel routes considering that the whole group has to leave the 
         * station (node) at the same time 
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         * @param pathList - a list of integer lists representing the user's input paths
         */
        void case2_e(int origin, int destiny, vector<vector<int>> pathList);
        
        /**
         * @brief Function that traverse the graph with a Breadth-First Search
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         * @return int - representing the maximum capacity of discovered path
         */
        int BFS(int origin, int destiny);
        
        /**
         * @brief Function creates a path between origin and destination (if it exists) using
         * the stored information
         * 
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         * @param path - an integer list that will be filled with a path
         * @param capacity - maximum capacity of current path
         * @return int - representing if an error occurs
         */
        int pathBuild(int origin, int destiny, vector<int> &path, int capacity);
        
        /**
         * @brief Function that verifies is a path already exists, if it does instead of adding it again to
         * travel routes List (pathList) it increments the number of travelers in it
         * 
         * @param pathList - a list of integer lists representing the user's input paths
         * @param path - an integer list that will be filled with a path
         * @param capacity - maximum capacity of current path
         * @param capacities - an integer list containing all capacities
         * @param remainderSize - an integer representing the remainder people
         * @return int - representing a new remainderSize
         */
        int verifyFoundPath(vector<vector<int>> &pathList, vector<int> &path, vector<int> &capacities, int &capacity, int remainderSize = INF);
        
        /**
         * @brief Function that calculates the earliest start in all nodes that is in the travel routes (for this case the earliest departure in a group if we
         * have to wait for the group to unite before leaving the node)
         */
        void getEarliestStart();
        
        /**
         * @brief Function that calculates the earliest arrival of a subgroup into a node (calculates for all nodes maked in the travel routes)
         */
        void getEarliestArrival();

    public:

        /**
         * Main constructor of the class Graph
         */
        Graph();
        
        /**
         * @brief Function that initializes the graph with the given file's information
         * 
         * @param filename - string representing the file that contains the graph information
         */
        void initialize(const string &filename);

        /**
         * @brief Function that verifies is input is valid for the graph (origin and destination) and call the correct option for case 1
         * 
         * @param mode - an integer value representing the selected mode
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         */
        void case1(int mode, int origin, int destiny);

        /**
         * @brief Function that verifies is input is valid for the graph (origin and destination) and call the correct option for case 2
         * 
         * @param mode - an integer value representing the selected mode
         * @param origin - an integer value representing the origin node
         * @param destiny - an integer value representing the destiny node
         * @param groupSize - an integer value representing the desired group size
         */
        void case2(int mode, int origin, int destiny, int groupSize = 0);
};

#endif /* PROJECT_DA_PT2_GRAPH_H */