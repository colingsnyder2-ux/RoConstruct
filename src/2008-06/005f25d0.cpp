// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 client-rtti-20d7263f39baa3c2210d.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG
#include <string>
#include <vector>
#include <windows.h>
extern "C" {
__declspec(dllimport) BOOL __stdcall WinHttpQueryDataAvailable(void*,DWORD*);
__declspec(dllimport) BOOL __stdcall WinHttpReadData(void*,void*,DWORD,DWORD*);
__declspec(dllimport) BOOL __stdcall InternetQueryDataAvailable(void*,DWORD*,DWORD,DWORD_PTR);
__declspec(dllimport) BOOL __stdcall InternetReadFile(void*,void*,DWORD,DWORD*);
}
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/signal.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/device/null.hpp>
#include <boost/iostreams/stream_buffer.hpp>
class WinHttpRequest_source : public boost::iostreams::device<boost::iostreams::input>
{ void* request; public: WinHttpRequest_source(void* r):request(r){}
 int read(char* s,int n){DWORD a;if(!WinHttpQueryDataAvailable(request,&a))goto fail;if(a==0)goto fail;DWORD b;if(!WinHttpReadData(request,s,n,&b))throw std::runtime_error("InternetReadFile failed");return b;fail:return -1;} };
class WiniInetRequest_source : public boost::iostreams::device<boost::iostreams::input>
{ void* request; public: WiniInetRequest_source(void* r):request(r){}
 int read(char* s,int n){DWORD a;if(!InternetQueryDataAvailable(request,&a,0,NULL))goto fail;if(a==0)goto fail;DWORD b;if(!InternetReadFile(request,s,n,&b))throw std::runtime_error("InternetReadFile failed");return b;fail:return -1;} };
struct String_sink : public boost::iostreams::device<boost::iostreams::output>
{ std::string& s; String_sink(std::string& x):s(x){} int write(const char* c,int n){s.append(c,n);return n;} };
template class boost::iostreams::detail::indirect_streambuf<class boost::iostreams::basic_null_device<char,struct boost::iostreams::output>,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::output>;
