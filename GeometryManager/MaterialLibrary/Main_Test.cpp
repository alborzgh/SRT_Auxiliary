#include <iostream>
#include <string>

#include "MaterialManager.h"

int main(int argc, const char* argv)
{
	std::cout << "Hello World!" << std::endl;

	MaterialManager mm("test.json");

	std::cout << std::endl;
	std::cout << std::endl;

	LayerMaterial theMat;
	theMat = mm.get_material("Clay1_mat");
	std::cout << theMat.get_tag() <<" : " << theMat.get_type() << " - G = " << theMat.get_prperty("G") << std::endl;

	return 1;
}