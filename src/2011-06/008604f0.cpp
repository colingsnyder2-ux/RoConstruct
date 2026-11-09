// from server: 100% by auto
// roc 2011-06 008604f0  unit: CXTCaptionButtonTheme  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008604f0
//
// 008604f0  56                   push esi
// 008604f1  8bf1                 mov esi, ecx
// 008604f3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008604f7  33c0                 xor eax, eax
// 008604f9  51                   push ecx
// 008604fa  8bce                 mov ecx, esi
// 008604fc  668906               mov word ptr [esi], ax
// 008604ff  e892c41600           call 0x9cc996
// 00860504  8bc6                 mov eax, esi
// 00860506  5e                   pop esi
// 00860507  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
