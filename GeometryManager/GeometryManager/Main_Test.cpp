#include <iostream>
#include <string>

#include "GeometryManager.h"

int main(int argc, const char* argv)
{
	std::cout << "Hello World!" << std::endl;

	GeometryManager gm("test.json");

	std::cout << gm.get_layer("Clay1").get_material_tag() << std::endl;
	std::cout << gm.get_base("Granite").get_material_tag() << std::endl;

	return 1;
}