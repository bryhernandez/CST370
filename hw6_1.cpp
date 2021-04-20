/*
 * Title: hw6_1.cpp
 * Abstract: this program takes in a list a numbers and then it puts all the negative numbers in front of all the positive numbers in two differemt ways.
 * Author: Bryan Hernandez
 * ID: 0711
 * Date: 03/13/2021
 */
 
 #include <iostream>
 #include <vector>
 using namespace std;
 
 void display(vector<int> numbers){
     for(int i = 0; i < numbers.size(); i ++){
         cout << numbers[i] << " ";
     }
     cout << endl;
 }
 
 
 int main(){
     int nums;
     cin >> nums;
     
     vector<int> numbers1;
     vector<int> numbers2;
     
     for (int i = 0; i < nums; i++){
         int temp;
         cin >> temp;
         numbers1.push_back(temp);
         numbers2.push_back(temp);
     }
     
     for(int i = 0; i < numbers1.size(); i++){ //first approach
         if(numbers1[i] > 0){ 
            for (int j = numbers1.size()-1; j >= 0; j--){
                if(i >= j)
                    break;
                if(numbers1[j] < 0){
                    int temp = numbers1[j];
                    numbers1[j] = numbers1[i];
                    numbers1[i] = temp;
                    break;
                }
            }
         }
     }
     
     display(numbers1);
     
     int counter = 0;
     for(int i = 0; i < numbers2.size(); i++){ //second approach
        if(counter >= numbers2.size())
            break;
         if(numbers2[i] > 0){ 
            for (int j = i; j < numbers2.size(); j++, counter++){
                if(numbers2[j] < 0){
                    int temp = numbers2[i];
                    numbers2[i] = numbers2[j];
                    numbers2[j] = temp;
                    i++;
                }
            }
         }
     }
     
     display(numbers2);
 }