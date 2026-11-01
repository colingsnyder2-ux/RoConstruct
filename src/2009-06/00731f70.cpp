// from server: 100% by auto
// roc 2009-06 00731f70  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00731f70
//
// 00731f70  83790400             cmp dword ptr [ecx + 4], 0
// 00731f74  750f                 jne 0x731f85
// 00731f76  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00731f79  85c0                 test eax, eax
// 00731f7b  7405                 je 0x731f82
// 00731f7d  833800               cmp dword ptr [eax], 0
// 00731f80  7503                 jne 0x731f85
// 00731f82  33c0                 xor eax, eax
// 00731f84  c3                   ret 
// 00731f85  b801000000           mov eax, 1
// 00731f8a  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsAlpha@CXTPImageManagerIconHandle@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
