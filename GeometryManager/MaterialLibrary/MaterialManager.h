#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include <string> 

#include "MaterialFile_Reader.h"

class MaterialManager
{
public:
	MaterialManager();
	MaterialManager(std::string materialLib_fn);
	MaterialManager(std::string materialLib_fn, std::string filetype);
	~MaterialManager();

	int read_material_file(std::string materialLib_fn, std::string filetype = "__na__");
	LayerMaterial get_material(std::string tag) { return material_library[tag]; };

private:
	MaterialFile_Reader* material_file;
	std::map<std::string, LayerMaterial> material_library;

};

#endif // !defien MATERIALMANAGER_H
