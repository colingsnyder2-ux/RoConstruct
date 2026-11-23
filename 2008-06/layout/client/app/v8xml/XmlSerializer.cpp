// =============================================================================
// XmlSerializer.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8xml/XmlSerializer.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8xml/XmlSerializer.h"
#include "AppUnit58C/base64.hpp"
#include "reflection/type.h"
#include <G3D/format.h>
#include <sstream>
#include <stdexcept>

static bool whitespaces[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1
};

XmlParser::XmlParser(std::streambuf* buffer)
	: buffer(buffer)
{
}

void TextXmlParser::skipWhitespace()
{
	while (whitespaces[(char)buffer->sgetc()])
		buffer->sbumpc();
}

std::string TextXmlParser::readTag()
{
	skipWhitespace();

	if ((char)buffer->sbumpc() != '<')
		throw std::runtime_error("tag expected");

	std::string tag;
	tag += '<';

	char lastChar;
	do
	{
		lastChar = buffer->sbumpc();
		tag += lastChar;
	}
	while (lastChar != '>');

	return tag;
}

std::string TextXmlParser::readFirstTag()
{
	skipWhitespace();

	int count = 0;
	char c;
	do
	{
		if (count++ > 4)
		{
			std::string message = "tag expected after Byte-Order-Mark";
			throw std::runtime_error(message);
		}
		c = buffer->sbumpc();
		if (buffer->sgetc() == -1)
			throw std::runtime_error("Expected '<' but got EOF in Xml stream");
	}
	while (c != '<');

	std::string tag;
	tag += '<';

	do
	{
		c = buffer->sbumpc();
		if (buffer->sgetc() == -1)
			throw std::runtime_error("Expected '>' but got EOF in Xml stream");
		tag += c;
	}
	while (c != '>');

	return tag;
}

std::string decodeString(std::string source)
{
	std::string result;

	size_t i = 0;
	while (i < source.size())
	{
		char c = source[i++];
		if (c == '&')
		{
			std::string entity;
			while (i < source.size())
			{
				c = source[i++];
				if (c == ';')
					break;
				entity += c;
			}

			if (entity == "lt")
				result += '<';
			else if (entity == "gt")
				result += '>';
			else if (entity == "amp")
				result += '&';
			else if (entity == "quot")
				result += '"';
			else if (entity == "apos")
				result += '\'';
			else if (entity == "nbsp")
				result += ' ';
			else if (entity.c_str()[0] == '#')
			{
				if (entity.size() < 2)
					throw std::runtime_error("bad XML. No character code following #");
				if (entity[1] == 'x')
					throw std::runtime_error("Unable to parse hexidecimal character code");
				result += (char)atoi(entity.substr(1).c_str());
			}
			else
			{
				result += "&" + entity + ";";
			}
		}
		else
		{
			result += c;
		}
	}

	return result;
}

std::string TextXmlParser::readText(bool decode)
{
	skipWhitespace();

	std::string text;
	while ((char)buffer->sgetc() != '<')
		text += buffer->sbumpc();

	if (decode)
		return decodeString(text);

	return text;
}

std::string TextXmlParser::removeTag(const std::string& contents, int& index)
{
	size_t i = 0;
	while (whitespaces[contents[i]] && i < contents.size())
		i++;

	size_t j = i;
	while (!whitespaces[contents[j]] && j < contents.size())
		j++;

	std::string contentsNoTag = contents.substr(i, j - i);
	index = (int)j + 1;

	return contentsNoTag;
}

std::string TextXmlParser::findNextToken(const std::string& contents, int& index)
{
	size_t i;
	for (i = index; i < contents.size(); i++)
	{
		if (!whitespaces[contents[i]])
			break;
	}

	bool inQuotes = false;
	size_t j = i;

	for (; j < contents.size(); j++)
	{
		if (contents[j] == '"')
		{
			inQuotes = !inQuotes;
		}
		else if (!inQuotes && whitespaces[contents[j]])
		{
			break;
		}
	}

	if (j != i)
	{
		std::string answer = contents.substr(i, j - i);
		index = (int)j + 1;
		return answer;
	}

	index = (int)contents.size();
	return "";
}

