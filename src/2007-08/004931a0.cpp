// from server: 100% by Yeetserama
// roc 2007-08 004931a0  unit: RBX::VInstance::?$NonFactoryProduct  size: 278 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004931a0
//
// 004931a0  6aff                 push -1
// 004931a2  6818a07300           push 0x73a018
// 004931a7  64a100000000         mov eax, dword ptr fs:[0]
// 004931ad  50                   push eax
// 004931ae  83ec18               sub esp, 0x18
// 004931b1  56                   push esi
// 004931b2  a188518b00           mov eax, dword ptr [0x8b5188]
// 004931b7  33c4                 xor eax, esp
// 004931b9  50                   push eax
// 004931ba  8d442420             lea eax, [esp + 0x20]
// 004931be  64a300000000         mov dword ptr fs:[0], eax
// 004931c4  b9501c8c00           mov ecx, 0x8c1c50
// 004931c9  c7442410501c8c00     mov dword ptr [esp + 0x10], 0x8c1c50
// 004931d1  e87a252900           call 0x725750
// 004931d6  c644241401           mov byte ptr [esp + 0x14], 1
// 004931db  833dacdf8b0000       cmp dword ptr [0x8bdfac], 0
// 004931e2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004931ea  0f859b000000         jne 0x49328b
// 004931f0  8d442408             lea eax, [esp + 8]
// 004931f4  50                   push eax
// 004931f5  e82681ffff           call 0x48b320
// 004931fa  8d4c241c             lea ecx, [esp + 0x1c]
// 004931fe  51                   push ecx
// 004931ff  c644243001           mov byte ptr [esp + 0x30], 1
// 00493204  e847770b00           call 0x54a950
// 00493209  83c408               add esp, 8
// 0049320c  8b00                 mov eax, dword ptr [eax]
// 0049320e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00493212  50                   push eax
// 00493213  c644242c02           mov byte ptr [esp + 0x2c], 2
// 00493218  e813e40a00           call 0x541630
// 0049321d  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00493221  85f6                 test esi, esi
// 00493223  c644242801           mov byte ptr [esp + 0x28], 1
// 00493228  742a                 je 0x493254
// 0049322a  8d5604               lea edx, [esi + 4]
// 0049322d  83c8ff               or eax, 0xffffffff
// 00493230  f00fc102             lock xadd dword ptr [edx], eax
// 00493234  751e                 jne 0x493254
// 00493236  8b16                 mov edx, dword ptr [esi]
// 00493238  8b4204               mov eax, dword ptr [edx + 4]
// 0049323b  8bce                 mov ecx, esi
// 0049323d  ffd0                 call eax
// 0049323f  8d4e08               lea ecx, [esi + 8]
// 00493242  83caff               or edx, 0xffffffff
// 00493245  f00fc111             lock xadd dword ptr [ecx], edx
// 00493249  7509                 jne 0x493254
// 0049324b  8b06                 mov eax, dword ptr [esi]
// 0049324d  8b5008               mov edx, dword ptr [eax + 8]
// 00493250  8bce                 mov ecx, esi
// 00493252  ffd2                 call edx
// 00493254  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00493258  85f6                 test esi, esi
// 0049325a  c644242800           mov byte ptr [esp + 0x28], 0
// 0049325f  742a                 je 0x49328b
// 00493261  8d4604               lea eax, [esi + 4]
// 00493264  83c9ff               or ecx, 0xffffffff
// 00493267  f00fc108             lock xadd dword ptr [eax], ecx
// 0049326b  751e                 jne 0x49328b
// 0049326d  8b16                 mov edx, dword ptr [esi]
// 0049326f  8b4204               mov eax, dword ptr [edx + 4]
// 00493272  8bce                 mov ecx, esi
// 00493274  ffd0                 call eax
// 00493276  8d4e08               lea ecx, [esi + 8]
// 00493279  83caff               or edx, 0xffffffff
// 0049327c  f00fc111             lock xadd dword ptr [ecx], edx
// 00493280  7509                 jne 0x49328b
// 00493282  8b06                 mov eax, dword ptr [esi]
// 00493284  8b5008               mov edx, dword ptr [eax + 8]
// 00493287  8bce                 mov ecx, esi
// 00493289  ffd2                 call edx
// 0049328b  8b35acdf8b00         mov esi, dword ptr [0x8bdfac]
// 00493291  b9501c8c00           mov ecx, 0x8c1c50
// 00493296  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0049329e  e8cd242900           call 0x725770
// 004932a3  8bc6                 mov eax, esi
// 004932a5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004932a9  64890d00000000       mov dword ptr fs:[0], ecx
// 004932b0  59                   pop ecx
// 004932b1  5e                   pop esi
// 004932b2  83c424               add esp, 0x24
// 004932b5  c3                   ret 
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
