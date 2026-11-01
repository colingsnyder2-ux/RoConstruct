// from server: 100% by Yeetserama
// roc 2007-08 0040f060  unit: CChildFrame  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040f060
//
// 0040f060  6aff                 push -1
// 0040f062  6818a07300           push 0x73a018
// 0040f067  64a100000000         mov eax, dword ptr fs:[0]
// 0040f06d  50                   push eax
// 0040f06e  83ec18               sub esp, 0x18
// 0040f071  56                   push esi
// 0040f072  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040f077  33c4                 xor eax, esp
// 0040f079  50                   push eax
// 0040f07a  8d442420             lea eax, [esp + 0x20]
// 0040f07e  64a300000000         mov dword ptr fs:[0], eax
// 0040f084  b9501c8c00           mov ecx, 0x8c1c50
// 0040f089  c7442410501c8c00     mov dword ptr [esp + 0x10], 0x8c1c50
// 0040f091  e8ba663100           call 0x725750
// 0040f096  c644241401           mov byte ptr [esp + 0x14], 1
// 0040f09b  833da4af8b0000       cmp dword ptr [0x8bafa4], 0
// 0040f0a2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0040f0aa  0f859b000000         jne 0x40f14b
// 0040f0b0  8d442408             lea eax, [esp + 8]
// 0040f0b4  50                   push eax
// 0040f0b5  e816ffffff           call 0x40efd0
// 0040f0ba  8d4c241c             lea ecx, [esp + 0x1c]
// 0040f0be  51                   push ecx
// 0040f0bf  c644243001           mov byte ptr [esp + 0x30], 1
// 0040f0c4  e887b81300           call 0x54a950
// 0040f0c9  83c408               add esp, 8
// 0040f0cc  8b00                 mov eax, dword ptr [eax]
// 0040f0ce  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040f0d2  50                   push eax
// 0040f0d3  c644242c02           mov byte ptr [esp + 0x2c], 2
// 0040f0d8  e853251300           call 0x541630
// 0040f0dd  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0040f0e1  85f6                 test esi, esi
// 0040f0e3  c644242801           mov byte ptr [esp + 0x28], 1
// 0040f0e8  742a                 je 0x40f114
// 0040f0ea  8d5604               lea edx, [esi + 4]
// 0040f0ed  83c8ff               or eax, 0xffffffff
// 0040f0f0  f00fc102             lock xadd dword ptr [edx], eax
// 0040f0f4  751e                 jne 0x40f114
// 0040f0f6  8b16                 mov edx, dword ptr [esi]
// 0040f0f8  8b4204               mov eax, dword ptr [edx + 4]
// 0040f0fb  8bce                 mov ecx, esi
// 0040f0fd  ffd0                 call eax
// 0040f0ff  8d4e08               lea ecx, [esi + 8]
// 0040f102  83caff               or edx, 0xffffffff
// 0040f105  f00fc111             lock xadd dword ptr [ecx], edx
// 0040f109  7509                 jne 0x40f114
// 0040f10b  8b06                 mov eax, dword ptr [esi]
// 0040f10d  8b5008               mov edx, dword ptr [eax + 8]
// 0040f110  8bce                 mov ecx, esi
// 0040f112  ffd2                 call edx
// 0040f114  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040f118  85f6                 test esi, esi
// 0040f11a  c644242800           mov byte ptr [esp + 0x28], 0
// 0040f11f  742a                 je 0x40f14b
// 0040f121  8d4604               lea eax, [esi + 4]
// 0040f124  83c9ff               or ecx, 0xffffffff
// 0040f127  f00fc108             lock xadd dword ptr [eax], ecx
// 0040f12b  751e                 jne 0x40f14b
// 0040f12d  8b16                 mov edx, dword ptr [esi]
// 0040f12f  8b4204               mov eax, dword ptr [edx + 4]
// 0040f132  8bce                 mov ecx, esi
// 0040f134  ffd0                 call eax
// 0040f136  8d4e08               lea ecx, [esi + 8]
// 0040f139  83caff               or edx, 0xffffffff
// 0040f13c  f00fc111             lock xadd dword ptr [ecx], edx
// 0040f140  7509                 jne 0x40f14b
// 0040f142  8b06                 mov eax, dword ptr [esi]
// 0040f144  8b5008               mov edx, dword ptr [eax + 8]
// 0040f147  8bce                 mov ecx, esi
// 0040f149  ffd2                 call edx
// 0040f14b  8b35a4af8b00         mov esi, dword ptr [0x8bafa4]
// 0040f151  b9501c8c00           mov ecx, 0x8c1c50
// 0040f156  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0040f15e  e80d663100           call 0x725770
// 0040f163  8bc6                 mov eax, esi
// 0040f165  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0040f169  64890d00000000       mov dword ptr fs:[0], ecx
// 0040f170  59                   pop ecx
// 0040f171  5e                   pop esi
// 0040f172  83c424               add esp, 0x24
// 0040f175  c3                   ret 
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
