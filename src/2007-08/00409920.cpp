// from server: 100% by Yeetserama
// roc 2007-08 00409920  unit: VCApp::?$CComObject  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00409920
//
// 00409920  6aff                 push -1
// 00409922  6818a07300           push 0x73a018
// 00409927  64a100000000         mov eax, dword ptr fs:[0]
// 0040992d  50                   push eax
// 0040992e  83ec18               sub esp, 0x18
// 00409931  56                   push esi
// 00409932  a188518b00           mov eax, dword ptr [0x8b5188]
// 00409937  33c4                 xor eax, esp
// 00409939  50                   push eax
// 0040993a  8d442420             lea eax, [esp + 0x20]
// 0040993e  64a300000000         mov dword ptr fs:[0], eax
// 00409944  b9501c8c00           mov ecx, 0x8c1c50
// 00409949  c7442410501c8c00     mov dword ptr [esp + 0x10], 0x8c1c50
// 00409951  e8fabd3100           call 0x725750
// 00409956  c644241401           mov byte ptr [esp + 0x14], 1
// 0040995b  833d44af8b0000       cmp dword ptr [0x8baf44], 0
// 00409962  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0040996a  0f859b000000         jne 0x409a0b
// 00409970  8d442408             lea eax, [esp + 8]
// 00409974  50                   push eax
// 00409975  e856fcffff           call 0x4095d0
// 0040997a  8d4c241c             lea ecx, [esp + 0x1c]
// 0040997e  51                   push ecx
// 0040997f  c644243001           mov byte ptr [esp + 0x30], 1
// 00409984  e8c70f1400           call 0x54a950
// 00409989  83c408               add esp, 8
// 0040998c  8b00                 mov eax, dword ptr [eax]
// 0040998e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00409992  50                   push eax
// 00409993  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00409998  e8937c1300           call 0x541630
// 0040999d  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004099a1  85f6                 test esi, esi
// 004099a3  c644242801           mov byte ptr [esp + 0x28], 1
// 004099a8  742a                 je 0x4099d4
// 004099aa  8d5604               lea edx, [esi + 4]
// 004099ad  83c8ff               or eax, 0xffffffff
// 004099b0  f00fc102             lock xadd dword ptr [edx], eax
// 004099b4  751e                 jne 0x4099d4
// 004099b6  8b16                 mov edx, dword ptr [esi]
// 004099b8  8b4204               mov eax, dword ptr [edx + 4]
// 004099bb  8bce                 mov ecx, esi
// 004099bd  ffd0                 call eax
// 004099bf  8d4e08               lea ecx, [esi + 8]
// 004099c2  83caff               or edx, 0xffffffff
// 004099c5  f00fc111             lock xadd dword ptr [ecx], edx
// 004099c9  7509                 jne 0x4099d4
// 004099cb  8b06                 mov eax, dword ptr [esi]
// 004099cd  8b5008               mov edx, dword ptr [eax + 8]
// 004099d0  8bce                 mov ecx, esi
// 004099d2  ffd2                 call edx
// 004099d4  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004099d8  85f6                 test esi, esi
// 004099da  c644242800           mov byte ptr [esp + 0x28], 0
// 004099df  742a                 je 0x409a0b
// 004099e1  8d4604               lea eax, [esi + 4]
// 004099e4  83c9ff               or ecx, 0xffffffff
// 004099e7  f00fc108             lock xadd dword ptr [eax], ecx
// 004099eb  751e                 jne 0x409a0b
// 004099ed  8b16                 mov edx, dword ptr [esi]
// 004099ef  8b4204               mov eax, dword ptr [edx + 4]
// 004099f2  8bce                 mov ecx, esi
// 004099f4  ffd0                 call eax
// 004099f6  8d4e08               lea ecx, [esi + 8]
// 004099f9  83caff               or edx, 0xffffffff
// 004099fc  f00fc111             lock xadd dword ptr [ecx], edx
// 00409a00  7509                 jne 0x409a0b
// 00409a02  8b06                 mov eax, dword ptr [esi]
// 00409a04  8b5008               mov edx, dword ptr [eax + 8]
// 00409a07  8bce                 mov ecx, esi
// 00409a09  ffd2                 call edx
// 00409a0b  8b3544af8b00         mov esi, dword ptr [0x8baf44]
// 00409a11  b9501c8c00           mov ecx, 0x8c1c50
// 00409a16  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00409a1e  e84dbd3100           call 0x725770
// 00409a23  8bc6                 mov eax, esi
// 00409a25  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00409a29  64890d00000000       mov dword ptr fs:[0], ecx
// 00409a30  59                   pop ecx
// 00409a31  5e                   pop esi
// 00409a32  83c424               add esp, 0x24
// 00409a35  c3                   ret 
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
