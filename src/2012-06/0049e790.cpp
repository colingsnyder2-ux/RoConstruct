// from server: 100% by Xemicl
// roc 2012-06 0049e790  unit: Scintilla::CScintillaFindReplaceDlg  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049e790
//
// 0049e790  56                   push esi
// 0049e791  8bf1                 mov esi, ecx
// 0049e793  e83a3c4e00           call 0x9823d2
// 0049e798  8b400c               mov eax, dword ptr [eax + 0xc]
// 0049e79b  818e8000000000020000 or dword ptr [esi + 0x80], 0x200
// 0049e7a5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0049e7a9  89467c               mov dword ptr [esi + 0x7c], eax
// 0049e7ac  8b442408             mov eax, dword ptr [esp + 8]
// 0049e7b0  8bc8                 mov ecx, eax
// 0049e7b2  f7d9                 neg ecx
// 0049e7b4  1bc9                 sbb ecx, ecx
// 0049e7b6  83c166               add ecx, 0x66
// 0049e7b9  52                   push edx
// 0049e7ba  8b542414             mov edx, dword ptr [esp + 0x14]
// 0049e7be  898e98000000         mov dword ptr [esi + 0x98], ecx
// 0049e7c4  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0049e7c8  51                   push ecx
// 0049e7c9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049e7cd  52                   push edx
// 0049e7ce  51                   push ecx
// 0049e7cf  50                   push eax
// 0049e7d0  8bce                 mov ecx, esi
// 0049e7d2  e813484e00           call 0x982fea
// 0049e7d7  5e                   pop esi
// 0049e7d8  c21400               ret 0x14
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