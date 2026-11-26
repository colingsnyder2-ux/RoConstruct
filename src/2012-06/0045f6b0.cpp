// from server: 100% by Xemicl
// roc 2012-06 0045f6b0  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045f6b0
//
// 0045f6b0  6aff                 push -1
// 0045f6b2  68e9f5a900           push 0xa9f5e9
// 0045f6b7  64a100000000         mov eax, dword ptr fs:[0]
// 0045f6bd  50                   push eax
// 0045f6be  64892500000000       mov dword ptr fs:[0], esp
// 0045f6c5  83ec08               sub esp, 8
// 0045f6c8  56                   push esi
// 0045f6c9  8bf1                 mov esi, ecx
// 0045f6cb  51                   push ecx
// 0045f6cc  8d442420             lea eax, [esp + 0x20]
// 0045f6d0  8bcc                 mov ecx, esp
// 0045f6d2  8964240c             mov dword ptr [esp + 0xc], esp
// 0045f6d6  50                   push eax
// 0045f6d7  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0045f6df  ff158047b200         call dword ptr [0xb24780]
// 0045f6e5  8bce                 mov ecx, esi
// 0045f6e7  e824295900           call 0x9f2010
// 0045f6ec  8b16                 mov edx, dword ptr [esi]
// 0045f6ee  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0045f6f4  8bce                 mov ecx, esi
// 0045f6f6  ffd0                 call eax
// 0045f6f8  8d4c2407             lea ecx, [esp + 7]
// 0045f6fc  51                   push ecx
// 0045f6fd  8bce                 mov ecx, esi
// 0045f6ff  8844240b             mov byte ptr [esp + 0xb], al
// 0045f703  e8b8adffff           call 0x45a4c0
// 0045f708  8d4c241c             lea ecx, [esp + 0x1c]
// 0045f70c  ff15d047b200         call dword ptr [0xb247d0]
// 0045f712  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045f716  64890d00000000       mov dword ptr fs:[0], ecx
// 0045f71d  5e                   pop esi
// 0045f71e  83c414               add esp, 0x14
// 0045f721  c20400               ret 4
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