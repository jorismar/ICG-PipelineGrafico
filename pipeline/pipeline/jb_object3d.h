#ifndef JB_OBJECT3D_H
#define JB_OBJECT3D_H

#include "jb_texture.h"
#include <fstream>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

class JB_Object3D {
	private:
		JB_Texture*			texture;
		std::string			path;
		const aiScene*		scene;
		Assimp::Importer	importer;

	public:
		JB_Object3D();
		JB_Object3D(std::string path);
		virtual ~JB_Object3D();

		bool loadObjFile();
		bool loadObjFile(std::string path);
};

#endif