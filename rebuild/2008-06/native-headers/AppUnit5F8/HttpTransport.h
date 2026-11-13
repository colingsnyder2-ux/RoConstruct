#pragma once
// 2008-06 native RBX::Http (inactive), declared under a non-colliding name: the original path util/Http.h is the donor
// header that other native units include (ContentProvider, CContentUpload, WorkspaceSiteTrust, ...). A unit must not
// include both this header and the donor util/Http.h.
//
// Layout (no allocation: Http is a stack object of its callers):
//   url               +0x00 std::string (post 00569a40 / get 00569ae0 / the transports read size +0x14, capacity +0x18
//                     and buffer +0x4; the WinINet failure helper 00569920 formats url at +0x4 / +0x18)
//   additionalHeaders +0x1c std::string (post 00569a40 `cmp [ecx + 0x30], 0`, capacity +0x34, buffer +0x20)
// Members (thiscall; evidence names for post / get):
//   post(std::istream&, bool, std::string&)             00569a40 (evidence name)
//   get(std::string&)                                    00569ae0 (evidence name)
//   the WinHttp transport (bool isPost, std::istream&, bool compress, const char* headers, std::string&) 005f8b60 and
//   the WinINet transport with the same arguments 005f9c30: get / post push response, headers, compress, data and
//   isPost and pass ecx = this (`ret 0x14`); the transport is chosen by a static int at 00946274 (0 = WinINet,
//   1 = WinHttp). Their names are analog names: the binary does not name them.
//   throwIfFailure(bool success, const char* message)    00569920 (`ret 8`; GetLastError / FormatMessageA, then
//                                                        runtime_error(format(..., url, message, ...))); analog name.
//   trustCheck(const char*)                              0056a2e0 (static; cdecl call `add esp, 4` at 005f9cb3).
#include <string>
#include <istream>

namespace RBX
{
	class Http
	{
	public:
		const std::string url;            // +0x00
		std::string additionalHeaders;    // +0x1c

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
		void post(std::istream& input, bool compress, std::string& response);   // 00569a40
		void get(std::string& response);                                         // 00569ae0

		static bool trustCheck(const char* url);                                 // 0056a2e0

	private:
		void httpGetPostWinHttp(bool isPost, std::istream& data, bool compressData, const char* headers,
			std::string& response);                                              // 005f8b60
		void httpGetPostWinInet(bool isPost, std::istream& data, bool compressData, const char* headers,
			std::string& response);                                              // 005f9c30
		void throwIfFailure(bool success, const char* message);                  // 00569920
	};
}
