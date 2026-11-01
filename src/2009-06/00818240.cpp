// from server: 100% by auto
// roc 2009-06 00818240  unit: CXTPDockingPaneAutoHidePanel  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00818240
//
// 00818240  56                   push esi
// 00818241  8b713c               mov esi, dword ptr [ecx + 0x3c]
// 00818244  85f6                 test esi, esi
// 00818246  7416                 je 0x81825e
// 00818248  8bc6                 mov eax, esi
// 0081824a  8b4808               mov ecx, dword ptr [eax + 8]
// 0081824d  8b01                 mov eax, dword ptr [ecx]
// 0081824f  8b5014               mov edx, dword ptr [eax + 0x14]
// 00818252  8b36                 mov esi, dword ptr [esi]
// 00818254  ffd2                 call edx
// 00818256  85c0                 test eax, eax
// 00818258  740b                 je 0x818265
// 0081825a  85f6                 test esi, esi
// 0081825c  75ea                 jne 0x818248
// 0081825e  b801000000           mov eax, 1
// 00818263  5e                   pop esi
// 00818264  c3                   ret 
// 00818265  33c0                 xor eax, eax
// 00818267  5e                   pop esi
// 00818268  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?IsEmpty@CXTPDockingPaneBaseContainer@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
