// from server: 100% by auto
// roc 2007-08 006d7d40  unit: CXTPDockingPaneBase  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d7d40
//
// 006d7d40  833900               cmp dword ptr [ecx], 0
// 006d7d43  7518                 jne 0x6d7d5d
// 006d7d45  83790800             cmp dword ptr [ecx + 8], 0
// 006d7d49  7512                 jne 0x6d7d5d
// 006d7d4b  83790400             cmp dword ptr [ecx + 4], 0
// 006d7d4f  750c                 jne 0x6d7d5d
// 006d7d51  83790c00             cmp dword ptr [ecx + 0xc], 0
// 006d7d55  7506                 jne 0x6d7d5d
// 006d7d57  b801000000           mov eax, 1
// 006d7d5c  c3                   ret 
// 006d7d5d  33c0                 xor eax, eax
// 006d7d5f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oledrop1.cpp (function ?IsRectNull@CRect@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledrop1.cpp
