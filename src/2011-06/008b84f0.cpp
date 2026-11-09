// from server: 100% by auto
// roc 2011-06 008b84f0  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b84f0
//
// 008b84f0  56                   push esi
// 008b84f1  57                   push edi
// 008b84f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008b84f6  8bf1                 mov esi, ecx
// 008b84f8  3bf7                 cmp esi, edi
// 008b84fa  741c                 je 0x8b8518
// 008b84fc  8b4708               mov eax, dword ptr [edi + 8]
// 008b84ff  6aff                 push -1
// 008b8501  50                   push eax
// 008b8502  e83966f8ff           call 0x83eb40
// 008b8507  8b4f08               mov ecx, dword ptr [edi + 8]
// 008b850a  8b5704               mov edx, dword ptr [edi + 4]
// 008b850d  8b4604               mov eax, dword ptr [esi + 4]
// 008b8510  51                   push ecx
// 008b8511  52                   push edx
// 008b8512  50                   push eax
// 008b8513  e848feffff           call 0x8b8360
// 008b8518  5f                   pop edi
// 008b8519  5e                   pop esi
// 008b851a  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ?Copy@?$CArray@HH@@QAEXABV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
