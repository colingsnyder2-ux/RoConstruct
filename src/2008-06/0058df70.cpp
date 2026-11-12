// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/v8xml/XmlSerializer.cpp

// Candidate translation unit (score above; library headers required).
#include "v8xml/XmlSerializer.h"

#include "reflection/type.h"
#include "util/ContentProvider.h"
#include "util/Name.h"
#include "util/base64.hpp"
#include "v8xml/XmlElement.h"

#include <G3D/format.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <istream>
#include <iterator>
#include <memory>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

// GLOBAL: WEBSERVICE 0x102d21b0
// GLOBAL: ROBLOX 0x00933258
// clang-format off
static bool whitespaces[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1
};
// clang-format on

// FUNCTION: WEBSERVICE 0x10084b30
// FUNCTION: ROBLOX 0x0059d1e0
bool isCloseTag(const std::string& test)
{
	if (test.length() >= 2) {
		return test.substr(0, 2) == "</";
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x10084bc0
// FUNCTION: ROBLOX 0x0059d270
bool endsWithClose(const std::string& test)
{
	size_t length = test.length();
	if (length >= 2) {
		return test.substr(length - 2, 2) == "/>";
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x10084c50
// FUNCTION: ROBLOX 0x0059d300
void TextXmlParser::skipWhitespace()
{
	while (whitespaces[(char) buffer->sgetc()]) {
		buffer->sbumpc();
	}
}

// FUNCTION: WEBSERVICE 0x10084c90
// FUNCTION: ROBLOX 0x0059d340
std::string TextXmlParser::readFirstTag()
{
	skipWhitespace();

	int count = 0;
	char c;
	do {
		if (count++ > 4) {
			std::string message = "tag expected after Byte-Order-Mark";
			throw std::runtime_error(message);
		}

		c = buffer->sbumpc();
		if (buffer->sgetc() == EOF) {
			throw std::runtime_error("Expected '<' but got EOF in Xml stream");
		}
	} while (c != '<');

	std::string result;
	result += '<';
	do {
		c = buffer->sbumpc();
		if (buffer->sgetc() == EOF) {
			throw std::runtime_error("Expected '>' but got EOF in Xml stream");
		}
		result += c;
	} while (c != '>');
	return result;
}

// FUNCTION: WEBSERVICE 0x10084e20
// FUNCTION: ROBLOX 0x0059d4d0
std::string TextXmlParser::readTag()
{
	skipWhitespace();

	char c = buffer->sbumpc();
	if (c != '<') {
		throw std::runtime_error("tag expected");
	}

	std::string result;
	result += '<';
	do {
		c = buffer->sbumpc();
		result += c;
	} while (c != '>');
	return result;
}

// FUNCTION: WEBSERVICE 0x10084ef0
// FUNCTION: ROBLOX 0x0059d5a0
std::string decodeString(std::string source)
{
	std::string result;
	unsigned int i = 0;
	while (i < source.size()) {
		char c = source[i++];
		if (c == '&') {
			std::string entity;
			while (i < source.size()) {
				c = source[i++];
				if (c == ';') {
					break;
				}
				entity += c;
			}

			if (entity == "lt") {
				result += '<';
			}
			else if (entity == "gt") {
				result += '>';
			}
			else if (entity == "amp") {
				result += '&';
			}
			else if (entity == "quot") {
				result += '"';
			}
			else if (entity == "apos") {
				result += '\'';
			}
			else if (entity[0] == '#') {
				result += (char) atoi(entity.substr(1).c_str());
			}
		}
		else {
			result += c;
		}
	}
	return result;
}

// FUNCTION: WEBSERVICE 0x10085160
// FUNCTION: ROBLOX 0x0059d810
std::string TextXmlParser::readText(bool decode)
{
	skipWhitespace();

	std::string result;
	while ((char) buffer->sgetc() != '<') {
		result += (char) buffer->sbumpc();
	}

	if (decode) {
		result = decodeString(result);
	}

	return result;
}

// FUNCTION: WEBSERVICE 0x10085230
// FUNCTION: ROBLOX 0x0059d8e0
std::string TextXmlParser::removeTag(const std::string& contents, int& index)
{
	unsigned int start = 0;
	while (whitespaces[contents[start]] && start < contents.size()) {
		start++;
	}

	unsigned int end = start;
	while (!whitespaces[contents[end]] && end < contents.size()) {
		end++;
	}

	std::string result = contents.substr(start, end - start);
	index = end + 1;
	return result;
}

// FUNCTION: WEBSERVICE 0x100852d0
// FUNCTION: ROBLOX 0x0059d980
std::string TextXmlParser::findNextToken(const std::string& contents, int& index)
{
	unsigned int start = index;
	while (start < contents.size() && whitespaces[contents[start]]) {
		start++;
	}

	bool inQuotes = false;
	unsigned int end;
	for (end = start; end < contents.size(); end++) {
		if (contents[end] == '"') {
			inQuotes = !inQuotes;
		}
		else if (!inQuotes && whitespaces[contents[end]]) {
			break;
		}
	}

	if (end != start) {
		std::string answer = contents.substr(start, end - start);
		index = end + 1;
		return answer;
	}

	index = contents.size();
	return "";
}

// FUNCTION: WEBSERVICE 0x10085810
// FUNCTION: ROBLOX 0x0059df50
void TextXmlWriter::writeCloseTag(const XmlElement* element, int depth)
{
	for (int i = 0; i < depth; ++i) {
		stream << '\t';
	}

	stream << "</" << element->getTag().name << '>';
}

// FUNCTION: WEBSERVICE 0x10085870
// FUNCTION: ROBLOX 0x0059dfb0
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
// FUNCTION: ROBLOX 0x0059e960
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

// FUNCTION: WEBSERVICE 0x10086310
// FUNCTION: ROBLOX 0x0059ea50
XmlElement* TextXmlParser::parseAttributes(const std::string& currentTag)
{
	std::string tagGuts = currentTag.substr(1, currentTag.size() - 2);

	int index = 0;
	std::string tagName = removeTag(tagGuts, index);
	XmlElement* element = new XmlElement(RBX::Name::lookup(tagName));

	std::string attribute = findNextToken(tagGuts, index);
	while (attribute.size() > 0) {
		std::string tag = attribute.substr(0, attribute.find("="));

		size_t start = attribute.find('"');
		size_t end = attribute.rfind('"');
		std::string text = decodeString(attribute.substr(start + 1, end - start - 1));

		element->addAttribute(RBX::Name::lookup(tag), text);
		attribute = findNextToken(tagGuts, index);
	}

	return element;
}

// FUNCTION: WEBSERVICE 0x10086590
// FUNCTION: ROBLOX 0x0059ecd0
void TextXmlWriter::serialize(const XmlElement* xmlNode)
{
	serialize(xmlNode, 0);
}

// FUNCTION: WEBSERVICE 0x10086af0
// FUNCTION: ROBLOX 0x0059f230
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
// FUNCTION: ROBLOX 0x0059f3d0
XmlParser::XmlParser(std::streambuf* buffer) : buffer(buffer)
{
}

// FUNCTION: WEBSERVICE 0x10086cb0
// FUNCTION: ROBLOX 0x0059f3f0
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
// STUB: ROBLOX 0x0059f540
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

				try {
					contentStream = RBX::ContentProvider::singleton().getContent(contentId);
				}
				catch (std::exception&) {
					goto hash;
				}

				if (&contentId.mimeType() == &RBX::Name::getNullName()) {
					stream << "<binary>";
				}
				else {
					stream << "<binary xmime:contentType=\"" << contentId.mimeType().name.c_str() << "\">";
				}

				std::istreambuf_iterator<char> _From(contentStream->rdbuf());
				std::ostreambuf_iterator<char> _Out(stream.rdbuf());
				std::istreambuf_iterator<char> _To;
				int _State;
				base64<char> encoder;
				encoder.put(_From, _To, _Out, _State, base64<char>::crlf());

				stream << "</binary>";
			}
			else {
			hash:
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

// FUNCTION: WEBSERVICE 0x10087650
// FUNCTION: ROBLOX 0x0059fbb0
std::auto_ptr<XmlElement> TextXmlParser::parse()
{
	if (buffer->sgetc() == EOF) {
		throw std::runtime_error("TextXmlParser::parse empty file");
	}

	bool firstTimeThrough = true;
	while (true) {
		std::string currentTag;

		if (firstTimeThrough) {
			firstTimeThrough = false;
			currentTag = readFirstTag();
			if (currentTag.substr(0, 2) == "<?") {
				continue;
			}
		}
		else {
			currentTag = readTag();
		}

		XmlElement* currentElement = elements.empty() ? NULL : elements.top();

		if (isCloseTag(currentTag)) {
			if (currentElement == NULL) {
				throw std::runtime_error(
					G3D::format("TextXmlParser::parse - Got close tag %s without open tag.", currentTag.c_str())
				);
			}

			elements.pop();

			if (elements.empty()) {
				return std::auto_ptr<XmlElement>(currentElement);
			}
		}
		else {
			XmlElement* newElement = parseAttributes(currentTag);
			elements.push(newElement);

			if (newElement->getTag() == RBX::Reflection::Type::singleton<RBX::ContentId>().tag) {
				bool nil;
				XmlAttribute* xsinil = newElement->findAttribute(name_xsinil);
				if (xsinil != NULL && xsinil->getValue(nil) && nil) {
				}
				else if (readText(false) != "") {
				}
				else {
					const RBX::Name* mimeType;
					XmlAttribute* mimeTypeAttribute = newElement->findAttribute(tag_mimeType);
					if (mimeTypeAttribute != NULL) {
						mimeTypeAttribute->getValue(mimeType);
					}
					else {
						mimeType = &RBX::Name::getNullName();
					}

					std::string contentChild = readTag();
					std::string tagName = contentChild.substr(1, contentChild.size() - 2);

					if (tagName.substr(0, 6) == "binary") {
						std::stringbuf encoded(readText(false), std::ios_base::in);
						std::istreambuf_iterator<char> _From(&encoded);
						std::istreambuf_iterator<char> _To;
						std::stringstream decoded;
						std::ostreambuf_iterator<char> _Out(decoded.rdbuf());
						base64<char> encoder;
						int _State = 0;
						encoder.get(_From, _To, _Out, _State);

						decoded.flush();
						RBX::ContentId contentId =
							RBX::ContentProvider::singleton().registerContent(decoded, *mimeType);

						std::string hash = RBX::MD5Hasher::convertToLegacyHash(contentId.toString());
						legacyHashes[hash] = contentId.toString();

						newElement->setValue(contentId);
					}
					else if (tag_hash == tagName) {
						std::string hash = readText(false);
						if (legacyHashes.find(hash) != legacyHashes.end()) {
							hash = legacyHashes[hash];
						}
						newElement->setValue(RBX::ContentId(hash.c_str(), *mimeType));
					}
					else if (tagName.substr(0, 3) == "url") {
						newElement->setValue(RBX::ContentId(readText(true).c_str(), *mimeType));
					}
					else if (tag_null == tagName) {
						newElement->setValue(RBX::ContentId());
					}
					else {
						throw std::runtime_error(
							G3D::format("TextXmlParser::parse - Unknown tag '%s'.", tagName.substr(0, 32).c_str())
						);
					}

					std::string closingTag = readTag();
					if (!isCloseTag(closingTag)) {
						throw std::runtime_error(
							G3D::format(
								"TextXmlParser::parse - '%s' should be a closing tag", closingTag.substr(0, 32).c_str()
							)
						);
					}
				}
			}
			else {
				newElement->setValue(readText(true));
			}

			if (currentElement != NULL) {
				currentElement->addChild(newElement);
			}

			if (endsWithClose(currentTag)) {
				elements.pop();
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x10087f40
// FUNCTION: ROBLOX 0x005a04a0
XmlWriter::XmlWriter(std::ostream& stream) : stream(stream)
{
}
