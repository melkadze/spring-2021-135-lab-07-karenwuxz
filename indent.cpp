#include <iostream>
#include <sstream>
#include "unindent.h"
#include "indent.h"

int countChar(std::string line, char c){
    int freq = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == c){
            freq++;
        }
    }
    return freq;
}
std::string formatting(){
    std::string result = "";
    std::string line;
    std::istringstream code(unindent());
    int opened = 0;
    while(getline(code, line)){
        if(countChar(line, '}') != 0){
            opened--;
        }
        for(int j = 0; j < opened; j++){
            result += '\t';
        }
        opened += countChar(line, '{');
        for(int i = 0; i < line.length(); i++){
            result += line[i];
        }
        result += '\n';
    }
    return result;
    
}
