// from server: 100% by auto
// roc 2010-06 00805010  unit: CXTCaptionButtonTheme  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805010
//
// 00805010  56                   push esi
// 00805011  8bf1                 mov esi, ecx
// 00805013  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00805017  33c0                 xor eax, eax
// 00805019  51                   push ecx
// 0080501a  8bce                 mov ecx, esi
// 0080501c  668906               mov word ptr [esi], ax
// 0080501f  e87e831700           call 0x97d3a2
// 00805024  8bc6                 mov eax, esi
// 00805026  5e                   pop esi
// 00805027  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
