// from server: 100% by auto
// roc 2009-06 00752720  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00752720
//
// 00752720  56                   push esi
// 00752721  57                   push edi
// 00752722  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00752726  8bf1                 mov esi, ecx
// 00752728  85ff                 test edi, edi
// 0075272a  7d05                 jge 0x752731
// 0075272c  e8b365fcff           call 0x718ce4
// 00752731  3b7e08               cmp edi, dword ptr [esi + 8]
// 00752734  7c0b                 jl 0x752741
// 00752736  6aff                 push -1
// 00752738  8d4701               lea eax, [edi + 1]
// 0075273b  50                   push eax
// 0075273c  e8cffdffff           call 0x752510
// 00752741  8b4e04               mov ecx, dword ptr [esi + 4]
// 00752744  8b542410             mov edx, dword ptr [esp + 0x10]
// 00752748  8914b9               mov dword ptr [ecx + edi*4], edx
// 0075274b  5f                   pop edi
// 0075274c  5e                   pop esi
// 0075274d  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetAtGrow@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHPAVCMFCRibbonBaseElement@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
