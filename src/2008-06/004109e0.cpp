// from server: 100% by EspClaude
// from server: 98% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-strlen roc_espclaude_ae7d75913e3dc6d1.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
#include <list>
#include <string>
extern "C" int __stdcall CheckNetwork(DWORD*);
extern bool IsSpecialURL(const char*);
struct Browser{char prefix[252];std::list<std::string>history;void Navigate(const char*,void*,const char*,void*,void*,void*);void BaseNavigate(const char*,void*,void*,void*,void*,int*);void OnNavigate(const char*,void*,void*,void*,void*,int*);};
void Browser::OnNavigate(const char*url,void*a,void*b,void*c,void*d,int*handled){char path[260];DWORD network=0;if(!CheckNetwork(&network)||network==0){HMODULE module=AfxGetModuleState()->m_hCurrentResourceHandle;if(::GetModuleFileNameA(module,path,260)){CStringA resource;resource.Format("res://%s/%d",path,215);if(resource.Compare(url)){Navigate(resource,0,0,0,0,0);*handled=1;return;}}}BaseNavigate(url,a,b,c,d,handled);if(*handled){Navigate(url,0,"_blank",0,0,0);return;}CStringA saved(url);if(!IsSpecialURL(url)){{std::string value(url);history.push_back(value);}if(history.size()>50)history.pop_front();}}

