#include "v8datamodel/Decal.h"
namespace RBX { void Decal::setTexture(TextureId value) { if (texture != value) { texture = value; raisePropertyChanged(prop_Texture); } } }
