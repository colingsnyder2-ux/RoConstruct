// from server: 94% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Hostent { char* h_name; char** h_aliases; short h_addrtype; short h_length; char** h_addr_list; };
struct InAddr { unsigned long s; };
extern "C" __declspec(dllimport) Hostent* __stdcall gethostbyname(const char*);
extern "C" __declspec(dllimport) char* __stdcall inet_ntoa(unsigned long);
extern "C" __declspec(dllimport) char* __stdcall inet_ntoa2(InAddr);
char* f(const char* name){ Hostent* h = gethostbyname(name); if (h && h->h_addr_list[0]) return inet_ntoa(*(unsigned long*)h->h_addr_list[0]); return 0; }
