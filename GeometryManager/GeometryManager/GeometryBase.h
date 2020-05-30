#ifndef GEOMETRYBASE_H
#define GEOMETRYBASE_H

#include <string>

class GeometryBase
{
public:
	GeometryBase();
	GeometryBase(std::string layer_tag, std::string material_tag);
	~GeometryBase();

	int set_material_tag(std::string tag);

	std::string get_tag() { return _layer_tag; };
	std::string get_material_tag() { return _material_tag; };

private:
	std::string _layer_tag;
	std::string _material_tag;
};

#endif // !GEOMETRYBASE_H