#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::string fileName = "input.txt";
    std::ifstream file {fileName};

    std::string pair;
    std::vector<std::string> pairs;

    bool left = false;
    bool hip = false;

    std::string rangeStart;
    std::string rangeEnd;
    std::string sectStart;
    std::string sectEnd;

    int partOne = 0;
    int partTwo = 0;

    while(std::getline(file, pair)){
        pairs.push_back(pair);
    }
    for(int word = 0; word < pairs.size(); word++){
        for(int letter = 0; letter < pairs[word].size(); letter++){
            char currentChar = pairs[word][letter];
            if(currentChar != '-' && currentChar != ',' && currentChar != '\n' && isdigit(currentChar)){
                if(hip == false && left == false)
                    rangeStart += currentChar;
                else if(hip == true && left == false)
                    rangeEnd += currentChar;
                else if(hip == false && left == true)
                    sectStart += currentChar;
                else
                    sectEnd += currentChar;
            }else if(currentChar == '-'){
                hip = true;
            }else if(currentChar == ','){
                left = true;
                hip = false;
            }
        }
        if(std::stoi(rangeStart) <= std::stoi(sectStart) && std::stoi(rangeEnd) >= std::stoi(sectEnd) || std::stoi(sectStart) <= std::stoi(rangeStart) && std::stoi(sectEnd) >= std::stoi(rangeEnd))
            partOne++;

        if(std::stoi(rangeStart) <= std::stoi(sectEnd) && std::stoi(rangeStart) >= std::stoi(sectStart) || std::stoi(sectStart) <= std::stoi(rangeEnd) && std::stoi(sectStart) >= std::stoi(rangeStart))
            partTwo++;

        left = false;
        hip = false;

        rangeStart.clear();
        rangeEnd.clear();
        sectStart.clear();
        sectEnd.clear();
    }
    std::cout << "Part One: " << partOne << '\n';
    std::cout << "Part Two: " << partTwo << '\n';
}
