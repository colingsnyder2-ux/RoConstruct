// from server: 66% by king_originala
// roc 2008-06 00419880  unit: VCLuaFunction::?$CComObject  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00419880
//
// 00419880  89642424             mov dword ptr [esp + 0x24], esp
// 00419884  50                   push eax
// 00419885  ff155c248000         call dword ptr [0x80245c]
// 0041988b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0041988e  8b5608               mov edx, dword ptr [esi + 8]
// 00419891  50                   push eax
// 00419892  83ec08               sub esp, 8
// 00419895  8bcc                 mov ecx, esp
// 00419897  8911                 mov dword ptr [ecx], edx
// 00419899  8b460c               mov eax, dword ptr [esi + 0xc]
// 0041989c  89642430             mov dword ptr [esp + 0x30], esp
// 004198a0  894104               mov dword ptr [ecx + 4], eax
// 004198a3  85c0                 test eax, eax
// 004198a5  740c                 je 0x4198b3
// 004198a7  83c004               add eax, 4
// 004198aa  b901000000           mov ecx, 1
// 004198af  f00fc108             lock xadd dword ptr [eax], ecx
// 004198b3  56                   push esi
// 004198b4  8bcf                 mov ecx, edi
// 004198b6  e855ebffff           call 0x418410
// 004198bb  5f                   pop edi
// 004198bc  5e                   pop esi
// 004198bd  59                   pop ecx
// 004198be  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct String;
extern void (__thiscall *copyString)(String*, const String*);

struct String {
    unsigned char data[28];
    String(const String&);
    ~String();
};

inline String::String(const String& other)
{
    copyString(this, &other);
}

struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedExchangeAdd(&control->references, 1);
}

struct Source {
    unsigned char reserved[8];
    Shared shared;
    unsigned long value;
    String text;
};

struct S {
    void f(Source*);
    void helper(Source*, Shared, unsigned long, String);
};

void S::f(Source* source)
{
    helper(source, source->shared, source->value, source->text);
}
