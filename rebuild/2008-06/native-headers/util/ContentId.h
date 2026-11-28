#pragma once
// Split from util/ContentProvider.h so v8xml/XmlElement.h does not cycle with v8tree/Instance.h
// when ContentProvider inherits DescribedNonCreatable<ContentProvider, Instance, sContentProvider>.
#include "util/Name.h"
#include <string>

namespace RBX
{
	class ContentId;
	bool operator!=(const ContentId&, const ContentId&);
	bool operator==(const ContentId&, const ContentId&);
	bool operator<(const ContentId&, const ContentId&);

	class ContentId
	{
	private:
		std::string id;
		const Name* mimeTypePtr;

	public:
		ContentId()
			: id(),
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const std::string& id)
			: id(id),
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const char* id)
			: id(id),
			  mimeTypePtr(&Name::getNullName())
		{
		}
		ContentId(const std::string& id, const Name& mimeType)
			: id(id),
			  mimeTypePtr(&mimeType)
		{
		}

	public:
		const Name& mimeType() const
		{
			return *mimeTypePtr;
		}
		const char* c_str() const
		{
			return id.c_str();
		}
		const std::string& toString() const
		{
			return id;
		}
		bool isNull() const
		{
			return id.empty();
		}
		bool isFile() const
		{
			return id.substr(0, 7) == "file://";
		}
		bool isAsset() const
		{
			return id.substr(0, 11) == "rbxasset://";
		}
		bool isHttp() const
		{
			return id.substr(0, 4) == "http";
		}

	public:
		static ContentId fromUrl(const std::string&);
		static ContentId fromFile(const std::string&);
		static ContentId fromAssets(const std::string& filePath);
		static ContentId fromAssets(const char* filePath); // 2008 overload used by RBX::Sky::Sky (0055bd80)
		static ContentId fromMD5Hash(const std::string&);
	};

	class ContentProvider; // forward declaration for headers that previously got it transitively via XmlElement.h
}
