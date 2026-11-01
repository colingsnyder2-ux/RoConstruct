// from server: 100% by auto
// roc 2009-06 0075da30  unit: CXTPDockingPaneManager  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075da30
//
// 0075da30  56                   push esi
// 0075da31  8b742418             mov esi, dword ptr [esp + 0x18]
// 0075da35  8d542408             lea edx, [esp + 8]
// 0075da39  33c0                 xor eax, eax
// 0075da3b  52                   push edx
// 0075da3c  668906               mov word ptr [esi], ax
// 0075da3f  e88c310000           call 0x760bd0
// 0075da44  85c0                 test eax, eax
// 0075da46  7515                 jne 0x75da5d
// 0075da48  b803000000           mov eax, 3
// 0075da4d  668906               mov word ptr [esi], ax
// 0075da50  c7460826000000       mov dword ptr [esi + 8], 0x26
// 0075da57  33c0                 xor eax, eax
// 0075da59  5e                   pop esi
// 0075da5a  c21400               ret 0x14
// 0075da5d  b857000780           mov eax, 0x80070057
// 0075da62  5e                   pop esi
// 0075da63  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleRole@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
