// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_ff34cd40c82265d7.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#include "roc_espeon_atl90installedaliases16e7a3b08ad00c2a.cpp"
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
		if (!WinHttpQueryDataAvailable(request, &numBytes))
			return -1;
		if (numBytes == 0)
			return -1;

		DWORD bytesRead;
		if (!WinHttpReadData(request, s, n, &bytesRead))
			throw std::runtime_error("WinHttpReadData failed");

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


namespace RBX {
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
struct NativeInternetHandle {
 HINTERNET value;
 NativeInternetHandle(HINTERNET v):value(v){}
 ~NativeInternetHandle(){WinHttpCloseHandle(value);}
 operator HINTERNET()const{return value;}
};
class NativeHttp:public Http {public:void requestWinHttp(bool,std::istream&,bool,const char*,std::string&);void failure(bool,const char*);};
void NativeHttp::requestWinHttp(bool isPost,std::istream& data,bool compressData,const char* additionalHeaders,std::string& response) {
 if(url.size()==0)throw std::runtime_error("empty url");
 if(!Http::trustCheck(url.c_str()))throw std::runtime_error(G3D::format("trust check failed for %s",url.c_str()));
 ATL::CUrl crack;crack.CrackUrl(url.c_str());
 if(crack.GetHostNameLength()==0)throw std::runtime_error(G3D::format("'%s' is missing a hostName",url.c_str()));
 NativeInternetHandle session=WinHttpOpen(L"Roblox/WinHttp",WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,NULL,NULL,0);
 {
 failure(session!=NULL,"WinHttpOpen");
 bool secure=crack.GetScheme()==ATL_URL_SCHEME_HTTPS;
 NativeInternetHandle connection=WinHttpConnect(session,ATL::CComBSTR(ATL::CStringA(crack.GetHostName())),crack.GetPortNumber(),0);
 {
 failure(connection!=NULL,"WinHttpConnect");
 std::string path=crack.GetUrlPath();path+=crack.GetExtraInfo();
 NativeInternetHandle request=WinHttpOpenRequest(connection,isPost?L"POST":L"GET",ATL::CComBSTR(path.c_str()),NULL,NULL,NULL,secure?WINHTTP_FLAG_SECURE:0);

 failure(request!=NULL,"WinHttpOpenRequest");
 if(additionalHeaders)failure(WinHttpAddRequestHeaders(request,ATL::CComBSTR(additionalHeaders),-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"WinHttpAddRequestHeaders");
 failure(WinHttpAddRequestHeaders(request,L"Accept-Encoding: gzip\r\n",-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"WinHttpAddRequestHeaders failed");
 boost::iostreams::gzip_params gzipParams(boost::iostreams::zlib::default_compression);
 if(!isPost) failure(WinHttpSendRequest(request,NULL,0,NULL,0,0,0)==TRUE,"WinHttpSendRequest failed");
 else {
  std::string uploadData;
  try {
   boost::iostreams::filtering_stream<boost::iostreams::output> out;
   if(compressData) {
    failure(WinHttpAddRequestHeaders(request,L"Content-Encoding: gzip\r\n",-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
    out.push(boost::iostreams::basic_gzip_compressor<>(gzipParams));
   }
   out.push(String_sink(uploadData));boost::iostreams::copy(data,out);
  } catch(boost::iostreams::gzip_error& e) { int err=e.error(); int zerr=e.zlib_error_code(); throw std::runtime_error(G3D::format("Upload GZip error %d, ZLib error %d, \"%s\"",err,zerr,url.c_str())); }
  std::string::size_type length=uploadData.size();
  if(length>10000) {
   std::string sizeHeader=G3D::format("Roblox-Content-Size: %d\r\n",length);
   failure(WinHttpAddRequestHeaders(request,ATL::CComBSTR(sizeHeader.c_str()),-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"WinHttpAddRequestHeaders failed");
   boost::scoped_ptr<MD5Hasher> hasher(MD5Hasher::create());hasher->addData(uploadData);
   std::string hashHeader=G3D::format("Roblox-Content-Hash: %s\r\n",hasher->c_str());
   failure(WinHttpAddRequestHeaders(request,ATL::CComBSTR(hashHeader.c_str()),-1,WINHTTP_ADDREQ_FLAG_ADD)==TRUE,"WinHttpAddRequestHeaders failed");
  }
  failure(WinHttpSendRequest(request,NULL,0,(void*)uploadData.c_str(),length,length,0)==TRUE,"WinHttpSendRequest failed");
 }
 failure(WinHttpReceiveResponse(request,NULL)==TRUE,"WinHttpReceiveResponse");
 try {
  boost::iostreams::filtering_stream<boost::iostreams::input> in;
  WCHAR buffer[256];DWORD length=256;
  if(WinHttpQueryHeaders(request,WINHTTP_QUERY_CONTENT_ENCODING,NULL,buffer,&length,NULL))if(ATL::CStringA(buffer)=="gzip")in.push(boost::iostreams::basic_gzip_decompressor<>());
  in.push(HttpRequest_source(request));boost::iostreams::copy(in,String_sink(response));
 } catch(boost::iostreams::gzip_error& e) { int err=e.error(); int zerr=e.zlib_error_code(); throw std::runtime_error(G3D::format("GZip error %d, ZLib error %d, \"%s\"",err,zerr,url.c_str())); }
 catch(boost::iostreams::zlib_error& e) { int err=e.error(); throw std::runtime_error(G3D::format("ZLib error %d, \"%s\"",err,url.c_str())); }
 int status=-1;
 { DWORD length=sizeof(status);
 failure(WinHttpQueryHeaders(request,WINHTTP_QUERY_STATUS_CODE|WINHTTP_QUERY_FLAG_NUMBER,NULL,&status,&length,NULL)==TRUE,"WinHttpQueryHeaders");
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
