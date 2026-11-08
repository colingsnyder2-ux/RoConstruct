#include "v8datamodel/Decal.h"
namespace RBX {
const Reflection::PropDescriptor<Decal, TextureId> Decal::prop_Texture("Texture", "Appearance", &Decal::getTexture, &Decal::setTexture, Reflection::PropertyDescriptor::STANDARD);
}
