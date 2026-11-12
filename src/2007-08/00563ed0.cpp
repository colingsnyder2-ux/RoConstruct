// from server: 100% by EspClaude
// from server: 44% by colin
// roc 2007-08 00563ed0  unit: RBX::SnapSelectionVerb  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00563ed0
//
// 00563ed0  83ec0c               sub esp, 0xc
// 00563ed3  53                   push ebx
// 00563ed4  8bd9                 mov ebx, ecx
// 00563ed6  56                   push esi
// 00563ed7  8b7320               mov esi, dword ptr [ebx + 0x20]
// 00563eda  e8b1a3ffff           call 0x55e290
// 00563edf  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 00563ee2  85c9                 test ecx, ecx
// 00563ee4  7405                 je 0x563eeb
// 00563ee6  e855ceeaff           call 0x410d40
// 00563eeb  8a442418             mov al, byte ptr [esp + 0x18]
// 00563eef  55                   push ebp
// 00563ef0  57                   push edi
// 00563ef1  8d7b14               lea edi, [ebx + 0x14]
// 00563ef4  6a01                 push 1
// 00563ef6  8bcf                 mov ecx, edi
// 00563ef8  8844241c             mov byte ptr [esp + 0x1c], al
// 00563efc  e8ffe3ffff           call 0x562300
// 00563f01  8bb004010000         mov esi, dword ptr [eax + 0x104]
// 00563f07  8b6e08               mov ebp, dword ptr [esi + 8]
// 00563f0a  396e04               cmp dword ptr [esi + 4], ebp
// 00563f0d  7606                 jbe 0x563f15
// 00563f0f  ff15d8e67700         call dword ptr [0x77e6d8]
// 00563f15  6a01                 push 1
// 00563f17  8bcf                 mov ecx, edi
// 00563f19  e8e2e3ffff           call 0x562300
// 00563f1e  8bb804010000         mov edi, dword ptr [eax + 0x104]
// 00563f24  8b4704               mov eax, dword ptr [edi + 4]
// 00563f27  3b4708               cmp eax, dword ptr [edi + 8]
// 00563f2a  89442410             mov dword ptr [esp + 0x10], eax
// 00563f2e  760a                 jbe 0x563f3a
// 00563f30  ff15d8e67700         call dword ptr [0x77e6d8]
// 00563f36  8b442410             mov eax, dword ptr [esp + 0x10]
// 00563f3a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00563f3e  51                   push ecx
// 00563f3f  b960f45500           mov ecx, 0x55f460
// 00563f44  51                   push ecx
// 00563f45  55                   push ebp
// 00563f46  56                   push esi
// 00563f47  50                   push eax
// 00563f48  8d542428             lea edx, [esp + 0x28]
// 00563f4c  57                   push edi
// 00563f4d  52                   push edx
// 00563f4e  e8adb4ffff           call 0x55f400
// 00563f53  8b5b20               mov ebx, dword ptr [ebx + 0x20]
// 00563f56  83c41c               add esp, 0x1c
// 00563f59  85db                 test ebx, ebx
// 00563f5b  5f                   pop edi
// 00563f5c  5d                   pop ebp
// 00563f5d  7409                 je 0x563f68
// 00563f5f  8bcb                 mov ecx, ebx
// 00563f61  e8ba69ffff           call 0x55a920
// 00563f66  eb02                 jmp 0x563f6a
// 00563f68  33c0                 xor eax, eax
// 00563f6a  6a08                 push 8
// 00563f6c  8bc8                 mov ecx, eax
// 00563f6e  e89d880200           call 0x58c810
// 00563f73  8b742418             mov esi, dword ptr [esp + 0x18]
// 00563f77  6aff                 push -1
// 00563f79  8bce                 mov ecx, esi
// 00563f7b  e830c9eaff           call 0x4108b0
// 00563f80  8b06                 mov eax, dword ptr [esi]
// 00563f82  8b5004               mov edx, dword ptr [eax + 4]
// 00563f85  6a01                 push 1
// 00563f87  8bce                 mov ecx, esi
// 00563f89  c74604ffffffff       mov dword ptr [esi + 4], 0xffffffff
// 00563f90  ffd2                 call edx
// 00563f92  5e                   pop esi
// 00563f93  5b                   pop ebx
// 00563f94  83c40c               add esp, 0xc
// 00563f97  c20400               ret 4
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace RBX {

class Instance;
class Selection;
class SoundService;
class DataModel;

class ServiceProvider {
public:
    template<class T> T* createService() const;
    template<class T> static T* create(const ServiceProvider* sp)
    {
        return sp ? sp->createService<T>() : 0;
    }
};

class Instance {
public:
    virtual ~Instance();
};

// boost::shared_ptr<Instance> stand-in (8 bytes: px, pn)
class SharedInstance {
public:
    Instance* px;
    void* pn;
    SharedInstance(const SharedInstance&);
    ~SharedInstance();
};

void snapInstance(SharedInstance);

// boost 1.34 bind shapes: arg<1>, storage1<arg<1> >, list1<arg<1> >, bind_t<void, F, list1>
template<int I> class arg {};
namespace { static arg<1> _1; }
template<class A1> struct storage1 {
    explicit storage1(A1 a1) : a1_(a1) {}
    A1 a1_;
};
template<class A1> class list1 : private storage1<A1> {
public:
    explicit list1(A1 a1) : storage1<A1>(a1) {}
};
template<class R, class F, class L> class bind_t {
    F f_;
    L l_;
public:
    bind_t(F f, L const& l) : f_(f), l_(l) {}
    template<class A1> void operator()(A1& a1) { f_(a1); }
};
template<class R, class B1, class A1>
bind_t<R, R (*)(B1), list1<A1> > bind(R (*f)(B1), A1 a1)
{
    typedef R (*F)(B1);
    typedef list1<A1> list_type;
    return bind_t<R, F, list_type>(f, list_type(a1));
}
typedef bind_t<void, void (*)(SharedInstance), list1<arg<1> > > SnapBinder;

class DataModel : public ServiceProvider {
};

class Selection {
public:
    char pad0[0x104];
    std::vector<SharedInstance>* selection;   // +0x104
};

class SoundService {
public:
    void playSound(int id);
};

template<class T> class ServiceClient {
public:
    T* get(bool create);
    T* operator->() { return get(true); }
    char pad0[0xc];
};

class IDataState {
public:
    virtual void unused0();
    virtual void setChanged(bool);     // vtable slot +4
    int counter;                        // +4
    void reset(int);
    void setDirty() { reset(-1); counter = -1; setChanged(true); }
};

namespace Network {
class Client { public: static bool clientIsPresent(const DataModel*, bool); };
class Server { public: static bool serverIsPresent(const DataModel*, bool); };
}

static __declspec(noinline) void checkRunPermissions(DataModel* instance)
{
    if (Network::Client::clientIsPresent(instance, true) && !Network::Server::serverIsPresent(instance, true)) {
        std::string message("Insufficinet permissions");
        throw std::runtime_error(message);
    }
}


}

namespace RBX {

class EditSelectionVerb {
protected:
    char pad0[0x14];
    ServiceClient<Selection> selection;   // +0x14
    DataModel* dataModel;                 // +0x20
};

class SnapSelectionVerb : public EditSelectionVerb {
public:
    void doIt(IDataState* state);
};

void SnapSelectionVerb::doIt(IDataState* state)
{
    checkRunPermissions(dataModel);
    ServiceProvider::create<Selection>(dataModel);
    std::for_each(selection->selection->begin(), selection->selection->end(), bind(snapInstance, _1));
    SoundService* sound = ServiceProvider::create<SoundService>(dataModel);
    sound->playSound(8);
    state->setDirty();
}

}
