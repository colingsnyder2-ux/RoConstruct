// 2008-06 native Ogre::VRbxFont: Roblox's port of G3D 6.09 GFont onto Ogre (Roblox Ogre fork, inactive recovery).
//
// Layout is binary-derived and fully explained (no padding guessed):
//   fromFile 00684eb0 allocates new(0x218), then calls the ctor 00684b10;
//   the ctor stores 128 ints at this+0x000 (loop [this + i*4]), this+0x200, this+0x204, this+0x208, and
//   constructs Ogre::TexturePtr at this+0x20c (12 bytes: SharedPtr vptr, pRep, pUseCount) -> ends at 0x218.
// Member names, order and the XAlign/YAlign/Spacing enums are G3D 6.09 GFont's (GLG3D/GFont.h): same fields at the
// same offsets; G3D's RenderDevice* member is absent here (texture is an Ogre::TexturePtr instead of TextureRef).
// Non-polymorphic: the exe has no RTTI/vftable for VRbxFont itself, only for SharedPtr<VRbxFont>.
#pragma once
// >>> native-status (generated) -- do not edit >>>
// VRbxFont2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 54fadce3 | roc native-status --write

#include <string>
#include <OgreSharedPtr.h>
#include <OgreTexture.h>
#include "G3D/Vector2.h"
#include "G3D/Color4.h"

namespace G3D
{
	class BinaryInput;
}

namespace Ogre
{
	class VisualEngine;     // exe-local, size 0x808: OgreRbx/VisualEngine2008.h

	class VRbxFont
	{
	public:
		enum XAlign {XALIGN_RIGHT, XALIGN_LEFT, XALIGN_CENTER};
		enum YAlign {YALIGN_TOP, YALIGN_BASELINE, YALIGN_CENTER, YALIGN_BOTTOM};
		enum Spacing {PROPORTIONAL_SPACING, FIXED_SPACING};

	private:
		int subWidth[128];                                           // +0x000
		int charWidth;                                               // +0x200
		int charHeight;                                              // +0x204
		int baseline;                                                // +0x208
		TexturePtr texture;                                          // +0x20c

		G3D::Vector2 computePackedArray(const std::string& s, double x, double y, double w, double h,
		                                Spacing spacing, G3D::Vector2* array) const;               // 006843f0

	public:
		VRbxFont(const std::string& filename, G3D::BinaryInput& b);                                // 00684b10
		static SharedPtr<VRbxFont> fromFile(const std::string& filename);                           // 00684eb0

		// Named from G3D 6.09 GFont: same body shape (size*1.5, charWidth/charHeight scale, subWidth sum or 'M'*0.85)
		// and called from draw2D's XALIGN_RIGHT / XALIGN_CENTER cases exactly as GFont::draw2D calls it.
		G3D::Vector2 get2DStringBounds(const std::string& s, double size, Spacing spacing) const;   // 00684640

		// 00684730: first parameter is VisualEngine*, not TwoDManager*: the only caller (AdornRbxGfx 0066fe0c) passes
		// AdornRbxGfx::visualEngine (+0x04), and the body calls TwoDManager::addQuad on [arg + 0x14] = VisualEngine's
		// TwoDManager*. (The registry's TwoDManager* spelling came from a generated roc_* analog.)
		G3D::Vector2 draw2D(VisualEngine* visualEngine, const std::string& s, const G3D::Vector2& pos2D, double size,
		                    const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign,
		                    YAlign yalign, Spacing spacing) const;                                 // 00684730
	};
}
