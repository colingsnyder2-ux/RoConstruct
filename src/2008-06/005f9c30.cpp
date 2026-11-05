// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_0f3b7fe0909768d5.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#define _CPPUNWIND 1
#include "roc_espeon_atl90installedaliases16e7a3b08ad00c2a.cpp"
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
extern char nativeAcceptEncodingHeader[];
struct NativeInternetHandle {
 HINTERNET value;
 NativeInternetHandle(HINTERNET v):value(v){}
 ~NativeInternetHandle(){InternetCloseHandle(value);}
 operator HINTERNET()const{return value;}
};
class NativeHttp:public Http {public:void request(bool,std::istream&,bool,const char*,std::string&);void failure(bool,const char*);};
void NativeHttp::request(bool isPost,std::istream& data,bool compressData,const char* additionalHeaders,std::string& response) {
 int status;
 if(url.size()==0)throw std::runtime_error("empty url");
 if(!Http::trustCheck(url.c_str()))throw std::runtime_error(G3D::format("trust check failed for %s",url.c_str()));
 ATL::CUrl crack;crack.CrackUrl(url.c_str());
 if(crack.GetHostNameLength()==0)throw std::runtime_error(G3D::format("'%s' is missing a hostName",url.c_str()));
 NativeInternetHandle session=InternetOpenA("Roblox/WinInet",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
 {
 NativeInternetHandle connection=InternetConnectA(session,crack.GetHostName(),crack.GetPortNumber(),crack.GetUserNameA(),crack.GetPassword(),INTERNET_SERVICE_HTTP,0,TRUE);
 {
 ATL::CStringA path=crack.GetUrlPath();path+=crack.GetExtraInfo();
 NativeInternetHandle request=HttpOpenRequestA(connection,isPost?"POST":"GET",path.GetString(),NULL,NULL,NULL,INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_KEEP_CONNECTION|INTERNET_FLAG_NEED_FILE,TRUE);
 {
 if(!request)throw std::runtime_error(G3D::format("HttpOpenRequest failed for %s",url.c_str()));
 if(additionalHeaders)failure(HttpAddRequestHeadersA(request,additionalHeaders,(int)strlen(additionalHeaders),HTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
 failure(HttpAddRequestHeadersA(request,nativeAcceptEncodingHeader,(int)strlen(nativeAcceptEncodingHeader),HTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
 boost::iostreams::gzip_params gzipParams(boost::iostreams::zlib::default_compression);
 if(!isPost)failure(HttpSendRequestA(request,NULL,0,NULL,0)==TRUE,"HttpSendRequest failed");
 else {
  std::string uploadData;
  try {
   boost::iostreams::filtering_stream<boost::iostreams::output> out;
   if(compressData) {
    std::string contentEncodingHeader="Content-Encoding: gzip\r\n";
    failure(HttpAddRequestHeadersA(request,contentEncodingHeader.c_str(),(int)contentEncodingHeader.size(),HTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
    out.push(boost::iostreams::basic_gzip_compressor<>(gzipParams));
   }
   out.push(String_sink(uploadData));boost::iostreams::copy(data,out);
 } catch(boost::iostreams::gzip_error& e) { int error=e.error(); int zlibError=e.zlib_error_code(); throw std::runtime_error(G3D::format("Upload GZip error %d, ZLib error %d, \"%s\"",error,zlibError,url.c_str())); }
  size_t length=uploadData.size();
  if(length>10000) {
   std::string sizeHeader=G3D::format("Roblox-Content-Size: %d\r\n",length);
   failure(HttpAddRequestHeadersA(request,sizeHeader.c_str(),(int)sizeHeader.size(),HTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
   std::string firstHeader=G3D::format("Roblox-Content-First: %d\r\n",uploadData[0]);
   failure(HttpAddRequestHeadersA(request,firstHeader.c_str(),(int)firstHeader.size(),HTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
   std::string lastHeader=G3D::format("Roblox-Content-Last: %d\r\n",uploadData.c_str()[length-1]);
   failure(HttpAddRequestHeadersA(request,lastHeader.c_str(),(int)lastHeader.size(),HTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
   boost::scoped_ptr<MD5Hasher> hasher(MD5Hasher::create());hasher->addData(uploadData);
   std::string hashHeader=G3D::format("Roblox-Content-Hash: %s\r\n",hasher->c_str());
   failure(HttpAddRequestHeadersA(request,hashHeader.c_str(),(int)hashHeader.size(),HTTP_ADDREQ_FLAG_ADD)==TRUE,"HttpAddRequestHeaders failed");
  }
  {
  INTERNET_BUFFERSA buffers;memset(&buffers,0,sizeof(buffers));buffers.dwStructSize=sizeof(buffers);buffers.dwBufferTotal=length;
  if(!HttpSendRequestExA(request,&buffers,NULL,0,0))throw std::runtime_error("HttpSendRequestEx failed");
  }
  try {
  DWORD written;
  failure(InternetWriteFile(request,uploadData.c_str(),length,&written)==TRUE,"InternetWriteFile failed");
  if(written!=length)throw std::runtime_error("Failed to upload content");
  } catch(std::exception&) { HttpEndRequestA(request,NULL,0,0);throw; }
  failure(HttpEndRequestA(request,NULL,0,0)==TRUE,"HttpEndRequest failed");

 }
 {DWORD length=sizeof(status);
 failure(HttpQueryInfoA(request,HTTP_QUERY_STATUS_CODE|HTTP_QUERY_FLAG_NUMBER,&status,&length,NULL)==TRUE,"HttpQueryInfo failed");}
 try {
  boost::iostreams::filtering_stream<boost::iostreams::input> in;
  char buffer[256];DWORD length=sizeof(buffer);
  if(HttpQueryInfoA(request,HTTP_QUERY_CONTENT_ENCODING,buffer,&length,NULL))if(std::string(buffer)=="gzip")in.push(boost::iostreams::basic_gzip_decompressor<>());
  in.push(HttpRequest_source(request));boost::iostreams::copy(in,String_sink(response));
 } catch(boost::iostreams::gzip_error& e) { int error=e.error(); int zlibError=e.zlib_error_code(); throw std::runtime_error(G3D::format("GZip error %d, ZLib error %d, \"%s\"",error,zlibError,url.c_str())); }
 catch(boost::iostreams::zlib_error& e) { int error=e.error(); throw std::runtime_error(G3D::format("ZLib error %d, \"%s\"",error,url.c_str())); }
 if(status!=200) {
  char buffer[512];DWORD length=sizeof(buffer);
  if(HttpQueryInfoA(request,HTTP_QUERY_STATUS_TEXT,buffer,&length,NULL))throw std::runtime_error(buffer);
  else throw std::runtime_error(G3D::format("statusCode = %d",status));
 }
 }
 }
 }

}
}

namespace RBX { char nativeAcceptEncodingHeader[]="Accept-Encoding: gzip\r\n"; }


