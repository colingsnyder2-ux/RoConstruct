#pragma once
#include "util/ContentId.h"
#include "util/ContentRequest.h" // INFERRED: 2008 ContentProvider stores std::list<ContentRequest> (NativeContentProvider.h, sizeof 0x19c)
#include "util/boost.hpp"
#include "v8tree/Instance.h"     // INFERRED: 2008 ContentProvider inherits DescribedNonCreatable<ContentProvider, Instance, sContentProvider>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <boost/date_time.hpp>
#include <boost/scoped_ptr.hpp>

namespace RBX
{
	class Instance;
	extern char sContentProvider[];

#ifndef RBX_CONTENT_REQUEST_DEFINED
#define RBX_CONTENT_REQUEST_DEFINED
	struct ContentRequest // INFERRED: 0x38 bytes (NativeContentProvider.h, 00562530)
	{
		ContentId id;
		std::vector<RequestCallback> callbacks;
		bool operator==(const ContentId& other) const { return id.toString() == other.toString(); }
		ContentRequest(const ContentRequest&);
		ContentRequest();
		~ContentRequest();
	};
#endif

	// INFERRED: 2008 ContentProvider is an Instance service (sizeof 0x19c; NativeContentProvider.h offset asserts)
	class ContentProvider : public DescribedNonCreatable<ContentProvider, Instance, sContentProvider>
	{
	private:
		enum HttpRequestType
		{
			NoHttpRequest,
			AsyncHttpRequest,
			SyncHttpRequest
		};

		struct CachedContent
		{
			boost::shared_ptr<const std::string> data;
			boost::shared_ptr<const std::string> filename;
		};

		struct FailedUrl
		{
		public:
			std::string url;
			boost::posix_time::ptime expiration;
		  
		public:
			FailedUrl(const char* url);
			bool expired() const;
		};

	private:
		boost::mutex requestSync;                          // +0x130
		std::list<ContentRequest> requestQueue;            // +0x138 (INFERRED: ContentRequest, NativeContentProvider.h)
		std::list<FailedUrl> failedUrls;                   // +0x154
		boost::mutex contentCacheMutex;                    // +0x170
		std::map<ContentId, CachedContent> contentCache;   // +0x178
		boost::scoped_ptr<worker_thread> requestProcessor; // +0x198 (INFERRED: no assetFolderPath member in 2008)
	  
	private:
		ContentProvider();
		virtual ~ContentProvider();

	public:
		static ContentId registerContent(std::istream& content, const Name& mimeType);
		ContentId registerContent(const char*, const Name&);
		void clearFileCache();
		bool isUrlBad(const char* url);
		void load(ContentId id, std::vector<boost::shared_ptr<Instance>>& instances);
		void clearContentCache();
		bool isRequestQueueEmpty();
		bool hasContent(ContentId id);
		boost::shared_ptr<const std::string> requestContentString(ContentId id);
		bool requestContentFile(ContentId id, std::string& filename);
		boost::shared_ptr<const std::string> getContentString(ContentId);
		std::auto_ptr<std::istream> getContent(ContentId ticket);
		std::string getFile(ContentId ticket);
		std::string getAssetFile(const std::string& filePath);
		static void setAssetFolder(const char* sPath);   // 00560590: no this pointer at the call (InitInstance path)
		std::string assetFolder() const;
		ContentId readContent(const char* id, std::istream& stream, unsigned long dataLength);
	private:
		CachedContent* loadContent(ContentId, HttpRequestType);
		worker_thread::work_result processRequests();
		std::string findFile(ContentId contentId);
		std::string findAsset(ContentId contentId);
		std::string findHashFile(ContentId contentId);
		bool registerFile(CachedContent* item);
	  
	public:
		static ContentProvider& singleton()
		{
			static ContentProvider sing;
			return sing;
		}

		static bool isUrl(const std::string&);
		static bool isHttpUrl(const std::string&);
	};

	class MD5Hasher
	{
	public:
		virtual void addData(std::istream& data) = 0;
		virtual void addData(const std::string& data) = 0;
		virtual void addData(const char* data, size_t nBytes) = 0;
		
		virtual std::string toString() = 0;
		virtual const char* c_str() = 0;

	public:
		static MD5Hasher* create();
	};
}
