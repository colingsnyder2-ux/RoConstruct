// 2008-06 native XmlSerializer.cpp rows (inactive) of the application range 0058c000..00590000: the TextXmlParser /
// TextXmlWriter unit 0058c990..0059001f, against the read-only v8xml owner headers native-headers/v8xml/XmlSerializer.h
// and XmlElement.h. Verified by tests/record_native_app_unit58c.py (receipt app-unit58c-working.json).
//   whitespaces  009494e0: initialised 256-byte table (.data; bytes 9, 10, 12, 13 and 32 set, no static initialiser),
//                read by skipWhitespace 0058cac1, removeTag 0058d22f and findNextToken 0058d2f0.
// TextXmlParser keeps a std::map<std::string, std::string> at +0x28 (declared `entities` by XmlSerializer.h; parse
// 0058f6c0 fills it with the legacy hash of each embedded binary content and maps <hash> names through it).
// Built with native-headers/writer-2008 ahead of native-headers (as WorkspaceXmlWriter.cpp is): that variant of the
// read-only v8xml owner header declares the TextXmlWriterWithEmbeddedContent ContentProvider at +0x48, read by
// serializeNode 0058f3e6 before the getContent call 00561f20.
//   vtables: TextXmlWriter 0080ea1c (slot 0 serialize 0058e810, slot 1 serializeNode 0058ecb0),
//   TextXmlWriterWithEmbeddedContent 0081c848 (slot 1 serializeNode 0058f270), TextXmlParser 0080ea28 (slot 0 parse),
//   XmlParser 00831b40 (stored by XmlParser() 0058f230); XmlWriter is novtable.
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

// 0058f230 (stores the XmlParser vtable 00831b40)
XmlParser::XmlParser(std::streambuf* buffer)
	: buffer(buffer)
{
}

// 0058cab0
void TextXmlParser::skipWhitespace()
{
	while (whitespaces[(char)buffer->sgetc()])
		buffer->sbumpc();
}

// 0058cc80
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

// 0058caf0
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

// 0058cd50
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

// 0058d130
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

// 0058d200
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

// 0058d2a0
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

// 0058e590
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

// 0058c990
bool isCloseTag(const std::string& test)
{
	if (test.size() >= 2)
		return test.substr(0, 2) == "</";

	return false;
}

// 0058ca20
bool endsWithClose(const std::string& test)
{
	if (test.size() >= 2)
		return test.substr(test.size() - 2, 2) == "/>";

	return false;
}

#ifndef NATIVE_APPUNIT58C_PENDING
// Without the static registerContent declaration parse 0058f6c0 is not built; these explicit instantiations emit the
// templates only parse instantiates in the original (the TextXmlParser +0x28 map: pair constructors 0058d3f0 /
// 0058d450, _Lbound 0058d6a0, const_iterator::_Dec 0058d6f0, _Buynode 0058d860, _Insert 0058e820, insert 0058ea20,
// find 0058ef70, insert(iterator, value) 0058eff0, operator[] 0058f5d0; base64<char>::get 0058d900 and _getCharType
// 0058d530).
template class std::_Tree<std::_Tmap_traits<std::string, std::string, std::less<std::string>,
	std::allocator<std::pair<const std::string, std::string> >, false> >;
template class std::map<std::string, std::string>;
template std::istreambuf_iterator<char> base64<char>::get(std::istreambuf_iterator<char>, std::istreambuf_iterator<char>,
	std::ostreambuf_iterator<char>, int&) const;
#else
// 0055bf20: called by parse 0058fb6b with the registered ContentId string by value, result in the hidden slot. No
// evidence name: `legacyHash` is descriptive (the result keys the +0x28 map that <hash> names are looked up in).
extern std::string legacyHash(std::string);

// 0058f6c0 (needs a static RBX::ContentProvider::registerContent(std::istream&, const Name&), 0055fbc0)
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

// 0058fff0
XmlWriter::XmlWriter(std::ostream& stream)
	: stream(stream)
{
}

// inlined at every call (writeOpenTag 0058ebd4, serializeNode 0058edc8)
void TextXmlWriter::encodedWrite(std::ostream& stream, const std::string& text)
{
	encodedWrite(stream, text.c_str());
}

// 0058eb10
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

// 0058d780
void TextXmlWriter::writeCloseTag(const XmlElement* element, int depth)
{
	for (int i = 0; i < depth; i++)
		stream << '\t';

	stream << "</" << element->getTag().name << '>';
}

// 0058ecb0
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

// 0058e810
void TextXmlWriter::serialize(const XmlElement* xmlNode)
{
	serialize(xmlNode, 0);
}

// 0058d7e0
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

// 0058e4a0
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

// 0058f270
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
