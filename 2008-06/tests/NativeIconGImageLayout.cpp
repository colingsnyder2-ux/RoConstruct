#include <G3D/GImage.h>
#include <stddef.h>
typedef char imageSize[sizeof(G3D::GImage)==20 ? 1 : -1];
typedef char widthOffset[offsetof(G3D::GImage,width)==8 ? 1 : -1];
typedef char heightOffset[offsetof(G3D::GImage,height)==12 ? 1 : -1];
typedef char channelsOffset[offsetof(G3D::GImage,channels)==16 ? 1 : -1];
const unsigned char* imageBytes(const G3D::GImage* image) { return image->byte(); }
