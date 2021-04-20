/*
 * Title: hw8_2.cpp
 * Abstract: this program will perform Kahn's algrotithm
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 04/09/21
 *
 * Credits for pseudocode for funciton to check for graph cycles:
 *  https://algorithms.tutorialhorizon.com/graph-detect-cycle-in-a-directed-graph/
 *  
 * Credits for Kahn's algorithm:
 * https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_cycle(int vertex, vector<vector<int>> edges, int num, vector<bool> visited, vector<bool> rec) {

  visited[vertex] = true;
  rec[vertex] = true;

  for (int i = 0; i < edges[vertex].size(); i++) {
    int curr = edges[vertex][i];
    if (!visited[curr] && is_cycle(curr, edges, num, visited, rec))
      return true;
    else if (rec[curr])
      return true;
  }
  return false;
}

int main() {
  int num_vert;
  int num_edge;

  cin >> num_vert;
  cin >> num_edge;

  vector <vector<int>> edges(num_vert, vector <int> (0));
  int mark[num_vert];

  for (int i = 0; i < num_vert; i++)
    mark[i] = 0;

  for (int i = 0; i < num_edge; i++) {
    int t1; 
    int t2; 
    cin >> t1;
    cin >> t2;
    
    edges[t1].push_back(t2);
    mark[t2]++;
  }

  for (int i = 0; i < num_vert; i++) 
    cout << "In-degree[" << i << "]:" << mark[i] << endl;

  queue <int> q;

  for (int i = 0; i < num_vert; i++) {
    if (mark[i] == 0)
      q.push(i);
  }

  if (q.empty()) {
    cout << "No Order:";
    return 0;
  }

  vector <bool> visited(num_vert, false);
  vector <bool> rec_stack(num_vert, false);

  for (int i = 0; i < num_vert; i++) {
    if (is_cycle(i, edges, num_vert, visited, rec_stack) == true) {
      cout << "No Order:";
      return 0;
    }
  }

  cout << "Order:";
  while (!q.empty()) {
    int curr = q.front();

    for (int i = 0; i < edges[curr].size(); i++) {
      mark[edges[curr][i]]--;
      if (mark[edges[curr][i]] == 0) {
        q.push(edges[curr][i]);
      }
    }

    q.pop();

    if (q.empty())
      cout << curr;
    else 
      cout << curr << "->";
  }

  return 0;
}