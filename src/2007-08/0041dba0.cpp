// from server: 100% by Yeetserama
// roc 2007-08 0041dba0  unit: CInstanceRecord::CNameItem  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041dba0
//
// 0041dba0  51                   push ecx
// 0041dba1  83ec08               sub esp, 8
// 0041dba4  8bc4                 mov eax, esp
// 0041dba6  c70000000000         mov dword ptr [eax], 0
// 0041dbac  c7400400000000       mov dword ptr [eax + 4], 0
// 0041dbb3  8b153cae8b00         mov edx, dword ptr [0x8bae3c]
// 0041dbb9  89642408             mov dword ptr [esp + 8], esp
// 0041dbbd  83ec08               sub esp, 8
// 0041dbc0  8bc4                 mov eax, esp
// 0041dbc2  8910                 mov dword ptr [eax], edx
// 0041dbc4  8b1540ae8b00         mov edx, dword ptr [0x8bae40]
// 0041dbca  895004               mov dword ptr [eax + 4], edx
// 0041dbcd  8bc2                 mov eax, edx
// 0041dbcf  85c0                 test eax, eax
// 0041dbd1  89642410             mov dword ptr [esp + 0x10], esp
// 0041dbd5  740c                 je 0x41dbe3
// 0041dbd7  83c004               add eax, 4
// 0041dbda  ba01000000           mov edx, 1
// 0041dbdf  f00fc110             lock xadd dword ptr [eax], edx
// 0041dbe3  8b01                 mov eax, dword ptr [ecx]
// 0041dbe5  8b10                 mov edx, dword ptr [eax]
// 0041dbe7  ffd2                 call edx
// 0041dbe9  59                   pop ecx
// 0041dbea  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000012@@QAEXXZ)

namespace ns_ROCX000012 {
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
}
