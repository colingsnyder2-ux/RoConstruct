// from server: 100% by auto
// roc 2009-06 00776240  unit: CXTPPropExchangeXMLNode  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00776240
//
// 00776240  56                   push esi
// 00776241  8bf1                 mov esi, ecx
// 00776243  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00776247  33c0                 xor eax, eax
// 00776249  51                   push ecx
// 0077624a  8bce                 mov ecx, esi
// 0077624c  668906               mov word ptr [esi], ax
// 0077624f  e8a0620d00           call 0x84c4f4
// 00776254  8bc6                 mov eax, esi
// 00776256  5e                   pop esi
// 00776257  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
