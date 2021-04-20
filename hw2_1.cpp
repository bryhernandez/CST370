/*
 * Title: hw2_1.cpp
 * Abstract: This program displays the difference between two times given by the user
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 02/12/21
 */
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
  string timestamp1, timestamp2; 
  vector<int> time1; 
  vector<int> time2; 
  int temp, second, minute, hour; 
  
  cin >> timestamp1;
  cin >> timestamp2;
  
  for (int i = 0; i < timestamp1.length(); i++) {
    if (timestamp1[i] == ':') {
      timestamp1[i] = ' ';
    }
  }
  
  for (int i = 0; i < timestamp2.length(); i++) {
    if (timestamp2[i] == ':') {
      timestamp2[i] = ' ';
    }
  }
  
  stringstream stream1(timestamp1);
  
  while (stream1 >> temp)
    time1.push_back(temp);
  
  stringstream stream2(timestamp2);
  
  while (stream2 >> temp)
    time2.push_back(temp);
  
  if (time2[2] - time1[2] < 0) {
    time2[1] -= 1;
    time2[2] += 60;
  }
  second = time2[2] - time1[2];
  
  if (time2[1] - time1[1] < 0) {
    time2[0] -= 1;
    time2[1] += 60;
  }
  minute = time2[1] - time1[1];

  if (time2[0] < time1[0]) {
    int subCount = time1[0];
    hour = time2[0];
    for (int i = subCount; i > 0; i--) {
      if (hour == 0) {
        hour = 24;
      }
      hour--;
    }
  } else
    hour = time2[0] - time1[0];

  if (hour < 10)
    cout << "0" << hour << ":";
  else 
    cout << hour << ":";
  
  if (minute < 10) 
    cout << "0" << minute << ":";
  else 
    cout << minute << ":";
  
  if (second < 10) 
    cout << "0" << second;
  else 
    cout << second;
  
  return 0;
}