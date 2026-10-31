// from server: 100% by EspClaude
// roc 2009-06 00462ab0  unit: Scintilla::CScintillaFindReplaceDlg  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00462ab0
//
// 00462ab0  56                   push esi
// 00462ab1  8bf1                 mov esi, ecx
// 00462ab3  e83e622b00           call 0x718cf6
// 00462ab8  8b400c               mov eax, dword ptr [eax + 0xc]
// 00462abb  818e8000000000020000 or dword ptr [esi + 0x80], 0x200
// 00462ac5  8b542418             mov edx, dword ptr [esp + 0x18]
// 00462ac9  89467c               mov dword ptr [esi + 0x7c], eax
// 00462acc  8b442408             mov eax, dword ptr [esp + 8]
// 00462ad0  8bc8                 mov ecx, eax
// 00462ad2  f7d9                 neg ecx
// 00462ad4  1bc9                 sbb ecx, ecx
// 00462ad6  83c166               add ecx, 0x66
// 00462ad9  52                   push edx
// 00462ada  8b542414             mov edx, dword ptr [esp + 0x14]
// 00462ade  898e98000000         mov dword ptr [esi + 0x98], ecx
// 00462ae4  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00462ae8  51                   push ecx
// 00462ae9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00462aed  52                   push edx
// 00462aee  51                   push ecx
// 00462aef  50                   push eax
// 00462af0  8bce                 mov ecx, esi
// 00462af2  e8ff6d2b00           call 0x7198f6
// 00462af7  5e                   pop esi
// 00462af8  c21400               ret 0x14
// copied from an identical function in another client (function ?f@S@ns_ROCX000068@@QAEHHHHHH@Z)

namespace ns_ROCX000068 {
extern "C" void* __stdcall sub_6a0926();

struct S {
    char pad_0[0x7c];
    void* field_7c;
    unsigned int field_80;
    char pad_84[0x14];
    int field_98;

    int sub_6a1412(int, int, int, int, int);
    int f(int, int, int, int, int);
};

int S::f(int a, int b, int c, int d, int e)
{
    void* h = *(void**)((char*)sub_6a0926() + 0x0c);
    field_80 |= 0x200;
    field_7c = h;
    field_98 = a ? 0x65 : 0x66;
    return sub_6a1412(a, b, c, d, e);
}
}
