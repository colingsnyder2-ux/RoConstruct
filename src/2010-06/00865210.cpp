// from server: 100% by auto
// roc 2010-06 00865210  unit: CXTPDockingPaneTabbedContainer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00865210
//
// 00865210  56                   push esi
// 00865211  8b742418             mov esi, dword ptr [esp + 0x18]
// 00865215  8d542408             lea edx, [esp + 8]
// 00865219  33c0                 xor eax, eax
// 0086521b  52                   push edx
// 0086521c  668906               mov word ptr [esi], ax
// 0086521f  e8cca8f8ff           call 0x7efaf0
// 00865224  85c0                 test eax, eax
// 00865226  7515                 jne 0x86523d
// 00865228  b803000000           mov eax, 3
// 0086522d  668906               mov word ptr [esi], ax
// 00865230  c746083c000000       mov dword ptr [esi + 8], 0x3c
// 00865237  33c0                 xor eax, eax
// 00865239  5e                   pop esi
// 0086523a  c21400               ret 0x14
// 0086523d  b857000780           mov eax, 0x80070057
// 00865242  5e                   pop esi
// 00865243  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetAccessibleRole@CXTPDockingPaneTabbedContainer@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
