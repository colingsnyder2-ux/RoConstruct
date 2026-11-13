// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native WinHttp transport of util/Http.cpp (inactive); declarations in native-headers/AppUnit5F8/HttpTransport.h.
// Verified by tests/record_native_app_unit5f8.py.
#define _SCL_SECURE_NO_DEPRECATE // required to disable a warning
#include "AppUnit5F8/HttpTransport.h"
#include <windows.h>
#include <atlutil.h>
#include <winhttp.h>
#include <sstream>
#include <G3D/format.h>
#include <boost/scoped_ptr.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include "util/ContentProvider.h"   // RBX::MD5Hasher (donor declaration, unchanged in 2008-06)

// Device class names from the RTTI of their boost.iostreams buffers: .?AV?$indirect_streambuf@VWinHttpRequest_source@@ / .?AV?$stream_buffer@VWinHttpRequest_source@@ and
// .?AV?$stream_buffer@UString_sink@@. read() shares one failure block for both early exits (hence the goto) and
// throws through a named message string; the WinHttp source reuses the WinINet message text (string bytes in the image).
class WinHttpRequest_source : public boost::iostreams::device<boost::iostreams::input>
{
private:
	HINTERNET request;

public:
	WinHttpRequest_source(HINTERNET request)
		: request(request)
	{
	}

public:
	int read(char* s, int n)
	{
		DWORD numBytes;
		DWORD bytesRead;
		if (!WinHttpQueryDataAvailable(request, &numBytes))
			goto fail;
		if (numBytes == 0)
			goto fail;
		if (!WinHttpReadData(request, s, n, &bytesRead))
		{
			std::string message("InternetReadFile failed");
			throw std::runtime_error(message);
		}
		return bytesRead;
	fail:
		return -1;
	}
};

struct String_sink : public boost::iostreams::device<boost::iostreams::output>
{
public:
	std::string& s;

public:
	String_sink(std::string& s)
		: s(s)
	{
	}

public:
	int write(const char* c, int n)
	{
		s.append(c, n);
		return n;
	}
};

namespace RBX
{
	// Handle owner (analog name): its destructor is the out-of-line row 005f20e0 (WinHttpCloseHandle) that the transport's unwind
	// paths call.
	class WinHttpHandle
	{
		HINTERNET handle;

	public:
		WinHttpHandle(HINTERNET handle)
			: handle(handle)
		{
		}
		~WinHttpHandle()
		{
			WinHttpCloseHandle(handle);
		}
		operator HINTERNET() const
		{
			return handle;
		}
	};

