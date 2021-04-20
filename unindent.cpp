#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <cctype>
#include "unindent.h"

std::string removingLeadingSpaces(std::string line){
    std::string result = "";
    // this will prevent us from removing spaces between words and only leading spaces
    bool hitLetter = false;
    for(int i = 0; i < line.length(); i++){
        // if not a leading space, add to results
        if(!isspace(line[i])){
            result += line[i];
            // indicated that you are in the middle of code and not leading spaces
            hitLetter = true;
        }else if(hitLetter){
            // will add spaces between words
            result += line[i];
        }
    }
    result += '\n';
    return result;
}
std::string unindent(){
    std::string code;
    std::string result = "";
    while(getline(std::cin, code)){
        result += removingLeadingSpaces(code);
    }
    return result;
}



// unindent() but with an input for testing.
// only differences are the inclusion of
// the std::istringstream line and the
// replacement of std::cin with issInput
std::string unindentTesting(std::string input) {
    std::string code;
    std::string result = "";
    
    // make a stringstream to read line by line
    std::istringstream issInput(input);
    
    while(getline(issInput, code)){
        result += removingLeadingSpaces(code);
    }
    
    return result;
}