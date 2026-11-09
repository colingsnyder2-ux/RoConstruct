// from server: 100% by auto
// roc 2008-06 004162f0  unit: CopyVerb  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004162f0
//
// 004162f0  56                   push esi
// 004162f1  8bf1                 mov esi, ecx
// 004162f3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004162f7  33c0                 xor eax, eax
// 004162f9  51                   push ecx
// 004162fa  8bce                 mov ecx, esi
// 004162fc  668906               mov word ptr [esi], ax
// 004162ff  e86cfaffff           call 0x415d70
// 00416304  8bc6                 mov eax, esi
// 00416306  5e                   pop esi
// 00416307  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ??0COleVariant@@QAE@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
