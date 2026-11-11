// from server: 100% by EspClaude
// from server: 74% by EspClaude
// roc 2007-08 0053ca00  unit: RBX::ScriptContext  size: 1042 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0053ca00
//
// 0053ca00  6aff                 push -1
// 0053ca02  688b107500           push 0x75108b
// 0053ca07  64a100000000         mov eax, dword ptr fs:[0]
// 0053ca0d  50                   push eax
// 0053ca0e  64892500000000       mov dword ptr fs:[0], esp
// 0053ca15  83ec78               sub esp, 0x78
// 0053ca18  53                   push ebx
// 0053ca19  55                   push ebp
// 0053ca1a  56                   push esi
// 0053ca1b  57                   push edi
// 0053ca1c  8bd9                 mov ebx, ecx
// 0053ca1e  80bb4401000000       cmp byte ptr [ebx + 0x144], 0
// 0053ca25  c784249000000000000000 mov dword ptr [esp + 0x90], 0
// 0053ca30  7464                 je 0x53ca96
// 0053ca32  8d842498000000       lea eax, [esp + 0x98]
// 0053ca39  50                   push eax
// 0053ca3a  8d8b28010000         lea ecx, [ebx + 0x128]
// 0053ca40  e8cbd2ffff           call 0x539d10
// 0053ca45  8bb4249c000000       mov esi, dword ptr [esp + 0x9c]
// 0053ca4c  85f6                 test esi, esi
// 0053ca4e  c7842490000000ffffffff mov dword ptr [esp + 0x90], 0xffffffff
// 0053ca59  0f8498030000         je 0x53cdf7
// 0053ca5f  8d4e04               lea ecx, [esi + 4]
// 0053ca62  83caff               or edx, 0xffffffff
// 0053ca65  f00fc111             lock xadd dword ptr [ecx], edx
// 0053ca69  0f8588030000         jne 0x53cdf7
// 0053ca6f  8b06                 mov eax, dword ptr [esi]
// 0053ca71  8b5004               mov edx, dword ptr [eax + 4]
// 0053ca74  8bce                 mov ecx, esi
// 0053ca76  ffd2                 call edx
// 0053ca78  8d4608               lea eax, [esi + 8]
// 0053ca7b  83c9ff               or ecx, 0xffffffff
// 0053ca7e  f00fc108             lock xadd dword ptr [eax], ecx
// 0053ca82  0f856f030000         jne 0x53cdf7
// 0053ca88  8b16                 mov edx, dword ptr [esi]
// 0053ca8a  8b4208               mov eax, dword ptr [edx + 8]
// 0053ca8d  8bce                 mov ecx, esi
// 0053ca8f  ffd0                 call eax
// 0053ca91  e961030000           jmp 0x53cdf7
// 0053ca96  8bac2498000000       mov ebp, dword ptr [esp + 0x98]
// 0053ca9d  55                   push ebp
// 0053ca9e  8d4c2420             lea ecx, [esp + 0x20]
// 0053caa2  51                   push ecx
// 0053caa3  8bcb                 mov ecx, ebx
// 0053caa5  e8869affff           call 0x536530
// 0053caaa  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 0053caaf  c684249000000001     mov byte ptr [esp + 0x90], 1
// 0053cab7  0f859e000000         jne 0x53cb5b
// 0053cabd  8d942498000000       lea edx, [esp + 0x98]
// 0053cac4  52                   push edx
// 0053cac5  8d8b28010000         lea ecx, [ebx + 0x128]
// 0053cacb  e840d2ffff           call 0x539d10
// 0053cad0  8b742420             mov esi, dword ptr [esp + 0x20]
// 0053cad4  85f6                 test esi, esi
// 0053cad6  c684249000000000     mov byte ptr [esp + 0x90], 0
// 0053cade  742a                 je 0x53cb0a
// 0053cae0  8d4604               lea eax, [esi + 4]
// 0053cae3  83c9ff               or ecx, 0xffffffff
// 0053cae6  f00fc108             lock xadd dword ptr [eax], ecx
// 0053caea  751e                 jne 0x53cb0a
// 0053caec  8b16                 mov edx, dword ptr [esi]
// 0053caee  8b4204               mov eax, dword ptr [edx + 4]
// 0053caf1  8bce                 mov ecx, esi
// 0053caf3  ffd0                 call eax
// 0053caf5  8d4e08               lea ecx, [esi + 8]
// 0053caf8  83caff               or edx, 0xffffffff
// 0053cafb  f00fc111             lock xadd dword ptr [ecx], edx
// 0053caff  7509                 jne 0x53cb0a
// 0053cb01  8b06                 mov eax, dword ptr [esi]
// 0053cb03  8b5008               mov edx, dword ptr [eax + 8]
// 0053cb06  8bce                 mov ecx, esi
// 0053cb08  ffd2                 call edx
// 0053cb0a  8bb4249c000000       mov esi, dword ptr [esp + 0x9c]
// 0053cb11  85f6                 test esi, esi
// 0053cb13  c7842490000000ffffffff mov dword ptr [esp + 0x90], 0xffffffff
// 0053cb1e  0f84d3020000         je 0x53cdf7
// 0053cb24  8d4604               lea eax, [esi + 4]
// 0053cb27  83c9ff               or ecx, 0xffffffff
// 0053cb2a  f00fc108             lock xadd dword ptr [eax], ecx
// 0053cb2e  0f85c3020000         jne 0x53cdf7
// 0053cb34  8b16                 mov edx, dword ptr [esi]
// 0053cb36  8b4204               mov eax, dword ptr [edx + 4]
// 0053cb39  8bce                 mov ecx, esi
// 0053cb3b  ffd0                 call eax
// 0053cb3d  8d4e08               lea ecx, [esi + 8]
// 0053cb40  83caff               or edx, 0xffffffff
// 0053cb43  f00fc111             lock xadd dword ptr [ecx], edx
// 0053cb47  0f85aa020000         jne 0x53cdf7
// 0053cb4d  8b06                 mov eax, dword ptr [esi]
// 0053cb4f  8b5008               mov edx, dword ptr [eax + 8]
// 0053cb52  8bce                 mov ecx, esi
// 0053cb54  ffd2                 call edx
// 0053cb56  e99c020000           jmp 0x53cdf7
// 0053cb5b  8bcb                 mov ecx, ebx
// 0053cb5d  e8fef0ffff           call 0x53bc60
// 0053cb62  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0053cb68  50                   push eax
// 0053cb69  e8b21c0800           call 0x5be820
// 0053cb6e  8bf0                 mov esi, eax
// 0053cb70  83c404               add esp, 4
// 0053cb73  85f6                 test esi, esi
// 0053cb75  7555                 jne 0x53cbcc
// 0053cb77  8d4c2414             lea ecx, [esp + 0x14]
// 0053cb7b  51                   push ecx
// 0053cb7c  e82ff80200           call 0x56c3b0
// 0053cb81  83c404               add esp, 4
// 0053cb84  83bde000000010       cmp dword ptr [ebp + 0xe0], 0x10
// 0053cb8b  c684249000000002     mov byte ptr [esp + 0x90], 2
// 0053cb93  7208                 jb 0x53cb9d
// 0053cb95  8badcc000000         mov ebp, dword ptr [ebp + 0xcc]
// 0053cb9b  eb06                 jmp 0x53cba3
// 0053cb9d  81c5cc000000         add ebp, 0xcc
// 0053cba3  8b00                 mov eax, dword ptr [eax]
// 0053cba5  55                   push ebp
// 0053cba6  68245d7a00           push 0x7a5d24
// 0053cbab  6a03                 push 3
// 0053cbad  50                   push eax
// 0053cbae  e8edf40200           call 0x56c0a0
// 0053cbb3  83c410               add esp, 0x10
// 0053cbb6  8d4c2414             lea ecx, [esp + 0x14]
// 0053cbba  c684249000000001     mov byte ptr [esp + 0x90], 1
// 0053cbc2  e89957f5ff           call 0x492360
// 0053cbc7  e903020000           jmp 0x53cdcf
// 0053cbcc  8b83f0000000         mov eax, dword ptr [ebx + 0xf0]
// 0053cbd2  89442410             mov dword ptr [esp + 0x10], eax
// 0053cbd6  c744242401000000     mov dword ptr [esp + 0x24], 1
// 0053cbde  89442428             mov dword ptr [esp + 0x28], eax
// 0053cbe2  6a00                 push 0
// 0053cbe4  6a00                 push 0
// 0053cbe6  56                   push esi
// 0053cbe7  c684249c00000003     mov byte ptr [esp + 0x9c], 3
// 0053cbef  e8ec120800           call 0x5bdee0
// 0053cbf4  6a00                 push 0
// 0053cbf6  6a00                 push 0
// 0053cbf8  56                   push esi
// 0053cbf9  e8e2120800           call 0x5bdee0
// 0053cbfe  6a07                 push 7
// 0053cc00  6874567a00           push 0x7a5674
// 0053cc05  56                   push esi
// 0053cc06  e8a50f0800           call 0x5bdbb0
// 0053cc0b  68eed8ffff           push 0xffffd8ee
// 0053cc10  56                   push esi
// 0053cc11  e82a0b0800           call 0x5bd740
// 0053cc16  6afd                 push -3
// 0053cc18  56                   push esi
// 0053cc19  e8d2130800           call 0x5bdff0
// 0053cc1e  6afe                 push -2
// 0053cc20  56                   push esi
// 0053cc21  e83a150800           call 0x5be160
// 0053cc26  68eed8ffff           push 0xffffd8ee
// 0053cc2b  56                   push esi
// 0053cc2c  e84f0a0800           call 0x5bd680
// 0053cc31  83c444               add esp, 0x44
// 0053cc34  6a02                 push 2
// 0053cc36  56                   push esi
// 0053cc37  e8d4e0ffff           call 0x53ad10
// 0053cc3c  8d54241c             lea edx, [esp + 0x1c]
// 0053cc40  56                   push esi
// 0053cc41  52                   push edx
// 0053cc42  e8a9050300           call 0x56d1f0
// 0053cc47  83c410               add esp, 0x10
// 0053cc4a  8bf8                 mov edi, eax
// 0053cc4c  8d8dac000000         lea ecx, [ebp + 0xac]
// 0053cc52  c684249000000004     mov byte ptr [esp + 0x90], 4
// 0053cc5a  e841ccffff           call 0x5398a0
// 0053cc5f  8b0f                 mov ecx, dword ptr [edi]
// 0053cc61  8908                 mov dword ptr [eax], ecx
// 0053cc63  83c704               add edi, 4
// 0053cc66  57                   push edi
// 0053cc67  8d4804               lea ecx, [eax + 4]
// 0053cc6a  e8f15decff           call 0x402a60
// 0053cc6f  8d4c2414             lea ecx, [esp + 0x14]
// 0053cc73  c684249000000003     mov byte ptr [esp + 0x90], 3
// 0053cc7b  e8e056f5ff           call 0x492360
// 0053cc80  83ec08               sub esp, 8
// 0053cc83  8d9424a0000000       lea edx, [esp + 0xa0]
// 0053cc8a  8bcc                 mov ecx, esp
// 0053cc8c  8964241c             mov dword ptr [esp + 0x1c], esp
// 0053cc90  52                   push edx
// 0053cc91  e86a8dffff           call 0x535a00
// 0053cc96  56                   push esi
// 0053cc97  e8049affff           call 0x5366a0
// 0053cc9c  681c5d7a00           push 0x7a5d1c
// 0053cca1  68eed8ffff           push 0xffffd8ee
// 0053cca6  56                   push esi
// 0053cca7  e874130800           call 0x5be020
// 0053ccac  8d842484000000       lea eax, [esp + 0x84]
// 0053ccb3  55                   push ebp
// 0053ccb4  50                   push eax
// 0053ccb5  e8b673ffff           call 0x534070
// 0053ccba  83c420               add esp, 0x20
// 0053ccbd  8bf8                 mov edi, eax
// 0053ccbf  6870707800           push 0x787070
// 0053ccc4  8d4c2454             lea ecx, [esp + 0x54]
// 0053ccc8  c684249400000005     mov byte ptr [esp + 0x94], 5
// 0053ccd0  ff1598e67700         call dword ptr [0x77e698]
// 0053ccd6  57                   push edi
// 0053ccd7  c684249400000006     mov byte ptr [esp + 0x94], 6
// 0053ccdf  50                   push eax
// 0053cce0  8d4c243c             lea ecx, [esp + 0x3c]
// 0053cce4  51                   push ecx
// 0053cce5  ff1568e57700         call dword ptr [0x77e568]
// 0053cceb  83c40c               add esp, 0xc
// 0053ccee  8d4c2450             lea ecx, [esp + 0x50]
// 0053ccf2  c684249000000008     mov byte ptr [esp + 0x90], 8
// 0053ccfa  ff15ace67700         call dword ptr [0x77e6ac]
// 0053cd00  8d4c246c             lea ecx, [esp + 0x6c]
// 0053cd04  c684249000000009     mov byte ptr [esp + 0x90], 9
// 0053cd0c  ff15ace67700         call dword ptr [0x77e6ac]
// 0053cd12  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0053cd16  ba10000000           mov edx, 0x10
// 0053cd1b  3954244c             cmp dword ptr [esp + 0x4c], edx
// 0053cd1f  7304                 jae 0x53cd25
// 0053cd21  8d7c2438             lea edi, [esp + 0x38]
// 0053cd25  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053cd29  395018               cmp dword ptr [eax + 0x18], edx
// 0053cd2c  8b4814               mov ecx, dword ptr [eax + 0x14]
// 0053cd2f  7205                 jb 0x53cd36
// 0053cd31  8b4004               mov eax, dword ptr [eax + 4]
// 0053cd34  eb03                 jmp 0x53cd39
// 0053cd36  83c004               add eax, 4
// 0053cd39  57                   push edi
// 0053cd3a  51                   push ecx
// 0053cd3b  50                   push eax
// 0053cd3c  56                   push esi
// 0053cd3d  e80e240800           call 0x5bf150
// 0053cd42  83c410               add esp, 0x10
// 0053cd45  85c0                 test eax, eax
// 0053cd47  7448                 je 0x53cd91
// 0053cd49  8d54242c             lea edx, [esp + 0x2c]
// 0053cd4d  52                   push edx
// 0053cd4e  e85df60200           call 0x56c3b0
// 0053cd53  8b38                 mov edi, dword ptr [eax]
// 0053cd55  6a00                 push 0
// 0053cd57  6aff                 push -1
// 0053cd59  56                   push esi
// 0053cd5a  c68424a00000000a     mov byte ptr [esp + 0xa0], 0xa
// 0053cd62  e8190c0800           call 0x5bd980
// 0053cd67  50                   push eax
// 0053cd68  6a03                 push 3
// 0053cd6a  57                   push edi
// 0053cd6b  e830f30200           call 0x56c0a0
// 0053cd70  83c41c               add esp, 0x1c
// 0053cd73  8d4c242c             lea ecx, [esp + 0x2c]
// 0053cd77  c684249000000009     mov byte ptr [esp + 0x90], 9
// 0053cd7f  e8dc55f5ff           call 0x492360
// 0053cd84  6afe                 push -2
// 0053cd86  56                   push esi
// 0053cd87  e804080800           call 0x5bd590
// 0053cd8c  83c408               add esp, 8
// 0053cd8f  eb0a                 jmp 0x53cd9b
// 0053cd91  6a00                 push 0
// 0053cd93  56                   push esi
// 0053cd94  8bcb                 mov ecx, ebx
// 0053cd96  e825ddffff           call 0x53aac0
// 0053cd9b  6a00                 push 0
// 0053cd9d  56                   push esi
// 0053cd9e  e8ed070800           call 0x5bd590
// 0053cda3  83c408               add esp, 8
// 0053cda6  8d4c2434             lea ecx, [esp + 0x34]
// 0053cdaa  c684249000000003     mov byte ptr [esp + 0x90], 3
// 0053cdb2  ff15ace67700         call dword ptr [0x77e6ac]
// 0053cdb8  8b442410             mov eax, dword ptr [esp + 0x10]
// 0053cdbc  6afe                 push -2
// 0053cdbe  50                   push eax
// 0053cdbf  c684249800000001     mov byte ptr [esp + 0x98], 1
// 0053cdc7  e8c4070800           call 0x5bd590
// 0053cdcc  83c408               add esp, 8
// 0053cdcf  8d4c241c             lea ecx, [esp + 0x1c]
// 0053cdd3  c684249000000000     mov byte ptr [esp + 0x90], 0
// 0053cddb  e88055f5ff           call 0x492360
// 0053cde0  8d8c2498000000       lea ecx, [esp + 0x98]
// 0053cde7  c7842490000000ffffffff mov dword ptr [esp + 0x90], 0xffffffff
// 0053cdf2  e86955f5ff           call 0x492360
// 0053cdf7  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 0053cdfe  5f                   pop edi
// 0053cdff  5e                   pop esi
// 0053ce00  5d                   pop ebp
// 0053ce01  64890d00000000       mov dword ptr fs:[0], ecx
// 0053ce08  5b                   pop ebx
// 0053ce09  81c484000000         add esp, 0x84
// 0053ce0f  c20800               ret 8

