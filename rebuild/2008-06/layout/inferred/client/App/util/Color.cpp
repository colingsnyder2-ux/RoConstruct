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
