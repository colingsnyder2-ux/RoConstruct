// from server: 44% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8xml/XmlSerializer.cpp

// Candidate translation unit (score above; library headers required).
#include "v8xml/XmlSerializer.h"

#include "util/ContentProvider.h"
#include "util/Name.h"
#include "util/base64.hpp"
#include "v8xml/XmlElement.h"

#include <cstdio>
#include <cstring>
#include <istream>
#include <iterator>
#include <memory>
#include <ostream>

// GLOBAL: WEBSERVICE 0x102d21b0
// clang-format off
static bool whitespaces[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1
};
// clang-format on

// FUNCTION: WEBSERVICE 0x10084c50
void TextXmlParser::skipWhitespace()
{
	while (whitespaces[(char) buffer->sgetc()]) {
		buffer->sbumpc();
	}
}

// FUNCTION: WEBSERVICE 0x10085810
void TextXmlWriter::writeCloseTag(const XmlElement* element, int depth)
{
	for (int i = 0; i < depth; ++i) {
		stream << '\t';
	}

	stream << "</" << element->getTag().name << '>';
}

// FUNCTION: WEBSERVICE 0x10085870
void TextXmlWriter::serialize(const XmlElement* xmlNode, int depth)
{
	if (xmlNode != NULL) {
		serializeNode(xmlNode, depth);

		const XmlElement* child = xmlNode->firstChild();

		if (child != NULL) {
			while (child != NULL) {
				stream << '\n';
				serialize(child, depth + 1);
				child = child->nextSibling();
			}

			stream << '\n';

			writeCloseTag(xmlNode, depth);
		}
		else {
			writeCloseTag(xmlNode, 0);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10086220
void TextXmlWriter::encodedWrite(std::ostream& stream, const char* text)
{
	size_t num = strlen(text);

	for (size_t i = 0; i < num; ++i) {
		char c = *text++;

		if (c == '<') {
			stream << "&lt;";
		}
		else if (c == '>') {
			stream << "&gt;";
		}
		else if (c == '&') {
			stream << "&amp;";
		}
		else if (c == '"') {
			stream << "&quot;";
		}
		else if (c == '\'') {
			stream << "&apos;";
		}
		else if (c < ' ' || c > '~') {
			char buffer[8];

			sprintf(buffer, "&#%d;", (unsigned char) c);

			stream << buffer;
		}
		else {
			stream << c;
		}
	}
}

// FUNCTION: WEBSERVICE 0x10086590
void TextXmlWriter::serialize(const XmlElement* xmlNode)
{
	serialize(xmlNode, 0);
}

// FUNCTION: WEBSERVICE 0x10086af0
void TextXmlWriter::writeOpenTag(const XmlElement* element, int depth, const XmlAttribute* extraAttribute)
{
	for (int i = 0; i < depth; ++i) {
		stream << '\t';
	}

	stream << '<' << element->getTag().name;

	for (const XmlAttribute* attribute = element->getFirstAttribute(); attribute != NULL;
		 attribute = element->getNextAttribute(attribute)) {
		stream << ' ' << attribute->getTag().name << "=\"";

		encodedWrite(stream, attribute->toString(this));

		stream << '"';
	}

	if (extraAttribute != NULL) {
		stream << ' ' << extraAttribute->getTag().name << "=\"";

		encodedWrite(stream, extraAttribute->toString(this));

		stream << '"';
	}

	stream << '>';
}

// FUNCTION: WEBSERVICE 0x10086c90
XmlParser::XmlParser(std::streambuf* buffer) : buffer(buffer)
{
}

// FUNCTION: WEBSERVICE 0x10086cb0
void TextXmlWriter::serializeNode(const XmlElement* xmlNode, int depth)
{
	if (xmlNode->isValueType<RBX::ContentId>()) {
		writeOpenTag(xmlNode, depth, NULL);

		RBX::ContentId contentId;

		xmlNode->getValue(contentId);

		if (contentId.isNull()) {
			stream << "<null></null>";
		}
		else {
			stream << "<hash>";
			stream << xmlNode->toString(this);
			stream << "</hash>";
		}
	}
	else {
		writeOpenTag(xmlNode, depth, NULL);

		encodedWrite(stream, xmlNode->toString(this));
	}
}

// STUB: WEBSERVICE 0x10086e00
void TextXmlWriterWithEmbeddedContent::serializeNode(const XmlElement* xmlNode, int depth)
{
	if (xmlNode->isValueType<RBX::ContentId>()) {
		RBX::ContentId contentId;

		xmlNode->getValue(contentId);

		if (&contentId.mimeType() == &RBX::Name::getNullName()) {
			writeOpenTag(xmlNode, depth, NULL);
		}
		else {
			XmlAttribute mimeType(tag_mimeType, contentId.mimeType().name.c_str());

			writeOpenTag(xmlNode, depth, &mimeType);
		}

		if (xmlNode->findAttribute(name_xsinil) == NULL) {
			if (contentId.isNull()) {
				stream << "<null></null>";
			}
			else if (contentId.isAsset() || contentId.isHttp()) {
				stream << "<url>";
				TextXmlWriter::encodedWrite(stream, contentId.c_str());
				stream << "</url>";
			}
			else if (embeddedContent.find(contentId) == embeddedContent.end()) {
				embeddedContent.insert(contentId);

				std::auto_ptr<std::istream> contentStream;

				contentStream = RBX::ContentProvider::singleton().getContent(contentId);

				if (&contentId.mimeType() == &RBX::Name::getNullName()) {
					stream << "<binary>";
				}
				else {
					stream << "<binary xmime:contentType=\"" << contentId.mimeType().name.c_str() << "\">";
				}

				int state;
				base64<char> encoder;

				encoder.put(
					std::istreambuf_iterator<char>(contentStream->rdbuf()),
					std::istreambuf_iterator<char>(),
					std::ostreambuf_iterator<char>(stream.rdbuf()),
					state,
					base64<char>::crlf()
				);

				stream << "</binary>";
			}
			else {
				embeddedContent.insert(contentId);

				stream << "<hash>";
				stream << xmlNode->toString(this);
				stream << "</hash>";
			}
		}
	}
	else {
		TextXmlWriter::serializeNode(xmlNode, depth);
	}
}

// FUNCTION: WEBSERVICE 0x10087f40
XmlWriter::XmlWriter(std::ostream& stream) : stream(stream)
{
}
