#include <iostream>
#include <string>
#include <fstream>

int main(){
    // rock A, paper B, scissor C
    // part2: X - lose, Y - draw, Z - win
    // rock - 1, paper - 2, scissor - 3
    // lost - 0, draw - 3, win - 6
    std::string fileName = "input";
    std::ifstream file {fileName};

    std::string input;
    int score = 0;
    while(std::getline(file, input)){
        if(input[0] == 'A'){ // rock
            if(input[2] == 'X')
                score += 3;
            else if(input[2] == 'Y')
                score += 4;
            else
                score += 8;
        }else if(input[0] == 'B'){ // paper
            if(input[2] == 'X')
                score += 1;
            else if(input[2] == 'Y')
                score += 5;
            else
                score += 9;
        }else{ // scissor
            if(input[2] == 'X')
                score += 2;
            else if(input[2] == 'Y')
                score += 6;
            else
                score += 7;
        }
    }
    std::cout << "Final score: " << score;
}
