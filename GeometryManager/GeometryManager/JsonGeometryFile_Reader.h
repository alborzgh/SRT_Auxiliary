#ifndef JSONGEOMETRYFILE_READER_H
#define JSONGEOMETRYFILE_READER_H

#include "GeometryFile_Reader.h"
#include "json.hpp"

class JsonGeometryFile_Reader :
	public GeometryFile_Reader
{
public:

	JsonGeometryFile_Reader();
	~JsonGeometryFile_Reader();

	virtual void set_input_file(std::string filename) { _input_filename = filename; };
	virtual int populate_layers(std::map<std::string, GeometryLayer>&, std::map<std::string, GeometryBase>&);

private:
	std::string _input_filename;
	nlohmann::json _data_json;

	int read_json_file();

};


#endif // !JSONGEOMETRYFILE_READER