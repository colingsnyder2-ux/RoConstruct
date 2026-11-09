// from server: 100% by auto
// roc 2008-06 006fd8e0  unit: CXTCaptionButtonTheme  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fd8e0
//
// 006fd8e0  56                   push esi
// 006fd8e1  8bf1                 mov esi, ecx
// 006fd8e3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006fd8e7  33c0                 xor eax, eax
// 006fd8e9  51                   push ecx
// 006fd8ea  8bce                 mov ecx, esi
// 006fd8ec  668906               mov word ptr [esi], ax
// 006fd8ef  e84ced0b00           call 0x7bc640
// 006fd8f4  8bc6                 mov eax, esi
// 006fd8f6  5e                   pop esi
// 006fd8f7  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
