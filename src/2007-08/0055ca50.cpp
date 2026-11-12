// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 0055ca50  unit: RBX::ServiceProvider  size: 703 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055ca50
//
// 0055ca50  6aff                 push -1
// 0055ca52  68923a7500           push 0x753a92
// 0055ca57  64a100000000         mov eax, dword ptr fs:[0]
// 0055ca5d  50                   push eax
// 0055ca5e  64892500000000       mov dword ptr fs:[0], esp
// 0055ca65  83ec10               sub esp, 0x10
// 0055ca68  53                   push ebx
// 0055ca69  55                   push ebp
// 0055ca6a  56                   push esi
// 0055ca6b  8bf1                 mov esi, ecx
// 0055ca6d  8dae4c010000         lea ebp, [esi + 0x14c]
// 0055ca73  8d9e7c010000         lea ebx, [esi + 0x17c]
// 0055ca79  57                   push edi
// 0055ca7a  8974241c             mov dword ptr [esp + 0x1c], esi
// 0055ca7e  c706b48d7a00         mov dword ptr [esi], 0x7a8db4
// 0055ca84  c74604a88d7a00       mov dword ptr [esi + 4], 0x7a8da8
// 0055ca8b  c74610a08d7a00       mov dword ptr [esi + 0x10], 0x7a8da0
// 0055ca92  c74614908d7a00       mov dword ptr [esi + 0x14], 0x7a8d90
// 0055ca99  c7462c808d7a00       mov dword ptr [esi + 0x2c], 0x7a8d80
// 0055caa0  c74644708d7a00       mov dword ptr [esi + 0x44], 0x7a8d70
// 0055caa7  c7465c608d7a00       mov dword ptr [esi + 0x5c], 0x7a8d60
// 0055caae  c74674508d7a00       mov dword ptr [esi + 0x74], 0x7a8d50
// 0055cab5  c7868c000000408d7a00 mov dword ptr [esi + 0x8c], 0x7a8d40
// 0055cabf  c786e8000000308d7a00 mov dword ptr [esi + 0xe8], 0x7a8d30
// 0055cac9  c78600010000208d7a00 mov dword ptr [esi + 0x100], 0x7a8d20
// 0055cad3  c78618010000108d7a00 mov dword ptr [esi + 0x118], 0x7a8d10
// 0055cadd  c74500088d7a00       mov dword ptr [ebp], 0x7a8d08
// 0055cae4  c78660010000f88c7a00 mov dword ptr [esi + 0x160], 0x7a8cf8
// 0055caee  c78678010000f08c7a00 mov dword ptr [esi + 0x178], 0x7a8cf0
// 0055caf8  c703e48c7a00         mov dword ptr [ebx], 0x7a8ce4
// 0055cafe  8b8690010000         mov eax, dword ptr [esi + 0x190]
// 0055cb04  85c0                 test eax, eax
// 0055cb06  c74424280c000000     mov dword ptr [esp + 0x28], 0xc
// 0055cb0e  740c                 je 0x55cb1c
// 0055cb10  53                   push ebx
// 0055cb11  8d8818010000         lea ecx, [eax + 0x118]
// 0055cb17  e8145aedff           call 0x432530
// 0055cb1c  8b86e0010000         mov eax, dword ptr [esi + 0x1e0]
// 0055cb22  50                   push eax
// 0055cb23  e83a310d00           call 0x62fc62
// 0055cb28  8bbedc010000         mov edi, dword ptr [esi + 0x1dc]
// 0055cb2e  83c404               add esp, 4
// 0055cb31  85ff                 test edi, edi
// 0055cb33  c64424280a           mov byte ptr [esp + 0x28], 0xa
// 0055cb38  742a                 je 0x55cb64
// 0055cb3a  8d4704               lea eax, [edi + 4]
// 0055cb3d  83c9ff               or ecx, 0xffffffff
// 0055cb40  f00fc108             lock xadd dword ptr [eax], ecx
// 0055cb44  751e                 jne 0x55cb64
// 0055cb46  8b17                 mov edx, dword ptr [edi]
// 0055cb48  8b4204               mov eax, dword ptr [edx + 4]
// 0055cb4b  8bcf                 mov ecx, edi
// 0055cb4d  ffd0                 call eax
// 0055cb4f  8d4f08               lea ecx, [edi + 8]
// 0055cb52  83caff               or edx, 0xffffffff
// 0055cb55  f00fc111             lock xadd dword ptr [ecx], edx
// 0055cb59  7509                 jne 0x55cb64
// 0055cb5b  8b07                 mov eax, dword ptr [edi]
// 0055cb5d  8b5008               mov edx, dword ptr [eax + 8]
// 0055cb60  8bcf                 mov ecx, edi
// 0055cb62  ffd2                 call edx
// 0055cb64  8d8eb8010000         lea ecx, [esi + 0x1b8]
// 0055cb6a  c644242809           mov byte ptr [esp + 0x28], 9
// 0055cb6f  ff15ace67700         call dword ptr [0x77e6ac]
// 0055cb75  8bbeac010000         mov edi, dword ptr [esi + 0x1ac]
// 0055cb7b  85ff                 test edi, edi
// 0055cb7d  c644242808           mov byte ptr [esp + 0x28], 8
// 0055cb82  742a                 je 0x55cbae
// 0055cb84  8d4704               lea eax, [edi + 4]
// 0055cb87  83c9ff               or ecx, 0xffffffff
// 0055cb8a  f00fc108             lock xadd dword ptr [eax], ecx
// 0055cb8e  751e                 jne 0x55cbae
// 0055cb90  8b17                 mov edx, dword ptr [edi]
// 0055cb92  8b4204               mov eax, dword ptr [edx + 4]
// 0055cb95  8bcf                 mov ecx, edi
// 0055cb97  ffd0                 call eax
// 0055cb99  8d4f08               lea ecx, [edi + 8]
// 0055cb9c  83caff               or edx, 0xffffffff
// 0055cb9f  f00fc111             lock xadd dword ptr [ecx], edx
// 0055cba3  7509                 jne 0x55cbae
// 0055cba5  8b07                 mov eax, dword ptr [edi]
// 0055cba7  8b5008               mov edx, dword ptr [eax + 8]
// 0055cbaa  8bcf                 mov ecx, edi
// 0055cbac  ffd2                 call edx
// 0055cbae  8bbea4010000         mov edi, dword ptr [esi + 0x1a4]
// 0055cbb4  85ff                 test edi, edi
// 0055cbb6  c644242807           mov byte ptr [esp + 0x28], 7
// 0055cbbb  742a                 je 0x55cbe7
// 0055cbbd  8d4704               lea eax, [edi + 4]
// 0055cbc0  83c9ff               or ecx, 0xffffffff
// 0055cbc3  f00fc108             lock xadd dword ptr [eax], ecx
// 0055cbc7  751e                 jne 0x55cbe7
// 0055cbc9  8b17                 mov edx, dword ptr [edi]
// 0055cbcb  8b4204               mov eax, dword ptr [edx + 4]
// 0055cbce  8bcf                 mov ecx, edi
// 0055cbd0  ffd0                 call eax
// 0055cbd2  8d4f08               lea ecx, [edi + 8]
// 0055cbd5  83caff               or edx, 0xffffffff
// 0055cbd8  f00fc111             lock xadd dword ptr [ecx], edx
// 0055cbdc  7509                 jne 0x55cbe7
// 0055cbde  8b07                 mov eax, dword ptr [edi]
// 0055cbe0  8b5008               mov edx, dword ptr [eax + 8]
// 0055cbe3  8bcf                 mov ecx, edi
// 0055cbe5  ffd2                 call edx
// 0055cbe7  8bbe9c010000         mov edi, dword ptr [esi + 0x19c]
// 0055cbed  85ff                 test edi, edi
// 0055cbef  c644242806           mov byte ptr [esp + 0x28], 6
// 0055cbf4  742a                 je 0x55cc20
// 0055cbf6  8d4704               lea eax, [edi + 4]
// 0055cbf9  83c9ff               or ecx, 0xffffffff
// 0055cbfc  f00fc108             lock xadd dword ptr [eax], ecx
// 0055cc00  751e                 jne 0x55cc20
// 0055cc02  8b17                 mov edx, dword ptr [edi]
// 0055cc04  8b4204               mov eax, dword ptr [edx + 4]
// 0055cc07  8bcf                 mov ecx, edi
// 0055cc09  ffd0                 call eax
// 0055cc0b  8d4f08               lea ecx, [edi + 8]
// 0055cc0e  83caff               or edx, 0xffffffff
// 0055cc11  f00fc111             lock xadd dword ptr [ecx], edx
// 0055cc15  7509                 jne 0x55cc20
// 0055cc17  8b07                 mov eax, dword ptr [edi]
// 0055cc19  8b5008               mov edx, dword ptr [eax + 8]
// 0055cc1c  8bcf                 mov ecx, edi
// 0055cc1e  ffd2                 call edx
// 0055cc20  8bbe94010000         mov edi, dword ptr [esi + 0x194]
// 0055cc26  85ff                 test edi, edi
// 0055cc28  c644242805           mov byte ptr [esp + 0x28], 5
// 0055cc2d  742a                 je 0x55cc59
// 0055cc2f  8d4704               lea eax, [edi + 4]
// 0055cc32  83c9ff               or ecx, 0xffffffff
// 0055cc35  f00fc108             lock xadd dword ptr [eax], ecx
// 0055cc39  751e                 jne 0x55cc59
// 0055cc3b  8b17                 mov edx, dword ptr [edi]
// 0055cc3d  8b4204               mov eax, dword ptr [edx + 4]
// 0055cc40  8bcf                 mov ecx, edi
// 0055cc42  ffd0                 call eax
// 0055cc44  8d4f08               lea ecx, [edi + 8]
// 0055cc47  83caff               or edx, 0xffffffff
// 0055cc4a  f00fc111             lock xadd dword ptr [ecx], edx
// 0055cc4e  7509                 jne 0x55cc59
// 0055cc50  8b07                 mov eax, dword ptr [edi]
// 0055cc52  8b5008               mov edx, dword ptr [eax + 8]
// 0055cc55  8bcf                 mov ecx, edi
// 0055cc57  ffd2                 call edx
// 0055cc59  8bbe8c010000         mov edi, dword ptr [esi + 0x18c]
// 0055cc5f  85ff                 test edi, edi
// 0055cc61  c644242804           mov byte ptr [esp + 0x28], 4
// 0055cc66  742a                 je 0x55cc92
// 0055cc68  8d4704               lea eax, [edi + 4]
// 0055cc6b  83c9ff               or ecx, 0xffffffff
// 0055cc6e  f00fc108             lock xadd dword ptr [eax], ecx
// 0055cc72  751e                 jne 0x55cc92
// 0055cc74  8b17                 mov edx, dword ptr [edi]
// 0055cc76  8b4204               mov eax, dword ptr [edx + 4]
// 0055cc79  8bcf                 mov ecx, edi
// 0055cc7b  ffd0                 call eax
// 0055cc7d  8d4f08               lea ecx, [edi + 8]
// 0055cc80  83caff               or edx, 0xffffffff
// 0055cc83  f00fc111             lock xadd dword ptr [ecx], edx
// 0055cc87  7509                 jne 0x55cc92
// 0055cc89  8b07                 mov eax, dword ptr [edi]
// 0055cc8b  8b5008               mov edx, dword ptr [eax + 8]
// 0055cc8e  8bcf                 mov ecx, edi
// 0055cc90  ffd2                 call edx
// 0055cc92  8bbe84010000         mov edi, dword ptr [esi + 0x184]
// 0055cc98  85ff                 test edi, edi
// 0055cc9a  c644242803           mov byte ptr [esp + 0x28], 3
// 0055cc9f  742a                 je 0x55cccb
// 0055cca1  8d4704               lea eax, [edi + 4]
// 0055cca4  83c9ff               or ecx, 0xffffffff
// 0055cca7  f00fc108             lock xadd dword ptr [eax], ecx
// 0055ccab  751e                 jne 0x55cccb
// 0055ccad  8b17                 mov edx, dword ptr [edi]
// 0055ccaf  8b4204               mov eax, dword ptr [edx + 4]
// 0055ccb2  8bcf                 mov ecx, edi
// 0055ccb4  ffd0                 call eax
// 0055ccb6  8d4f08               lea ecx, [edi + 8]
// 0055ccb9  83caff               or edx, 0xffffffff
// 0055ccbc  f00fc111             lock xadd dword ptr [ecx], edx
// 0055ccc0  7509                 jne 0x55cccb
// 0055ccc2  8b07                 mov eax, dword ptr [edi]
// 0055ccc4  8b5008               mov edx, dword ptr [eax + 8]
// 0055ccc7  8bcf                 mov ecx, edi
// 0055ccc9  ffd2                 call edx
// 0055cccb  8d8e60010000         lea ecx, [esi + 0x160]
// 0055ccd1  c703545b7900         mov dword ptr [ebx], 0x795b54
// 0055ccd7  c644242801           mov byte ptr [esp + 0x28], 1
// 0055ccdc  e8dfedffff           call 0x55bac0
// 0055cce1  8bcd                 mov ecx, ebp
// 0055cce3  c644242800           mov byte ptr [esp + 0x28], 0
// 0055cce8  e8b37d0000           call 0x564aa0
// 0055cced  8bce                 mov ecx, esi
// 0055ccef  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0055ccf7  e874d5feff           call 0x54a270
// 0055ccfc  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0055cd00  5f                   pop edi
// 0055cd01  5e                   pop esi
// 0055cd02  5d                   pop ebp
// 0055cd03  5b                   pop ebx
// 0055cd04  64890d00000000       mov dword ptr fs:[0], ecx
// 0055cd0b  83c41c               add esp, 0x1c
// 0055cd0e  c3                   ret 
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Model of RBX::DataModel::~DataModel (2007-08), cf. 2008 exact 0057ad70.
#include <string>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;     // slot +4
    virtual void destroy();         // slot +8
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
private:
    long use_count_;    // +4
    long weak_count_;   // +8
};
class shared_count {
    sp_counted_base* pi_;
public:
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* get() const { return px; }
    T* operator->() const { return px; }
private:
    T* px;
    detail::shared_count pn;
};
}

