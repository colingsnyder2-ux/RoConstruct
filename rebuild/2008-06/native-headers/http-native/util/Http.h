#pragma once
// >>> native-status (generated) -- do not edit >>>
// Http | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 403512b9 | roc native-status --write
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
	public:
		void post(std::istream&, bool, std::string&);
		void get(std::string&);

	private:
		void httpRequest(bool, std::istream&, bool, const char*, std::string&);
		void httpRequestAlternate(bool, std::istream&, bool, const char*, std::string&);

	public:
		static bool trustCheck(const char*);
		static bool isScript(const char*);
		static bool isRobloxSite(const char*);
		static bool isCached(const char*);
	};
}
