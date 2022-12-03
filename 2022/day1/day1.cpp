#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    std::string fileName = "input.txt";
    std::ifstream file {fileName};

    std::string calories;
    std::vector<std::string> tempCalories;
    std::vector<std::vector<std::string>> elfCalories;

    int calSum = 0;
    std::vector<int> finalVec;

    while(std::getline(file, calories)){
        if(calories == ""){
            elfCalories.push_back(tempCalories);
            tempCalories.clear();
        }else{
            tempCalories.push_back(calories);
        }
    }

    for(std::vector<std::string> tempVec: elfCalories){
        for(std::string i: tempVec){
            calSum += stoi(i);
        }
        finalVec.push_back(calSum);
        calSum = 0;
    }
    std::sort(finalVec.begin(), finalVec.end());
    calSum = finalVec[finalVec.size() - 1] + finalVec[finalVec.size() - 2] + finalVec[finalVec.size() - 3];
    std::cout << "Top guy: " << finalVec[finalVec.size() - 1] << '\n';
    std::cout << "Top three: " << calSum;
}
