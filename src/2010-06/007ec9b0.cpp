// from server: 100% by auto
// roc 2010-06 007ec9b0  unit: CXTPDockingPaneManager  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ec9b0
//
// 007ec9b0  56                   push esi
// 007ec9b1  8b742418             mov esi, dword ptr [esp + 0x18]
// 007ec9b5  8d542408             lea edx, [esp + 8]
// 007ec9b9  33c0                 xor eax, eax
// 007ec9bb  52                   push edx
// 007ec9bc  668906               mov word ptr [esi], ax
// 007ec9bf  e82c310000           call 0x7efaf0
// 007ec9c4  85c0                 test eax, eax
// 007ec9c6  7515                 jne 0x7ec9dd
// 007ec9c8  b803000000           mov eax, 3
// 007ec9cd  668906               mov word ptr [esi], ax
// 007ec9d0  c7460826000000       mov dword ptr [esi + 8], 0x26
// 007ec9d7  33c0                 xor eax, eax
// 007ec9d9  5e                   pop esi
// 007ec9da  c21400               ret 0x14
// 007ec9dd  b857000780           mov eax, 0x80070057
// 007ec9e2  5e                   pop esi
// 007ec9e3  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleRole@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
