// from server: 100% by coldek
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Minimal target-backed ABI views; unused native APIs and prefix fields are omitted.
// Lua declarations use the C++ linkage of the bundled client headers.
// errorString is a descriptive label for the measured two-argument safe conversion helper.
#include <string>
#include <vector>
#include <stdexcept>
#include <intrin.h>
#include <utility>
#include <stddef.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    sp_counted_base():use_count_(1),weak_count_(1){}
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
template<class Y>struct sp_counted_impl_p:sp_counted_base {Y*pointer;explicit sp_counted_impl_p(Y*p):pointer(p){}void dispose(){delete pointer;}};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
namespace detail {inline void sp_enable_shared_from_this(const shared_count&,...) {}}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> __declspec(noinline) shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}



struct lua_State;
lua_State* __cdecl lua_newthread(lua_State*);void __cdecl lua_createtable(lua_State*,int,int);void __cdecl lua_pushlstring(lua_State*,const char*,unsigned);void __cdecl lua_pushvalue(lua_State*,int);
 void __cdecl lua_settable(lua_State*,int);int __cdecl lua_setmetatable(lua_State*,int);void __cdecl lua_replace(lua_State*,int);void __cdecl lua_setfield(lua_State*,int,const char*);void __cdecl lua_settop(lua_State*,int);
 int __cdecl luaL_loadbuffer(lua_State*,const char*,unsigned,const char*);
namespace G3D {std::string __cdecl format(const char*,...);}
namespace RBX {
namespace Reflection {struct DescribedBase {virtual ~DescribedBase();void*opaque;void*descriptor;};}
struct PrimaryInstance {virtual ~PrimaryInstance();char opaque[12];};struct FactoryProduct {virtual ~FactoryProduct();};
template<class T>struct Association {struct Item;std::vector<Item*>items;template<class U>U&get();};
struct Instance:PrimaryInstance,FactoryProduct,Reflection::DescribedBase {
 char opaque[0xec-0x20];Association<Instance>assoc;char opaque104[0x110-0x104];std::string name;
 Association<Instance>&association(){return assoc;}const std::string&getName()const{return name;}std::string getFullName()const;
};
struct Script:Instance {boost::shared_ptr<const std::string>requestCode();};
namespace Security {enum Identities{Anonymous,LocalGUI,GameScript,CmdLine,TrustedCOM,TrustedWebService,Replicator};}
enum MessageType{MESSAGE_OUTPUT,MESSAGE_INFO,MESSAGE_WARNING,MESSAGE_ERROR};
struct StandardOut {static boost::shared_ptr<StandardOut>singleton();void __cdecl print(MessageType,const char*,...);};
namespace Lua {
struct ScopedPopper {int popCount;lua_State*thread;ScopedPopper(lua_State*L,int n):popCount(n),thread(L){}~ScopedPopper(){lua_settop(thread,-popCount-1);}};
struct ThreadRef {struct Node {static boost::shared_ptr<Node>create(lua_State*);};typedef boost::shared_ptr<Node>NodePtr;};
struct ObjectBridge {static void push(lua_State*,boost::shared_ptr<Reflection::DescribedBase>);};
const char* __cdecl errorString(lua_State*,int);
}
struct ScriptContext {
 char opaque[0x138];lua_State*globalState;char opaque13c[0x188-0x13c];std::vector<boost::shared_ptr<Script> >pendingScripts;char opaque1a0[0x1ac-0x1a0];bool scriptsDisabled;
 enum Result{Success,Yield,Error};void openState();static void __cdecl setThreadIdentity(lua_State*,Security::Identities);Result resume(lua_State*,int);void startScript(boost::shared_ptr<Script>);
};
void ScriptContext::startScript(boost::shared_ptr<Script>script){
 if(scriptsDisabled){pendingScripts.push_back(script);return;}
 boost::shared_ptr<const std::string>code=script->requestCode();
 if(!code){pendingScripts.push_back(script);return;}
 openState();lua_State*thread=lua_newthread(globalState);
 if(!thread)throw std::runtime_error(G3D::format("Unable to create a new thread for %s",script->getName().c_str()));
 Lua::ScopedPopper popper(globalState,1);
 lua_createtable(thread,0,0);lua_createtable(thread,0,0);lua_pushlstring(thread,"__index",7);lua_pushvalue(thread,-10002);lua_settable(thread,-3);lua_setmetatable(thread,-2);lua_replace(thread,-10002);
 setThreadIdentity(thread,Security::GameScript);
 script->association().get<Lua::ThreadRef::NodePtr>()=Lua::ThreadRef::Node::create(thread);
 Lua::ObjectBridge::push(thread,script);lua_setfield(thread,-10002,"script");
 std::string name=std::string("=")+script->getFullName();
 int result=luaL_loadbuffer(thread,code->c_str(),code->length(),name.c_str());
 if(result){
  StandardOut::singleton()->print(MESSAGE_ERROR,Lua::errorString(thread,-1));lua_settop(thread,-2);
 }else resume(thread,0);
 lua_settop(thread,0);
}
}
typedef char pending_offset[offsetof(RBX::ScriptContext,pendingScripts)==0x188?1:-1];
typedef char disabled_offset[offsetof(RBX::ScriptContext,scriptsDisabled)==0x1ac?1:-1];
typedef char association_offset[offsetof(RBX::Instance,assoc)==0xec?1:-1];
typedef char instance_name_offset[offsetof(RBX::Instance,name)==0x110?1:-1];
typedef char shared_size[sizeof(boost::shared_ptr<RBX::Script>)==8?1:-1];
