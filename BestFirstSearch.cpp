#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <sstream>


int main(int argc, char ** argv){
	//assert(argc == 3);
	std::ifstream reader(argv[1]);
	std::string line;
	while(std::getline(reader, line)){
		std::stringstream linestream(line);
		std::string value;

		while(getline(linestream, value, ',')){
			std::cout << "Value = " << value << std::endl;
		}
		std::cout << "End of line==============" << std::endl;
	}



	return 0;
}
