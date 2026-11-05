// from server: 100% by auto
// roc 2007-08 006d2ae0  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d2ae0
//
// 006d2ae0  56                   push esi
// 006d2ae1  57                   push edi
// 006d2ae2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006d2ae6  8bf1                 mov esi, ecx
// 006d2ae8  3bf7                 cmp esi, edi
// 006d2aea  741c                 je 0x6d2b08
// 006d2aec  8b4708               mov eax, dword ptr [edi + 8]
// 006d2aef  6aff                 push -1
// 006d2af1  50                   push eax
// 006d2af2  e8b9cf0200           call 0x6ffab0
// 006d2af7  8b4f08               mov ecx, dword ptr [edi + 8]
// 006d2afa  8b5704               mov edx, dword ptr [edi + 4]
// 006d2afd  8b4604               mov eax, dword ptr [esi + 4]
// 006d2b00  51                   push ecx
// 006d2b01  52                   push edx
// 006d2b02  50                   push eax
// 006d2b03  e838feffff           call 0x6d2940
// 006d2b08  5f                   pop edi
// 006d2b09  5e                   pop esi
// 006d2b0a  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ?Copy@?$CArray@HH@@QAEXABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
