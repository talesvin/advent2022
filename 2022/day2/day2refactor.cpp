#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main(){
    // rock A, paper B, scissor C
    // part2: X - lose, Y - draw, Z - win
    // rock - 1, paper - 2, scissor - 3
    // lost - 0, draw - 3, win - 6
    std::string fileName = "input.txt";
    std::ifstream file {fileName};

    std::string input;
    int score = 0;

    std::map<std::string, int> gameScore {
            {"A X", 3}, {"A Y", 4}, {"A Z", 8}, 
            {"B X", 1}, {"B Y", 5}, {"B Z", 9}, 
            {"C X", 2}, {"C Y", 6}, {"C Z", 7}};

    while(std::getline(file, input)){
        score += gameScore[input];
    }

    std::cout << "Final score: " << score;
}
