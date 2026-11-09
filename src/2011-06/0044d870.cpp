// from server: 100% by Yeetserama
// roc 2011-06 0044d870  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0044d870
//
// 0044d870  6aff                 push -1
// 0044d872  68491a9d00           push 0x9d1a49
// 0044d877  64a100000000         mov eax, dword ptr fs:[0]
// 0044d87d  50                   push eax
// 0044d87e  64892500000000       mov dword ptr fs:[0], esp
// 0044d885  83ec08               sub esp, 8
// 0044d888  56                   push esi
// 0044d889  8bf1                 mov esi, ecx
// 0044d88b  51                   push ecx
// 0044d88c  8d442420             lea eax, [esp + 0x20]
// 0044d890  8bcc                 mov ecx, esp
// 0044d892  8964240c             mov dword ptr [esp + 0xc], esp
// 0044d896  50                   push eax
// 0044d897  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0044d89f  ff15e42da400         call dword ptr [0xa42de4]
// 0044d8a5  8bce                 mov ecx, esi
// 0044d8a7  e8f4c14200           call 0x879aa0
// 0044d8ac  8b16                 mov edx, dword ptr [esi]
// 0044d8ae  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0044d8b4  8bce                 mov ecx, esi
// 0044d8b6  ffd0                 call eax
// 0044d8b8  8d4c2407             lea ecx, [esp + 7]
// 0044d8bc  51                   push ecx
// 0044d8bd  8bce                 mov ecx, esi
// 0044d8bf  8844240b             mov byte ptr [esp + 0xb], al
// 0044d8c3  e878ddffff           call 0x44b640
// 0044d8c8  8d4c241c             lea ecx, [esp + 0x1c]
// 0044d8cc  ff15082ea400         call dword ptr [0xa42e08]
// 0044d8d2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044d8d6  64890d00000000       mov dword ptr fs:[0], ecx
// 0044d8dd  5e                   pop esi
// 0044d8de  83c414               add esp, 0x14
// 0044d8e1  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000010@@QAEXUString@2@@Z)

namespace ns_ROCX000010 {
// from server: 100% by colin
struct String;


struct String
{
    void* data;

    __declspec(dllimport) String(const String&);
    __declspec(dllimport) ~String() throw();
};





struct S
{
    typedef bool (__thiscall *Query)(S*);
    Query* vtable;

    void f(String value);
    void set(String value);
    void update(const bool& value);
};

void S::f(String value)
{
    set(value);
    bool result = vtable[60](this);
    update(result);
}
}
