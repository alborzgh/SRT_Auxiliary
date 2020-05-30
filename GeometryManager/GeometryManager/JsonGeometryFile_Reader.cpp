#include "JsonGeometryFile_Reader.h"

#include <fstream>
#include <iostream>

JsonGeometryFile_Reader::JsonGeometryFile_Reader()
{

}

JsonGeometryFile_Reader::~JsonGeometryFile_Reader()
{

}

int
JsonGeometryFile_Reader::read_json_file()
{
	std::ifstream json_file(_input_filename);
	_data_json = nlohmann::json::parse(json_file)["Geometry_Library"];

	return 0;
}

int
JsonGeometryFile_Reader::populate_layers(std::map<std::string, GeometryLayer>& layer_list, std::map<std::string, GeometryBase>& base_list)
{
	read_json_file();

	try
	{
		for (nlohmann::json::iterator it = _data_json.begin(); it != _data_json.end(); ++it)
		{
			if (it.key() == "Base_Library")
			{
				nlohmann::json temp = it.value();
				for (nlohmann::json::iterator layer_it = temp.begin(); layer_it != temp.end(); ++layer_it)
				{
					nlohmann::json temp2 = layer_it.value();
					base_list[layer_it.key()] = GeometryBase(layer_it.key(), temp2["Material"]);
				}
			}
			else if (it.key() == "Layers_Library") {
				nlohmann::json temp = it.value();
				for (nlohmann::json::iterator layer_it = temp.begin(); layer_it != temp.end(); ++layer_it)
				{
					nlohmann::json temp2 = layer_it.value();
					layer_list[layer_it.key()] = GeometryLayer(layer_it.key(), temp2["Thickness"], temp2["Material"]);
				}
			}
			std::cout << it.key() << " : " << it.value() << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Error in parsing the json file." << std::endl;
	}

	return 0;
}
