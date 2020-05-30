#ifndef SITELAYERING_H
#define SITELAYERING_H

#include "GeometryManager.h"
#include "GeometryLayer.h"
#include "GeometryBase.h"
#include "SiteLayeringFile_Reader.h"

#include "MaterialManager.h"
#include "LayerMaterial.h"

class SiteLayering
{
public:
	SiteLayering();
	~SiteLayering();

	double getTotThickness() { return sl_totalThickness; };
	double getEquivalentShearVel() { return sl_equivalentVS; };
	double getEquivalentCompVel() { return sl_equivalentVP; };
	int    getNumLayers() { return sl_numLayers; };
	double getGWTdepth() { return sl_GWT_depth; };

	void addNewLayer(GeometryLayer newLayer);
	GeometryLayer getLayer(int index);
	GeometryBase getBase();
	double getNaturalPeriod();
	int readFromFile(const char*);

private:
	MaterialManager* theMatManager;
	GeometryManager* theGeomManager;
	SiteLayeringFile_Reader* theReader;

	std::vector<GeometryLayer> sl_layers;
	GeometryBase sl_base;

	double sl_natPeriod;
	double sl_totalThickness;
	double sl_equivalentVS;
	double sl_equivalentVP;
	double sl_GWT_depth;
	int    sl_numLayers;
};

#endif // !SITELAYERING_H