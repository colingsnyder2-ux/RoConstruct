// from server: 100% by auto
// roc 2011-06 008f3a10  unit: CXTCaptionPopupWnd  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f3a10
//
// 008f3a10  56                   push esi
// 008f3a11  8bf1                 mov esi, ecx
// 008f3a13  ff15f819a400         call dword ptr [0xa419f8]
// 008f3a19  8d4e60               lea ecx, [esi + 0x60]
// 008f3a1c  85c9                 test ecx, ecx
// 008f3a1e  7403                 je 0x8f3a23
// 008f3a20  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008f3a23  3bc1                 cmp eax, ecx
// 008f3a25  7460                 je 0x8f3a87
// 008f3a27  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 008f3a2d  85c9                 test ecx, ecx
// 008f3a2f  7403                 je 0x8f3a34
// 008f3a31  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008f3a34  3bc1                 cmp eax, ecx
// 008f3a36  744f                 je 0x8f3a87
// 008f3a38  85f6                 test esi, esi
// 008f3a3a  7504                 jne 0x8f3a40
// 008f3a3c  33c9                 xor ecx, ecx
// 008f3a3e  eb03                 jmp 0x8f3a43
// 008f3a40  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008f3a43  3bc1                 cmp eax, ecx
// 008f3a45  7440                 je 0x8f3a87
// 008f3a47  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 008f3a4a  85c9                 test ecx, ecx
// 008f3a4c  7403                 je 0x8f3a51
// 008f3a4e  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008f3a51  3bc1                 cmp eax, ecx
// 008f3a53  7432                 je 0x8f3a87
// 008f3a55  8b4654               mov eax, dword ptr [esi + 0x54]
// 008f3a58  85c0                 test eax, eax
// 008f3a5a  7403                 je 0x8f3a5f
// 008f3a5c  8b4020               mov eax, dword ptr [eax + 0x20]
// 008f3a5f  50                   push eax
// 008f3a60  ff15ec1ba400         call dword ptr [0xa41bec]
// 008f3a66  85c0                 test eax, eax
// 008f3a68  741d                 je 0x8f3a87
// 008f3a6a  8b4654               mov eax, dword ptr [esi + 0x54]
// 008f3a6d  8b4820               mov ecx, dword ptr [eax + 0x20]
// 008f3a70  6a00                 push 0
// 008f3a72  6a00                 push 0
// 008f3a74  683f270000           push 0x273f
// 008f3a79  51                   push ecx
// 008f3a7a  ff15c019a400         call dword ptr [0xa419c0]
// 008f3a80  b801000000           mov eax, 1
// 008f3a85  5e                   pop esi
// 008f3a86  c3                   ret 
// 008f3a87  33c0                 xor eax, eax
// 008f3a89  5e                   pop esi
// 008f3a8a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?SendCancelMessage@CXTCaptionPopupWnd@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
