// from server: 100% by auto
// roc 2009-12 0083b9a0  unit: CXTPToolBar::CControlButtonExpand  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b9a0
//
// 0083b9a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083b9a4  85c9                 test ecx, ecx
// 0083b9a6  7445                 je 0x83b9ed
// 0083b9a8  0fb701               movzx eax, word ptr [ecx]
// 0083b9ab  6685c0               test ax, ax
// 0083b9ae  7443                 je 0x83b9f3
// 0083b9b0  6683f803             cmp ax, 3
// 0083b9b4  7442                 je 0x83b9f8
// 0083b9b6  6683f802             cmp ax, 2
// 0083b9ba  7442                 je 0x83b9fe
// 0083b9bc  ba03400000           mov edx, 0x4003
// 0083b9c1  663bc2               cmp ax, dx
// 0083b9c4  7506                 jne 0x83b9cc
// 0083b9c6  83790800             cmp dword ptr [ecx + 8], 0
// 0083b9ca  7539                 jne 0x83ba05
// 0083b9cc  ba02400000           mov edx, 0x4002
// 0083b9d1  663bc2               cmp ax, dx
// 0083b9d4  7506                 jne 0x83b9dc
// 0083b9d6  83790800             cmp dword ptr [ecx + 8], 0
// 0083b9da  7531                 jne 0x83ba0d
// 0083b9dc  ba0c400000           mov edx, 0x400c
// 0083b9e1  663bc2               cmp ax, dx
// 0083b9e4  7507                 jne 0x83b9ed
// 0083b9e6  8b4908               mov ecx, dword ptr [ecx + 8]
// 0083b9e9  85c9                 test ecx, ecx
// 0083b9eb  75bb                 jne 0x83b9a8
// 0083b9ed  83c8ff               or eax, 0xffffffff
// 0083b9f0  c20400               ret 4
// 0083b9f3  33c0                 xor eax, eax
// 0083b9f5  c20400               ret 4
// 0083b9f8  8b4108               mov eax, dword ptr [ecx + 8]
// 0083b9fb  c20400               ret 4
// 0083b9fe  0fbf4108             movsx eax, word ptr [ecx + 8]
// 0083ba02  c20400               ret 4
// 0083ba05  8b4108               mov eax, dword ptr [ecx + 8]
// 0083ba08  8b00                 mov eax, dword ptr [eax]
// 0083ba0a  c20400               ret 4
// 0083ba0d  8b4908               mov ecx, dword ptr [ecx + 8]
// 0083ba10  0fbf01               movsx eax, word ptr [ecx]
// 0083ba13  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetChildIndex@CXTPAccessible@@IAEJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