namespace RBX {

class LocalBackpack; class Workspace; class StarterPackService; class GuiRoot; class GuiTarget;
class RunService;
enum RunTransition {};

template<class Class, class Event> class Listener {
public:
    virtual ~Listener() {}
    virtual void onEvent(const Class*, Event) = 0;
};

template<class Class, class Event> class Notifier {
public:
    void removeListener(Listener<Class, Event>* listener);
};

class RunServiceBase { char pad[0x118]; };
class RunService : public RunServiceBase, public Notifier<RunService, RunTransition> {};

// polymorphic subobjects of the ServiceProvider/Instance base (offsets from the target vptr stores)
struct S00 { virtual void f00(); };
struct S04 { virtual void f04(); char pad[0x10 - 0x04 - 4]; };
struct S10 { virtual void f10(); };
struct S14 { virtual void f14(); char pad[0x2c - 0x14 - 4]; };
struct S2c { virtual void f2c(); char pad[0x44 - 0x2c - 4]; };
struct S44 { virtual void f44(); char pad[0x5c - 0x44 - 4]; };
struct S5c { virtual void f5c(); char pad[0x74 - 0x5c - 4]; };
struct S74 { virtual void f74(); char pad[0x8c - 0x74 - 4]; };
struct S8c { virtual void f8c(); char pad[0xe8 - 0x8c - 4]; };
struct Se8 { virtual void fe8(); char pad[0x100 - 0xe8 - 4]; };
struct S100 { virtual void f100(); char pad[0x118 - 0x100 - 4]; };
struct S118 { virtual void f118(); char pad[0x14c - 0x118 - 4]; };

class ServiceProviderBase : public S00, public S04, public S10, public S14, public S2c, public S44,
                            public S5c, public S74, public S8c, public Se8, public S100, public S118 {
public:
    virtual ~ServiceProviderBase();
};

class VerbContainer {        // +0x14c
public:
    virtual ~VerbContainer();
    char pad[0x14 - 4];
};

class Base160 {              // +0x160
public:
    virtual ~Base160();
    char pad[0x18 - 4];
};

class IDataState {           // +0x178
public:
    virtual void setDirty(bool) = 0;
};

class OwnedBuffer {          // +0x1e0
public:
    ~OwnedBuffer() { delete p; }
    char* p;
};

class DataModel : public ServiceProviderBase,
                  public VerbContainer,
                  public Base160,
                  public IDataState,
                  public Listener<RunService, RunTransition>
{
    boost::shared_ptr<LocalBackpack> localBackpack;            // +0x180
    boost::shared_ptr<Workspace> workspace;                    // +0x188
    boost::shared_ptr<RunService> runService;                  // +0x190
    boost::shared_ptr<StarterPackService> starterPackService;  // +0x198
    boost::shared_ptr<GuiRoot> guiRoot;                        // +0x1a0
    boost::shared_ptr<GuiRoot> guiHooks;                       // +0x1a8
    GuiTarget* guiTarget;                                      // +0x1b0
    bool forceArrowCursor;                                     // +0x1b4
    std::string uiMessage;                                     // +0x1b8
    int drawId;                                                // +0x1d4
    boost::shared_ptr<void> mutex;                             // +0x1d8
    OwnedBuffer buffer;                                        // +0x1e0
public:
    virtual ~DataModel();
    virtual void setDirty(bool);
    virtual void onEvent(const RunService*, RunTransition);
};

DataModel::~DataModel()
{
    if (runService.get())
        runService->Notifier<RunService, RunTransition>::removeListener(this);
}

}
