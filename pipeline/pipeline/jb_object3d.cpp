#include "jb_object3d.h"

JB_Object3D::JB_Object3D() {
	this->texture = new JB_Texture();
	this->path = "";
	this->scene = NULL;
}

JB_Object3D::JB_Object3D(std::string path) {
	this->texture = new JB_Texture();
	this->path = path;
	this->scene = NULL;
}

JB_Object3D::~JB_Object3D() {

}

bool JB_Object3D::loadObjFile() {
	// Check if file exists
	std::ifstream fin(this->path.c_str());
	if (!fin.fail())
	{
		fin.close();
	}
	else
	{
		/*************** ERR_HANDLING ***************
		MessageBox(NULL, ("Couldn't open file: " + pFile).c_str(), "ERROR", MB_OK | MB_ICONEXCLAMATION);
		logInfo(importer.GetErrorString());
		*/
		return false;
	}

	this->scene = this->importer.ReadFile(this->path, aiProcessPreset_TargetRealtime_Quality);

	// If the import failed, report it
	if (!scene)
	{
		/*************** ERR_HANDLING ***************
		logInfo(this->importer.GetErrorString());
		*/
		return false;
	}

	// Now we can access the file's contents.
	/*************** ERR_HANDLING ***************
	logInfo("Import of scene " + pFile + " succeeded.");
	*/

	// We're done. Everything will be cleaned up by the importer destructor
	return true;
}

bool JB_Object3D::loadObjFile(std::string path) {
	this->path = path;
	return this->loadObjFile();
}