// from server: 100% by coldek
// roc-cl: 50727
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
 int __cdecl luaL_loadbuffer(lua_State*,const char*,unsigned,const char*);const char* __cdecl lua_tolstring(lua_State*,int,unsigned*);
namespace G3D {std::string __cdecl format(const char*,...);}
namespace RBX {
namespace Reflection {struct DescribedBase {virtual ~DescribedBase();void*opaque;void*descriptor;};}
struct PrimaryInstance {virtual ~PrimaryInstance();char opaque[12];};struct FactoryProduct {virtual ~FactoryProduct();};
template<class T>struct Association {struct Item;std::vector<Item*>items;template<class U>U&get();};
struct Instance:PrimaryInstance,FactoryProduct,Reflection::DescribedBase {
 char opaque[0xac-0x20];Association<Instance>assoc;char opaquebc[0xc8-0xbc];std::string name;
 Association<Instance>&association(){return assoc;}const std::string&getName()const{return name;}
};
struct Script:Instance {};
namespace Security {enum Identities{Anonymous,LocalGUI,GameScript,CmdLine,TrustedCOM,TrustedWebService,Replicator};}
enum MessageType{MESSAGE_OUTPUT,MESSAGE_INFO,MESSAGE_WARNING,MESSAGE_ERROR};
struct StandardOut {static boost::shared_ptr<StandardOut>singleton();void __cdecl print(MessageType,const char*,...);};
namespace Lua {
struct ScopedPopper {int popCount;lua_State*thread;ScopedPopper(lua_State*L,int n):popCount(n),thread(L){}~ScopedPopper(){lua_settop(thread,-popCount-1);}};
struct ThreadRef {struct Node {static boost::shared_ptr<Node>create(lua_State*);};typedef boost::shared_ptr<Node>NodePtr;};
struct ObjectBridge {static void push(lua_State*,boost::shared_ptr<Reflection::DescribedBase>);};

}
struct ScriptContext {
 char opaque[0xf0];lua_State*globalState;char opaquef4[0x128-0xf4];std::vector<boost::shared_ptr<Script> >pendingScripts;char opaque138[0x144-0x138];bool scriptsDisabled;
 enum Result{Success,Yield,Error};void openState();static void __cdecl setThreadIdentity(lua_State*,Security::Identities);Result resume(lua_State*,int);void startScript(boost::shared_ptr<Script>);boost::shared_ptr<const std::string>requestCode(Script*);static std::string __cdecl getFullName(Script*);
};
void ScriptContext::startScript(boost::shared_ptr<Script>script){
 if(scriptsDisabled){pendingScripts.push_back(script);return;}
 boost::shared_ptr<const std::string>code=requestCode(script.get());
 if(!code){pendingScripts.push_back(script);return;}
 openState();lua_State*thread=lua_newthread(globalState);
 if(!thread){StandardOut::singleton()->print(MESSAGE_ERROR,"Unable to create a new thread for %s. It did not execute",script->getName().c_str());return;}
 Lua::ScopedPopper popper(globalState,1);
 lua_createtable(thread,0,0);lua_createtable(thread,0,0);lua_pushlstring(thread,"__index",7);lua_pushvalue(thread,-10002);lua_settable(thread,-3);lua_setmetatable(thread,-2);lua_replace(thread,-10002);
 setThreadIdentity(thread,Security::GameScript);
 script->association().get<Lua::ThreadRef::NodePtr>()=Lua::ThreadRef::Node::create(thread);
 Lua::ObjectBridge::push(thread,script);lua_setfield(thread,-10002,"script");
 std::string name=std::string("=")+getFullName(script.get());
 int result=luaL_loadbuffer(thread,code->c_str(),code->length(),name.c_str());
 if(result){
  StandardOut::singleton()->print(MESSAGE_ERROR,lua_tolstring(thread,-1,0));lua_settop(thread,-2);
 }else resume(thread,0);
 lua_settop(thread,0);
}
}
typedef char pending_offset[offsetof(RBX::ScriptContext,pendingScripts)==0x128?1:-1];
typedef char disabled_offset[offsetof(RBX::ScriptContext,scriptsDisabled)==0x144?1:-1];
typedef char association_offset[offsetof(RBX::Instance,assoc)==0xac?1:-1];
typedef char instance_name_offset[offsetof(RBX::Instance,name)==0xc8?1:-1];
typedef char shared_size[sizeof(boost::shared_ptr<RBX::Script>)==8?1:-1];
