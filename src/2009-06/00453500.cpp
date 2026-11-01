// from server: 86% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_3ebabcdd84449057.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <memory>
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct Pool{char cs[0x18];void*freeList;};
Pool*getPool();
extern long g_resourceCount;
struct Resource{~Resource();
static void operator delete(void*p){Pool*pool=getPool();EnterCriticalSection(pool);*(void**)p=pool->freeList;pool->freeList=p;LeaveCriticalSection(pool);InterlockedDecrement(&g_resourceCount);}};
struct Workspace{char prefix[0x9c];int active;void setActive(int);};
struct Service{void stop();};
struct Model{char prefix[0x20c];Service*service;Workspace*workspace();void reset();};
struct Holder{boost::shared_ptr<Model>get();};
struct Guard{int storage;Guard(boost::shared_ptr<Model>,bool);~Guard();};
template<class T>struct AutoPtr{T*p_;T*get()const{return p_;}__declspec(noinline) void reset(T*p=0){if(p!=p_)delete p_;p_=p;}};
extern void detach(Resource*,Model*);
inline Workspace*workspaceOf(const boost::shared_ptr<Model>&m){return m?m->workspace():0;}
struct Doc{char prefix[0x74];AutoPtr<Resource>resource;char gap[0x24];Holder*holder;boost::shared_ptr<Model>getModel();void stop();};
void Doc::stop(){Guard guard(holder->get(),true);if(getModel()->workspace()->active!=0){workspaceOf(getModel())->setActive(0);getModel()->reset();detach(resource.get(),getModel().get());getModel()->service->stop();resource.reset();}}
