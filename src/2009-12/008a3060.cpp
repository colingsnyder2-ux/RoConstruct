// from server: 100% by auto
// roc 2009-12 008a3060  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a3060
//
// 008a3060  56                   push esi
// 008a3061  57                   push edi
// 008a3062  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008a3066  8bf1                 mov esi, ecx
// 008a3068  3bf7                 cmp esi, edi
// 008a306a  741c                 je 0x8a3088
// 008a306c  8b4708               mov eax, dword ptr [edi + 8]
// 008a306f  6aff                 push -1
// 008a3071  50                   push eax
// 008a3072  e82923fbff           call 0x8553a0
// 008a3077  8b4f08               mov ecx, dword ptr [edi + 8]
// 008a307a  8b5704               mov edx, dword ptr [edi + 4]
// 008a307d  8b4604               mov eax, dword ptr [esi + 4]
// 008a3080  51                   push ecx
// 008a3081  52                   push edx
// 008a3082  50                   push eax
// 008a3083  e8f8defeff           call 0x890f80
// 008a3088  5f                   pop edi
// 008a3089  5e                   pop esi
// 008a308a  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ?Copy@?$CArray@HH@@QAEXABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
