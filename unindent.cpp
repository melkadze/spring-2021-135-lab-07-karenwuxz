#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "unindent.h"

std::string unindent(){
    std::string code;
    std::string result = "";
    bool hitLetter = false;
    while(getline(std::cin, code)){
        for(int i = 0; i < code.length(); i++){
            if(!isspace(code[i])){
                result += code[i];
                hitLetter = true;
            }else if(hitLetter){
                result += code[i];
            }
        }
        result += '\n';
        hitLetter = false;
    }
    return result;
}


