// from server: 100% by auto
// roc 2009-12 008e6b90  unit: CXTCaptionPopupWnd  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6b90
//
// 008e6b90  56                   push esi
// 008e6b91  8bf1                 mov esi, ecx
// 008e6b93  ff15eccb9800         call dword ptr [0x98cbec]
// 008e6b99  8d4e60               lea ecx, [esi + 0x60]
// 008e6b9c  85c9                 test ecx, ecx
// 008e6b9e  7403                 je 0x8e6ba3
// 008e6ba0  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008e6ba3  3bc1                 cmp eax, ecx
// 008e6ba5  7460                 je 0x8e6c07
// 008e6ba7  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 008e6bad  85c9                 test ecx, ecx
// 008e6baf  7403                 je 0x8e6bb4
// 008e6bb1  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008e6bb4  3bc1                 cmp eax, ecx
// 008e6bb6  744f                 je 0x8e6c07
// 008e6bb8  85f6                 test esi, esi
// 008e6bba  7504                 jne 0x8e6bc0
// 008e6bbc  33c9                 xor ecx, ecx
// 008e6bbe  eb03                 jmp 0x8e6bc3
// 008e6bc0  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008e6bc3  3bc1                 cmp eax, ecx
// 008e6bc5  7440                 je 0x8e6c07
// 008e6bc7  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 008e6bca  85c9                 test ecx, ecx
// 008e6bcc  7403                 je 0x8e6bd1
// 008e6bce  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008e6bd1  3bc1                 cmp eax, ecx
// 008e6bd3  7432                 je 0x8e6c07
// 008e6bd5  8b4654               mov eax, dword ptr [esi + 0x54]
// 008e6bd8  85c0                 test eax, eax
// 008e6bda  7403                 je 0x8e6bdf
// 008e6bdc  8b4020               mov eax, dword ptr [eax + 0x20]
// 008e6bdf  50                   push eax
// 008e6be0  ff1584cc9800         call dword ptr [0x98cc84]
// 008e6be6  85c0                 test eax, eax
// 008e6be8  741d                 je 0x8e6c07
// 008e6bea  8b4654               mov eax, dword ptr [esi + 0x54]
// 008e6bed  8b4820               mov ecx, dword ptr [eax + 0x20]
// 008e6bf0  6a00                 push 0
// 008e6bf2  6a00                 push 0
// 008e6bf4  683f270000           push 0x273f
// 008e6bf9  51                   push ecx
// 008e6bfa  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008e6c00  b801000000           mov eax, 1
// 008e6c05  5e                   pop esi
// 008e6c06  c3                   ret 
// 008e6c07  33c0                 xor eax, eax
// 008e6c09  5e                   pop esi
// 008e6c0a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?SendCancelMessage@CXTCaptionPopupWnd@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
