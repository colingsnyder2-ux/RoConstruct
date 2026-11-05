// from server: 100% by auto
// roc 2007-03 006b5f70  unit: seg_006b0000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b5f70
//
// 006b5f70  56                   push esi
// 006b5f71  57                   push edi
// 006b5f72  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b5f76  8bf1                 mov esi, ecx
// 006b5f78  3bf7                 cmp esi, edi
// 006b5f7a  741c                 je 0x6b5f98
// 006b5f7c  8b4708               mov eax, dword ptr [edi + 8]
// 006b5f7f  6aff                 push -1
// 006b5f81  50                   push eax
// 006b5f82  e89952daff           call 0x45b220
// 006b5f87  8b4f08               mov ecx, dword ptr [edi + 8]
// 006b5f8a  8b5704               mov edx, dword ptr [edi + 4]
// 006b5f8d  8b4604               mov eax, dword ptr [esi + 4]
// 006b5f90  51                   push ecx
// 006b5f91  52                   push edx
// 006b5f92  50                   push eax
// 006b5f93  e888e9fdff           call 0x694920
// 006b5f98  5f                   pop edi
// 006b5f99  5e                   pop esi
// 006b5f9a  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ?Copy@?$CArray@HH@@QAEXABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
