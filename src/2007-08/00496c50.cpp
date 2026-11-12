// from server: 95% by EspClaude
// roc 2007-08 00496c50  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 383 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00496c50
//
// 00496c50  6aff                 push -1
// 00496c52  68d1847400           push 0x7484d1
// 00496c57  64a100000000         mov eax, dword ptr fs:[0]
// 00496c5d  50                   push eax
// 00496c5e  83ec4c               sub esp, 0x4c
// 00496c61  56                   push esi
// 00496c62  57                   push edi
// 00496c63  a188518b00           mov eax, dword ptr [0x8b5188]
// 00496c68  33c4                 xor eax, esp
// 00496c6a  50                   push eax
// 00496c6b  8d442458             lea eax, [esp + 0x58]
// 00496c6f  64a300000000         mov dword ptr fs:[0], eax
// 00496c75  8bf1                 mov esi, ecx
// 00496c77  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00496c7f  83be3801000000       cmp dword ptr [esi + 0x138], 0
// 00496c86  7434                 je 0x496cbc
// 00496c88  6814bc7900           push 0x79bc14
// 00496c8d  8d4c2418             lea ecx, [esp + 0x18]
// 00496c91  ff1598e67700         call dword ptr [0x77e698]
// 00496c97  8d442414             lea eax, [esp + 0x14]
// 00496c9b  50                   push eax
// 00496c9c  8d4c2434             lea ecx, [esp + 0x34]
// 00496ca0  c744246400000000     mov dword ptr [esp + 0x64], 0
// 00496ca8  e813c1f7ff           call 0x412dc0
// 00496cad  68c0108400           push 0x8410c0
// 00496cb2  8d4c2434             lea ecx, [esp + 0x34]
// 00496cb6  51                   push ecx
// 00496cb7  e8e29e1900           call 0x630b9e
// 00496cbc  8d54240c             lea edx, [esp + 0xc]
// 00496cc0  52                   push edx
// 00496cc1  e86a76f7ff           call 0x40e330
// 00496cc6  83c404               add esp, 4
// 00496cc9  8b08                 mov ecx, dword ptr [eax]
// 00496ccb  83c004               add eax, 4
// 00496cce  898e38010000         mov dword ptr [esi + 0x138], ecx
// 00496cd4  50                   push eax
// 00496cd5  8d8e3c010000         lea ecx, [esi + 0x13c]
// 00496cdb  c744246401000000     mov dword ptr [esp + 0x64], 1
// 00496ce3  e878bdf6ff           call 0x402a60
// 00496ce8  8b442410             mov eax, dword ptr [esp + 0x10]
// 00496cec  85c0                 test eax, eax
// 00496cee  c7442460ffffffff     mov dword ptr [esp + 0x60], 0xffffffff
// 00496cf6  742c                 je 0x496d24
// 00496cf8  8bf8                 mov edi, eax
// 00496cfa  83c004               add eax, 4
// 00496cfd  83caff               or edx, 0xffffffff
// 00496d00  f00fc110             lock xadd dword ptr [eax], edx
// 00496d04  751e                 jne 0x496d24
// 00496d06  8b07                 mov eax, dword ptr [edi]
// 00496d08  8b5004               mov edx, dword ptr [eax + 4]
// 00496d0b  8bcf                 mov ecx, edi
// 00496d0d  ffd2                 call edx
// 00496d0f  8d4708               lea eax, [edi + 8]
// 00496d12  83c9ff               or ecx, 0xffffffff
// 00496d15  f00fc108             lock xadd dword ptr [eax], ecx
// 00496d19  7509                 jne 0x496d24
// 00496d1b  8b17                 mov edx, dword ptr [edi]
// 00496d1d  8b4208               mov eax, dword ptr [edx + 8]
// 00496d20  8bcf                 mov ecx, edi
// 00496d22  ffd0                 call eax
// 00496d24  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 00496d2a  85c0                 test eax, eax
// 00496d2c  7405                 je 0x496d33
// 00496d2e  83c004               add eax, 4
// 00496d31  eb02                 jmp 0x496d35
// 00496d33  33c0                 xor eax, eax
// 00496d35  8b0d44de8b00         mov ecx, dword ptr [0x8bde44]
// 00496d3b  8b11                 mov edx, dword ptr [ecx]
// 00496d3d  8d7c246c             lea edi, [esp + 0x6c]
// 00496d41  57                   push edi
// 00496d42  50                   push eax
// 00496d43  8b4208               mov eax, dword ptr [edx + 8]
// 00496d46  ffd0                 call eax
// 00496d48  8b8e38010000         mov ecx, dword ptr [esi + 0x138]
// 00496d4e  56                   push esi
// 00496d4f  e8dca80a00           call 0x541630
// 00496d54  6808e18b00           push 0x8be108
// 00496d59  8bce                 mov ecx, esi
// 00496d5b  e8b0d9faff           call 0x444710
// 00496d60  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 00496d66  85c0                 test eax, eax
// 00496d68  7417                 je 0x496d81
// 00496d6a  8b0d28de8b00         mov ecx, dword ptr [0x8bde28]
// 00496d70  8b11                 mov edx, dword ptr [ecx]
// 00496d72  83c004               add eax, 4
// 00496d75  50                   push eax
// 00496d76  8b4204               mov eax, dword ptr [edx + 4]
// 00496d79  ffd0                 call eax
// 00496d7b  8844240c             mov byte ptr [esp + 0xc], al
// 00496d7f  eb05                 jmp 0x496d86
// 00496d81  c644240c00           mov byte ptr [esp + 0xc], 0
// 00496d86  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00496d8a  51                   push ecx
// 00496d8b  8d8e00010000         lea ecx, [esi + 0x100]
// 00496d91  e82ab8ffff           call 0x4925c0
// 00496d96  8b9638010000         mov edx, dword ptr [esi + 0x138]
// 00496d9c  8b442468             mov eax, dword ptr [esp + 0x68]
// 00496da0  8910                 mov dword ptr [eax], edx
// 00496da2  8bb63c010000         mov esi, dword ptr [esi + 0x13c]
// 00496da8  85f6                 test esi, esi
// 00496daa  897004               mov dword ptr [eax + 4], esi
// 00496dad  740c                 je 0x496dbb
// 00496daf  83c604               add esi, 4
// 00496db2  b901000000           mov ecx, 1
// 00496db7  f00fc10e             lock xadd dword ptr [esi], ecx
// 00496dbb  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00496dbf  64890d00000000       mov dword ptr fs:[0], ecx
// 00496dc6  59                   pop ecx
// 00496dc7  5f                   pop edi
// 00496dc8  5e                   pop esi
// 00496dc9  83c458               add esp, 0x58
// 00496dcc  c20800               ret 8
// Rewritten as Players::createLocalPlayer(int) returning shared_ptr<Player> (hidden return, ret 8):
// localPlayer shared_ptr at this+0x138/0x13c, throw std::runtime_error("Local player already exists")
// (string 0x79bc14), create via 0x40e330 (shared_ptr by hidden pointer), descriptor at [0x8bde44] slot 2
// called with (DescribedBase* = player+4, &userId), setParent 0x541630, raisePropertyChanged 0x444710(&0x8be108),
// [0x8bde28] slot 1 -> bool passed to member at this+0x100 (0x4925c0).
#include <string>
#include <stdexcept>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
    shared_ptr() : px(0) {}
    shared_ptr& operator=(const shared_ptr& r) { px = r.px; pn = r.pn; return *this; }
    T* get() const { return px; }
    T* operator->() const { return px; }
};

