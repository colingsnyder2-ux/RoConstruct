// from server: 100% by auto
// roc 2008-06 00754b70  unit: CXTPDockingPaneBase  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00754b70
//
// 00754b70  833900               cmp dword ptr [ecx], 0
// 00754b73  7518                 jne 0x754b8d
// 00754b75  83790800             cmp dword ptr [ecx + 8], 0
// 00754b79  7512                 jne 0x754b8d
// 00754b7b  83790400             cmp dword ptr [ecx + 4], 0
// 00754b7f  750c                 jne 0x754b8d
// 00754b81  83790c00             cmp dword ptr [ecx + 0xc], 0
// 00754b85  7506                 jne 0x754b8d
// 00754b87  b801000000           mov eax, 1
// 00754b8c  c3                   ret 
// 00754b8d  33c0                 xor eax, eax
// 00754b8f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcontrolrenderer.cpp (function ?IsRectNull@CRect@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontrolrenderer.cpp
