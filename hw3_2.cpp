/*
 * Title: hw3_2.cpp
 * Abstract: This program will take in a set of vertices and edges and will then demonstreate the linked list related to the set
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 02/19/21
 */
 
#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> pairs; 

void printList(int x, set<pairs>& s){
    string list = to_string(x);
    for (auto const &y : s) { 
        if(x == y.first){
            list += "->" + to_string(y.second);
        }
    } 
    cout << list << endl;
}

int main (){
    int vertices, edges, v, e;
    set<pairs> linkedlist;
    vector<int>vertex;
    
    cin >> vertices;
    cin >> edges;
    
    for(int i = 0; i < vertices; i++) 
        vertex.push_back(i); 
        
    for(int i = 0 ; i < edges; i ++){
        cin >> v >> e;
        pairs x = make_pair(v, e);
        linkedlist.insert(x);
    }
    
    for (int i = 0; i < vertex.size(); i++)
        printList(vertex[i], linkedlist);
}