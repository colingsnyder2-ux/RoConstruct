// from server: 100% by auto
// roc 2007-03 00707240  unit: seg_00700000  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00707240
//
// 00707240  56                   push esi
// 00707241  8bf1                 mov esi, ecx
// 00707243  ff154cee7700         call dword ptr [0x77ee4c]
// 00707249  8d4e60               lea ecx, [esi + 0x60]
// 0070724c  85c9                 test ecx, ecx
// 0070724e  7403                 je 0x707253
// 00707250  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00707253  3bc1                 cmp eax, ecx
// 00707255  7460                 je 0x7072b7
// 00707257  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 0070725d  85c9                 test ecx, ecx
// 0070725f  7403                 je 0x707264
// 00707261  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00707264  3bc1                 cmp eax, ecx
// 00707266  744f                 je 0x7072b7
// 00707268  85f6                 test esi, esi
// 0070726a  7504                 jne 0x707270
// 0070726c  33c9                 xor ecx, ecx
// 0070726e  eb03                 jmp 0x707273
// 00707270  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00707273  3bc1                 cmp eax, ecx
// 00707275  7440                 je 0x7072b7
// 00707277  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0070727a  85c9                 test ecx, ecx
// 0070727c  7403                 je 0x707281
// 0070727e  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00707281  3bc1                 cmp eax, ecx
// 00707283  7432                 je 0x7072b7
// 00707285  8b4654               mov eax, dword ptr [esi + 0x54]
// 00707288  85c0                 test eax, eax
// 0070728a  7403                 je 0x70728f
// 0070728c  8b4020               mov eax, dword ptr [eax + 0x20]
// 0070728f  50                   push eax
// 00707290  ff1574ed7700         call dword ptr [0x77ed74]
// 00707296  85c0                 test eax, eax
// 00707298  741d                 je 0x7072b7
// 0070729a  8b4654               mov eax, dword ptr [esi + 0x54]
// 0070729d  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007072a0  6a00                 push 0
// 007072a2  6a00                 push 0
// 007072a4  683f270000           push 0x273f
// 007072a9  51                   push ecx
// 007072aa  ff1550ee7700         call dword ptr [0x77ee50]
// 007072b0  b801000000           mov eax, 1
// 007072b5  5e                   pop esi
// 007072b6  c3                   ret 
// 007072b7  33c0                 xor eax, eax
// 007072b9  5e                   pop esi
// 007072ba  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?SendCancelMessage@CXTCaptionPopupWnd@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
