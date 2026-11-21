// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// SerializerV2::loadInstances 00593250 (550 B) and SerializerV2::load(std::istream&, DataModel*) 00593730 (1142 B).
// Both follow ~ArchiveBinder 005931e0 in the SerializerV2 / ArchiveBinder object (ArchiveBinder.cpp holds the binder
// rows, SerializerRoot.cpp loadXML; neither is this batch's file, flags copied from them). Identities: registry
// ?loadInstances@SerializerV2@@QAEXPAVXmlElement@@AAV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@...@std@@@Z
// (identity-closure, unique body) and ?load@SerializerV2@@QAEXAAV?$basic_istream@DU?$char_traits@D@std@@@std@@PAVDataModel@RBX@@@Z
// (identity-closure). Body shape: openrbx v8xml/SerializerV2.cpp (2007 client analog), adjusted to the 2008 bytes.
//
// Both bodies are guarded: each needs one declaration that a core header lacks (owner proposals, measured below).
#ifdef NATIVE_CONTENTPROVIDER_READCONTENT_DECLARED
#include "util/NativeContentProvider.h" // first: it renames the donor ContentProvider declaration
#include "v8datamodel/DataModel.h"
#endif
#include "../native-headers/v8xml/XmlElement.h"
#include "metadata-load/v8xml/SerializerV2.h"
#include "v8xml/XmlSerializer.h"
#include <G3D/Log.h>
#ifndef NATIVE_CONTENTPROVIDER_READCONTENT_DECLARED
#include "v8datamodel/DataModel.h" // SerializerV2::load(XmlElement*, DataModel*) converts DataModel* to Instance*
#endif

// 00593500 ?load@SerializerV2@@SAXPAVXmlElement@@PAVDataModel@RBX@@@Z (static, registry identity-closure; callers
// 00455744 and loadXML 00593570 at 00593690). Same ArchiveBinder object: ArchiveBinder() 00592940, the data model's
// Instance::readChildren 0055b6a0 (public in v8tree/Instance.h), resolveRefs 00592720 called directly,
// ~ArchiveBinder 005931e0 (EH state 0, handler 007d1df8). Body follows openrbx v8xml/SerializerV2.cpp.
void SerializerV2::load(XmlElement* root, RBX::DataModel* dataModel)
{
	ArchiveBinder binder;
	dataModel->readChildren(root, binder);
	binder.resolveRefs();
}

#ifdef NATIVE_INSTANCE_READ_DECLARED
// 00593250 (`ret 8`). Callees: findAttribute 0057c2b0, getValue(int&) 0057c4f0, ArchiveBinder() 00592940,
// findFirstChildByTag 0057c230, getValue(const Name*&) 0057c360, AbstractFactoryProduct<Instance>::create 00420190,
// Instance::read 0055b6f0, vector push_back 00420110, StandardOut::singleton 00569620 / print 005693a0
// ("Unknown object class \"%s\" while reading XML" 00831f34), findNextChildWithSameTag 0057c250, resolveRefs
// 00592720, ~ArchiveBinder 005931e0, G3D::Log::common 00509db0 / println 00509ef0 (00831ee0).
// BLOCKER: core v8tree/Instance.h does not declare `void read(const ::XmlElement*, IReferenceBinder&); // 0055b6f0`
// (public; the body is in AppUnit558_2008Instance.cpp). With that one line in a scratch copy of Instance.h this body
// compiles to 550 bytes, IDENTICAL to 00593250 (relocations masked).
void SerializerV2::loadInstances(XmlElement* root, std::vector<boost::shared_ptr<RBX::Instance> >& instances)
{
	if (root->getTag() == tag_roblox)
	{
		XmlAttribute* version = root->findAttribute(tag_version);
		if (version && version->getValue(schemaVersionLoading) && schemaVersionLoading >= 4)
		{
			ArchiveBinder binder;
			const XmlElement* itemElement = root->findFirstChildByTag(tag_Item);
			while (itemElement)
			{
				const RBX::Name* className = NULL;
				if (itemElement->findAttributeValue(tag_class, className))
				{
					boost::shared_ptr<RBX::Instance> instance = RBX::AbstractFactoryProduct<RBX::Instance>::create(*className);
					if (instance)
					{
						instance->read(itemElement, binder);
						instances.push_back(instance);
					}
					else
					{
						RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, "Unknown object class \"%s\" while reading XML", className ? className->c_str() : "");
					}
				}
				itemElement = root->findNextChildWithSameTag(itemElement);
			}
			binder.resolveRefs();
			return;
		}
	}
	G3D::Log::common()->println("Version 1.0 - 3.0 model files not supported - all future version will be supported");
}
#endif

