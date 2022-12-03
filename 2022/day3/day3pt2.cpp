#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string fileName = "input.txt";
    std::ifstream file {fileName};

    std::string contents;
    std::vector<std::string> rucksacks;
    int finalSum = 0;

    std::string repeated;
    int firstLocation = -1;
    int secondLocation = -1;

    while(std::getline(file, contents)){
        rucksacks.push_back(contents);
    }

    //Part1
    for(std::string content: rucksacks){
        for(int i = 0; i < content.size() / 2; i++){
            for(int j = content.size() / 2; j < content.size(); j++){
                firstLocation = repeated.find(content[i]);
                if(content[i] == content[j] && firstLocation == -1){
                    repeated += content[i];
                    if(static_cast<int>(content[i]) > 90)
                        finalSum += (static_cast<int>(content[i] - 96));
                    else
                        finalSum += (static_cast<int>(content[i] - 38));
                    break;
                }
            }
        }
        firstLocation = -1;
        repeated.clear();
    }

    std::cout << "Part 1: " << finalSum << '\n';

    //Part2
    finalSum = 0;
    firstLocation = -1;
    for(int i = 0; i < rucksacks.size(); i += 3){
        for(char j: rucksacks[i]){
            firstLocation = rucksacks[i+1].find(j);
            secondLocation = rucksacks[i+2].find(j);
            if(firstLocation >= 0 && secondLocation >= 0){
                if(static_cast<int>(j) > 90)
                    finalSum += (static_cast<int>(j - 96));
                else
                    finalSum += (static_cast<int>(j - 38));
                firstLocation = -1;
                secondLocation = -1;
                break;
            }
            firstLocation = -1;
            secondLocation = -1;
        }
    }

    std::cout << "Part 2: " << finalSum << '\n';
}
