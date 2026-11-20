// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native RBX::ViewNew::Texture::onTexturePropertyChanged (004e6bc0, ownerless lane draft).
// Decoded assembly (roc native-asm): descriptor==&FaceInstance::prop_Face(0x97b57c)->invalidateMesh(0x4e6740);
// descriptor==&RBX::Decal::prop_Texture/prop_Specular/prop_Shiny{0x975f14,0x975ef8,0x975f30}->invalidateMaterial(0x4e68b0);
// descriptor==&RBX::Texture::prop_StudsPerTileU/prop_StudsPerTileV{0x975f68,0x975f4c}->invalidateMesh(0x4e6740); ret 4.
// The target compares the descriptor POINTER to the static property addresses (no *descriptor dereference,
// no null check).  Statement order matches nearest analog Decal::onDecalPropertyChanged in ViewNewPart.cpp.
#include "ViewNew/PartChunk.h"
#include "v8datamodel/Decal.h"

namespace RBX
{
	namespace ViewNew
	{
		void Texture::onTexturePropertyChanged(const Reflection::PropertyDescriptor* descriptor)
		{
			__assume(descriptor != 0);
			if (descriptor == &FaceInstance::prop_Face)
				invalidateMesh();
			else if (descriptor == &RBX::Decal::prop_Texture || descriptor == &RBX::Decal::prop_Specular || descriptor == &RBX::Decal::prop_Shiny)
				invalidateMaterial();
			else if (descriptor == &RBX::Texture::prop_StudsPerTileU || descriptor == &RBX::Texture::prop_StudsPerTileV)
				invalidateMesh();
		}
	}
}
