#ifndef SITELAYERINGFILEREADER_H
#define SITELAYERINGFILEREADER_H

#include "SiteLayering.h"

#include <string>

class SiteLayeringFile_Reader
{
public:
	SiteLayeringFile_Reader();
	~SiteLayeringFile_Reader();

	virtual void set_input_file(std::string) = 0;
	virtual void populate_layering(SiteLayering*) = 0;
};

#endif // !SITELAYERINGFILEREADER_H