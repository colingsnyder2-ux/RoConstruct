// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll App/util/Utilities.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Utilities.h"

#include "decomp.h"

#include <G3D/Vector3.h>
#include <cstdio>
#include <limits>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10090030
template <>
std::string StringConverter<bool>::convertToString(const bool& value)
{
	return value ? "true" : "false";
}

// STUB: WEBSERVICE 0x10090060
template <>
bool StringConverter<bool>::convertToValue(const std::string& text, bool& value)
{
	STUB(0x10090060);
	return false;
}

// FUNCTION: WEBSERVICE 0x100900f0
template <>
std::string StringConverter<int>::convertToString(const int& value)
{
	char szText[16];

	_snprintf(szText, sizeof(szText), "%d", value);

	return szText;
}

// FUNCTION: WEBSERVICE 0x10090130
template <>
std::string StringConverter<unsigned int>::convertToString(const unsigned int& value)
{
	char szText[16];

	_snprintf(szText, sizeof(szText), "%u", value);

	return szText;
}

// FUNCTION: WEBSERVICE 0x10090170
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

// STUB: WEBSERVICE 0x10090670
template <>
bool StringConverter<int>::convertToValue(const std::string& text, int& value)
{
	STUB(0x10090670);
	return false;
}

// STUB: WEBSERVICE 0x100906e0
template <>
bool StringConverter<unsigned int>::convertToValue(const std::string& text, unsigned int& value)
{
	STUB(0x100906e0);
	return false;
}

// STUB: WEBSERVICE 0x10090750
template <>
bool StringConverter<double>::convertToValue(const std::string& text, double& value)
{
	STUB(0x10090750);
	return false;
}

// STUB: WEBSERVICE 0x10090860
template <>
bool StringConverter<float>::convertToValue(const std::string& text, float& value)
{
	STUB(0x10090860);
	return false;
}

// FUNCTION: WEBSERVICE 0x10090970
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

} // namespace RBX
