#include "jb_texture.h"

JB_Texture::JB_Texture() {

}

JB_Texture::JB_Texture(std::string path) {

}

JB_Texture::~JB_Texture() {

}

bool JB_Texture::loadFile(std::string path) {
	ILboolean success;

	if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
	{
		/// wrong DevIL version ///
		//std::string err_msg = "Wrong DevIL version. Old devil.dll in system32/SysWow64?";
		//char* cErr_msg = (char *)err_msg.c_str();
		//abortGLInit(cErr_msg);
		return -1;
	}

	ilInit();

	//if (scene->HasTextures()) abortGLInit("Support for meshes with embedded textures is not implemented");

	/* getTexture Filenames and Numb of Textures */
	for (unsigned int m = 0; m < scene->mNumMaterials; m++)
	{
		int texIndex = 0;
		aiReturn texFound = AI_SUCCESS;

		aiString path;	// filename

		while (texFound == AI_SUCCESS)
		{
			texFound = scene->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
			textureIdMap[path.data] = NULL; //fill map with textures, pointers still NULL yet
			texIndex++;
		}
	}


}