class Instance {
public:
    virtual ~Instance();
    void setParent(Instance* p);
};
class DescribedBase { public: virtual void dummy(); };
class Player : public Instance, public DescribedBase {};

struct PropertyDescriptor { virtual void v0(); virtual void v1(); virtual void setValue(DescribedBase* o, const int& v) const; };
struct Predicate { virtual void v0(); virtual bool test(DescribedBase* o) const; };
extern PropertyDescriptor* g_userIdProp;
extern Predicate* g_pred;
struct PropDesc {};
extern PropDesc g_localPlayerProp;
shared_ptr<Player> createPlayer();

struct Signal { void fire(bool b); };

class Players : public Instance {
public:
    char pad[0x100 - 4];
    Signal sig;
    char pad2[0x138 - 0x101];
    shared_ptr<Player> localPlayer;
    void raisePropertyChanged(const PropDesc& d);
    shared_ptr<Player> createLocalPlayer(int userId);
};

shared_ptr<Player> Players::createLocalPlayer(int userId)
{
    if (localPlayer.get())
        throw std::runtime_error("Local player already exists");
    localPlayer = createPlayer();
    g_userIdProp->setValue(localPlayer.get(), userId);
    localPlayer->setParent(this);
    raisePropertyChanged(g_localPlayerProp);
    sig.fire(localPlayer.get() ? g_pred->test(localPlayer.get()) : false);
    return localPlayer;
}
