// from server: 100% by EspClaude
// from server: 81% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a12929c469ffad23.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8xml/XmlElement.h", "roc_unit_3373cfbf6826d597.cpp")
#include <v8xml/XmlSerializer.h>
#include <util/base64.hpp>
#include <reflection/type.h>
#include <G3D/format.h>
#include <sstream>
template<> bool XmlNameValuePair::isValueType<RBX::ContentId>() const;
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
						contentStream = (*reinterpret_cast<RBX::ContentProvider**>(reinterpret_cast<char*>(this) + 0x48))->getContent(contentId);
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


