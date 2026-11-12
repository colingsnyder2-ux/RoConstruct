// from server: 100% by EspClaude
// roc 2007-08 004b0920  unit: RBX::Network::VReplicator::?$SignalDesc  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b0920
//
// 004b0920  6aff                 push -1
// 004b0922  68c8a77400           push 0x74a7c8
// 004b0927  64a100000000         mov eax, dword ptr fs:[0]
// 004b092d  50                   push eax
// 004b092e  83ec08               sub esp, 8
// 004b0931  53                   push ebx
// 004b0932  56                   push esi
// 004b0933  57                   push edi
// 004b0934  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b0939  33c4                 xor eax, esp
// 004b093b  50                   push eax
// 004b093c  8d442418             lea eax, [esp + 0x18]
// 004b0940  64a300000000         mov dword ptr fs:[0], eax
// 004b0946  8bf1                 mov esi, ecx
// 004b0948  e85340feff           call 0x4949a0
// 004b094d  85c0                 test eax, eax
// 004b094f  0f85ae000000         jne 0x4b0a03
// 004b0955  8d442410             lea eax, [esp + 0x10]
// 004b0959  50                   push eax
// 004b095a  e841bbfdff           call 0x48c4a0
// 004b095f  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 004b0963  68a8df8b00           push 0x8bdfa8
// 004b0968  6820214900           push 0x492120
// 004b096d  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004b0975  e8a64b2700           call 0x725520
// 004b097a  83c40c               add esp, 0xc
// 004b097d  e83e0ffeff           call 0x4918c0
// 004b0982  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 004b0988  85c9                 test ecx, ecx
// 004b098a  8bf8                 mov edi, eax
// 004b098c  740f                 je 0x4b099d
// 004b098e  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 004b0994  2bc1                 sub eax, ecx
// 004b0996  c1f803               sar eax, 3
// 004b0999  3bf8                 cmp edi, eax
// 004b099b  7206                 jb 0x4b09a3
// 004b099d  ff15d8e67700         call dword ptr [0x77e6d8]
// 004b09a3  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 004b09a9  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b09ad  8d04f9               lea eax, [ecx + edi*8]
// 004b09b0  8d4c2414             lea ecx, [esp + 0x14]
// 004b09b4  51                   push ecx
// 004b09b5  8d4804               lea ecx, [eax + 4]
// 004b09b8  8910                 mov dword ptr [eax], edx
// 004b09ba  e8a120f5ff           call 0x402a60
// 004b09bf  56                   push esi
// 004b09c0  8bcb                 mov ecx, ebx
// 004b09c2  e8690c0900           call 0x541630
// 004b09c7  8b742414             mov esi, dword ptr [esp + 0x14]
// 004b09cb  85f6                 test esi, esi
// 004b09cd  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004b09d5  742a                 je 0x4b0a01
// 004b09d7  8d5604               lea edx, [esi + 4]
// 004b09da  83c8ff               or eax, 0xffffffff
// 004b09dd  f00fc102             lock xadd dword ptr [edx], eax
// 004b09e1  751e                 jne 0x4b0a01
// 004b09e3  8b16                 mov edx, dword ptr [esi]
// 004b09e5  8b4204               mov eax, dword ptr [edx + 4]
// 004b09e8  8bce                 mov ecx, esi
// 004b09ea  ffd0                 call eax
// 004b09ec  8d4e08               lea ecx, [esi + 8]
// 004b09ef  83caff               or edx, 0xffffffff
// 004b09f2  f00fc111             lock xadd dword ptr [ecx], edx
// 004b09f6  7509                 jne 0x4b0a01
// 004b09f8  8b06                 mov eax, dword ptr [esi]
// 004b09fa  8b5008               mov edx, dword ptr [eax + 8]
// 004b09fd  8bce                 mov ecx, esi
// 004b09ff  ffd2                 call edx
// 004b0a01  8bc3                 mov eax, ebx
// 004b0a03  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b0a07  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0a0e  59                   pop ecx
// 004b0a0f  5f                   pop edi
// 004b0a10  5e                   pop esi
// 004b0a11  5b                   pop ebx
// 004b0a12  83c414               add esp, 0x14
// 004b0a15  c3                   ret 
// Rewritten as ServiceProvider-style create<T>(): find() (0x4949a0, thiscall on this),
// else Creatable create (0x48c4a0, shared_ptr returned through hidden pointer),
// call_once(0x492120, flag 0x8bdfa8) via 0x725520, index getter 0x4918c0,
// checked vector<shared_ptr<T>> element store at this+0x130 (_Myfirst +0x134, _Mylast +0x138,
// element size 8 from sar 3), shared_count assign 0x402a60, setParent 0x541630 thiscall(arg this).
#include <stddef.h>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement, _InterlockedExchangeAdd)
__declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
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
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
};

struct once_flag { long v; };
void call_once(void (*f)(), once_flag& flag);

class Instance;
class Service {
public:
    void setParent(Instance* p);
};
extern once_flag g_indexFlag;
void initIndex();
int getIndex();
shared_ptr<Service> createService();

template<class T> struct vec {
    int alval;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    size_t size() const { return _Myfirst == 0 ? 0 : _Mylast - _Myfirst; }
    T& operator[](size_t i) {
        if (_Myfirst == 0 || i >= size()) _invalid_parameter_noinfo();
        return _Myfirst[i];
    }
};

class Instance {
public:
    char pad[0x130];
    vec< shared_ptr<Service> > services;
    Service* find();
    Service* create();
};

Service* Instance::create()
{
    Service* result = find();
    if (!result) {
        shared_ptr<Service> s = createService();
        result = s.get();
        call_once(&initIndex, g_indexFlag);
        int i = getIndex();
        shared_ptr<Service>& slot = services[i];
        slot.px = s.px;
        slot.pn = s.pn;
        result->setParent(this);
    }
    return result;
}
