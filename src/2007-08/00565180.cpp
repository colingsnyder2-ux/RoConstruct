// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_native_app_workspace_73fe1715c557d90b.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#include "v8xml/XmlSerializer.h"
#include "util/Debug.h"
#include "util/base64.hpp"
#include "reflection/type.h"
#include <G3D/format.h>
#include <sstream>

class Whitespaces
{
public:
	char data[256];
  
public:
	Whitespaces()
	{
		data[9] = true;
		data[10] = true;
		data[12] = true;
		data[13] = true;
		data[32] = true;
	}
};

static Whitespaces whitespaces;

XmlParser::XmlParser(std::streambuf* buffer)
	: buffer(buffer)
{
	
}

void TextXmlParser::skipWhitespace()
{
	while (whitespaces.data[(char)buffer->sgetc()])
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

	std::string s;
	char c = buffer->sbumpc();
	if (c != '<')
	{
		s += c;
		c = buffer->sbumpc();
		s += c;
		c = buffer->sbumpc();
		s += c;
		c = buffer->sbumpc();
		s += c;
		if (c != '<')
		{
			for (int i = 0; i != 50; i++)
			{
				if (buffer->sgetc() == -1)
					continue;
				s += buffer->sbumpc();
			}

			std::string message = "tag expected after Byte-Order-Mark:";
			message += s;
			throw std::runtime_error(message);
		}
	}

	std::string tag;
	tag += c;

	char lastChar;
	do
	{
		lastChar = buffer->sbumpc();
		tag += lastChar;
	}
	while (lastChar != '>');

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
			else if (entity[0] == '#')
				result += atoi(entity.substr(1).c_str());
			else
				RBXASSERT(0);
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
		text += buffer->sgetc();

	if (decode)
		text = decodeString(text);

	return text;
}

std::string TextXmlParser::removeTag(const std::string& contents, int& index)
{
	size_t i = 0;
	while (whitespaces.data[contents[i]] && i < contents.size())
		i++;

	size_t j = i;
	while (!whitespaces.data[contents[j]] && j < contents.size())
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
		if (!whitespaces.data[contents[i]])
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
		else if (!inQuotes && whitespaces.data[contents[j]])
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
				if (xsiNilAttribute && xsiNilAttribute->getValue(isXsiNil) && !isXsiNil)
				{
					if (readText(false) == "")
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
							std::stringstream decoded;

							int ioStatus = 0;
							base64<char> decoder;
							decoder.get(
								std::istreambuf_iterator<char>(&encoded),
								std::istreambuf_iterator<char>(),
								std::ostreambuf_iterator<char>(decoded),
								ioStatus);

							decoded.flush();

							RBX::ContentId contentId = RBX::ContentProvider::singleton().registerContent(decoded, *mimeType);
							newElement->setValue(contentId);
						}
						else if (tag_hash == tagName)
						{
							std::string name = readText(false);
							newElement->setValue(RBX::ContentId(name.c_str(), *mimeType));
						}
						else if (tagName.substr(0, 3) == "url")
						{
							std::string url = readText(true);
							newElement->setValue(RBX::ContentId(url.c_str(), *mimeType));
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
							throw std::runtime_error(G3D::format("TextXmlParser::parse - '%s' should be a closing tag", tagName.substr(0, 32).c_str()));
					}
				}
			}
			else
			{
				newElement->setValue(readText(true));
			}

			currentElement->pushBackChild(newElement);

			if (endsWithClose(currentTag))
				elements.pop();
		}
	}
}

XmlWriter::XmlWriter(std::ostream& stream)
	: stream(stream)
{
}

int XmlWriter::getHandleIndex(RBX::InstanceHandle h)
{
	std::map<RBX::InstanceHandle, int>::iterator iter = handles.find(h);
	if (iter == handles.end())
	{
		int index = (int)handles.size();
		handles[h] = index;
		return index;
	}
	else
	{
		return iter->second;
	}
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
		else if (c >= ' ' && c <= '~') // every other printable character
		{
			stream << c;
		}
		else
		{
			char buffer[8];
			sprintf(buffer, "&#%d;", c);
			stream << buffer;
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
					TextXmlWriter::encodedWrite(stream, contentId.toString());
					stream << "</url>";
				}
				else if (embeddedContent.find(contentId) == embeddedContent.end())
				{
					embeddedContent.insert(contentId);

					std::auto_ptr<std::istream> contentStream;

					try
					{
						contentStream = RBX::ContentProvider::singleton().getContent(contentId);

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
					catch (std::exception&)
					{
						goto hash;
					}
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
