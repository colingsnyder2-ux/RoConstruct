// from server: 100% by auto
// roc 2009-06 00416520  unit: CopyVerb  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00416520
//
// 00416520  56                   push esi
// 00416521  8bf1                 mov esi, ecx
// 00416523  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00416527  33c0                 xor eax, eax
// 00416529  51                   push ecx
// 0041652a  8bce                 mov ecx, esi
// 0041652c  668906               mov word ptr [esi], ax
// 0041652f  e88cfeffff           call 0x4163c0
// 00416534  8bc6                 mov eax, esi
// 00416536  5e                   pop esi
// 00416537  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
