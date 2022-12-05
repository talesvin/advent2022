#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void clearInts(int& mq, int& mf, int& mt){
    mq = 0;
    mf = 0;
    mt = 0;
}

void part1(const int& mq, const int& mf, const int& mt, std::vector<std::vector<char>>& c){
    char letter;
    int temp = 1;
    while(temp <= mq){
        letter = c[mf-1][c[mf-1].size() - temp];
        c[mt-1].push_back(letter);
        temp++;
    }

    temp = mq;
    while(temp > 0){
        c[mf-1].pop_back();
        temp--;
    }
}

void part2(const int& mq, const int& mf, const int& mt, std::vector<std::vector<char>>& c){
    char letter;
    int temp = mq;
    while(temp > 0){
        letter = c[mf-1][c[mf-1].size() - temp];
        c[mt-1].push_back(letter);
        temp--;
    }

    temp = mq;
    while(temp > 0){
        c[mf-1].pop_back();
        temp--;
    }
}

int main(){
    std::vector<std::vector<char>> crates{
            {'B', 'Q', 'C'},
            {'R', 'Q', 'W', 'Z'},
            {'B', 'M', 'R', 'L', 'V'},
            {'C', 'Z', 'H', 'V', 'T', 'W'},
            {'D', 'Z', 'H', 'B', 'N', 'V', 'G'},
            {'H', 'N', 'P', 'C', 'J', 'F', 'V', 'Q'},
            {'D', 'G', 'T', 'R', 'W', 'Z', 'S'},
            {'C', 'G', 'M', 'N', 'B', 'W', 'Z', 'P'},
            {'N', 'J', 'B', 'M', 'W', 'Q', 'F', 'P'}
    };

    std::string fileName = "input2.txt";
    std::ifstream file {fileName};

    char commands;
    int movQuant = 0;
    int movFrom = 0;
    int movTo = 0;
    std::string tempNum;

    while(!file.eof()){
        commands = file.get();
        if(commands == ' '){
            if(movQuant > 0 && tempNum.size() > 0){
                movFrom = std::stoi(tempNum);
                tempNum.clear();
            }else if(tempNum.size() > 0){
                movQuant = std::stoi(tempNum);
                tempNum.clear();
            }
        }else if(commands == '\n'){
            movTo = std::stoi(tempNum);
            // Uncomment the part you want to see the answer
            // part1(movQuant, movFrom, movTo, crates);
            part2(movQuant, movFrom, movTo, crates);
            clearInts(movQuant, movFrom, movTo);
            tempNum.clear();
        }else if(std::isdigit(commands)){
            tempNum += commands;
        }
    }

    int inputSize = crates.size();
    for(int i = 0; i < inputSize; i++){
        std::cout << crates[i][crates[i].size() - 1] << '\n';
    }
}