	// 005f8b60
	void Http::httpGetPostWinHttp(bool isPost, std::istream& data, bool compressData, const char* additionalHeaders,
		std::string& response)
	{
		if (url.size() == 0)
			throw std::runtime_error("empty url");
		if (!Http::trustCheck(url.c_str()))
			throw std::runtime_error(G3D::format("trust check failed for %s", url.c_str()));
		ATL::CUrl crack;
		crack.CrackUrl(url.c_str());
		if (crack.GetHostNameLength() == 0)
			throw std::runtime_error(G3D::format("'%s' is missing a hostName", url.c_str()));
		WinHttpHandle session = WinHttpOpen(L"Roblox/WinHttp", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, NULL, NULL, 0);
		{
			throwIfFailure(session != NULL, "WinHttpOpen");
			bool secure = crack.GetScheme() == ATL_URL_SCHEME_HTTPS;
			WinHttpHandle connection = WinHttpConnect(session, ATL::CComBSTR(ATL::CStringA(crack.GetHostName())),
				crack.GetPortNumber(), 0);
			{
				throwIfFailure(connection != NULL, "WinHttpConnect");
				std::string path = crack.GetUrlPath();
				path += crack.GetExtraInfo();
				WinHttpHandle request = WinHttpOpenRequest(connection, isPost ? L"POST" : L"GET",
					ATL::CComBSTR(path.c_str()), NULL, NULL, NULL, secure ? WINHTTP_FLAG_SECURE : 0);

				throwIfFailure(request != NULL, "WinHttpOpenRequest");
				if (additionalHeaders)
					throwIfFailure(WinHttpAddRequestHeaders(request, ATL::CComBSTR(additionalHeaders), -1,
						WINHTTP_ADDREQ_FLAG_ADD) == TRUE, "WinHttpAddRequestHeaders");
				throwIfFailure(WinHttpAddRequestHeaders(request, L"Accept-Encoding: gzip\r\n", -1,
					WINHTTP_ADDREQ_FLAG_ADD) == TRUE, "WinHttpAddRequestHeaders failed");
				boost::iostreams::gzip_params gzipParams(boost::iostreams::zlib::default_compression);
				if (!isPost)
					throwIfFailure(WinHttpSendRequest(request, NULL, 0, NULL, 0, 0, 0) == TRUE, "WinHttpSendRequest failed");
				else
				{
					std::string uploadData;
					try
					{
						boost::iostreams::filtering_stream<boost::iostreams::output> out;
						if (compressData)
						{
							throwIfFailure(WinHttpAddRequestHeaders(request, L"Content-Encoding: gzip\r\n", -1,
								WINHTTP_ADDREQ_FLAG_ADD) == TRUE, "HttpAddRequestHeaders failed");
							out.push(boost::iostreams::basic_gzip_compressor<>(gzipParams));
						}
						out.push(String_sink(uploadData));
						boost::iostreams::copy(data, out);
					}
					catch (boost::iostreams::gzip_error& e)
					{
						int err = e.error();
						int zerr = e.zlib_error_code();
						throw std::runtime_error(G3D::format("Upload GZip error %d, ZLib error %d, \"%s\"", err, zerr, url.c_str()));
					}
					std::string::size_type length = uploadData.size();
					if (length > 10000)
					{
						std::string sizeHeader = G3D::format("Roblox-Content-Size: %d\r\n", length);
						throwIfFailure(WinHttpAddRequestHeaders(request, ATL::CComBSTR(sizeHeader.c_str()), -1,
							WINHTTP_ADDREQ_FLAG_ADD) == TRUE, "WinHttpAddRequestHeaders failed");
						boost::scoped_ptr<MD5Hasher> hasher(MD5Hasher::create());
						hasher->addData(uploadData);
						std::string hashHeader = G3D::format("Roblox-Content-Hash: %s\r\n", hasher->c_str());
						throwIfFailure(WinHttpAddRequestHeaders(request, ATL::CComBSTR(hashHeader.c_str()), -1,
							WINHTTP_ADDREQ_FLAG_ADD) == TRUE, "WinHttpAddRequestHeaders failed");
					}
					throwIfFailure(WinHttpSendRequest(request, NULL, 0, (void*)uploadData.c_str(), length, length, 0) == TRUE,
						"WinHttpSendRequest failed");
				}
				throwIfFailure(WinHttpReceiveResponse(request, NULL) == TRUE, "WinHttpReceiveResponse");
				try
				{
					boost::iostreams::filtering_stream<boost::iostreams::input> in;
					WCHAR buffer[256];
					DWORD length = 256;
					if (WinHttpQueryHeaders(request, WINHTTP_QUERY_CONTENT_ENCODING, NULL, buffer, &length, NULL))
						if (ATL::CStringA(buffer) == "gzip")
							in.push(boost::iostreams::basic_gzip_decompressor<>());
					in.push(WinHttpRequest_source(request));
					boost::iostreams::copy(in, String_sink(response));
				}
				catch (boost::iostreams::gzip_error& e)
				{
					int err = e.error();
					int zerr = e.zlib_error_code();
					throw std::runtime_error(G3D::format("GZip error %d, ZLib error %d, \"%s\"", err, zerr, url.c_str()));
				}
				catch (boost::iostreams::zlib_error& e)
				{
					int err = e.error();
					throw std::runtime_error(G3D::format("ZLib error %d, \"%s\"", err, url.c_str()));
				}
				int status = -1;
				{
					DWORD length = sizeof(status);
					throwIfFailure(WinHttpQueryHeaders(request, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, NULL,
						&status, &length, NULL) == TRUE, "WinHttpQueryHeaders");
				}
				if (status != 200)
				{
					WCHAR buffer[512];
					DWORD length = 512;
					if (WinHttpQueryHeaders(request, WINHTTP_QUERY_STATUS_TEXT, NULL, buffer, &length, NULL))
						throw std::runtime_error(ATL::CStringA(buffer).GetString());
					else
						throw std::runtime_error(G3D::format("statusCode = %d", status));
				}
			}
		}
	}

}
