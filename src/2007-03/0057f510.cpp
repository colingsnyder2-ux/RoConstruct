// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/Utilities.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Utilities.h"

#include "decomp.h"
#include "util/ContentProvider.h"
#include "v8datamodel/BrickColor.h"

#include <G3D/Color3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector2int16.h>
#include <G3D/Vector3.h>
#include <boost/lexical_cast.hpp>
#include <cstdio>
#include <limits>
#include <stdlib.h>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10090030
// FUNCTION: ROBLOX 0x005c8080
template <>
std::string StringConverter<bool>::convertToString(const bool& value)
{
	return value ? "true" : "false";
}

// FUNCTION: WEBSERVICE 0x10090060
// FUNCTION: ROBLOX 0x005c80b0
template <>
bool StringConverter<bool>::convertToValue(const std::string& text, bool& value)
{
	if (text == "true" || text == "True" || text == "TRUE") {
		value = true;
	}
	else if (text == "false" || text == "False" || text == "FALSE") {
		value = false;
	}
	else {
		return false;
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100900f0
// FUNCTION: ROBLOX 0x005c8140
template <>
std::string StringConverter<int>::convertToString(const int& value)
{
	char szText[16];

	_snprintf(szText, sizeof(szText), "%d", value);

	return szText;
}

// FUNCTION: WEBSERVICE 0x10090130
// FUNCTION: ROBLOX 0x005c8180
template <>
std::string StringConverter<unsigned int>::convertToString(const unsigned int& value)
{
	char szText[16];

	_snprintf(szText, sizeof(szText), "%u", value);

	return szText;
}

// FUNCTION: WEBSERVICE 0x10090170
// FUNCTION: ROBLOX 0x005c81c0
template <>
std::string StringConverter<double>::convertToString(const double& value)
{
	char szText[32];

	if (value == std::numeric_limits<double>::infinity()) {
		return "INF";
	}
	else if (value == -std::numeric_limits<double>::infinity()) {
		return "-INF";
	}
	else if (!(value < 0.0 || value >= 0.0)) {
		return "NAN";
	}

	_snprintf(szText, sizeof(szText), "%.9g", value);

	return szText;
}

// FUNCTION: WEBSERVICE 0x10090240
// FUNCTION: ROBLOX 0x005c8290
template <>
std::string StringConverter<float>::convertToString(const float& value)
{
	char szText[32];

	if (value == std::numeric_limits<float>::infinity()) {
		return "INF";
	}
	else if (value == -std::numeric_limits<float>::infinity()) {
		return "-INF";
	}
	else if (!(value < 0.0 || value >= 0.0)) {
		return "NAN";
	}

	_snprintf(szText, sizeof(szText), "%.9g", value);

	return szText;
}

// FUNCTION: WEBSERVICE 0x10090670
// FUNCTION: ROBLOX 0x005c87f0
template <>
bool StringConverter<int>::convertToValue(const std::string& text, int& value)
{
	if (text.size() == 0) {
		return false;
	}

	try {
		value = boost::lexical_cast<int>(text);
	}
	catch (boost::bad_lexical_cast&) {
		return false;
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100906e0
// FUNCTION: ROBLOX 0x005c8860
template <>
bool StringConverter<unsigned int>::convertToValue(const std::string& text, unsigned int& value)
{
	if (text.size() == 0) {
		return false;
	}

	try {
		value = boost::lexical_cast<unsigned int>(text);
	}
	catch (boost::bad_lexical_cast&) {
		return false;
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x10090750
// FUNCTION: ROBLOX 0x005c88d0
template <>
bool StringConverter<double>::convertToValue(const std::string& text, double& value)
{
	if (text.size() == 0) {
		return false;
	}

	if (text == "INF") {
		value = std::numeric_limits<double>::infinity();
	}
	else if (text == "-INF") {
		value = -std::numeric_limits<double>::infinity();
	}
	else if (text == "NAN") {
		value = std::numeric_limits<double>::quiet_NaN();
	}
	else {
		try {
			value = boost::lexical_cast<double>(text);
		}
		catch (boost::bad_lexical_cast&) {
			return false;
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x10090860
// FUNCTION: ROBLOX 0x005c89e0
template <>
bool StringConverter<float>::convertToValue(const std::string& text, float& value)
{
	if (text.size() == 0) {
		return false;
	}

	if (text == "INF") {
		value = std::numeric_limits<float>::infinity();
	}
	else if (text == "-INF") {
		value = -std::numeric_limits<float>::infinity();
	}
	else if (text == "NAN") {
		value = std::numeric_limits<float>::quiet_NaN();
	}
	else {
		try {
			value = boost::lexical_cast<float>(text);
		}
		catch (boost::bad_lexical_cast&) {
			return false;
		}
	}

	return true;
}

// STUB: ROBLOX 0x005c8af0
template <>
std::string StringConverter<G3D::Vector2int16>::convertToString(const G3D::Vector2int16& value)
{
	std::string result = StringConverter<int>::convertToString(value.x);

	result += ", ";
	result += StringConverter<int>::convertToString(value.y);

	return result;
}

// FUNCTION: ROBLOX 0x005c8ba0
template <>
bool StringConverter<G3D::Vector2int16>::convertToValue(const std::string& text, G3D::Vector2int16& value)
{
	int x = text.find_first_of(",;");
	if (x < 0) {
		return false;
	}

	value.x = atoi(text.substr(0, x).c_str());

	int start = x + 1;
	if ((int) text.size() < start) {
		return false;
	}

	value.y = atoi(text.substr(start, text.size() - start).c_str());

	return true;
}

// FUNCTION: WEBSERVICE 0x10090970
// FUNCTION: ROBLOX 0x005c8c60
template <>
std::string StringConverter<G3D::Vector3>::convertToString(const G3D::Vector3& value)
{
	std::string result = StringConverter<float>::convertToString(value.x);

	result += ", ";
	result += StringConverter<float>::convertToString(value.y);
	result += ", ";
	result += StringConverter<float>::convertToString(value.z);

	return result;
}

// FUNCTION: WEBSERVICE 0x10090a50
// FUNCTION: ROBLOX 0x005c8d40
template <>
std::string StringConverter<G3D::CoordinateFrame>::convertToString(const G3D::CoordinateFrame& value)
{
	std::string result = StringConverter<G3D::Vector3>::convertToString(value.translation);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result += ", ";
			result += StringConverter<float>::convertToString(value.rotation[i][j]);
		}
	}

	return result;
}

// FUNCTION: WEBSERVICE 0x10090b10
// FUNCTION: ROBLOX 0x005c8e00
template <>
bool StringConverter<G3D::Vector3>::convertToValue(const std::string& text, G3D::Vector3& value)
{
	int x = text.find_first_of(",;");
	if (x < 0) {
		return false;
	}

	value.x = (float) atof(text.substr(0, x).c_str());

	int start = x + 1;
	int y = text.find_first_of(",;", start);
	if (y < start) {
		return false;
	}

	value.y = (float) atof(text.substr(start, y - start).c_str());

	start = y + 1;
	if ((int) text.size() < start) {
		return false;
	}

	value.z = (float) atof(text.substr(start, text.size() - start).c_str());

	return true;
}

// FUNCTION: WEBSERVICE 0x10090c20
// FUNCTION: ROBLOX 0x005c8f10
template <>
std::string StringConverter<BrickColor>::convertToString(const BrickColor& value)
{
	return value.name();
}

// FUNCTION: WEBSERVICE 0x10090c50
// FUNCTION: ROBLOX 0x005c8f40
template <>
std::string StringConverter<G3D::Color3>::convertToString(const G3D::Color3& value)
{
	char szText[64];
	_snprintf(szText, 64, "%g, %g, %g", value.r, value.g, value.b);
	return szText;
}

// FUNCTION: WEBSERVICE 0x10090cb0
// FUNCTION: ROBLOX 0x005c8fa0
template <>
bool StringConverter<G3D::Color3>::convertToValue(const std::string& text, G3D::Color3& value)
{
	if (text.c_str()[0] == '#') {
		if (text.size() != 7) {
			return false;
		}

		value.r = strtol(text.substr(1, 2).c_str(), NULL, 16) / 255.0f;
		value.g = strtol(text.substr(3, 2).c_str(), NULL, 16) / 255.0f;
		value.b = strtol(text.substr(5, 2).c_str(), NULL, 16) / 255.0f;
	}
	else if (text.substr(0, 2) == "0x") {
		if (text.size() != 8) {
			return false;
		}

		value.r = strtol(text.substr(2, 2).c_str(), NULL, 16) / 255.0f;
		value.g = strtol(text.substr(4, 2).c_str(), NULL, 16) / 255.0f;
		value.b = strtol(text.substr(6, 2).c_str(), NULL, 16) / 255.0f;
	}
	else {
		int r = text.find_first_of(",;");
		if (r < 0) {
			return false;
		}

		value.r = (float) atof(text.substr(0, r).c_str());

		int start = r + 1;
		int g = text.find_first_of(",;", start);
		if (g < start) {
			return false;
		}

		value.g = (float) atof(text.substr(start, g - start).c_str());

		start = g + 1;
		if ((int) text.size() < start) {
			return false;
		}

		value.b = (float) atof(text.substr(start, text.size() - start).c_str());
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100ff530 FOLDED
// FUNCTION: ROBLOX 0x005ac0a0 FOLDED
template <>
std::string StringConverter<ContentId>::convertToString(const ContentId& value)
{
	return value.toString();
}

// FUNCTION: WEBSERVICE 0x100ff580 FOLDED
// FUNCTION: ROBLOX 0x005ac0c0 FOLDED
template <>
bool StringConverter<ContentId>::convertToValue(const std::string& text, ContentId& value)
{
	value = ContentId(text);
	return true;
}

} // namespace RBX
