// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8xml/XmlSerializer.h"
#include <cstdio>
#include <cstring>
void TextXmlWriter::writeOpenTag(const XmlElement* element, int depth, const XmlAttribute* extraAttribute)
{
	for (int i = 0; i < depth; i++)
		stream << '\t';

	stream << '<' << element->getTag().name;

	for (const XmlAttribute* attribute = element->getFirstAttribute(); attribute != NULL; attribute = attribute->nextSibling())
	{
		stream << ' ' << attribute->getTag().name << "=\"";
		encodedWrite(stream, attribute->toString(this));
		stream << '\"';
	}

	if (extraAttribute)
	{
		stream << ' ' << extraAttribute->getTag().name << "=\"";
		encodedWrite(stream, extraAttribute->toString(this));
		stream << '\"';
	}

	stream << '>';
}

void TextXmlWriter::writeCloseTag(const XmlElement* element, int depth)
{
	for (int i = 0; i < depth; i++)
		stream << '\t';

	stream << "</" << element->getTag().name << '>';
}

void TextXmlWriter::serializeNode(const XmlElement* xmlNode, int depth)
{
	if (xmlNode->isValueType<RBX::ContentId>())
	{
		writeOpenTag(xmlNode, depth, NULL);

		RBX::ContentId contentId;
		xmlNode->getValue(contentId);
		if (contentId.isNull())
		{
			stream << "<null></null>";
		}
		else
		{
			stream << "<hash>";
			stream << xmlNode->toString(this);
			stream << "</hash>";
		}
	}
	else
	{
		writeOpenTag(xmlNode, depth, NULL);
		encodedWrite(stream, xmlNode->toString(this));
	}
}

void TextXmlWriter::serialize(const XmlElement* xmlNode)
{
	serialize(xmlNode, 0);
}

void TextXmlWriter::serialize(const XmlElement* xmlNode, int depth)
{
	if (xmlNode)
	{
		serializeNode(xmlNode, depth);
		if (xmlNode->firstChild())
		{
			for (const XmlElement* child = xmlNode->firstChild(); child != NULL; child = child->nextSibling())
			{
				stream << '\n';
				serialize(child, depth + 1);
			}
			stream << '\n';
			writeCloseTag(xmlNode, depth);
		}
		else
		{
			writeCloseTag(xmlNode, 0);
		}
	}
}

void TextXmlWriter::encodedWrite(std::ostream& stream, const std::string& text)
{
	encodedWrite(stream, text.c_str());
}

void TextXmlWriter::encodedWrite(std::ostream& stream, const char* text)
{
	size_t len = strlen(text);
	for (size_t i = 0; i != len; ++i)
	{
		unsigned char c = *text++;
		if (c == '<')
		{
			stream << "&lt;";
		}
		else if (c == '>')
		{
			stream << "&gt;";
		}
		else if (c == '&')
		{
			stream << "&amp;";
		}
		else if (c == '"')
		{
			stream << "&quot;";
		}
		else if (c == '\'')
		{
			stream << "&apos";
		}
		else if ((c < ' ' && c != '\t' && c != '\n' && c != '\r') || c > '~')
		{
			char buffer[8];
			sprintf(buffer, "&#%d;", c);
			stream << buffer;
		}
		else
		{
			stream << c;
		}
	}
}

