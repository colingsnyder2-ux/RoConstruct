// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreVRbxFont | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 30a4f97a | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
// 2008-06 native Ogre::RbxFont (inactive): G3D 6.09 GFont ctor/fromFile ported to Ogre textures.
// Body order follows the original 00684b10 / 00684eb0 and upstream GLG3D/GFont.cpp.
#include "OgreRbx/VRbxFont2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbxNode/TwoDManager2008.h"
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
	// INFERRED: counter spelling; original read/write address0097dbc8.
	int fontTextureCount = 0;

	RbxFont::RbxFont(const std::string& filename, G3D::BinaryInput& b)
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

	G3D::Vector2 RbxFont::computePackedArray(
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

	// INFERRED: method spelling from GFont port; unique target00684640.
	G3D::Vector2 RbxFont::get2DStringBounds(
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

	// G3D GFont::draw2D with the OpenGL vertex arrays replaced by one TwoDManager::addQuad per character
	// (outline passes at dx,dy = +-1 when outline.a > 0.05, then the color pass).
	G3D::Vector2 RbxFont::draw2D(
		VisualEngine*               visualEngine,
		const std::string&          s,
		const G3D::Vector2&         pos2D,
		double                      size,
		const G3D::Color4&          color,
		const G3D::Color4&          border,
		XAlign                      xalign,
		YAlign                      yalign,
		Spacing                     spacing) const {

		float x = pos2D.x;
		float y = pos2D.y;

		float h = size * 1.5f;
		float w = h * charWidth / charHeight;

		switch (xalign) {
		case XALIGN_RIGHT:
			x -= get2DStringBounds(s, size, spacing).x;
			break;

		case XALIGN_CENTER:
			x -= get2DStringBounds(s, size, spacing).x / 2;
			break;

		default:
			break;
		}

		// Ogre's 2D space is y-up: Roblox's port shifts by h for YALIGN_TOP and leaves YALIGN_BOTTOM alone.
		switch (yalign) {
		case YALIGN_TOP:
			y -= h;
			break;

		case YALIGN_BASELINE:
			y -= baseline * h / (double)charHeight;
			break;

		case YALIGN_CENTER:
			y -= h / 2.0;
			break;

		default:
			break;
		}

		int numChars = 0;
		for (unsigned int i = 0; i < s.length(); ++i) {
			numChars += ((s[i] % 128) != ' ') ? 1 : 0;
		}
		if (numChars == 0) {
			return G3D::Vector2(0, h);
		}

		// Packed vertex array; tex coord and vertex are interlaced, 4 vertices per character.
		G3D::Vector2* array = (G3D::Vector2*)malloc(numChars * 4 * 2 * sizeof(G3D::Vector2));

		G3D::Vector2 bounds;
		bounds = computePackedArray(s, x, y, w, h, spacing, array);

		TwoDManager* twoD = visualEngine->twoD;
		int texWidth  = texture->getWidth();
		int texHeight = texture->getHeight();

		if (border.a > 0.05f) {
			for (int dy = -1; dy <= 1; dy += 2) {
				for (int dx = -1; dx <= 1; dx += 2) {
					if ((dx != 0) || (dy != 0)) {
						const G3D::Vector2* q = array;
						for (int i = 0; i < numChars; ++i, q += 8) {
							twoD->addQuad(texture->getName(), border,
							              q[1].x + dx, q[1].y + dy, q[5].x + dx, q[5].y + dy,
							              q[0].x / texWidth, q[4].y / texHeight, q[4].x / texWidth, q[0].y / texHeight);
						}
					}
				}
			}
		}

		// Draw foreground
		const G3D::Vector2* q = array;
		for (int i = 0; i < numChars; ++i, q += 8) {
			twoD->addQuad(texture->getName(), color,
			              q[1].x, q[1].y, q[5].x, q[5].y,
			              q[0].x / texWidth, q[4].y / texHeight, q[4].x / texWidth, q[0].y / texHeight);
		}

		free(array);

		return bounds;
	}


	SharedPtr<RbxFont> RbxFont::fromFile(const std::string& filename)
	{
		if (! G3D::fileExists(filename)) {
			return SharedPtr<RbxFont>();
		}

		G3D::BinaryInput b(filename, G3D::G3D_LITTLE_ENDIAN, true);
		return SharedPtr<RbxFont>(new RbxFont(filename, b));
	}
}
