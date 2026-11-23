// =============================================================================
// Color.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/Color.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include <G3D/Color3.h>

namespace RBX
{
	// INFERRED: class shape from the decorated names only (static members, no instances observed).
	class Color
	{
	public:
		static const G3D::Color3& red();
		static const G3D::Color3& blue();
		static const G3D::Color3& green();
		static const G3D::Color3& purple();
		static const G3D::Color3& orange();
		static const G3D::Color3& yellow();
		static const G3D::Color3& pink();
	};

	const G3D::Color3& Color::red()
	{
		static G3D::Color3 c(173 / 255.0f, 35 / 255.0f, 35 / 255.0f);
		return c;
	}

	const G3D::Color3& Color::blue()
	{
		static G3D::Color3 c(42 / 255.0f, 75 / 255.0f, 215 / 255.0f);
		return c;
	}

	const G3D::Color3& Color::green()
	{
		static G3D::Color3 c(29 / 255.0f, 105 / 255.0f, 20 / 255.0f);
		return c;
	}

	const G3D::Color3& Color::purple()
	{
		static G3D::Color3 c(129 / 255.0f, 38 / 255.0f, 192 / 255.0f);
		return c;
	}

	const G3D::Color3& Color::orange()
	{
		static G3D::Color3 c(255 / 255.0f, 146 / 255.0f, 51 / 255.0f);
		return c;
	}

	const G3D::Color3& Color::yellow()
	{
		static G3D::Color3 c(255 / 255.0f, 238 / 255.0f, 51 / 255.0f);
		return c;
	}

	const G3D::Color3& Color::pink()
	{
		static G3D::Color3 c(255 / 255.0f, 205 / 255.0f, 243 / 255.0f);
		return c;
	}
}
