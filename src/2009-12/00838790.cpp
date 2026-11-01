// from server: 100% by auto
// roc 2009-12 00838790  unit: CXTPDockingPaneManager  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00838790
//
// 00838790  56                   push esi
// 00838791  8b742418             mov esi, dword ptr [esp + 0x18]
// 00838795  8d542408             lea edx, [esp + 8]
// 00838799  33c0                 xor eax, eax
// 0083879b  52                   push edx
// 0083879c  668906               mov word ptr [esi], ax
// 0083879f  e8fc310000           call 0x83b9a0
// 008387a4  85c0                 test eax, eax
// 008387a6  7515                 jne 0x8387bd
// 008387a8  b803000000           mov eax, 3
// 008387ad  668906               mov word ptr [esi], ax
// 008387b0  c7460826000000       mov dword ptr [esi + 8], 0x26
// 008387b7  33c0                 xor eax, eax
// 008387b9  5e                   pop esi
// 008387ba  c21400               ret 0x14
// 008387bd  b857000780           mov eax, 0x80070057
// 008387c2  5e                   pop esi
// 008387c3  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleRole@CXTPDockingPaneManager@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
