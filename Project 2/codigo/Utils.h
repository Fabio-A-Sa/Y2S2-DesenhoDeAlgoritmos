/**
 * @file Utils.h
 * @brief This file contains the definition of nodes, edges and a fuction to read a graph file
 * 
 * @author Fábio Araújo de Sá, Marcos William Ferreira Pinto
 *
 * @date 31/05/2022
 */

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/**
 * Definition of the largest number used in class bellow
 */
#define INF (INT_MAX/2)

/**
 * Struct that groups all characteristics of the edge that separates two nodes
 */
struct Edge {

    /**
     * @param dest - an integer value that represents the destination of current edge, based on node's index
     */
    int dest;
    
    /**
     * @param capacity - an integer value that represents the capacity of the vehicle on this path
     */
    int capacity;

    /**
     * @param duration - an integer value that represents the duration of traveling to destination node
     */
    int duration;

    /**
     * @param visit - a boolean value that represents if current node was visited
     */
    bool visit;
};

/**
 * Struct that represents a Stop in Porto
 */
struct Node {

    /**
     * @param adjacent - a list of Edges containing all possible paths from the current node
     */
    list<Edge> adjacent;

    /**
     * @param visited - a boolean attribute that indicates if the stop is active
     */
    bool visited;

    /**
     * @param parent - an integer value represents previous node index
     */
    int parent;

    /**
     * @param capacity - an integer value represents the node capacity
     */
    int capacity;

    /**
     * @param earliestStart - an integer value represents the earliest start
     */
    int earliestStart;

    /**
     * @param earliestArrival - an integer value represents the earliest arrival
     */
    int earliestArrival;

    /**
     * @param degreeE - an integer value represents the node degree
     */
    int degreeE;
};

/**
 * @brief Function that reads a file and gathers information about travel paths and the total capacity of the routes together
 * 
 * @param paths - a vector which contains different travel routes (to be populated)
 * @param groupSize - an integer value representing the desired group size
 * @return true - if an error occurs
 * @return false - otherwise
 */
bool readGivenPaths(vector<vector<int>> *paths, int *groupSize);

#endif /* UTILS_H */