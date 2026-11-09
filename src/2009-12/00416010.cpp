// from server: 100% by auto
// roc 2009-12 00416010  unit: PasteVerb  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00416010
//
// 00416010  56                   push esi
// 00416011  8bf1                 mov esi, ecx
// 00416013  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00416017  33c0                 xor eax, eax
// 00416019  51                   push ecx
// 0041601a  8bce                 mov ecx, esi
// 0041601c  668906               mov word ptr [esi], ax
// 0041601f  e88cfeffff           call 0x415eb0
// 00416024  8bc6                 mov eax, esi
// 00416026  5e                   pop esi
// 00416027  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
