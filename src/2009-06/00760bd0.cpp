// from server: 100% by auto
// roc 2009-06 00760bd0  unit: CXTPToolBar::CControlButtonExpand  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760bd0
//
// 00760bd0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00760bd4  85c9                 test ecx, ecx
// 00760bd6  7445                 je 0x760c1d
// 00760bd8  0fb701               movzx eax, word ptr [ecx]
// 00760bdb  6685c0               test ax, ax
// 00760bde  7443                 je 0x760c23
// 00760be0  6683f803             cmp ax, 3
// 00760be4  7442                 je 0x760c28
// 00760be6  6683f802             cmp ax, 2
// 00760bea  7442                 je 0x760c2e
// 00760bec  ba03400000           mov edx, 0x4003
// 00760bf1  663bc2               cmp ax, dx
// 00760bf4  7506                 jne 0x760bfc
// 00760bf6  83790800             cmp dword ptr [ecx + 8], 0
// 00760bfa  7539                 jne 0x760c35
// 00760bfc  ba02400000           mov edx, 0x4002
// 00760c01  663bc2               cmp ax, dx
// 00760c04  7506                 jne 0x760c0c
// 00760c06  83790800             cmp dword ptr [ecx + 8], 0
// 00760c0a  7531                 jne 0x760c3d
// 00760c0c  ba0c400000           mov edx, 0x400c
// 00760c11  663bc2               cmp ax, dx
// 00760c14  7507                 jne 0x760c1d
// 00760c16  8b4908               mov ecx, dword ptr [ecx + 8]
// 00760c19  85c9                 test ecx, ecx
// 00760c1b  75bb                 jne 0x760bd8
// 00760c1d  83c8ff               or eax, 0xffffffff
// 00760c20  c20400               ret 4
// 00760c23  33c0                 xor eax, eax
// 00760c25  c20400               ret 4
// 00760c28  8b4108               mov eax, dword ptr [ecx + 8]
// 00760c2b  c20400               ret 4
// 00760c2e  0fbf4108             movsx eax, word ptr [ecx + 8]
// 00760c32  c20400               ret 4
// 00760c35  8b4108               mov eax, dword ptr [ecx + 8]
// 00760c38  8b00                 mov eax, dword ptr [eax]
// 00760c3a  c20400               ret 4
// 00760c3d  8b4908               mov ecx, dword ptr [ecx + 8]
// 00760c40  0fbf01               movsx eax, word ptr [ecx]
// 00760c43  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetChildIndex@CXTPAccessible@@IAEJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
