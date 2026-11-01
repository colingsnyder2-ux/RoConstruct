// from server: 100% by auto
// roc 2007-03 006c0f00  unit: seg_006c0000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c0f00
//
// 006c0f00  833900               cmp dword ptr [ecx], 0
// 006c0f03  7518                 jne 0x6c0f1d
// 006c0f05  83790800             cmp dword ptr [ecx + 8], 0
// 006c0f09  7512                 jne 0x6c0f1d
// 006c0f0b  83790400             cmp dword ptr [ecx + 4], 0
// 006c0f0f  750c                 jne 0x6c0f1d
// 006c0f11  83790c00             cmp dword ptr [ecx + 0xc], 0
// 006c0f15  7506                 jne 0x6c0f1d
// 006c0f17  b801000000           mov eax, 1
// 006c0f1c  c3                   ret 
// 006c0f1d  33c0                 xor eax, eax
// 006c0f1f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oledrop1.cpp (function ?IsRectNull@CRect@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledrop1.cpp
