#include <G3D/Color3.h>

namespace RBX
{
	class Color
	{
	private:
		G3D::Color3 rgb;

	private:
		Color(float r, float g, float b)
			: rgb(r/255.0f, g/255.0f, b/255.0f)
		{
		}

		const G3D::Color3& color3()
		{
			return rgb;
		}

	public:
		static const G3D::Color3& black();
		static const G3D::Color3& darkGray();
		static const G3D::Color3& red()
		{
			static Color c(173.0f, 35.0f, 35.0f);
			return c.color3();
		}
		static const G3D::Color3& blue()
		{
			static Color c(42.0f, 75.0f, 215.0f);
			return c.color3();
		}
		static const G3D::Color3& green()
		{
			static Color c(29.0f, 105.0f, 20.0f);
			return c.color3();
		}
		static const G3D::Color3& brown();
		static const G3D::Color3& purple()
		{
			static Color c(129.0f, 38.0f, 192.0f);
			return c.color3();
		}
		static const G3D::Color3& lightGray();
		static const G3D::Color3& lightGreen()
		{
			static Color c(129.0f, 197.0f, 22.0f);
			return c.color3();
		}
		static const G3D::Color3& lightBlue();
		static const G3D::Color3& cyan();
		static const G3D::Color3& orange()
		{
			static Color c(255.0f, 146.0f, 51.0f);
			return c.color3();
		}
		static const G3D::Color3& yellow()
		{
			static Color c(255.0f, 238.0f, 51.0f);
			return c.color3();
		}
		static const G3D::Color3& tan()
		{
			static Color c(233.0f, 222.0f, 187.0f);
			return c.color3();
		}
		static const G3D::Color3& pink()
		{
			static Color c(255.0f, 205.0f, 243.0f);
			return c.color3();
		}
		static const G3D::Color3& white();

		static const G3D::Color3& colorFromIndex8(int index)
		{
			switch (index)
			{
			case 0:
				return red();
			case 1:
				return blue();
			case 2:
				return green();
			case 3:
				return purple();
			case 4:
				return orange();
			case 5:
				return yellow();
			case 6:
				return pink();
			default:
				return tan();
			}
		}
	};
}
