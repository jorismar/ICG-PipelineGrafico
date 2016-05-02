#ifndef JB_TEXTURE_H
#define JB_TEXTURE_H

#include <map>
#include <string>
#include <gl/GL.h>
#include <IL/il.h>
#include <assimp/scene.h>

class JB_Texture {
	private:
		GLuint*		textureIds;
		std::string path;
		std::map<std::string, GLuint*> textureIdMap;	// map image filenames to textureIds

	public:
		JB_Texture();
		JB_Texture(std::string path);
		virtual ~JB_Texture();

		int loadTexture(const aiScene* scene);
		int loadTexture(std::string path, const aiScene* scene);
};

#endif
