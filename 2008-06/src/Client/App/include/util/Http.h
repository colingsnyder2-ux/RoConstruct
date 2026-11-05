#pragma once
#include <string>

namespace RBX
{
	class Http
	{
	public:
		const std::string url;
		std::string additionalHeaders;

	public:
		Http(const std::string& url)
			: url(url)
		{
		}

		Http(const char* url)
			: url(url)
		{
		}
	private:
		// 00569a40/00569ae0 dispatch on a global int between two implementations
		// (005f9c30/005f8b60). The binary proves this receiver and the five-argument
		// signature; the original identifiers are not recoverable, so these names
		// are provisional descriptions, not recovered source names.
		void httpRequest(bool isPost, std::istream& data, bool compressData, const char* headers, std::string& response);
		void httpRequestAlternate(bool isPost, std::istream& data, bool compressData, const char* headers, std::string& response);
	public:
		void post(std::istream&, bool, std::string&);
		void get(std::string&);

	public:
		static bool trustCheck(const char*);
		static bool isScript(const char*);
		static bool isRobloxSite(const char*);
		static bool isCached(const char*);
	};
}