#ifdef NATIVE_CONTENTPROVIDER_READCONTENT_DECLARED
// 00593730 (`ret 8`). Strings 008321b8 / 0083217c / 00832150 / 00832124 and "(1)".."(6)" 008320bc / 00832088 /
// 00832054 / 00832020 / 008320f0 / 00831fec; "RBX_" 008321b0 compared by the inline strcmp; std::runtime_error
// 00409d50; non-"RBX_" and final paths call loadXML 00593570; the compound-file loop calls
// ServiceProvider::create<ContentProvider> 0041eea0 (NULL-checked provider) and ContentProvider 00562a30 (hidden
// ContentId return, destroyed at once).
// BLOCKER: the native ContentProvider (core util/NativeContentProvider.h) does not declare the donor
// `ContentId readContent(const char* id, std::istream& stream, unsigned long dataLength); // 00562a30`. With that line
// (public, after getContent) in a scratch copy of the header this body compiles to 1142 bytes, IDENTICAL to 00593730
// (relocations masked). Trial 1 (loadXML once after the if/else, openrbx shape): 1121 B, `this` spilled instead of
// kept in edi (rejected); trial 2 (loadXML and return inside the non-"RBX_" branch): exact.
void SerializerV2::load(std::istream& stream, RBX::DataModel* dataModel)
{
	char header[5];
	header[4] = 0;
	if (!stream.read(header, 4).good())
		throw std::runtime_error("SerializerV2::load can't read header");

	if (strcmp(header, "RBX_") != 0)
	{
		stream.clear();
		stream.seekg(0, std::ios_base::beg);
		loadXML(stream, dataModel);
		return;
	}
	else
	{
		unsigned long fileFormatVersion;
		if (!stream.read((char*)&fileFormatVersion, 4).good())
			throw std::runtime_error("SerializerV2::load can't read old fileFormatVersion");
		if (fileFormatVersion != 1)
			throw std::runtime_error("SerializerV2::load canfileFormatVersion!=1");

		unsigned long contentPos = 0;
		if (!stream.read((char*)&contentPos, 4).good())
			throw std::runtime_error("SerializerV2::load can't read contentPos");

		if (contentPos != 0)
		{
			std::streamoff xmlPos = stream.tellg();
			stream.clear();
			stream.seekg(contentPos, std::ios_base::beg);

			while (stream.peek())
			{
				char id[33];
				id[32] = 0;
				if (!stream.read(id, 32).good())
					throw std::runtime_error("SerializerV2::load error reading compound file (1)");

				unsigned long contentLength;
				if (!stream.read((char*)&contentLength, 4).good())
					throw std::runtime_error("SerializerV2::load error reading compound file (2)");

				char compression;
				if (!stream.read(&compression, 1).good())
					throw std::runtime_error("SerializerV2::load error reading compound file (3)");
				if (compression != 0)
					throw std::runtime_error("SerializerV2::load error reading compound file (4)");

				RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel)->readContent(id, stream, contentLength);
			}

			stream.clear();
			stream.seekg(xmlPos, std::ios_base::beg);
		}

		char xmlCompression;
		if (!stream.read(&xmlCompression, 1).good())
			throw std::runtime_error("SerializerV2::load error reading compound file (5)");
		if (xmlCompression != 0)
			throw std::runtime_error("SerializerV2::load error reading compound file (6)");
	}

	loadXML(stream, dataModel);
}
#endif
