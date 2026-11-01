// from server: 100% by auto
// roc 2009-12 008a7fa0  unit: CXTPDockingPaneBase  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a7fa0
//
// 008a7fa0  833900               cmp dword ptr [ecx], 0
// 008a7fa3  7518                 jne 0x8a7fbd
// 008a7fa5  83790800             cmp dword ptr [ecx + 8], 0
// 008a7fa9  7512                 jne 0x8a7fbd
// 008a7fab  83790400             cmp dword ptr [ecx + 4], 0
// 008a7faf  750c                 jne 0x8a7fbd
// 008a7fb1  83790c00             cmp dword ptr [ecx + 0xc], 0
// 008a7fb5  7506                 jne 0x8a7fbd
// 008a7fb7  b801000000           mov eax, 1
// 008a7fbc  c3                   ret 
// 008a7fbd  33c0                 xor eax, eax
// 008a7fbf  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oledrop1.cpp (function ?IsRectNull@CRect@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledrop1.cpp
