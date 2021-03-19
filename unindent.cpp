#include <iostream>
#include <stdio.h>
#include <ctype.h>
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


