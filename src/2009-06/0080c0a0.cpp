// from server: 100% by auto
// roc 2009-06 0080c0a0  unit: CXTCaptionPopupWnd  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080c0a0
//
// 0080c0a0  56                   push esi
// 0080c0a1  8bf1                 mov esi, ecx
// 0080c0a3  ff1578ee8900         call dword ptr [0x89ee78]
// 0080c0a9  8d4e60               lea ecx, [esi + 0x60]
// 0080c0ac  85c9                 test ecx, ecx
// 0080c0ae  7403                 je 0x80c0b3
// 0080c0b0  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0080c0b3  3bc1                 cmp eax, ecx
// 0080c0b5  7460                 je 0x80c117
// 0080c0b7  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 0080c0bd  85c9                 test ecx, ecx
// 0080c0bf  7403                 je 0x80c0c4
// 0080c0c1  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0080c0c4  3bc1                 cmp eax, ecx
// 0080c0c6  744f                 je 0x80c117
// 0080c0c8  85f6                 test esi, esi
// 0080c0ca  7504                 jne 0x80c0d0
// 0080c0cc  33c9                 xor ecx, ecx
// 0080c0ce  eb03                 jmp 0x80c0d3
// 0080c0d0  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0080c0d3  3bc1                 cmp eax, ecx
// 0080c0d5  7440                 je 0x80c117
// 0080c0d7  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0080c0da  85c9                 test ecx, ecx
// 0080c0dc  7403                 je 0x80c0e1
// 0080c0de  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0080c0e1  3bc1                 cmp eax, ecx
// 0080c0e3  7432                 je 0x80c117
// 0080c0e5  8b4654               mov eax, dword ptr [esi + 0x54]
// 0080c0e8  85c0                 test eax, eax
// 0080c0ea  7403                 je 0x80c0ef
// 0080c0ec  8b4020               mov eax, dword ptr [eax + 0x20]
// 0080c0ef  50                   push eax
// 0080c0f0  ff15e0ed8900         call dword ptr [0x89ede0]
// 0080c0f6  85c0                 test eax, eax
// 0080c0f8  741d                 je 0x80c117
// 0080c0fa  8b4654               mov eax, dword ptr [esi + 0x54]
// 0080c0fd  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0080c100  6a00                 push 0
// 0080c102  6a00                 push 0
// 0080c104  683f270000           push 0x273f
// 0080c109  51                   push ecx
// 0080c10a  ff1590ee8900         call dword ptr [0x89ee90]
// 0080c110  b801000000           mov eax, 1
// 0080c115  5e                   pop esi
// 0080c116  c3                   ret 
// 0080c117  33c0                 xor eax, eax
// 0080c119  5e                   pop esi
// 0080c11a  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?SendCancelMessage@CXTCaptionPopupWnd@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
