// from server: 100% by auto
// roc 2010-06 007bd290  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bd290
//
// 007bd290  83790400             cmp dword ptr [ecx + 4], 0
// 007bd294  750f                 jne 0x7bd2a5
// 007bd296  8b4114               mov eax, dword ptr [ecx + 0x14]
// 007bd299  85c0                 test eax, eax
// 007bd29b  7405                 je 0x7bd2a2
// 007bd29d  833800               cmp dword ptr [eax], 0
// 007bd2a0  7503                 jne 0x7bd2a5
// 007bd2a2  33c0                 xor eax, eax
// 007bd2a4  c3                   ret 
// 007bd2a5  b801000000           mov eax, 1
// 007bd2aa  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?IsAlpha@CXTPImageManagerIconHandle@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
