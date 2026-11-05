// from server: 100% by auto
// roc 2011-06 008c2660  unit: CXTPDockingPaneTabbedContainer  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008c2660
//
// 008c2660  56                   push esi
// 008c2661  8b742418             mov esi, dword ptr [esp + 0x18]
// 008c2665  8d542408             lea edx, [esp + 8]
// 008c2669  33c0                 xor eax, eax
// 008c266b  52                   push edx
// 008c266c  668906               mov word ptr [esi], ax
// 008c266f  e8bcecf8ff           call 0x851330
// 008c2674  85c0                 test eax, eax
// 008c2676  7515                 jne 0x8c268d
// 008c2678  b803000000           mov eax, 3
// 008c267d  668906               mov word ptr [esi], ax
// 008c2680  c746083c000000       mov dword ptr [esi + 8], 0x3c
// 008c2687  33c0                 xor eax, eax
// 008c2689  5e                   pop esi
// 008c268a  c21400               ret 0x14
// 008c268d  b857000780           mov eax, 0x80070057
// 008c2692  5e                   pop esi
// 008c2693  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetAccessibleRole@CXTPDockingPaneTabbedContainer@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
