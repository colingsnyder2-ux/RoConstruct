// from server: 100% by Xemicl
// roc 2012-06 00416a30  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00416a30
//
// 00416a30  8b442408             mov eax, dword ptr [esp + 8]
// 00416a34  68bc94b500           push 0xb594bc
// 00416a39  50                   push eax
// 00416a3a  e871ff0800           call 0x4a69b0
// 00416a3f  83c408               add esp, 8
// 00416a42  c20800               ret 8
// copied from an identical function in another client (function ?f_0040f2f0@@YGHHH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct ExeGuid { unsigned long a; unsigned short b, c; unsigned char d[8]; };
extern const ExeGuid guid_8b6a38;
int __cdecl helper_4683a0(int, const ExeGuid*);
int __stdcall f_0040f2f0(int, int b)
{
    return helper_4683a0(b, &guid_8b6a38);
}