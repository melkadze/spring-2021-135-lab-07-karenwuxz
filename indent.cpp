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
        // if a } appears, we want to unindent by subtracking one \t from result 
        if(countChar(line, '}') != 0){
            opened--;
        }
        // adding tabs in the beginning of lines after checking for }
        for(int j = 0; j < opened; j++){
            result += '\t';
        }
        // Check/update the amount of {,telling us how many times to indent
        opened += countChar(line, '{');
        // add the rest of the line into result
        for(int i = 0; i < line.length(); i++){
            result += line[i];
        }
        result += '\n';
    }
    return result;
    
}

// formatting() but with an input for testing.
// only difference is replacing unindent()
// with unindentTesting(input)
std::string formattingTesting(std::string input){
    std::string result = "";
    std::string line;
    std::istringstream code(unindentTesting(input));
    int opened = 0;
    while(getline(code, line)){
        // if a } appears, we want to unindent by subtracking one \t from result 
        if(countChar(line, '}') != 0){
            opened--;
        }
        // adding tabs in the beginning of lines after checking for }
        for(int j = 0; j < opened; j++){
            result += '\t';
        }
        // Check/update the amount of {,telling us how many times to indent
        opened += countChar(line, '{');
        // add the rest of the line into result
        for(int i = 0; i < line.length(); i++){
            result += line[i];
        }
        result += '\n';
    }
    return result;
    
}