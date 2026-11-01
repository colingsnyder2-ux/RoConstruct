// from server: 100% by auto
// roc 2009-12 008b1130  unit: CXTPDockingPaneTabbedContainer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b1130
//
// 008b1130  56                   push esi
// 008b1131  8b742418             mov esi, dword ptr [esp + 0x18]
// 008b1135  8d542408             lea edx, [esp + 8]
// 008b1139  33c0                 xor eax, eax
// 008b113b  52                   push edx
// 008b113c  668906               mov word ptr [esi], ax
// 008b113f  e85ca8f8ff           call 0x83b9a0
// 008b1144  85c0                 test eax, eax
// 008b1146  7515                 jne 0x8b115d
// 008b1148  b803000000           mov eax, 3
// 008b114d  668906               mov word ptr [esi], ax
// 008b1150  c746083c000000       mov dword ptr [esi + 8], 0x3c
// 008b1157  33c0                 xor eax, eax
// 008b1159  5e                   pop esi
// 008b115a  c21400               ret 0x14
// 008b115d  b857000780           mov eax, 0x80070057
// 008b1162  5e                   pop esi
// 008b1163  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetAccessibleRole@CXTPDockingPaneTabbedContainer@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
