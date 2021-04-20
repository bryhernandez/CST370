/*
 * Title: hw7_2.cpp
 * Abstract: This program will show the best traversal with a specified number if hops
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 03/26/2021
 */
 
 #include <iostream>
 #include <vector>
 #include <string>
 #include <queue>
 #include <algorithm>
 using namespace std;
 
 int index_of(vector<string> cities, string city){
    for(int i = 0; i < cities.size(); i ++){
        if(cities[i] == city)
            return i;
    }
    return -1;
 }
 
 int main(){
    int city_num;
    cin >> city_num;
    
    vector<string> cities;
    vector<vector<int>> edges(city_num, vector <int> (0));
    
    for(int i = 0; i < city_num; i++){
        string city;
        cin >> city;
        cities.push_back(city);
    }
    sort(cities.begin(), cities.end());
    
    int edges_num;
    cin >> edges_num;
    
    for (int i = 0; i < edges_num; i++) {
        string start;
        string end;
        cin >> start >> end;
        int st_index = 0;
        int end_index = 0;
    
        for (int k = 0; k < cities.size(); k++) {
          if (start == cities[k])
            st_index = k;
          if (end == cities[k])
            end_index = k;
        }
    
        edges[st_index].push_back(end_index);
    }
    
    string start_city;
    cin >> start_city;
    int max;
    cin >> max;
    
    int start_index = index_of(cities, start_city);
    
    vector <int> mark(edges.size(), -1);
    queue <int> q;
    
    int count = -1;
    mark[start_index] = ++count;
    q.push(start_index);
    while (!q.empty()) {
        bool is_hop = false; //true if the city has been visited
        int current = q.front();
        q.pop();
    
        for (int i = 0; i < edges[current].size(); i++) {
          int next_hop = edges[current][i];
          if (mark[next_hop] == -1) {
            mark[next_hop] = mark[current] + 1;
            q.push(next_hop);
            is_hop = true;
          }
        }
        if (is_hop)
          ++count;
    }
    
    for (int i = 0; i < edges.size(); i++) {
        if (mark[i] > max || mark[i] == -1)
            continue;
        cout << cities[i] << endl;
    }
 }