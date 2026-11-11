// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native Ogre::VRbxFont (inactive): G3D 6.09 GFont ctor/fromFile ported to Ogre textures.
// Body order follows the original 00684b10 / 00684eb0 and upstream GLG3D/GFont.cpp.
// >>> native-status (generated) -- do not edit >>>
// OgreVRbxFont | 2008-06 | 11 byte-exact, inactive (not link-selected)
// 11/11 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (+2) (chatgpt:gpt-6.1-sol)
// <<< native-status | src 3689f26a | roc native-status --write
#include "OgreRbx/VRbxFont2008.h"
#include <OgreTextureManager.h>
#include <OgreDataStream.h>
#include "G3D/BinaryInput.h"
#include "G3D/g3dmath.h"
#include "G3D/fileutils.h"

namespace Ogre
{
	// Unique texture names "ft0", "ft1", ... (original counter at 0097dbc8, format "ft%d" at 0084e808).
	// External linkage: the original stores the increment after the _snprintf argument pushes, which an
	// internal-linkage static does not reproduce. Name unknown (placeholder).
	int fontTextureCount = 0;

	VRbxFont::VRbxFont(const std::string& filename, G3D::BinaryInput& b)
	{
		int ver = b.readInt32();
		(void)ver;

		// Read the widths
		for (int c = 0; c < 128; ++c) {
			subWidth[c] = b.readUInt16();
		}

		baseline = b.readUInt16();
		int texWidth = b.readUInt16();
		charWidth  = texWidth / 16;
		charHeight = texWidth / 16;

		// The input may not be a power of 2
		int width  = G3D::ceilPow2(charWidth * 16);
		int height = G3D::ceilPow2(charHeight * 8);

		const G3D::uint8* ptr = ((G3D::uint8*)b.getCArray()) + b.getPosition();

		char name[8];
		_snprintf(name, 8, "ft%d", fontTextureCount++);
		texture = TextureManager::getSingleton().create(name, "General");
		DataStreamPtr stream(new MemoryDataStream((void*)ptr, width * height, false));
		texture->loadRawData(stream, width, height, PF_A8);
	}

	G3D::Vector2 VRbxFont::computePackedArray(
		const std::string&  s,
		double              x,
		double              y,
		double              w,
		double              h,
		Spacing             spacing,
		G3D::Vector2*       array) const {

		const double propW = w / charWidth;
		const size_t n = s.length();   // unsigned in the original (jbe/jb loop tests)

		// Shrink the vertical texture coordinates by 1 texel to avoid
		// bilinear interpolation interactions with mipmapping.
		float sy = h / charHeight;

		float x0 = 0;

		const float mwidth = subWidth[(int)'M'] * 0.85f * propW;

		int count = -1;
		for (size_t i = 0; i < n; ++i) {
			char c = s[i] & 127; // s[i] % 128; avoid using illegal chars

			if (c != ' ') {
				int row   = c >> 4; // fast version of c / 16
				int col   = c & 15; // fast version of c % 16

				// Fixed width
				float sx = (spacing == PROPORTIONAL_SPACING) ?
					(charWidth - subWidth[(int)c]) * propW * 0.5f : 0.0f;

				float xx = x - sx;
				// Tex, Vert
				++count;
				array[count].x = col * charWidth;
				array[count].y = row * charHeight + 1;

				++count;
				array[count].x = xx;
				array[count].y = y + sy;

				++count;
				array[count].x = col * charWidth;
				array[count].y = (row + 1) * charHeight - 2;

				++count;
				array[count].x = xx;
				array[count].y = y + h - sy;

				xx += w;
				++count;
				array[count].x = (col + 1) * charWidth - 1;
				array[count].y = (row + 1) * charHeight - 2;

				++count;
				array[count].x = xx;
				array[count].y = y + h - sy;

				++count;
				array[count].x = (col + 1) * charWidth - 1;
				array[count].y = row * charHeight + 1;

				++count;
				array[count].x = xx;
				array[count].y = y + sy;
			}

			x += (spacing == PROPORTIONAL_SPACING) ?
				propW * subWidth[(int)c] : mwidth;
		}

		return G3D::Vector2(x - x0, h);
	}

	G3D::Vector2 VRbxFont::get2DStringBounds(
		const std::string&  s,
		double              size,
		Spacing             spacing) const {

		int n = s.length();

		double h = size * 1.5;
		double w = h * charWidth / charHeight;
		double propW = w / charWidth;
		double x = 0;
		double y = h;

		if (spacing == PROPORTIONAL_SPACING) {
			for (int i = 0; i < n; ++i) {
				char c   = s[i] & 127;
				x += propW * subWidth[(int)c];
			}
		} else {
			x = subWidth[(int)'M'] * n * 0.85 * propW;
		}

		return G3D::Vector2(x, y);
	}

	SharedPtr<VRbxFont> VRbxFont::fromFile(const std::string& filename)
	{
		if (! G3D::fileExists(filename)) {
			return SharedPtr<VRbxFont>();
		}

		G3D::BinaryInput b(filename, G3D::G3D_LITTLE_ENDIAN, true);
		return SharedPtr<VRbxFont>(new VRbxFont(filename, b));
	}
}
