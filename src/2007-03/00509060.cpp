// from server: 100% by auto
// roc 2007-03 00509060  unit: seg_00500000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509060
//
// 00509060  837c240400           cmp dword ptr [esp + 4], 0
// 00509065  7423                 je 0x50908a
// 00509067  8b442408             mov eax, dword ptr [esp + 8]
// 0050906b  85c0                 test eax, eax
// 0050906d  741b                 je 0x50908a
// 0050906f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00509073  8b11                 mov edx, dword ptr [ecx]
// 00509075  89505a               mov dword ptr [eax + 0x5a], edx
// 00509078  8b5104               mov edx, dword ptr [ecx + 4]
// 0050907b  89505e               mov dword ptr [eax + 0x5e], edx
// 0050907e  668b4908             mov cx, word ptr [ecx + 8]
// 00509082  83480820             or dword ptr [eax + 8], 0x20
// 00509086  66894862             mov word ptr [eax + 0x62], cx
// 0050908a  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
