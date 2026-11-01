// from server: 100% by auto
// roc 2007-03 005c2740  unit: seg_005c0000  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2740
//
// 005c2740  80790600             cmp byte ptr [ecx + 6], 0
// 005c2744  742a                 je 0x5c2770
// 005c2746  83c9ff               or ecx, 0xffffffff
// 005c2749  c740102c9a7b00       mov dword ptr [eax + 0x10], 0x7b9a2c
// 005c2750  89481c               mov dword ptr [eax + 0x1c], ecx
// 005c2753  894820               mov dword ptr [eax + 0x20], ecx
// 005c2756  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005c2759  6a3c                 push 0x3c
// 005c275b  c7400c289a7b00       mov dword ptr [eax + 0xc], 0x7b9a28
// 005c2762  51                   push ecx
// 005c2763  83c024               add eax, 0x24
// 005c2766  50                   push eax
// 005c2767  e8f4600300           call 0x5f8860
// 005c276c  83c40c               add esp, 0xc
// 005c276f  c3                   ret 
// 005c2770  8b5110               mov edx, dword ptr [ecx + 0x10]
// 005c2773  8b5220               mov edx, dword ptr [edx + 0x20]
// 005c2776  83c210               add edx, 0x10
// 005c2779  895010               mov dword ptr [eax + 0x10], edx
// 005c277c  8b5110               mov edx, dword ptr [ecx + 0x10]
// 005c277f  8b523c               mov edx, dword ptr [edx + 0x3c]
// 005c2782  89501c               mov dword ptr [eax + 0x1c], edx
// 005c2785  83781c00             cmp dword ptr [eax + 0x1c], 0
// 005c2789  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 005c278c  8b5140               mov edx, dword ptr [ecx + 0x40]
// 005c278f  895020               mov dword ptr [eax + 0x20], edx
// 005c2792  b9209a7b00           mov ecx, 0x7b9a20
// 005c2797  7405                 je 0x5c279e
// 005c2799  b9805e7a00           mov ecx, 0x7a5e80
// 005c279e  89480c               mov dword ptr [eax + 0xc], ecx
// 005c27a1  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005c27a4  6a3c                 push 0x3c
// 005c27a6  51                   push ecx
// 005c27a7  83c024               add eax, 0x24
// 005c27aa  50                   push eax
// 005c27ab  e8b0600300           call 0x5f8860
// 005c27b0  83c40c               add esp, 0xc
// 005c27b3  c3                   ret 
// library lua-5.1.1/ldebug.c (function _funcinfo)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
