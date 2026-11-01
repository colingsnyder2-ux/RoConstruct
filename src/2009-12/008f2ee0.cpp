// from server: 100% by auto
// roc 2009-12 008f2ee0  unit: CXTPDockingPaneAutoHidePanel  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2ee0
//
// 008f2ee0  56                   push esi
// 008f2ee1  8b713c               mov esi, dword ptr [ecx + 0x3c]
// 008f2ee4  85f6                 test esi, esi
// 008f2ee6  7416                 je 0x8f2efe
// 008f2ee8  8bc6                 mov eax, esi
// 008f2eea  8b4808               mov ecx, dword ptr [eax + 8]
// 008f2eed  8b01                 mov eax, dword ptr [ecx]
// 008f2eef  8b5014               mov edx, dword ptr [eax + 0x14]
// 008f2ef2  8b36                 mov esi, dword ptr [esi]
// 008f2ef4  ffd2                 call edx
// 008f2ef6  85c0                 test eax, eax
// 008f2ef8  740b                 je 0x8f2f05
// 008f2efa  85f6                 test esi, esi
// 008f2efc  75ea                 jne 0x8f2ee8
// 008f2efe  b801000000           mov eax, 1
// 008f2f03  5e                   pop esi
// 008f2f04  c3                   ret 
// 008f2f05  33c0                 xor eax, eax
// 008f2f07  5e                   pop esi
// 008f2f08  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?IsEmpty@CXTPDockingPaneBaseContainer@@MBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
