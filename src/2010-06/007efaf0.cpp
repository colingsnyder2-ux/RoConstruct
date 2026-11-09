// from server: 100% by auto
// roc 2010-06 007efaf0  unit: CXTPToolBar::CControlButtonExpand  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efaf0
//
// 007efaf0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007efaf4  85c9                 test ecx, ecx
// 007efaf6  7445                 je 0x7efb3d
// 007efaf8  0fb701               movzx eax, word ptr [ecx]
// 007efafb  6685c0               test ax, ax
// 007efafe  7443                 je 0x7efb43
// 007efb00  6683f803             cmp ax, 3
// 007efb04  7442                 je 0x7efb48
// 007efb06  6683f802             cmp ax, 2
// 007efb0a  7442                 je 0x7efb4e
// 007efb0c  ba03400000           mov edx, 0x4003
// 007efb11  663bc2               cmp ax, dx
// 007efb14  7506                 jne 0x7efb1c
// 007efb16  83790800             cmp dword ptr [ecx + 8], 0
// 007efb1a  7539                 jne 0x7efb55
// 007efb1c  ba02400000           mov edx, 0x4002
// 007efb21  663bc2               cmp ax, dx
// 007efb24  7506                 jne 0x7efb2c
// 007efb26  83790800             cmp dword ptr [ecx + 8], 0
// 007efb2a  7531                 jne 0x7efb5d
// 007efb2c  ba0c400000           mov edx, 0x400c
// 007efb31  663bc2               cmp ax, dx
// 007efb34  7507                 jne 0x7efb3d
// 007efb36  8b4908               mov ecx, dword ptr [ecx + 8]
// 007efb39  85c9                 test ecx, ecx
// 007efb3b  75bb                 jne 0x7efaf8
// 007efb3d  83c8ff               or eax, 0xffffffff
// 007efb40  c20400               ret 4
// 007efb43  33c0                 xor eax, eax
// 007efb45  c20400               ret 4
// 007efb48  8b4108               mov eax, dword ptr [ecx + 8]
// 007efb4b  c20400               ret 4
// 007efb4e  0fbf4108             movsx eax, word ptr [ecx + 8]
// 007efb52  c20400               ret 4
// 007efb55  8b4108               mov eax, dword ptr [ecx + 8]
// 007efb58  8b00                 mov eax, dword ptr [eax]
// 007efb5a  c20400               ret 4
// 007efb5d  8b4908               mov ecx, dword ptr [ecx + 8]
// 007efb60  0fbf01               movsx eax, word ptr [ecx]
// 007efb63  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetChildIndex@CXTPAccessible@@IAEJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
