// from server: 100% by auto
// roc 2008-06 0070e320  unit: CXTPStatusBar  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070e320
//
// 0070e320  56                   push esi
// 0070e321  57                   push edi
// 0070e322  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0070e326  8bf1                 mov esi, ecx
// 0070e328  85ff                 test edi, edi
// 0070e32a  7d05                 jge 0x70e331
// 0070e32c  e81326f9ff           call 0x6a0944
// 0070e331  3b7e08               cmp edi, dword ptr [esi + 8]
// 0070e334  7c0b                 jl 0x70e341
// 0070e336  6aff                 push -1
// 0070e338  8d4701               lea eax, [edi + 1]
// 0070e33b  50                   push eax
// 0070e33c  e88ffeffff           call 0x70e1d0
// 0070e341  8b4e04               mov ecx, dword ptr [esi + 4]
// 0070e344  8b542410             mov edx, dword ptr [esp + 0x10]
// 0070e348  8914b9               mov dword ptr [ecx + edi*4], edx
// 0070e34b  5f                   pop edi
// 0070e34c  5e                   pop esi
// 0070e34d  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetAtGrow@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHPAVCMFCRibbonBaseElement@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
