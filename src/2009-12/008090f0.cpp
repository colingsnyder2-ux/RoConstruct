// from server: 100% by auto
// roc 2009-12 008090f0  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008090f0
//
// 008090f0  83790400             cmp dword ptr [ecx + 4], 0
// 008090f4  750f                 jne 0x809105
// 008090f6  8b4114               mov eax, dword ptr [ecx + 0x14]
// 008090f9  85c0                 test eax, eax
// 008090fb  7405                 je 0x809102
// 008090fd  833800               cmp dword ptr [eax], 0
// 00809100  7503                 jne 0x809105
// 00809102  33c0                 xor eax, eax
// 00809104  c3                   ret 
// 00809105  b801000000           mov eax, 1
// 0080910a  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?IsAlpha@CXTPImageManagerIconHandle@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
