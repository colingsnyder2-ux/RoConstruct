// from server: 100% by Yeetserama
// roc 2010-06 0046f160  unit: Scintilla::CScintillaFindReplaceDlg  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046f160
//
// 0046f160  56                   push esi
// 0046f161  8bf1                 mov esi, ecx
// 0046f163  e8f68a3300           call 0x7a7c5e
// 0046f168  8b400c               mov eax, dword ptr [eax + 0xc]
// 0046f16b  818e8000000000020000 or dword ptr [esi + 0x80], 0x200
// 0046f175  8b542418             mov edx, dword ptr [esp + 0x18]
// 0046f179  89467c               mov dword ptr [esi + 0x7c], eax
// 0046f17c  8b442408             mov eax, dword ptr [esp + 8]
// 0046f180  8bc8                 mov ecx, eax
// 0046f182  f7d9                 neg ecx
// 0046f184  1bc9                 sbb ecx, ecx
// 0046f186  83c166               add ecx, 0x66
// 0046f189  52                   push edx
// 0046f18a  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046f18e  898e98000000         mov dword ptr [esi + 0x98], ecx
// 0046f194  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046f198  51                   push ecx
// 0046f199  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046f19d  52                   push edx
// 0046f19e  51                   push ecx
// 0046f19f  50                   push eax
// 0046f1a0  8bce                 mov ecx, esi
// 0046f1a2  e8bd963300           call 0x7a8864
// 0046f1a7  5e                   pop esi
// 0046f1a8  c21400               ret 0x14
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
