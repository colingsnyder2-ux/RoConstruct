// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native XML serializer constructors (inactive).
#include "v8xml/XmlSerializer.h"

XmlParser::XmlParser(std::streambuf* buffer)
	: buffer(buffer)
{
}

XmlWriter::XmlWriter(std::ostream& stream)
	: stream(stream)
{
}

bool isCloseTag(const std::string& test)
{
	if (test.size() >= 2)
		return test.substr(0, 2) == "</";

	return false;
}

bool endsWithClose(const std::string& test)
{
	if (test.size() >= 2)
		return test.substr(test.size() - 2, 2) == "/>";

	return false;
}
