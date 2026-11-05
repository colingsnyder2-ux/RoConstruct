// from server: 100% by auto
// roc 2009-06 007cd190  unit: CXTPDockingPaneBase  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cd190
//
// 007cd190  833900               cmp dword ptr [ecx], 0
// 007cd193  7518                 jne 0x7cd1ad
// 007cd195  83790800             cmp dword ptr [ecx + 8], 0
// 007cd199  7512                 jne 0x7cd1ad
// 007cd19b  83790400             cmp dword ptr [ecx + 4], 0
// 007cd19f  750c                 jne 0x7cd1ad
// 007cd1a1  83790c00             cmp dword ptr [ecx + 0xc], 0
// 007cd1a5  7506                 jne 0x7cd1ad
// 007cd1a7  b801000000           mov eax, 1
// 007cd1ac  c3                   ret 
// 007cd1ad  33c0                 xor eax, eax
// 007cd1af  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcontrolrenderer.cpp (function ?IsRectNull@CRect@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontrolrenderer.cpp
