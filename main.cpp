#include <iostream>
#include "unindent.h"
#include "indent.h"

int main(){ 
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << formatting() <<std::endl;
  std::cout << unindent() <<std::endl;
  return 0;
}
