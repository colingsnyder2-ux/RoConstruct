// from server: 100% by EspClaude
// roc 2009-06 0043baa0  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043baa0
//
// 0043baa0  6aff                 push -1
// 0043baa2  68d9f88400           push 0x84f8d9
// 0043baa7  64a100000000         mov eax, dword ptr fs:[0]
// 0043baad  50                   push eax
// 0043baae  64892500000000       mov dword ptr fs:[0], esp
// 0043bab5  83ec08               sub esp, 8
// 0043bab8  56                   push esi
// 0043bab9  8bf1                 mov esi, ecx
// 0043babb  51                   push ecx
// 0043babc  8d442420             lea eax, [esp + 0x20]
// 0043bac0  8bcc                 mov ecx, esp
// 0043bac2  8964240c             mov dword ptr [esp + 0xc], esp
// 0043bac6  50                   push eax
// 0043bac7  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0043bacf  ff15e4fc8900         call dword ptr [0x89fce4]
// 0043bad5  8bce                 mov ecx, esi
// 0043bad7  e8d4e73400           call 0x78a2b0
// 0043badc  8b16                 mov edx, dword ptr [esi]
// 0043bade  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0043bae4  8bce                 mov ecx, esi
// 0043bae6  ffd0                 call eax
// 0043bae8  8d4c2407             lea ecx, [esp + 7]
// 0043baec  51                   push ecx
// 0043baed  8bce                 mov ecx, esi
// 0043baef  8844240b             mov byte ptr [esp + 0xb], al
// 0043baf3  e838d5ffff           call 0x439030
// 0043baf8  8d4c241c             lea ecx, [esp + 0x1c]
// 0043bafc  ff1510fd8900         call dword ptr [0x89fd10]
// 0043bb02  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043bb06  64890d00000000       mov dword ptr fs:[0], ecx
// 0043bb0d  5e                   pop esi
// 0043bb0e  83c414               add esp, 0x14
// 0043bb11  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000016@@QAEXUString@2@@Z)

namespace ns_ROCX000016 {
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
