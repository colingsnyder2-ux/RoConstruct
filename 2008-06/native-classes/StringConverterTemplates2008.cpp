// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast
// 2008-06 native StringConverter<T>::convertToValue instances (inactive). util/Utilities.h declares the member without a body.
//   int 005be5a0, float 005be790, double 005be680, BrickColor 005bf0a0, Vector2int16 005be950, Color3 005bed50
#include <limits>
#include <boost/lexical_cast.hpp>
#include "util/Utilities.h"
#include "v8datamodel/BrickColor.h"
#include "G3D/Vector2int16.h"
#include "G3D/Color3.h"
#include <stdlib.h>

namespace RBX
{
	// Numbers: empty text fails, lexical_cast failure (bad_lexical_cast) fails.
	template<>
	bool StringConverter<int>::convertToValue(const std::string& text, int& value)
	{
		unsigned length = text.size();
		if (length)
		{
			try
			{
				value = boost::lexical_cast<int>(text);
				return true;
			}
			catch (...)
			{
			}
		}
		return false;
	}

	// Floating point text also accepts the INF / -INF / NAN spellings.
	template<>
	bool StringConverter<float>::convertToValue(const std::string& text, float& value)
	{
		unsigned length = text.size();
		if (!length)
			return false;
		if (text == "INF")
		{
			value = std::numeric_limits<float>::infinity();
			return true;
		}
		if (text == "-INF")
		{
			value = -std::numeric_limits<float>::infinity();
			return true;
		}
		if (text == "NAN")
		{
			value = std::numeric_limits<float>::quiet_NaN();
			return true;
		}
		try
		{
			value = boost::lexical_cast<float>(text);
			return true;
		}
		catch (...)
		{
			return false;
		}
	}

	template<>
	bool StringConverter<double>::convertToValue(const std::string& text, double& value)
	{
		unsigned length = text.size();
		if (!length)
			return false;
		if (text == "INF")
		{
			value = std::numeric_limits<double>::infinity();
			return true;
		}
		if (text == "-INF")
		{
			value = -std::numeric_limits<double>::infinity();
			return true;
		}
		if (text == "NAN")
		{
			value = std::numeric_limits<double>::quiet_NaN();
			return true;
		}
		try
		{
			value = boost::lexical_cast<double>(text);
			return true;
		}
		catch (...)
		{
			return false;
		}
	}

	template<>
	bool StringConverter<BrickColor>::convertToValue(const std::string& text, BrickColor& value)
	{
		value = BrickColor::parse(text.c_str());
		return true;
	}

	// "x,y" or "x;y": split at the first separator (data 00838460 is ",;").
	template<>
	bool StringConverter<G3D::Vector2int16>::convertToValue(const std::string& text, G3D::Vector2int16& value)
	{
		int separator = text.find_first_of(",;", 0, 2);
		if (separator < 0)
			return false;
		value.x = atoi(text.substr(0, separator).c_str());
		int next = separator + 1;
		if ((int)text.size() < next)
			return false;
		value.y = atoi(text.substr(next, text.size() - next).c_str());
		return true;
	}

	// Color3: "#rrggbb", "0xrrggbb" (hex bytes scaled by 1/255), or "r,g,b" / "r;g;b" floats.
	template<>
	bool StringConverter<G3D::Color3>::convertToValue(const std::string& text, G3D::Color3& value)
	{
		const float scale = 1.0f / 255.0f;
		if (text.c_str()[0] == '#')
		{
			if (text.size() != 7)
				return false;
			value.r = strtol(text.substr(1, 2).c_str(), 0, 16) * scale;
			value.g = strtol(text.substr(3, 2).c_str(), 0, 16) * scale;
			value.b = strtol(text.substr(5, 2).c_str(), 0, 16) * scale;
		}
		else if (text.substr(0, 2) == "0x")
		{
			if (text.size() != 8)
				return false;
			value.r = strtol(text.substr(2, 2).c_str(), 0, 16) * scale;
			value.g = strtol(text.substr(4, 2).c_str(), 0, 16) * scale;
			value.b = strtol(text.substr(6, 2).c_str(), 0, 16) * scale;
		}
		else
		{
			int first = text.find_first_of(",;", 0, 2);
			if (first < 0)
				return false;
			value.r = (float)atof(text.substr(0, first).c_str());
			int start = first + 1;
			int second = text.find_first_of(",;", start, 2);
			if (second < start)
				return false;
			value.g = (float)atof(text.substr(start, second - start).c_str());
			int next = second + 1;
			if ((int)text.size() < next)
				return false;
			value.b = (float)atof(text.substr(next, text.size() - next).c_str());
		}
		return true;
	}
}
