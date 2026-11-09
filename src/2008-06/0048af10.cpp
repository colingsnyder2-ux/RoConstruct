// from server: 100% by king_originala
#include <string>
#include <exception>
// from server: 100% by king_originala
// roc 2008-06 0048af10  unit: RBX::Network::P8Player::?$GetSetImpl  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048af10
//
// 0048af10  55                   push ebp
// 0048af11  8bec                 mov ebp, esp
// 0048af13  6aff                 push -1
// 0048af15  6819617c00           push 0x7c6119
// 0048af1a  64a100000000         mov eax, dword ptr fs:[0]
// 0048af20  50                   push eax
// 0048af21  64892500000000       mov dword ptr fs:[0], esp
// 0048af28  83ec2c               sub esp, 0x2c
// 0048af2b  53                   push ebx
// 0048af2c  56                   push esi
// 0048af2d  57                   push edi
// 0048af2e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0048af31  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048af38  c645fc01             mov byte ptr [ebp - 4], 1
// 0048af3c  85c9                 test ecx, ecx
// 0048af3e  7408                 je 0x48af48
// 0048af40  8d91d0feffff         lea edx, [ecx - 0x130]
// 0048af46  eb02                 jmp 0x48af4a
// 0048af48  33d2                 xor edx, edx
// 0048af4a  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048af4d  83ec08               sub esp, 8
// 0048af50  8bc4                 mov eax, esp
// 0048af52  8908                 mov dword ptr [eax], ecx
// 0048af54  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0048af57  894804               mov dword ptr [eax + 4], ecx
// 0048af5a  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0048af5d  8965ec               mov dword ptr [ebp - 0x14], esp
// 0048af60  85c0                 test eax, eax
// 0048af62  740c                 je 0x48af70
// 0048af64  83c004               add eax, 4
// 0048af67  b901000000           mov ecx, 1
// 0048af6c  f00fc108             lock xadd dword ptr [eax], ecx
// 0048af70  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0048af73  8b01                 mov eax, dword ptr [ecx]
// 0048af75  52                   push edx
// 0048af76  8b10                 mov edx, dword ptr [eax]
// 0048af78  ffd2                 call edx

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedExchangeAdd)

struct Count {
    volatile long value;
    void increment();
};

__forceinline void Count::increment()
{
    _InterlockedExchangeAdd(&value, 1);
}

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    Count strong;
    Count weak;
    void release() {
        if (_InterlockedDecrement(&strong.value) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak.value) == 0)
            destroy();
    }
};

struct Shared {
    void* pointer;
    Control* control;
    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        control->strong.increment();
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Object;

struct Callback {
    virtual void invoke(Object*, Shared) = 0;
};

struct S {
    void f(Shared value, Callback* callback);
};

struct Prefix {
    char padding[0x130];
};

struct Object : Prefix, S {
};

struct StandardOut {
    void print(int, const char *, ...);
};

struct OutHandle {
    StandardOut *pointer;
    void *count;
    ~OutHandle();
    StandardOut *operator->() const { return pointer; }
};

OutHandle __cdecl singleton();


void S::f(Shared value, Callback* callback)
{
    try {
        callback->invoke(static_cast<Object*>(this), value);
    }
    catch (std::exception& error) {
        std::string what(error.what());
        singleton()->print(2, "Exception caught in onEvent. %s", what.c_str());
    }
}
