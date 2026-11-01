// from server: 100% by auto
// roc 2009-06 007d65f0  unit: CXTPDockingPaneTabbedContainer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d65f0
//
// 007d65f0  56                   push esi
// 007d65f1  8b742418             mov esi, dword ptr [esp + 0x18]
// 007d65f5  8d542408             lea edx, [esp + 8]
// 007d65f9  33c0                 xor eax, eax
// 007d65fb  52                   push edx
// 007d65fc  668906               mov word ptr [esi], ax
// 007d65ff  e8cca5f8ff           call 0x760bd0
// 007d6604  85c0                 test eax, eax
// 007d6606  7515                 jne 0x7d661d
// 007d6608  b803000000           mov eax, 3
// 007d660d  668906               mov word ptr [esi], ax
// 007d6610  c746083c000000       mov dword ptr [esi + 8], 0x3c
// 007d6617  33c0                 xor eax, eax
// 007d6619  5e                   pop esi
// 007d661a  c21400               ret 0x14
// 007d661d  b857000780           mov eax, 0x80070057
// 007d6622  5e                   pop esi
// 007d6623  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetAccessibleRole@CXTPDockingPaneTabbedContainer@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
