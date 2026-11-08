// Request and read bodies match; other stream helpers and runtime ABI remain unverified.
// >>> native-status (generated) -- do not edit >>>
// HttpWinHttp | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 2acebad0 | roc native-status --write
#define NDEBUG 1
#include <shlwapi.h>
#include "util/ContentProvider.h"
#define NDEBUG 1
// Native CString comparison569d30 imports _mbscmp.
#define _MBCS 1
// /EHsc prelude is required before the library preprocessor.
#define _CPPUNWIND 1
#define _SCL_SECURE_NO_DEPRECATE // required to disable a warning
#include "util/Http.h"
#include <windows.h>
#include <atlutil.h>
#include <winhttp.h>
#include <sstream>
#include <G3D/format.h>
#include <boost/scoped_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>

class WinHttpRequest_source : public boost::iostreams::device<boost::iostreams::input>
{
private:
	void* request;

public:
	WinHttpRequest_source(void* request)
		: request(request)
	{
	}
public:
	int read(char* s, int n)
	{
		DWORD numBytes;
		if (!WinHttpQueryDataAvailable(request, &numBytes))
			goto fail;
		if (numBytes == 0)
			goto fail;

		DWORD bytesRead;
		if (!WinHttpReadData(request, s, n, &bytesRead))
			throw std::runtime_error("InternetReadFile failed");

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
	// NOTE: not checked
	int write(const char* c, int n)
	{
		s.append(c, n);
		return n;
	}
};


namespace RBX {
struct WinHttpHandle {
 HINTERNET value;
 WinHttpHandle(HINTERNET v):value(v){}
 ~WinHttpHandle(){WinHttpCloseHandle(value);}
 operator HINTERNET()const{return value;}
};
void Http::httpRequestAlternate(bool isPost,std::istream& data,bool compressData,const char* additionalHeaders,std::string& response) {
 if(url.size()==0)throw std::runtime_error("empty url");
 if(!Http::trustCheck(url.c_str()))throw std::runtime_error(G3D::format("trust check failed for %s",url.c_str()));
 ATL::CUrl crack;crack.CrackUrl(url.c_str());
 if(crack.GetHostNameLength()==0)throw std::runtime_error(G3D::format("'%s' is missing a hostName",url.c_str()));
 WinHttpHandle session=WinHttpOpen(L"Roblox/WinHttp",WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,NULL,NULL,0);
 {
 checkHttpResult(session!=NULL,"WinHttpOpen");
 bool secure=crack.GetScheme()==ATL_URL_SCHEME_HTTPS;
 WinHttpHandle connection=WinHttpConnect(session,ATL::CComBSTR(ATL::CStringA(crack.GetHostName())),crack.GetPortNumber(),0);
 {
 checkHttpResult(connection!=NULL,"WinHttpConnect");
 std::string path=crack.GetUrlPath();path+=crack.GetExtraInfo();
 WinHttpHandle request=WinHttpOpenRequest(connection,isPost?L"POST":L"GET",ATL::CComBSTR(path.c_str()),NULL,NULL,NULL,secure?WINHTTP_FLAG_SECURE:0);

 checkHttpResult(request!=NULL,"WinHttpOpenRequest");
 if(additionalHeaders)checkHttpResult(WinHttpAddRequestHeaders(request,ATL::CComBSTR(additionalHeaders),-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"WinHttpAddRequestHeaders");
 checkHttpResult(WinHttpAddRequestHeaders(request,L"Accept-Encoding: gzip\r\n",-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"WinHttpAddRequestHeaders failed");
 boost::iostreams::gzip_params gzipParams(boost::iostreams::zlib::default_compression);
 if(!isPost) checkHttpResult(WinHttpSendRequest(request,NULL,0,NULL,0,0,0)==TRUE,"WinHttpSendRequest failed");
 else {
  std::string uploadData;
  try {
   boost::iostreams::filtering_stream<boost::iostreams::output> out;
   if(compressData) {
    checkHttpResult(WinHttpAddRequestHeaders(request,L"Content-Encoding: gzip\r\n",-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
    out.push(boost::iostreams::basic_gzip_compressor<>(gzipParams));
   }
   out.push(String_sink(uploadData));boost::iostreams::copy(data,out);
  } catch(boost::iostreams::gzip_error& e) { int err=e.error(); int zerr=e.zlib_error_code(); throw std::runtime_error(G3D::format("Upload GZip error %d, ZLib error %d, \"%s\"",err,zerr,url.c_str())); }
  std::string::size_type length=uploadData.size();
  if(length>10000) {
   std::string sizeHeader=G3D::format("Roblox-Content-Size: %d\r\n",length);
   checkHttpResult(WinHttpAddRequestHeaders(request,ATL::CComBSTR(sizeHeader.c_str()),-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"WinHttpAddRequestHeaders failed");
   boost::scoped_ptr<MD5Hasher> hasher(MD5Hasher::create());hasher->addData(uploadData);
   std::string hashHeader=G3D::format("Roblox-Content-Hash: %s\r\n",hasher->c_str());
   checkHttpResult(WinHttpAddRequestHeaders(request,ATL::CComBSTR(hashHeader.c_str()),-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"WinHttpAddRequestHeaders failed");
  }
  checkHttpResult(WinHttpSendRequest(request,NULL,0,(void*)uploadData.c_str(),length,length,0)==TRUE,"WinHttpSendRequest failed");
 }
 checkHttpResult(WinHttpReceiveResponse(request,NULL)==TRUE,"WinHttpReceiveResponse");
 try {
  boost::iostreams::filtering_stream<boost::iostreams::input> in;
  WCHAR buffer[256];DWORD length=256;
  if(WinHttpQueryHeaders(request,WINHTTP_QUERY_CONTENT_ENCODING,NULL,buffer,&length,NULL))if(ATL::CStringA(buffer)=="gzip")in.push(boost::iostreams::basic_gzip_decompressor<>());
  in.push(WinHttpRequest_source(request));boost::iostreams::copy(in,String_sink(response));
 } catch(boost::iostreams::gzip_error& e) { int err=e.error(); int zerr=e.zlib_error_code(); throw std::runtime_error(G3D::format("GZip error %d, ZLib error %d, \"%s\"",err,zerr,url.c_str())); }
 catch(boost::iostreams::zlib_error& e) { int err=e.error(); throw std::runtime_error(G3D::format("ZLib error %d, \"%s\"",err,url.c_str())); }
 int status=-1;
 { DWORD length=sizeof(status);
 checkHttpResult(WinHttpQueryHeaders(request,WINHTTP_QUERY_STATUS_CODE|WINHTTP_QUERY_FLAG_NUMBER,NULL,&status,&length,NULL)==TRUE,"WinHttpQueryHeaders");
 }
 if(status!=200) {
  WCHAR buffer[512];DWORD length=512;
  if(WinHttpQueryHeaders(request,WINHTTP_QUERY_STATUS_TEXT,NULL,buffer,&length,NULL))throw std::runtime_error(ATL::CStringA(buffer).GetString());
  else throw std::runtime_error(G3D::format("statusCode = %d",status));
 }
 }
 }

}
}
