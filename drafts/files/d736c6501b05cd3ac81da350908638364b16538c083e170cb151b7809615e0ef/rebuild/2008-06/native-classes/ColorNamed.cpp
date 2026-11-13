// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Color (inactive): the named Roblox palette colors. Decorated names from the identity registry
// (?red@Color@RBX@@SAABVColor3@G3D@@XZ etc.): public static `const G3D::Color3& ()` members of class RBX::Color.
// Each body is a function-local static guarded by its own init bit, initialized from folded float constants; the
// values are byte colors /255 (red 173,35,35; blue 42,75,215; green 29,105,20; purple 129,38,192; orange 255,146,51;
// yellow 255,238,51; pink 255,205,243). red 00600500 sits in the Tool range, the others 0064f6b0..0064f7f0 precede
// a 7-way dispatcher 0064f830 (not built here). No header declares RBX::Color yet; it is declared in this unit.
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

	// 00600500
	const G3D::Color3& Color::red()
	{
		static G3D::Color3 c(173 / 255.0f, 35 / 255.0f, 35 / 255.0f);
		return c;
	}

	// 0064f6b0
	const G3D::Color3& Color::blue()
	{
		static G3D::Color3 c(42 / 255.0f, 75 / 255.0f, 215 / 255.0f);
		return c;
	}

	// 0064f6f0
	const G3D::Color3& Color::green()
	{
		static G3D::Color3 c(29 / 255.0f, 105 / 255.0f, 20 / 255.0f);
		return c;
	}

	// 0064f730
	const G3D::Color3& Color::purple()
	{
		static G3D::Color3 c(129 / 255.0f, 38 / 255.0f, 192 / 255.0f);
		return c;
	}

	// 0064f770
	const G3D::Color3& Color::orange()
	{
		static G3D::Color3 c(255 / 255.0f, 146 / 255.0f, 51 / 255.0f);
		return c;
	}

	// 0064f7b0
	const G3D::Color3& Color::yellow()
	{
		static G3D::Color3 c(255 / 255.0f, 238 / 255.0f, 51 / 255.0f);
		return c;
	}

	// 0064f7f0
	const G3D::Color3& Color::pink()
	{
		static G3D::Color3 c(255 / 255.0f, 205 / 255.0f, 243 / 255.0f);
		return c;
	}
}
