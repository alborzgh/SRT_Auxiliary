#include "GeometryBase.h"

GeometryBase::GeometryBase()
{

}

GeometryBase::GeometryBase(std::string layer_tag, std::string material_tag)
{
	_layer_tag = layer_tag;
	_material_tag = material_tag;
}

GeometryBase::~GeometryBase()
{

}

int GeometryBase::set_material_tag(std::string tag)
{
	_material_tag = tag;
	return 0;
}

