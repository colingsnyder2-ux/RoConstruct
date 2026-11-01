// from server: 100% by Yeetserama
// roc 2007-08 00498f60  unit: RBX::Network::AbuseReporter::Udata::?$sp_counted_impl_p  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00498f60
//
// 00498f60  6aff                 push -1
// 00498f62  6818a07300           push 0x73a018
// 00498f67  64a100000000         mov eax, dword ptr fs:[0]
// 00498f6d  50                   push eax
// 00498f6e  83ec18               sub esp, 0x18
// 00498f71  56                   push esi
// 00498f72  a188518b00           mov eax, dword ptr [0x8b5188]
// 00498f77  33c4                 xor eax, esp
// 00498f79  50                   push eax
// 00498f7a  8d442420             lea eax, [esp + 0x20]
// 00498f7e  64a300000000         mov dword ptr fs:[0], eax
// 00498f84  b9501c8c00           mov ecx, 0x8c1c50
// 00498f89  c7442410501c8c00     mov dword ptr [esp + 0x10], 0x8c1c50
// 00498f91  e8bac72800           call 0x725750
// 00498f96  c644241401           mov byte ptr [esp + 0x14], 1
// 00498f9b  833df8e28b0000       cmp dword ptr [0x8be2f8], 0
// 00498fa2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00498faa  0f859b000000         jne 0x49904b
// 00498fb0  8d442408             lea eax, [esp + 8]
// 00498fb4  50                   push eax
// 00498fb5  e816ffffff           call 0x498ed0
// 00498fba  8d4c241c             lea ecx, [esp + 0x1c]
// 00498fbe  51                   push ecx
// 00498fbf  c644243001           mov byte ptr [esp + 0x30], 1
// 00498fc4  e887190b00           call 0x54a950
// 00498fc9  83c408               add esp, 8
// 00498fcc  8b00                 mov eax, dword ptr [eax]
// 00498fce  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00498fd2  50                   push eax
// 00498fd3  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00498fd8  e853860a00           call 0x541630
// 00498fdd  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00498fe1  85f6                 test esi, esi
// 00498fe3  c644242801           mov byte ptr [esp + 0x28], 1
// 00498fe8  742a                 je 0x499014
// 00498fea  8d5604               lea edx, [esi + 4]
// 00498fed  83c8ff               or eax, 0xffffffff
// 00498ff0  f00fc102             lock xadd dword ptr [edx], eax
// 00498ff4  751e                 jne 0x499014
// 00498ff6  8b16                 mov edx, dword ptr [esi]
// 00498ff8  8b4204               mov eax, dword ptr [edx + 4]
// 00498ffb  8bce                 mov ecx, esi
// 00498ffd  ffd0                 call eax
// 00498fff  8d4e08               lea ecx, [esi + 8]
// 00499002  83caff               or edx, 0xffffffff
// 00499005  f00fc111             lock xadd dword ptr [ecx], edx
// 00499009  7509                 jne 0x499014
// 0049900b  8b06                 mov eax, dword ptr [esi]
// 0049900d  8b5008               mov edx, dword ptr [eax + 8]
// 00499010  8bce                 mov ecx, esi
// 00499012  ffd2                 call edx
// 00499014  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00499018  85f6                 test esi, esi
// 0049901a  c644242800           mov byte ptr [esp + 0x28], 0
// 0049901f  742a                 je 0x49904b
// 00499021  8d4604               lea eax, [esi + 4]
// 00499024  83c9ff               or ecx, 0xffffffff
// 00499027  f00fc108             lock xadd dword ptr [eax], ecx
// 0049902b  751e                 jne 0x49904b
// 0049902d  8b16                 mov edx, dword ptr [esi]
// 0049902f  8b4204               mov eax, dword ptr [edx + 4]
// 00499032  8bce                 mov ecx, esi
// 00499034  ffd0                 call eax
// 00499036  8d4e08               lea ecx, [esi + 8]
// 00499039  83caff               or edx, 0xffffffff
// 0049903c  f00fc111             lock xadd dword ptr [ecx], edx
// 00499040  7509                 jne 0x49904b
// 00499042  8b06                 mov eax, dword ptr [esi]
// 00499044  8b5008               mov edx, dword ptr [eax + 8]
// 00499047  8bce                 mov ecx, esi
// 00499049  ffd2                 call edx
// 0049904b  8b35f8e28b00         mov esi, dword ptr [0x8be2f8]
// 00499051  b9501c8c00           mov ecx, 0x8c1c50
// 00499056  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0049905e  e80dc72800           call 0x725770
// 00499063  8bc6                 mov eax, esi
// 00499065  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00499069  64890d00000000       mov dword ptr fs:[0], ecx
// 00499070  59                   pop ecx
// 00499071  5e                   pop esi
// 00499072  83c424               add esp, 0x24
// 00499075  c3                   ret 
// copied from an identical function in another client (function ?getObject@ns_ROCX00001b@@YAPAUObject@1@XZ)

namespace ns_ROCX00001b {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Lock {
    void acquire();
    void release();
};

struct Object {
    void initialize(Object*);
};

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
    Object* get() const;
};

struct Guard {
    Lock* lock;
    bool locked;
    Guard(Lock&);
    ~Guard();
};

extern Lock globalLock;
extern Object* globalObject;

Shared __cdecl makeObject();
Shared __cdecl getDependency();

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline Shared::~Shared()
{
    if (control)
        control->release();
}

__forceinline Object* Shared::get() const
{
    return object;
}

__forceinline Guard::Guard(Lock& value)
    : lock(&value)
{
    lock->acquire();
    locked = true;
}

__forceinline Guard::~Guard()
{
    if (locked)
        lock->release();
}

Object* __cdecl getObject()
{
    Guard guard(globalLock);
    if (!globalObject) {
        Shared object = makeObject();
        object.object->initialize(getDependency().get());
    }
    return globalObject;
}
}
