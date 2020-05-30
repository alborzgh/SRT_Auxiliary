#ifndef GEOMETRYMANAGER_H 
#define GEOMETRYMANAGER_H 

#include <string> 

#include "GeometryFile_Reader.h"
#include "GeometryLayer.h"
#include "GeometryBase.h"

class GeometryManager
{
public:
	GeometryManager();
	GeometryManager(std::string geometry_fn);
	GeometryManager(std::string geometry_fn, std::string filetype);
	~GeometryManager();

	int read_geometry_file(std::string geometry_fn, std::string filetype = "__na__");
	GeometryLayer get_layer(std::string tag) { return layer_library[tag]; };
	GeometryBase get_base(std::string tag) { return base_library[tag]; };

private:
	GeometryFile_Reader* geometry_file;
	std::map<std::string, GeometryLayer> layer_library;
	std::map<std::string, GeometryBase> base_library;

};

#endif // !GEOMETRYMANAGER_H