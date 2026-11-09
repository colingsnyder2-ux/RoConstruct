// from server: 100% by auto
// roc 2010-06 00415d50  unit: PasteVerb  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00415d50
//
// 00415d50  56                   push esi
// 00415d51  8bf1                 mov esi, ecx
// 00415d53  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00415d57  33c0                 xor eax, eax
// 00415d59  51                   push ecx
// 00415d5a  8bce                 mov ecx, esi
// 00415d5c  668906               mov word ptr [esi], ax
// 00415d5f  e88cfeffff           call 0x415bf0
// 00415d64  8bc6                 mov eax, esi
// 00415d66  5e                   pop esi
// 00415d67  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
