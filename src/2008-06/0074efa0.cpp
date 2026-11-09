// from server: 100% by auto
// roc 2008-06 0074efa0  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0074efa0
//
// 0074efa0  56                   push esi
// 0074efa1  57                   push edi
// 0074efa2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0074efa6  8bf1                 mov esi, ecx
// 0074efa8  3bf7                 cmp esi, edi
// 0074efaa  741c                 je 0x74efc8
// 0074efac  8b4708               mov eax, dword ptr [edi + 8]
// 0074efaf  6aff                 push -1
// 0074efb1  50                   push eax
// 0074efb2  e819f2fbff           call 0x70e1d0
// 0074efb7  8b4f08               mov ecx, dword ptr [edi + 8]
// 0074efba  8b5704               mov edx, dword ptr [edi + 4]
// 0074efbd  8b4604               mov eax, dword ptr [esi + 4]
// 0074efc0  51                   push ecx
// 0074efc1  52                   push edx
// 0074efc2  50                   push eax
// 0074efc3  e878feffff           call 0x74ee40
// 0074efc8  5f                   pop edi
// 0074efc9  5e                   pop esi
// 0074efca  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ?Copy@?$CArray@HH@@QAEXABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
