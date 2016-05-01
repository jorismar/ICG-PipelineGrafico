#include <IL/il.h>
#include <string>
#include <assimp/scene.h>

class JB_Texture {
private:
	aiScene* scene;

public:
	JB_Texture();
	JB_Texture(std::string path);
	virtual ~JB_Texture();

	bool loadFile(std::string path);
};

