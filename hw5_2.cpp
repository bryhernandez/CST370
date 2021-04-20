/*
 * Title: hw5_2.cpp
 * Abstract: This program dipslays the prefered path and cost of said path in TSP problem
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 03/05/21
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include<climits>
#include <string>
using namespace std;

int indexOf(vector<string> cities, string city){
    for(int i = 0; i < cities.size(); i++)
        if(cities[i] == city)
            return i;
    
    return -1;
}

int main() {
  int vertices;
  int edges;

  cin >> vertices;
  
  vector<string> cities;
  string city;
  for(int i = 0; i < vertices; i++){
      cin >> city; 
      cities.push_back(city);
  }
  
  cin >> edges;

  vector <vector<int>> input(vertices, vector<int> (vertices, 0));
  vector <vector<int>> true_permutations;

  for (int i = 0; i < edges; i++) {
    string city1, city2;
    int c;
    cin >> city1 >> city2;
    cin >> c;
    
    input[indexOf(cities, city1)][indexOf(cities, city2)] = c;
  }

  int verts[vertices];

  for (int i = 0; i < vertices; i++)
    verts[i] = i;

  vector <vector<int>> perms(0, vector <int> (0));

  do {
    if (verts[0] == 0) {
      vector <int> temp;
      for (int i = 0; i < vertices; i++)
        temp.push_back(verts[i]);
        
      perms.push_back(temp);
    }
  } while (next_permutation(verts, verts + vertices));

  vector <int> costs;
  int cost = 0;
  bool path = true;
  int index;
  int breaks = 0;

  for (int i = 0; i < perms.size(); i++) {
    cost = 0;
    path = true;
    for (int k = 0; k < vertices; k++) {
      if (k == vertices - 1 && input[perms[i][k]][0] != 0) {
        cost += input[perms[i][k]][0];
        break;
      } else if (input[perms[i][k]][perms[i][k + 1]] == 0 || k == vertices) {
        path = false;
        breaks++;
        break;
      } else {
        cost += input[perms[i][k]][perms[i][k + 1]];
      }
    }
    if (path == true) {
      costs.push_back(cost);
      vector < int > temp;
      for (int j = 0; j < vertices; j++)
        temp.push_back(perms[i][j]);
      true_permutations.push_back(temp);
    }
  }

  if (breaks == perms.size()) {
    cout << "Path:" << endl;
    cout << "Cost:-1" << endl;
    return 0;
  }

  int min = costs[0];
  index = 0;
  for (int i = 0; i < costs.size(); i++) {
    if (costs[i] < min) {
      index = i;
      min = costs[i];
    }
  }

  cout << "Path:";
  for (int i = 0; i < vertices; i++)
    cout << cities[true_permutations[index][i]] << "->";
  cout << cities[0] << endl;

  cout << "Cost:" << min;
  return 0;
}