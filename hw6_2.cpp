/*
 * Title: hw6_2.cpp
 * Abstract: this program implemetns the DFS algorithm using stack and a mark array
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 03/13/2021
 */
 
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int vertices, edges;
  stack <int> myStack;

  cin >> vertices >> edges;

  vector <vector<int>> graph(vertices, vector <int> (0)); 
  vector <int> mark(vertices, -1);
  int count = 1;

  for (int i = 0; i < edges; i++) {
    int edge1, edge2;
    cin >> edge1 >> edge2;
    graph[edge1].push_back(edge2);
  }

  myStack.push(0);
  mark[0] = count;

  while (!myStack.empty()) {
    int current = myStack.top(); 
    bool visited = true; 

    sort(graph[current].begin(), graph[current].end()); 

    for (int i = 0; i < graph[current].size(); i++) {
      int adj = graph[current][i]; 

      if (mark[adj] == -1) {
        mark[graph[current][i]] = ++count;
        myStack.push(graph[current][i]);
        visited = false;
        break;
      } 
    }

    if (visited) 
      myStack.pop();

  }

  for (int i = 0; i < mark.size(); i++) 
    cout << "Mark[" << i << "]:" << mark[i] << endl;

  return 0;
}