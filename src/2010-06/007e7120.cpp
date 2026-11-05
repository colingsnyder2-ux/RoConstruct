// from server: 100% by auto
// roc 2010-06 007e7120  unit: CXTTreeBase  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7120
//
// 007e7120  83ec10               sub esp, 0x10
// 007e7123  56                   push esi
// 007e7124  8bf1                 mov esi, ecx
// 007e7126  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e7129  e8b05c1900           call 0x97cdde
// 007e712e  a900020000           test eax, 0x200
// 007e7133  0f848b000000         je 0x7e71c4
// 007e7139  837c241855           cmp dword ptr [esp + 0x18], 0x55
// 007e713e  0f8580000000         jne 0x7e71c4
// 007e7144  837e1400             cmp dword ptr [esi + 0x14], 0
// 007e7148  7464                 je 0x7e71ae
// 007e714a  53                   push ebx
// 007e714b  57                   push edi
// 007e714c  ff15ecb99e00         call dword ptr [0x9eb9ec]
// 007e7152  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e7155  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007e7158  0fbff8               movsx edi, ax
// 007e715b  c1e810               shr eax, 0x10
// 007e715e  0fbfd8               movsx ebx, ax
// 007e7161  8d44240c             lea eax, [esp + 0xc]
// 007e7165  50                   push eax
// 007e7166  52                   push edx
// 007e7167  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 007e716d  53                   push ebx
// 007e716e  57                   push edi
// 007e716f  8d442414             lea eax, [esp + 0x14]
// 007e7173  50                   push eax
// 007e7174  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 007e717a  5f                   pop edi
// 007e717b  5b                   pop ebx
// 007e717c  85c0                 test eax, eax
// 007e717e  754c                 jne 0x7e71cc
// 007e7180  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e7183  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007e7186  6a55                 push 0x55
// 007e7188  52                   push edx
// 007e7189  ff1560ba9e00         call dword ptr [0x9eba60]
// 007e718f  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e7192  6a00                 push 0
// 007e7194  c7461400000000       mov dword ptr [esi + 0x14], 0
// 007e719b  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e719e  6a00                 push 0
// 007e71a0  51                   push ecx
// 007e71a1  ff1578ba9e00         call dword ptr [0x9eba78]
// 007e71a7  5e                   pop esi
// 007e71a8  83c410               add esp, 0x10
// 007e71ab  c20400               ret 4
// 007e71ae  8b5634               mov edx, dword ptr [esi + 0x34]
// 007e71b1  8b4220               mov eax, dword ptr [edx + 0x20]
// 007e71b4  6a55                 push 0x55
// 007e71b6  50                   push eax
// 007e71b7  ff1560ba9e00         call dword ptr [0x9eba60]
// 007e71bd  5e                   pop esi
// 007e71be  83c410               add esp, 0x10
// 007e71c1  c20400               ret 4
// 007e71c4  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e71c7  e8a40dfcff           call 0x7a7f70
// 007e71cc  5e                   pop esi
// 007e71cd  83c410               add esp, 0x10
// 007e71d0  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnTimer@CXTTreeBase@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
