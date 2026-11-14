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
