#pragma once
// >>> native-status (generated) -- do not edit >>>
// Http | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src f8ab0cf4 | roc native-status --write
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

		Http(const char* url);
		~Http();
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
