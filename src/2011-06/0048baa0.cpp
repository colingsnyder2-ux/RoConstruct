// from server: 100% by Yeetserama
// roc 2011-06 0048baa0  unit: Scintilla::CScintillaFindReplaceDlg  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048baa0
//
// 0048baa0  56                   push esi
// 0048baa1  8bf1                 mov esi, ecx
// 0048baa3  e874e83700           call 0x80a31c
// 0048baa8  8b400c               mov eax, dword ptr [eax + 0xc]
// 0048baab  818e8000000000020000 or dword ptr [esi + 0x80], 0x200
// 0048bab5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0048bab9  89467c               mov dword ptr [esi + 0x7c], eax
// 0048babc  8b442408             mov eax, dword ptr [esp + 8]
// 0048bac0  8bc8                 mov ecx, eax
// 0048bac2  f7d9                 neg ecx
// 0048bac4  1bc9                 sbb ecx, ecx
// 0048bac6  83c166               add ecx, 0x66
// 0048bac9  52                   push edx
// 0048baca  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048bace  898e98000000         mov dword ptr [esi + 0x98], ecx
// 0048bad4  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048bad8  51                   push ecx
// 0048bad9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048badd  52                   push edx
// 0048bade  51                   push ecx
// 0048badf  50                   push eax
// 0048bae0  8bce                 mov ecx, esi
// 0048bae2  e871f43700           call 0x80af58
// 0048bae7  5e                   pop esi
// 0048bae8  c21400               ret 0x14
// copied from an identical function in another client (function ?f@S@ns_ROCX000002@@QAEHHHHHH@Z)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
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
