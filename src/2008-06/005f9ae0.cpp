// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_ca18cb6bd8223514.cpp

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
template int boost::iostreams::detail::copy_impl<class boost::reference_wrapper<class std::basic_istream<char,struct std::char_traits<char> > >,class boost::reference_wrapper<class boost::iostreams::filtering_stream<struct boost::iostreams::output,char,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::public_> > >(class boost::reference_wrapper<class std::basic_istream<char,struct std::char_traits<char> > > &,class boost::reference_wrapper<class boost::iostreams::filtering_stream<struct boost::iostreams::output,char,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::public_> > &,int,struct boost::mpl::bool_<0>,struct boost::mpl::bool_<0>);
template void boost::iostreams::detail::chain_base<class boost::iostreams::chain<struct boost::iostreams::input,char,struct std::char_traits<char>,class std::allocator<char> >,char,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::input>::push_impl<class WinHttpRequest_source>(class WinHttpRequest_source const &,int,int);
template void boost::iostreams::detail::chain_base<class boost::iostreams::chain<struct boost::iostreams::input,char,struct std::char_traits<char>,class std::allocator<char> >,char,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::input>::push_impl<class WiniInetRequest_source>(class WiniInetRequest_source const &,int,int);
template void boost::iostreams::detail::chain_base<class boost::iostreams::chain<struct boost::iostreams::output,char,struct std::char_traits<char>,class std::allocator<char> >,char,struct std::char_traits<char>,class std::allocator<char>,struct boost::iostreams::output>::push_impl<struct String_sink>(struct String_sink const &,int,int);
