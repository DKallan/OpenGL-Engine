#include "BasicTexture.h"

BasicTexture::BasicTexture(const char* file)
{
	TextureLoader::Instance().LoadTexture(file);
}

BasicTexture::~BasicTexture()
{
}

void BasicTexture::BindTexture() const
{
	glBindTexture(GL_TEXTURE_2D, _id);
}
