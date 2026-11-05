// from server: 100% by auto
// roc 2009-12 00850fa0  unit: CXTPPropExchangeXMLNode  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00850fa0
//
// 00850fa0  56                   push esi
// 00850fa1  8bf1                 mov esi, ecx
// 00850fa3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00850fa7  33c0                 xor eax, eax
// 00850fa9  51                   push ecx
// 00850faa  8bce                 mov ecx, esi
// 00850fac  668906               mov word ptr [esi], ax
// 00850faf  e8ac5a0d00           call 0x926a60
// 00850fb4  8bc6                 mov eax, esi
// 00850fb6  5e                   pop esi
// 00850fb7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
