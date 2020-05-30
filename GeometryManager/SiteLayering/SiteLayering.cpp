#include "SiteLayering.h"

SiteLayering::SiteLayering() :
	sl_natPeriod(0.0),
	sl_numLayers(0),
	sl_totalThickness(0.0),
	sl_equivalentVS(0.0),
	sl_equivalentVP(0.0)
{

}

SiteLayering::~SiteLayering()
{

}

GeometryLayer
SiteLayering::getLayer(int index)
{
	return sl_layers[index];
}

GeometryBase 
SiteLayering::getBase()
{
	return sl_base;
}
