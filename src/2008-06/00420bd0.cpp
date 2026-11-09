// from server: 100% by colin
// from server: 96% by king_originala
// roc 2008-06 00420bd0  unit: CInstanceRecord::CNameItem  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00420bd0
//
// 00420bd0  51                   push ecx
// 00420bd1  83ec08               sub esp, 8
// 00420bd4  8bc4                 mov eax, esp
// 00420bd6  c70000000000         mov dword ptr [eax], 0
// 00420bdc  c7400400000000       mov dword ptr [eax + 4], 0
// 00420be3  8b155cc29600         mov edx, dword ptr [0x96c25c]
// 00420be9  89642408             mov dword ptr [esp + 8], esp
// 00420bed  83ec08               sub esp, 8
// 00420bf0  8bc4                 mov eax, esp
// 00420bf2  8910                 mov dword ptr [eax], edx
// 00420bf4  8b1560c29600         mov edx, dword ptr [0x96c260]
// 00420bfa  895004               mov dword ptr [eax + 4], edx
// 00420bfd  8bc2                 mov eax, edx
// 00420bff  89642410             mov dword ptr [esp + 0x10], esp
// 00420c03  85c0                 test eax, eax
// 00420c05  740c                 je 0x420c13
// 00420c07  83c004               add eax, 4
// 00420c0a  ba01000000           mov edx, 1
// 00420c0f  f00fc110             lock xadd dword ptr [eax], edx
// 00420c13  8b01                 mov eax, dword ptr [ecx]
// 00420c15  8b10                 mov edx, dword ptr [eax]
// 00420c17  ffd2                 call edx
// 00420c19  59                   pop ecx
// 00420c1a  c3                   ret 

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct ControlBlock {
    void* vtable;
    volatile long references;
};

struct Pointer {
    void* object;
    ControlBlock* control;

    Pointer() throw();
    Pointer(const Pointer&) throw();
    ~Pointer() throw();
};

inline Pointer::Pointer() throw()
    : object(0), control(0)
{
}

inline Pointer::Pointer(const Pointer& other) throw()
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

extern Pointer globalPointer;

struct S {
    virtual void set(Pointer, Pointer);
    void f();
};

void S::f()
{
    set(globalPointer, Pointer());
}
