// from server: 100% by auto
// roc 2011-06 008b9290  unit: CXTPDockingPaneBase  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b9290
//
// 008b9290  833900               cmp dword ptr [ecx], 0
// 008b9293  7518                 jne 0x8b92ad
// 008b9295  83790800             cmp dword ptr [ecx + 8], 0
// 008b9299  7512                 jne 0x8b92ad
// 008b929b  83790400             cmp dword ptr [ecx + 4], 0
// 008b929f  750c                 jne 0x8b92ad
// 008b92a1  83790c00             cmp dword ptr [ecx + 0xc], 0
// 008b92a5  7506                 jne 0x8b92ad
// 008b92a7  b801000000           mov eax, 1
// 008b92ac  c3                   ret 
// 008b92ad  33c0                 xor eax, eax
// 008b92af  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcontrolrenderer.cpp (function ?IsRectNull@CRect@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontrolrenderer.cpp
