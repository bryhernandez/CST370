/*
 * Title: hw4_2.cpp
 * Abstract: This program shows the number of events that take place concurrently
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 02/26/21
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> events){
    for (int i = 0; i < events.size(); i++)
        cout << events[i] << " " ;
    cout << endl;
}

int findConcurrent(int x, vector<int> events){
    int count = 0;
    for(int i = 0; i < events.size(); i++){
        if(events[i] == x)
            count ++;
    }
    return count;
}

int main(){
    int numEvents;
    cin >> numEvents;
    
    int start, end;
    vector <int> events;
    
    for (int i = 0; i < numEvents; i++){
        cin >> start >> end;
        
        for (int j = start; j <= end; j++){
            events.push_back(j);
        }
    }
    
    sort(events.begin(), events.end());
    
    int max = findConcurrent(events[0], events);
    for(int i = 0; i < events.size(); i ++){
        if(max < findConcurrent(events[i], events))
            max = findConcurrent(events[i], events);
    }
    
    cout << "Max events: " << max;
}