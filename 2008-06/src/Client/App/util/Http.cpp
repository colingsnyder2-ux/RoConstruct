#define _SCL_SECURE_NO_DEPRECATE // required to disable a warning
#include "util/Http.h"
#include <windows.h>
#include <atlutil.h>
#include <wininet.h>
#include <sstream>
#include <G3D/format.h>
#include <boost/scoped_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>

class HttpRequest_source : public boost::iostreams::device<boost::iostreams::input>
{
private:
	void* request;

public:
	HttpRequest_source(void* request)
		: request(request)
	{
	}
public:
	// does not match
	int read(char* s, int n)
	{
		DWORD numBytes;
		if (!InternetQueryDataAvailable(request, &numBytes, 0, NULL))
			return -1;
		if (numBytes == 0)
			return -1;

		DWORD bytesRead;
		if (!InternetReadFile(request, s, n, &bytesRead))
			throw std::runtime_error("InternetReadFile failed");

		return bytesRead;
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
	// NOTE: not checked
	int write(const char* c, int n)
	{
		s.append(c, n);
		return n;
	}
};

namespace RBX
{
	void ThrowIfFailure(bool success, const char* message)
	{
		if (!success)
		{
			DWORD error = GetLastError();

			char buffer[256];
			if (!FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT), buffer, sizeof(buffer), NULL))
				throw std::runtime_error(G3D::format("%s, err=0x%X", message, error));
			else
				throw std::runtime_error(G3D::format("%s, %s", message, buffer));
		}
	}

	// Provisional: 0x946274 is a global int read by both dispatchers (0 selects
	// the 005f9c30 implementation, 1 the 005f8b60 implementation).
	static int mode = 0;

	void Http::httpRequest(bool isPost, std::istream& data, bool compressData, const char* additionalHeaders, std::string& response)
	{
		if (url.size() == 0)
			throw std::runtime_error("empty url");

		if (!Http::trustCheck(url.c_str()))
			throw std::runtime_error(G3D::format("trust check failed for %s", url.c_str()));

		ATL::CUrl crack;
		crack.CrackUrl(url.c_str());

		if (crack.GetHostNameLength() == 0)
			throw std::runtime_error(G3D::format("'%s' is missing a hostName", url.c_str()));

		HINTERNET session = InternetOpenA("Roblox", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

		HINTERNET connection = InternetConnectA(session,
			crack.GetHostName(),
			crack.GetPortNumber(),
			crack.GetUserNameA(),
			crack.GetPassword(),
			INTERNET_SERVICE_HTTP,
			0,
			TRUE);

		{
			ATL::CString s = crack.GetUrlPath();
			s += crack.GetExtraInfo();

			HINTERNET request = HttpOpenRequestA(
				connection,
				isPost ? "POST" : "GET",
				s.GetString(),
				NULL,
				NULL,
				NULL,
				INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NEED_FILE,
				TRUE);

			if (!request)
				throw std::runtime_error(G3D::format("HttpOpenRequest failed for %s", url.c_str()));

			if (additionalHeaders)
			{
				if (!HttpAddRequestHeadersA(request, additionalHeaders, (int)strlen(additionalHeaders), HTTP_ADDREQ_FLAG_ADD))
					ThrowIfFailure(false, "HttpAddRequestHeaders failed");
			}

			if (!HttpAddRequestHeadersA(request, "Accept-Encoding: gzip\r\n", (int)strlen("Accept-Encoding: gzip\r\n"), HTTP_ADDREQ_FLAG_ADD))
				ThrowIfFailure(false, "HttpAddRequestHeaders failed");

			{
				boost::iostreams::gzip_params gzipParams(boost::iostreams::zlib::default_compression);

				if (isPost)
				{
					std::string uploadData;

					{
						boost::iostreams::filtering_stream<boost::iostreams::output> out;

						if (compressData)
						{
							std::string contentEncodingHeader = "Content-Encoding: gzip\r\n";
							if (!HttpAddRequestHeadersA(request, contentEncodingHeader.c_str(), (int)contentEncodingHeader.size(), HTTP_ADDREQ_FLAG_ADD))
								ThrowIfFailure(false, "HttpAddRequestHeaders failed");

							out.push(boost::iostreams::basic_gzip_compressor<>(gzipParams));
						}

						out.push(String_sink(uploadData));
						boost::iostreams::copy(data, out);
					}

					int headerLength = (int)uploadData.size();

					INTERNET_BUFFERSA buffers = {0};
					buffers.dwStructSize = sizeof(INTERNET_BUFFERSA);
					if (!HttpSendRequestExA(request, &buffers, NULL, 0, TRUE))
						throw std::runtime_error("HttpSendRequestEx failed");

					DWORD bytesWritten;
					if (!InternetWriteFile(request, uploadData.c_str(), headerLength, &bytesWritten))
						ThrowIfFailure(false, "InternetWriteFile failed");

					if (bytesWritten != headerLength)
						throw std::runtime_error("Failed to upload content");

					if (!HttpEndRequestA(request, NULL, 0, TRUE))
						ThrowIfFailure(false, "HttpEndRequest failed");
				}
				else
				{
					if (!HttpSendRequestA(request, NULL, 0, NULL, 0))
						ThrowIfFailure(false, "HttpSendRequest failed");
				}

				int statusCode;
				{
					char buffer[80];
					DWORD length = sizeof(buffer);
					if (!HttpQueryInfoA(request, HTTP_QUERY_STATUS_CODE, buffer, &length, NULL))
						ThrowIfFailure(false, "HttpQueryInfo failed");
					statusCode = atol(buffer);
				}

				{
					boost::iostreams::filtering_stream<boost::iostreams::input> in;

					char buffer[256];
					DWORD length = sizeof(buffer);
					if (HttpQueryInfoA(request, HTTP_QUERY_CONTENT_ENCODING, buffer, &length, NULL))
					{
						if (std::string(buffer) == "gzip")
							in.push(boost::iostreams::basic_gzip_decompressor<>());
					}

					in.push(HttpRequest_source(request));
					boost::iostreams::copy(in, String_sink(response));
				}

				if (statusCode != 200)
					throw std::runtime_error(G3D::format("statusCode = %d", statusCode));
			}

			InternetCloseHandle(request);
		}

		InternetCloseHandle(connection);
		InternetCloseHandle(session);
	}

	void Http::httpRequestAlternate(bool isPost, std::istream& data, bool compressData, const char* additionalHeaders, std::string& response)
	{
		if (url.size() == 0)
			throw std::runtime_error("empty url");

		if (!Http::trustCheck(url.c_str()))
			throw std::runtime_error(G3D::format("trust check failed for %s", url.c_str()));

		ATL::CUrl crack;
		crack.CrackUrl(url.c_str());

		if (crack.GetHostNameLength() == 0)
			throw std::runtime_error(G3D::format("'%s' is missing a hostName", url.c_str()));

		HINTERNET session = InternetOpenA("Roblox", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

		HINTERNET connection = InternetConnectA(session,
			crack.GetHostName(),
			crack.GetPortNumber(),
			crack.GetUserNameA(),
			crack.GetPassword(),
			INTERNET_SERVICE_HTTP,
			0,
			TRUE);

		{
			ATL::CString s = crack.GetUrlPath();
			s += crack.GetExtraInfo();

			HINTERNET request = HttpOpenRequestA(
				connection,
				isPost ? "POST" : "GET",
				s.GetString(),
				NULL,
				NULL,
				NULL,
				INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NEED_FILE,
				TRUE);

			if (!request)
				throw std::runtime_error(G3D::format("HttpOpenRequest failed for %s", url.c_str()));

			if (additionalHeaders)
			{
				if (!HttpAddRequestHeadersA(request, additionalHeaders, (int)strlen(additionalHeaders), HTTP_ADDREQ_FLAG_ADD))
					ThrowIfFailure(false, "HttpAddRequestHeaders failed");
			}

			if (!HttpAddRequestHeadersA(request, "Accept-Encoding: gzip\r\n", (int)strlen("Accept-Encoding: gzip\r\n"), HTTP_ADDREQ_FLAG_ADD))
				ThrowIfFailure(false, "HttpAddRequestHeaders failed");

			{
				boost::iostreams::gzip_params gzipParams(boost::iostreams::zlib::default_compression);

				if (isPost)
				{
					std::string uploadData;

					{
						boost::iostreams::filtering_stream<boost::iostreams::output> out;

						if (compressData)
						{
							std::string contentEncodingHeader = "Content-Encoding: gzip\r\n";
							if (!HttpAddRequestHeadersA(request, contentEncodingHeader.c_str(), (int)contentEncodingHeader.size(), HTTP_ADDREQ_FLAG_ADD))
								ThrowIfFailure(false, "HttpAddRequestHeaders failed");

							out.push(boost::iostreams::basic_gzip_compressor<>(gzipParams));
						}

						out.push(String_sink(uploadData));
						boost::iostreams::copy(data, out);
					}

					int headerLength = (int)uploadData.size();

					INTERNET_BUFFERSA buffers = {0};
					buffers.dwStructSize = sizeof(INTERNET_BUFFERSA);
					if (!HttpSendRequestExA(request, &buffers, NULL, 0, TRUE))
						throw std::runtime_error("HttpSendRequestEx failed");

					DWORD bytesWritten;
					if (!InternetWriteFile(request, uploadData.c_str(), headerLength, &bytesWritten))
						ThrowIfFailure(false, "InternetWriteFile failed");

					if (bytesWritten != headerLength)
						throw std::runtime_error("Failed to upload content");

					if (!HttpEndRequestA(request, NULL, 0, TRUE))
						ThrowIfFailure(false, "HttpEndRequest failed");
				}
				else
				{
					if (!HttpSendRequestA(request, NULL, 0, NULL, 0))
						ThrowIfFailure(false, "HttpSendRequest failed");
				}

				int statusCode;
				{
					char buffer[80];
					DWORD length = sizeof(buffer);
					if (!HttpQueryInfoA(request, HTTP_QUERY_STATUS_CODE, buffer, &length, NULL))
						ThrowIfFailure(false, "HttpQueryInfo failed");
					statusCode = atol(buffer);
				}

				{
					boost::iostreams::filtering_stream<boost::iostreams::input> in;

					char buffer[256];
					DWORD length = sizeof(buffer);
					if (HttpQueryInfoA(request, HTTP_QUERY_CONTENT_ENCODING, buffer, &length, NULL))
					{
						if (std::string(buffer) == "gzip")
							in.push(boost::iostreams::basic_gzip_decompressor<>());
					}

					in.push(HttpRequest_source(request));
					boost::iostreams::copy(in, String_sink(response));
				}

				if (statusCode != 200)
					throw std::runtime_error(G3D::format("statusCode = %d", statusCode));
			}

			InternetCloseHandle(request);
		}

		InternetCloseHandle(connection);
		InternetCloseHandle(session);
	}

	bool Http::isScript(const char* url)
	{
		ATL::CUrl crack;
		crack.CrackUrl(url);
		if (crack.GetScheme() == ATL_URL_SCHEME_FTP || (crack.GetScheme() > ATL_URL_SCHEME_GOPHER && crack.GetScheme() <= ATL_URL_SCHEME_HTTPS))
			return false;

		ATL::CString sUrl(url);
		if (sUrl.Find("javascript:") == 0)
			return true;
		if (sUrl.Find("jscript:") == 0)
			return true;

		return false;
	}

	bool Http::isRobloxSite(const char* url)
	{
		ATL::CUrl crack;
		crack.CrackUrl(url);
		if (crack.GetScheme() != ATL_URL_SCHEME_FTP && (crack.GetScheme() <= ATL_URL_SCHEME_GOPHER && crack.GetScheme() > ATL_URL_SCHEME_HTTPS))
			return false;

		ATL::CString hostName = crack.GetHostName();
		hostName.MakeLower();
		if (hostName.Right((int)strlen("roblox.com")) == "roblox.com")
			return true;
		if (hostName.Right((int)strlen("72.32.62.210")) == "72.32.62.210")
			return true;
		if (hostName.Right((int)strlen("robloxopolis.com")) == "robloxopolis.com")
			return true;

		return false;
	}

	static boost::mutex trustCheckMutex;

	bool Http::trustCheck(const char* url)
	{
		{
			boost::mutex::scoped_lock lock(trustCheckMutex);

			static boost::scoped_ptr<bool> skipTrustCheck;
			if (!skipTrustCheck)
			{
				DWORD data;

				ATL::CRegKey key;
				if (key.Open(HKEY_CURRENT_USER, "Software\\ROBLOX Corporation\\Roblox", KEY_READ) == ERROR_SUCCESS)
					key.QueryDWORDValue("SkipTrustCheck", data);

				if (key.Open(HKEY_LOCAL_MACHINE, "Software\\Roblox", KEY_READ) == ERROR_SUCCESS)
					key.QueryDWORDValue("SkipTrustCheck", data);

				skipTrustCheck.reset(new bool(data == TRUE));
			}

			if (*skipTrustCheck)
				return true;
		}

		if (ATL::CString("about:blank") == url)
			return true;

		if (isRobloxSite(url))
			return true;

		if (isScript(url))
			return true;

		ATL::CString sUrl(url);
		if (sUrl.Find("res:") == 0)
			return true;

		return false;
	}

	void Http::get(std::string& response)
	{
		const char* h = NULL;
		if (!additionalHeaders.empty())
			h = additionalHeaders.c_str();

		std::istringstream dummy;

		try
		{
			if (mode == 0)
				httpRequest(false, dummy, false, h, response);
			else if (mode == 1)
				httpRequestAlternate(false, dummy, false, h, response);
		}
		catch (...)
		{
			if (mode == 0)
				httpRequest(false, dummy, false, h, response);
			else if (mode == 1)
				httpRequestAlternate(false, dummy, false, h, response);
		}
	}

	void Http::post(std::istream& input, bool compress, std::string& response)
	{
		if (additionalHeaders.empty())
		{
			if (mode == 0)
				httpRequest(true, input, compress, NULL, response);
			else if (mode == 1)
				httpRequestAlternate(true, input, compress, NULL, response);
		}
		else
		{
			const char* h = additionalHeaders.c_str();

			if (mode == 0)
				httpRequest(true, input, compress, h, response);
			else if (mode == 1)
				httpRequestAlternate(true, input, compress, h, response);
		}
	}
}
