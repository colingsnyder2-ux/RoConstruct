// from server: 100% by Yeetserama
// roc 2007-08 00440fd0  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00440fd0
//
// 00440fd0  6aff                 push -1
// 00440fd2  6869297600           push 0x762969
// 00440fd7  64a100000000         mov eax, dword ptr fs:[0]
// 00440fdd  50                   push eax
// 00440fde  83ec08               sub esp, 8
// 00440fe1  56                   push esi
// 00440fe2  a188518b00           mov eax, dword ptr [0x8b5188]
// 00440fe7  33c4                 xor eax, esp
// 00440fe9  50                   push eax
// 00440fea  8d442410             lea eax, [esp + 0x10]
// 00440fee  64a300000000         mov dword ptr fs:[0], eax
// 00440ff4  8bf1                 mov esi, ecx
// 00440ff6  51                   push ecx
// 00440ff7  8d442424             lea eax, [esp + 0x24]
// 00440ffb  8bcc                 mov ecx, esp
// 00440ffd  89642410             mov dword ptr [esp + 0x10], esp
// 00441001  50                   push eax
// 00441002  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0044100a  ff1574dd7700         call dword ptr [0x77dd74]
// 00441010  8bce                 mov ecx, esi
// 00441012  e8e9762500           call 0x698700
// 00441017  8b16                 mov edx, dword ptr [esi]
// 00441019  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 0044101f  8bce                 mov ecx, esi
// 00441021  ffd0                 call eax
// 00441023  8d4c240b             lea ecx, [esp + 0xb]
// 00441027  51                   push ecx
// 00441028  8bce                 mov ecx, esi
// 0044102a  8844240f             mov byte ptr [esp + 0xf], al
// 0044102e  e82decffff           call 0x43fc60
// 00441033  8d4c2420             lea ecx, [esp + 0x20]
// 00441037  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0044103d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441041  64890d00000000       mov dword ptr fs:[0], ecx
// 00441048  59                   pop ecx
// 00441049  5e                   pop esi
// 0044104a  83c414               add esp, 0x14
// 0044104d  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000001@@QAEXUString@2@@Z)

namespace ns_ROCX000001 {
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
