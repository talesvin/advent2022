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
    int location = -1;

    while(std::getline(file, contents)){
        rucksacks.push_back(contents);
    }

    for(std::string content: rucksacks){
        for(int i = 0; i < content.size() / 2; i++){
            for(int j = content.size() / 2; j < content.size(); j++){
                location = repeated.find(content[i]);
                if(content[i] == content[j] && location == -1){
                    repeated += content[i];
                    if(static_cast<int>(content[i]) > 90)
                        finalSum += (static_cast<int>(content[i] - 96));
                    else
                        finalSum += (static_cast<int>(content[i] - 38));
                    break;
                }
            }
        }
        location = -1;
        repeated.clear();
    }
    std::cout << finalSum;
}
