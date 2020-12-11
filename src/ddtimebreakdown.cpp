#include "../header/timebreakdown.hpp"
#include "../header/ddtimebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

DDTimeBreakdown::DDTimeBreakdown() {}

void DDTimeBreakdown::collectPriceMetadata(Restaurant *rest) {
    ifstream fin;
    fin.open("../CSV/DoorDash - Restauraunt List.csv");

    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> column; 
    string line, word, temp;
    getline(fin, line);
    istringstream ss(line);
    int colIdx = 0;
    while(ss >> word){
        if(word == rest->getRestaurantName()){
            column.push_back(word);
            break;
        }
        else{
            if(ss.peek() == ',') ss.ignore();
            colIdx++;
        }
    }
    while(getline(fin,line)){
        int columnIdx = 0;
        while(ss >> word){
            if(columnIdx == colIdx){
                column.push_back(word);
                if(ss.peek() == ',') ss.ignore();
            }
            else{
                columnIdx++;
            }
        }
    }

    fin.close();
    
    // calculate time needed to prepare food
    //int foodPrep = rest->numItems() * 2;
    
    //Time cooking("Cooking", foodPrep);
    //timeBreakdown.push_back(foodPrep);

    int deliveryTime = stoi(row[4]);
    Time delivery("Delivery", deliveryTime);
    timeBreakdown.push_back(deliveryTime);
}