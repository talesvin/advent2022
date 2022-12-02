#include <iostream>
#include <string>
#include <fstream>

int main(){
    // rock A - X, paper B - Y, scissor C - Z
    // rock - 1, paper - 2, scissor - 3
    // lost - 0, draw - 3, win - 6
    std::string fileName = "input";
    std::ifstream file {fileName};

    std::string input;
    int score = 0;
    while(std::getline(file, input)){
        if(input[0] == 'A'){
            if(input[2] == 'Y')
                score += 8;
            else if(input[2] == 'Z')
                score += 3;
            else
                score += 4;
        }else if(input[0] == 'B'){
            if(input[2] == 'X')
                score += 1;
            else if(input[2] == 'Z')
                score += 9;
            else
                score += 5;
        }else{
            if(input[2] == 'X')
                score += 7;
            else if(input[2] == 'Y')
                score += 2;
            else 
                score += 6;
        }
    }
    std::cout << "Final score: " << score;
}
