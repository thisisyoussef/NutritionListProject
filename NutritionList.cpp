// NutritionList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cpprest/http_client.h>
#include <json/json.h>
#include <json/value.h>
#include "Graph.h"
#include "User.h"
using namespace std;
void addEdges(vector<node> &currentlist,Graph& productGraph) {
    for (unsigned int j = 0; j < currentlist.size(); j++) {
        for (unsigned int k = 0; k < currentlist.size(); k++) {
            if (k != j) {
                productGraph.insertEdge(currentlist[j], currentlist[k], currentlist[k].protien);
            }
        }
    }
    currentlist.clear();
}
int main()
{
    static vector<node> products;
    std::cout << "Hello World!\n";
    vector<string> ids;
   // ReadFile("food.csv", ids);
    Graph productGraph;
    vector<node> highProtein;
    vector<node> highFat;
    vector<node> neutral;
    vector<node> highCarbs;
    vector<node> other;

    std::cout << "Processing Data.." << endl;
    std::ifstream people_file("foodData2.json", std::ifstream::binary);
    Json::Value food1;
    people_file >> food1;
    people_file.close();
    for (unsigned int i = 0; i < food1["SurveyFoods"].size(); i++) {
       // cout << food1["SurveyFoods"][i] << endl;
        node temp;
        temp.protien = food1["SurveyFoods"][i]["foodNutrients"][0]["amount"].asFloat();
        temp.carb = food1["SurveyFoods"][i]["foodNutrients"][2]["amount"].asFloat();
        temp.fat = food1["SurveyFoods"][i]["foodNutrients"][1]["amount"].asFloat();
        temp.name = food1["SurveyFoods"][i]["description"].asString();
        temp.ID = food1["SurveyFoods"][i]["fdcId"].asInt();
        if (temp.protien > 10) {
            if (highProtein.size() >= 10) {
                addEdges(highProtein, productGraph);
            }
            highProtein.push_back(temp);
        }
        if (temp.fat > 10) {
            if (highFat.size() >= 10) {
                addEdges(highFat, productGraph);
            }
            highFat.push_back(temp);
        }  
        if (temp.carb > 10) {
            if (highCarbs.size() >= 10) {
                addEdges(highCarbs, productGraph);
            }
            highCarbs.push_back(temp);
        }
        if (temp.carb <= 10 && temp.fat <= 10 && temp.protien <= 10) {
            if (other.size() >= 10) {
                addEdges(other, productGraph);
            }
            other.push_back(temp);
        }
    }

    productGraph.printGraph();
    productGraph.BFSsearch("products[1].name");
    return 0;
}