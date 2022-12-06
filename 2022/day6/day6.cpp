#include <iostream>
#include <fstream>
#include <string>

int isUnique(std::string& c){
    for(int i = 0; i < c.size(); i++){
        for(int j = i + 1; j < c.size(); j++){
            if(c[i] == c[j])
                return i+1;
        }
    }
    return 0;
}

int getMarker(const std::string& content, int& marker, const int& distinct){
    std::string check;
    int checkUnique = 0;

    while(true){
        check = content.substr(marker, distinct);
        checkUnique = isUnique(check);
        if(checkUnique == 0){
            break;
        }else{
            check.clear();
            marker += checkUnique;
        }
    }
    marker += distinct;
    return marker;
}

int main(){
    std::string fileName = "input.txt";
    std::ifstream file {fileName};

    std::string content;
    file >> content;

    int marker = 0;
    std::string check;
    int checkUnique = 0;

    int part1 = getMarker(content, marker, 4);
    int part2 = getMarker(content, marker, 14);
    std::cout << "Part one: " << part1 << "\nPart two: " << part2 << '\n';
}
