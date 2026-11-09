// from server: 100% by auto
// roc 2010-06 007e14b0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e14b0
//
// 007e14b0  56                   push esi
// 007e14b1  57                   push edi
// 007e14b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007e14b6  8bf1                 mov esi, ecx
// 007e14b8  85ff                 test edi, edi
// 007e14ba  7d05                 jge 0x7e14c1
// 007e14bc  e88b67fcff           call 0x7a7c4c
// 007e14c1  3b7e08               cmp edi, dword ptr [esi + 8]
// 007e14c4  7c0b                 jl 0x7e14d1
// 007e14c6  6aff                 push -1
// 007e14c8  8d4701               lea eax, [edi + 1]
// 007e14cb  50                   push eax
// 007e14cc  e82ffeffff           call 0x7e1300
// 007e14d1  8b4e04               mov ecx, dword ptr [esi + 4]
// 007e14d4  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e14d8  8914b9               mov dword ptr [ecx + edi*4], edx
// 007e14db  5f                   pop edi
// 007e14dc  5e                   pop esi
// 007e14dd  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetAtGrow@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHPAVCMFCRibbonBaseElement@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
