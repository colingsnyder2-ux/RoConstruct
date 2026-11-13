// 2008-06 native WinINet transport of util/Http.cpp (inactive); declarations in native-headers/AppUnit5F8/HttpTransport.h.
// Verified by tests/record_native_app_unit5f8.py.
#define _SCL_SECURE_NO_DEPRECATE // required to disable a warning
#include "AppUnit5F8/HttpTransport.h"
#include <windows.h>
#include <atlutil.h>
#include <wininet.h>
#include <sstream>
#include <G3D/format.h>
#include <boost/scoped_ptr.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include "util/ContentProvider.h"   // RBX::MD5Hasher (donor declaration, unchanged in 2008-06)

// Device class names from the RTTI of their boost.iostreams buffers: .?AV?$indirect_streambuf@VWiniInetRequest_source@@ / .?AV?$stream_buffer@VWiniInetRequest_source@@ (sic) and
// .?AV?$stream_buffer@UString_sink@@. read() shares one failure block for both early exits (hence the goto) and
// throws through a named message string; the WinHttp source reuses the WinINet message text (string bytes in the image).
class WiniInetRequest_source : public boost::iostreams::device<boost::iostreams::input>
{
private:
	HINTERNET request;

public:
	WiniInetRequest_source(HINTERNET request)
		: request(request)
	{
	}

public:
	int read(char* s, int n)
	{
		DWORD numBytes;
		DWORD bytesRead;
		if (!InternetQueryDataAvailable(request, &numBytes, 0, NULL))
			goto fail;
		if (numBytes == 0)
			goto fail;
		if (!InternetReadFile(request, s, n, &bytesRead))
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
	// Handle owner (analog name): its destructor is the out-of-line row 005f9440 (InternetCloseHandle) that the transport's unwind
	// paths call.
	class WinInetHandle
	{
		HINTERNET handle;

	public:
		WinInetHandle(HINTERNET handle)
			: handle(handle)
		{
		}
		~WinInetHandle()
		{
			InternetCloseHandle(handle);
		}
		operator HINTERNET() const
		{
			return handle;
		}
	};

	// 005f9c30
	void Http::httpGetPostWinInet(bool isPost, std::istream& data, bool compressData, const char* additionalHeaders,
		std::string& response)
	{
		int status;
		if (url.size() == 0)
			throw std::runtime_error("empty url");
		if (!Http::trustCheck(url.c_str()))
			throw std::runtime_error(G3D::format("trust check failed for %s", url.c_str()));
		ATL::CUrl crack;
		crack.CrackUrl(url.c_str());
		if (crack.GetHostNameLength() == 0)
			throw std::runtime_error(G3D::format("'%s' is missing a hostName", url.c_str()));
		WinInetHandle session = InternetOpenA("Roblox/WinInet", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
		{
			WinInetHandle connection = InternetConnectA(session, crack.GetHostName(), crack.GetPortNumber(),
				crack.GetUserNameA(), crack.GetPassword(), INTERNET_SERVICE_HTTP, 0, TRUE);
			{
				ATL::CStringA path = crack.GetUrlPath();
				path += crack.GetExtraInfo();
				WinInetHandle request = HttpOpenRequestA(connection, isPost ? "POST" : "GET", path.GetString(), NULL, NULL,
					NULL, INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NEED_FILE, TRUE);
				{
					if (!request)
						throw std::runtime_error(G3D::format("HttpOpenRequest failed for %s", url.c_str()));
					if (additionalHeaders)
						throwIfFailure(HttpAddRequestHeadersA(request, additionalHeaders, (int)strlen(additionalHeaders),
							HTTP_ADDREQ_FLAG_ADD) == TRUE, "HttpAddRequestHeaders failed");
					const char* acceptEncodingHeader = "Accept-Encoding: gzip\r\n";
					throwIfFailure(HttpAddRequestHeadersA(request, acceptEncodingHeader, (int)strlen(acceptEncodingHeader),
						HTTP_ADDREQ_FLAG_ADD) == TRUE, "HttpAddRequestHeaders failed");
					boost::iostreams::gzip_params gzipParams(boost::iostreams::zlib::default_compression);
					if (!isPost)
						throwIfFailure(HttpSendRequestA(request, NULL, 0, NULL, 0) == TRUE, "HttpSendRequest failed");
					else
					{
						std::string uploadData;
						try
						{
							boost::iostreams::filtering_stream<boost::iostreams::output> out;
							if (compressData)
							{
								std::string contentEncodingHeader = "Content-Encoding: gzip\r\n";
								throwIfFailure(HttpAddRequestHeadersA(request, contentEncodingHeader.c_str(),
									(int)contentEncodingHeader.size(), HTTP_ADDREQ_FLAG_ADD) == TRUE,
									"HttpAddRequestHeaders failed");
								out.push(boost::iostreams::basic_gzip_compressor<>(gzipParams));
							}
							out.push(String_sink(uploadData));
							boost::iostreams::copy(data, out);
						}
						catch (boost::iostreams::gzip_error& e)
						{
							int error = e.error();
							int zlibError = e.zlib_error_code();
							throw std::runtime_error(G3D::format("Upload GZip error %d, ZLib error %d, \"%s\"", error,
								zlibError, url.c_str()));
						}
						size_t length = uploadData.size();
						if (length > 10000)
						{
							std::string sizeHeader = G3D::format("Roblox-Content-Size: %d\r\n", length);
							throwIfFailure(HttpAddRequestHeadersA(request, sizeHeader.c_str(), (int)sizeHeader.size(),
								HTTP_ADDREQ_FLAG_ADD) == TRUE, "HttpAddRequestHeaders failed");
							std::string firstHeader = G3D::format("Roblox-Content-First: %d\r\n", uploadData[0]);
							throwIfFailure(HttpAddRequestHeadersA(request, firstHeader.c_str(), (int)firstHeader.size(),
								HTTP_ADDREQ_FLAG_ADD) == TRUE, "HttpAddRequestHeaders failed");
							std::string lastHeader = G3D::format("Roblox-Content-Last: %d\r\n", uploadData.c_str()[length - 1]);
							throwIfFailure(HttpAddRequestHeadersA(request, lastHeader.c_str(), (int)lastHeader.size(),
								HTTP_ADDREQ_FLAG_ADD) == TRUE, "HttpAddRequestHeaders failed");
							boost::scoped_ptr<MD5Hasher> hasher(MD5Hasher::create());
							hasher->addData(uploadData);
							std::string hashHeader = G3D::format("Roblox-Content-Hash: %s\r\n", hasher->c_str());
							throwIfFailure(HttpAddRequestHeadersA(request, hashHeader.c_str(), (int)hashHeader.size(),
								HTTP_ADDREQ_FLAG_ADD) == TRUE, "HttpAddRequestHeaders failed");
						}
						{
							INTERNET_BUFFERSA buffers;
							memset(&buffers, 0, sizeof(buffers));
							buffers.dwStructSize = sizeof(buffers);
							buffers.dwBufferTotal = length;
							if (!HttpSendRequestExA(request, &buffers, NULL, 0, 0))
								throw std::runtime_error("HttpSendRequestEx failed");
						}
						try
						{
							DWORD written;
							throwIfFailure(InternetWriteFile(request, uploadData.c_str(), length, &written) == TRUE,
								"InternetWriteFile failed");
							if (written != length)
								throw std::runtime_error("Failed to upload content");
						}
						catch (std::exception&)
						{
							HttpEndRequestA(request, NULL, 0, 0);
							throw;
						}
						throwIfFailure(HttpEndRequestA(request, NULL, 0, 0) == TRUE, "HttpEndRequest failed");
					}
					{
						DWORD length = sizeof(status);
						throwIfFailure(HttpQueryInfoA(request, HTTP_QUERY_STATUS_CODE | HTTP_QUERY_FLAG_NUMBER, &status, &length,
							NULL) == TRUE, "HttpQueryInfo failed");
					}
					try
					{
						boost::iostreams::filtering_stream<boost::iostreams::input> in;
						char buffer[256];
						DWORD length = sizeof(buffer);
						if (HttpQueryInfoA(request, HTTP_QUERY_CONTENT_ENCODING, buffer, &length, NULL))
							if (std::string(buffer) == "gzip")
								in.push(boost::iostreams::basic_gzip_decompressor<>());
						in.push(WiniInetRequest_source(request));
						boost::iostreams::copy(in, String_sink(response));
					}
					catch (boost::iostreams::gzip_error& e)
					{
						int error = e.error();
						int zlibError = e.zlib_error_code();
						throw std::runtime_error(G3D::format("GZip error %d, ZLib error %d, \"%s\"", error, zlibError,
							url.c_str()));
					}
					catch (boost::iostreams::zlib_error& e)
					{
						int error = e.error();
						throw std::runtime_error(G3D::format("ZLib error %d, \"%s\"", error, url.c_str()));
					}
					if (status != 200)
					{
						char buffer[512];
						DWORD length = sizeof(buffer);
						if (HttpQueryInfoA(request, HTTP_QUERY_STATUS_TEXT, buffer, &length, NULL))
							throw std::runtime_error(buffer);
						else
							throw std::runtime_error(G3D::format("statusCode = %d", status));
					}
				}
			}
		}
	}
}
