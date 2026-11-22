// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast
// 2008-06 native StringConverter<bool / int / unsigned / double> text conversions (inactive), the head of the
// StringConverter run 005bde30..005be030 (util/Utilities.h declares the members without a body; flags follow the
// sibling native-classes/StringConverterTemplates2008.cpp). Identity: registry decorated names
// ?convertToString@?$StringConverter@_N@RBX@@ 005bde30, ?convertToValue@?$StringConverter@_N@RBX@@ 005bde60,
// ?convertToString@?$StringConverter@H@RBX@@ 005bdef0, ?convertToString@?$StringConverter@I@RBX@@ 005bdf30; 005bdf70
// (func_005bdf70) is the double convertToString: same shape as the float one 005be040 (StringConverterRecovery_005be040.cpp)
// with MSVCP90 _Inf, "%.20g" (00838438) and a 0x40 buffer. String data: "true" 0081ba94, "True" 00838430, "TRUE"
// 00838428, "false" 0081e21c, "False" 00838420, "FALSE" 00838418, "%d" 008135d0, "%u" 00826b14, "INF" 0083844c,
// "-INF" 00838444, "NAN" 00838440.
#include <limits>
#include <stdio.h>
#include <boost/lexical_cast.hpp>
#include "util/Utilities.h"

namespace RBX
{
	// 005bde30
	template<>
	std::string StringConverter<bool>::convertToString(const bool& value)
	{
		return value ? "true" : "false";
	}

	// 005bde60: std::operator==(const string&, const char*) (MSVCP90 import) against each spelling
	template<>
	bool StringConverter<bool>::convertToValue(const std::string& text, bool& value)
	{
		if (text == "true" || text == "True" || text == "TRUE")
		{
			value = true;
			return true;
		}
		if (text == "false" || text == "False" || text == "FALSE")
		{
			value = false;
			return true;
		}
		return false;
	}

	// 005bdef0
	template<>
	std::string StringConverter<int>::convertToString(const int& value)
	{
		char buffer[16];
		_snprintf(buffer, 16, "%d", value);
		return buffer;
	}

	// 005bdf30
	template<>
	std::string StringConverter<unsigned int>::convertToString(const unsigned int& value)
	{
		char buffer[16];
		_snprintf(buffer, 16, "%u", value);
		return buffer;
	}

	// 005be610 (func_005be610; XmlNameValuePair::getValue(unsigned&) 0057c5b0's callee): the int body 005be5a0 of
	// StringConverterTemplates2008.cpp over lexical_cast<unsigned int> 005be240.
	template<>
	bool StringConverter<unsigned int>::convertToValue(const std::string& text, unsigned int& value)
	{
		unsigned length = text.size();
		if (length)
		{
			try
			{
				value = boost::lexical_cast<unsigned int>(text);
				return true;
			}
			catch (...)
			{
			}
		}
		return false;
	}

	// 005bdf70 (func_005bdf70)
	template<>
	std::string StringConverter<double>::convertToString(const double& value)
	{
		char buffer[64];
		if (value == std::numeric_limits<double>::infinity()) return "INF";
		if (-std::numeric_limits<double>::infinity() == value) return "-INF";
		if (!(value < 0.0 || value >= 0.0)) return "NAN";
		_snprintf(buffer, 64, "%.20g", value);
		return buffer;
	}

	// 005be040 (func_005be040): the float convertToString, the double body above with MSVCP90 _FInf, "%.9g" (00838450)
	// and a 0x20 buffer. Callers: the Vector3 / Color3 converters (005bea10..005beb63) and the float property
	// getStringValue rows (0056e1a7, 0056f1f1, 005760b3..). Supersedes StringConverterRecovery_005be040.cpp (a near
	// miss of the same name: volatile local and swapped compare operands).
	template<>
	std::string StringConverter<float>::convertToString(const float& value)
	{
		char buffer[32];
		if (value == std::numeric_limits<float>::infinity()) return "INF";
		if (-std::numeric_limits<float>::infinity() == value) return "-INF";
		if (!(value < 0.0f || value >= 0.0f)) return "NAN";
		_snprintf(buffer, 32, "%.9g", value);
		return buffer;
	}
}
