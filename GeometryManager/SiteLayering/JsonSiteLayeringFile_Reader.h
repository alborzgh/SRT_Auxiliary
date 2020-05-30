#ifndef JSONSITELAYERINGFILEREDER_H
#define JSONSITELAYERINGFILEREDER_H

#include "SiteLayeringFile_Reader.h"

class JsonSiteLayeringFile_Reader :
    public SiteLayeringFile_Reader
{
public:
    JsonSiteLayeringFile_Reader();
    ~JsonSiteLayeringFile_Reader();

    virtual void set_input_file(std::string);
    virtual void populate_layering(SiteLayering*);
};

#endif // !JSONSITELAYERINGFILEREDER_H