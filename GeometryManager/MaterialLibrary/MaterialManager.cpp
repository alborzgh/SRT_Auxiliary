#include "MaterialManager.h"
#include "JsonMaterialFile_Reader.h"

MaterialManager::MaterialManager()
{

}

MaterialManager::MaterialManager(std::string materialLib_fn)
{
	read_material_file(materialLib_fn);
}

MaterialManager::MaterialManager(std::string materialLib_fn, std::string filetype)
{
	read_material_file(materialLib_fn, filetype);
}

MaterialManager::~MaterialManager()
{

}

int 
MaterialManager::read_material_file(std::string materialLib_fn, std::string filetype)
{
	std::string material_filetype;

	if (filetype == "__na__")
	{
		// get the file extension
		size_t pos = materialLib_fn.find_last_of('.');
		if (pos == std::string::npos)
		{
			// Error, geometry file type not defined.
			return -1;
		}
		std::string file_ext = materialLib_fn.substr(pos + 1);

		if (file_ext == "json")
			material_filetype = "json";
		else if (file_ext == "txt")
			material_filetype = "text";
	}
	else {
		material_filetype = filetype;
	}

	if (material_filetype == "json")
	{
		if (!material_file)
		{
			material_file = new JsonMaterialFile_Reader();
			material_file->set_input_file(materialLib_fn);
			material_file->populate_materials(material_library);
		}
		else {
			material_file->set_input_file(materialLib_fn);
			material_file->populate_materials(material_library);
		}
	}
	else {
		// Error: File type either not detected or not appropriate
		return -1;
	}
	return 0;
}