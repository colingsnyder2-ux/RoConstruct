// from server: 100% by auto
// roc 2010-06 00845310  unit: CXTPDockBar  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00845310
//
// 00845310  56                   push esi
// 00845311  57                   push edi
// 00845312  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00845316  8bf1                 mov esi, ecx
// 00845318  3bf7                 cmp esi, edi
// 0084531a  741c                 je 0x845338
// 0084531c  8b4708               mov eax, dword ptr [edi + 8]
// 0084531f  6aff                 push -1
// 00845321  50                   push eax
// 00845322  e8d9bff9ff           call 0x7e1300
// 00845327  8b4f08               mov ecx, dword ptr [edi + 8]
// 0084532a  8b5704               mov edx, dword ptr [edi + 4]
// 0084532d  8b4604               mov eax, dword ptr [esi + 4]
// 00845330  51                   push ecx
// 00845331  52                   push edx
// 00845332  50                   push eax
// 00845333  e8681d0100           call 0x8570a0
// 00845338  5f                   pop edi
// 00845339  5e                   pop esi
// 0084533a  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ?Copy@?$CArray@HH@@QAEXABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