XmlElement* TextXmlParser::parseAttributes(const std::string& currentTag)
{
	std::string tagGuts = currentTag.substr(1, currentTag.size() - 2);

	int index = 0;
	std::string tagName = removeTag(tagGuts, index);

	XmlElement* element = new XmlElement(RBX::Name::lookup(tagName));

	std::string attribute = findNextToken(tagGuts, index);
	while (attribute.size() > 0)
	{
		size_t equalsSignIndex = attribute.find("=", 0, 1);
		std::string attributeName = attribute.substr(0, equalsSignIndex);

		size_t startQuoteMarkIndex = attribute.find('\"');
		size_t endQuoteMarkIndex = attribute.rfind('\"');
		std::string text = decodeString(attribute.substr(startQuoteMarkIndex + 1, endQuoteMarkIndex - startQuoteMarkIndex - 1));

		element->addAttribute(RBX::Name::lookup(attributeName), text);

		attribute = findNextToken(tagGuts, index);
	}

	return element;
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

#ifndef NATIVE_APPUNIT58C_PENDING
template class std::_Tree<std::_Tmap_traits<std::string, std::string, std::less<std::string>,
	std::allocator<std::pair<const std::string, std::string> >, false> >;
template class std::map<std::string, std::string>;
template std::istreambuf_iterator<char> base64<char>::get(std::istreambuf_iterator<char>, std::istreambuf_iterator<char>,
	std::ostreambuf_iterator<char>, int&) const;
#else
extern std::string legacyHash(std::string);

std::auto_ptr<XmlElement> TextXmlParser::parse()
{
	if (buffer->sgetc() == -1)
		throw std::runtime_error("TextXmlParser::parse empty file");

	bool firstTag = true;
	while (true)
	{
		std::string currentTag;
		if (firstTag)
		{
			firstTag = false;
			currentTag = readFirstTag();
			if (currentTag.substr(0, 2) == "<?")
				continue;
		}
		else
		{
			currentTag = readTag();
		}

		XmlElement* currentElement = elements.empty() ? NULL : elements.top();
		if (isCloseTag(currentTag))
		{
			if (!currentElement)
				throw std::runtime_error(G3D::format("TextXmlParser::parse - Got close tag %s without open tag.", currentTag.c_str()));

			elements.pop();
			if (elements.empty())
				return std::auto_ptr<XmlElement>(currentElement);
		}
		else
		{
			XmlElement* newElement = parseAttributes(currentTag);
			elements.push(newElement);

			if (newElement->getTag() == RBX::Reflection::Type::singleton<RBX::ContentId>().tag)
			{
				bool isXsiNil;
				const XmlAttribute* xsiNilAttribute = newElement->findAttribute(name_xsinil);
				if (!xsiNilAttribute || !xsiNilAttribute->getValue(isXsiNil) || !isXsiNil)
				{
					if (readText(false) != "")
					{
					}
					else
					{
						const RBX::Name* mimeType;
						const XmlAttribute* mimeTypeAttribute = newElement->findAttribute(tag_mimeType);
						if (mimeTypeAttribute)
							mimeTypeAttribute->getValue(mimeType);
						else
							mimeType = &RBX::Name::getNullName();

						std::string contentChild = readTag();
						std::string tagName = contentChild.substr(1, contentChild.size() - 2);

						if (tagName.substr(0, 6) == "binary")
						{
							std::stringbuf encoded(readText(false), std::ios_base::in);
							std::istreambuf_iterator<char> from(&encoded);
							std::istreambuf_iterator<char> to;
							std::stringstream decoded;
							std::ostreambuf_iterator<char> out(decoded.rdbuf());
							int ioStatus = 0;
							base64<char> decoder;
							decoder.get(from, to, out, ioStatus);

							decoded.flush();

							RBX::ContentId contentId = RBX::ContentProvider::registerContent(decoded, *mimeType);
							std::string oldHash = legacyHash(contentId.toString());
							entities[oldHash] = contentId.toString();
							newElement->setValue(contentId);
						}
						else if (tag_hash == tagName)
						{
							std::string name = readText(false);
							if (entities.find(name) != entities.end())
								name = entities[name];
							newElement->setValue(RBX::ContentId(name.c_str(), *mimeType));
						}
						else if (tagName.substr(0, 3) == "url")
						{
							newElement->setValue(RBX::ContentId(readText(true).c_str(), *mimeType));
						}
						else if (tag_null == tagName)
						{
							newElement->setValue(RBX::ContentId());
						}
						else
						{
							throw std::runtime_error(G3D::format("TextXmlParser::parse - Unknown tag '%s'.", tagName.substr(0, 32).c_str()));
						}

						std::string closingTag = readTag();
						if (!isCloseTag(closingTag))
							throw std::runtime_error(G3D::format("TextXmlParser::parse - '%s' should be a closing tag", closingTag.substr(0, 32).c_str()));
					}
				}
			}
			else
			{
				newElement->setValue(readText(true));
			}

			if (currentElement)
				currentElement->pushBackChild(newElement);

			if (endsWithClose(currentTag))
				elements.pop();
		}
	}
}
#endif

XmlWriter::XmlWriter(std::ostream& stream)
	: stream(stream)
{
}

void TextXmlWriter::encodedWrite(std::ostream& stream, const std::string& text)
{
	encodedWrite(stream, text.c_str());
}

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
		const XmlElement* child = xmlNode->firstChild();
		if (child)
		{
			for (; child != NULL; child = child->nextSibling())
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
			stream << "&apos;";
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

void TextXmlWriterWithEmbeddedContent::serializeNode(const XmlElement* xmlNode, int depth)
{
	if (xmlNode->isValueType<RBX::ContentId>())
	{
		RBX::ContentId contentId;
		xmlNode->getValue(contentId);

		if (contentId.mimeType() == RBX::Name::getNullName())
		{
			writeOpenTag(xmlNode, depth, NULL);
		}
		else
		{
			XmlAttribute mimeTypeAttribute(tag_mimeType, contentId.mimeType().c_str());
			writeOpenTag(xmlNode, depth, &mimeTypeAttribute);
		}

		if (!xmlNode->findAttribute(name_xsinil))
		{
			if (contentId.isNull())
			{
				stream << "<null></null>";
			}
			else
			{
				if (contentId.isAsset() || contentId.isHttp())
				{
					stream << "<url>";
					TextXmlWriter::encodedWrite(stream, contentId.c_str());
					stream << "</url>";
				}
				else if (embeddedContent.find(contentId) == embeddedContent.end())
				{
					embeddedContent.insert(contentId);

					std::auto_ptr<std::istream> contentStream;

					try
					{
						contentStream = contentProvider->getContent(contentId);
					}
					catch (std::exception&)
					{
						goto hash;
					}

					if (contentId.mimeType() == RBX::Name::getNullName())
					{
						stream << "<binary>";
					}
					else
					{
						stream << "<binary xmime:contentType=\"" << contentId.mimeType().c_str() << "\">";
					}

					std::istreambuf_iterator<char> _From(contentStream->rdbuf());
					std::istreambuf_iterator<char> _To;
					std::ostreambuf_iterator<char> _Out(stream.rdbuf());
					int _State;

					base64<char> encoder;
					encoder.put(_From, _To, _Out, _State, base64<>::crlf());

					stream << "</binary>";
				}
				else
				{
hash:
					embeddedContent.insert(contentId);

					stream << "<hash>";
					stream << xmlNode->toString(this);
					stream << "</hash>";
				}
			}
		}
	}
	else
	{
		TextXmlWriter::serializeNode(xmlNode, depth);
	}
}
