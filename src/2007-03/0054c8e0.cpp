// from server: 100% by colin
// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp

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
template class boost::iostreams::detail::indirect_streambuf<class WiniInetRequest_source,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::input>;
template class boost::iostreams::detail::indirect_streambuf<struct String_sink,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::output>;
template class boost::iostreams::stream_buffer<class WinHttpRequest_source,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::input>;
template class boost::iostreams::stream_buffer<struct String_sink,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::output>;
