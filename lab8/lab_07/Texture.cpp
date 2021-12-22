#include "Texture.h"
void Texture::load(std::string filename)
{
	ILuint imageId = ilGenImage();
	ilBindImage(imageId);
	wchar_t unicodeString[256];
	wsprintf(unicodeString, L"%S", filename.c_str());
	bool loaded = ilLoadImage(unicodeString);
	if (loaded) {
		ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
		int width = ilGetInteger(IL_IMAGE_WIDTH);
		int height = ilGetInteger(IL_IMAGE_HEIGHT);
		int format = ilGetInteger(IL_IMAGE_FORMAT);
		int type = ilGetInteger(IL_IMAGE_TYPE);
		ILubyte* pixData = new ILubyte[IL_IMAGE_WIDTH * IL_IMAGE_HEIGHT];
		ilCopyPixels(0, 0, 0, width, height, 1, format, type, pixData);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glActiveTexture(GL_TEXTURE0);
		glGenTextures(1, &texIndex);
		glBindTexture(GL_TEXTURE_2D, texIndex);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixData);
		glGenerateMipmap(GL_TEXTURE_2D);
		ilDeleteImage(imageId);
	}
	else {
		std::cout << "Not open image\n";
	}
}

void Texture::apply()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}
void Texture::disableAll() {
	glDisable(GL_TEXTURE_2D);
}