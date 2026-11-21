#pragma once
// 2008-06 native RBX::ViewNew::MaterialFactory, profile copy for the Part::getMaterial 004eb190 unit
// (native-classes/ViewNewPartMaterial.cpp, reached first through /I{headers}/partmaterial-profile). It is the
// ViewNew/MaterialFactory2008.h declaration (destructor only, no layout: never use it for new, sizeof or member
// access) plus the two lookups that getMaterial calls:
//   004f1a60 getMegaMaterial / 004f1c60 getMaterial: thiscall on ViewBase +0x10 (materialFactory.get()), hidden
//   ReferenceCountedPointer<MaterialBase> result, Attributes passed by value (`sub esp, 0xc` and three dword
//   stores: BrickColor, transparency, reflectance) - 004eba11..004eba31, 004ebab6..004ebad6, 004ebbc9..004ebbe9.
//   Names and by-value Attributes follow the donor tools/openrbx Client/RbxView/MaterialFactory.h
//   (getMegaMaterial(Attributes), getMaterial(Attributes)); the 2008 return pointee is RenderBase::MaterialBase
//   (PartChunk material +0xc4). Proposal: move these two declarations into ViewNew/MaterialFactory2008.h.

#include "v8datamodel/BrickColor.h"
#include <G3D/ReferenceCount.h>

namespace RBX
{
	namespace RenderBase
	{
		class MaterialBase;
	}

	namespace ViewNew
	{
		class MaterialFactory
		{
		public:
			// INFERRED: 12-byte material-cache key used by the 2008 comparator.
			struct Attributes
			{
				BrickColor color;
				float transparency;
				float reflectance;
				bool operator<(const Attributes& other) const;
			};
			~MaterialFactory();                                          // 004d7460
			G3D::ReferenceCountedPointer<RenderBase::MaterialBase> getMegaMaterial(Attributes attributes); // 004f1a60
			G3D::ReferenceCountedPointer<RenderBase::MaterialBase> getMaterial(Attributes attributes);     // 004f1c60
		};
	}
}
