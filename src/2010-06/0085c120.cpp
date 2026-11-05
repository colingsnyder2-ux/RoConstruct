// from server: 100% by auto
// roc 2010-06 0085c120  unit: CXTPDockingPaneBase  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085c120
//
// 0085c120  833900               cmp dword ptr [ecx], 0
// 0085c123  7518                 jne 0x85c13d
// 0085c125  83790800             cmp dword ptr [ecx + 8], 0
// 0085c129  7512                 jne 0x85c13d
// 0085c12b  83790400             cmp dword ptr [ecx + 4], 0
// 0085c12f  750c                 jne 0x85c13d
// 0085c131  83790c00             cmp dword ptr [ecx + 0xc], 0
// 0085c135  7506                 jne 0x85c13d
// 0085c137  b801000000           mov eax, 1
// 0085c13c  c3                   ret 
// 0085c13d  33c0                 xor eax, eax
// 0085c13f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcontrolrenderer.cpp (function ?IsRectNull@CRect@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontrolrenderer.cpp
