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

		__declspec(noinline) Http(const char* value) : url(value) {}
		// INFERRED: 00579c10 destroys both url and additionalHeaders inline, so the
		// 2008-06 Http declaration had an implicit destructor.
	public:
		void post(std::istream&, bool, std::string&);
		void get(std::string&);

	private:
		void checkHttpResult(bool, const char*);
		void httpRequest(bool, std::istream&, bool, const char*, std::string&);
		void httpRequestAlternate(bool, std::istream&, bool, const char*, std::string&);

	public:
		static bool trustCheck(const char*);
		static bool isScript(const char*);
		static bool isRobloxSite(const char*);
		static bool isCached(const char*);
	};
}
