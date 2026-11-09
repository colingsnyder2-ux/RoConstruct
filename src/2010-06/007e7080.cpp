// from server: 100% by auto
// roc 2010-06 007e7080  unit: CXTTreeBase  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7080
//
// 007e7080  83ec10               sub esp, 0x10
// 007e7083  56                   push esi
// 007e7084  8bf1                 mov esi, ecx
// 007e7086  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e7089  e8505d1900           call 0x97cdde
// 007e708e  a900020000           test eax, 0x200
// 007e7093  747c                 je 0x7e7111
// 007e7095  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007e7099  33c0                 xor eax, eax
// 007e709b  89442404             mov dword ptr [esp + 4], eax
// 007e709f  89442408             mov dword ptr [esp + 8], eax
// 007e70a3  8944240c             mov dword ptr [esp + 0xc], eax
// 007e70a7  89442410             mov dword ptr [esp + 0x10], eax
// 007e70ab  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e70af  8d542404             lea edx, [esp + 4]
// 007e70b3  52                   push edx
// 007e70b4  89442408             mov dword ptr [esp + 8], eax
// 007e70b8  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e70bb  6a00                 push 0
// 007e70bd  894c2410             mov dword ptr [esp + 0x10], ecx
// 007e70c1  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007e70c4  6811110000           push 0x1111
// 007e70c9  51                   push ecx
// 007e70ca  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e70d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007e70d4  85c0                 test eax, eax
// 007e70d6  7407                 je 0x7e70df
// 007e70d8  f644240c46           test byte ptr [esp + 0xc], 0x46
// 007e70dd  7502                 jne 0x7e70e1
// 007e70df  33c0                 xor eax, eax
// 007e70e1  394614               cmp dword ptr [esi + 0x14], eax
// 007e70e4  742b                 je 0x7e7111
// 007e70e6  894614               mov dword ptr [esi + 0x14], eax
// 007e70e9  85c0                 test eax, eax
// 007e70eb  7413                 je 0x7e7100
// 007e70ed  8b5634               mov edx, dword ptr [esi + 0x34]
// 007e70f0  8b4220               mov eax, dword ptr [edx + 0x20]
// 007e70f3  6a00                 push 0
// 007e70f5  6a37                 push 0x37
// 007e70f7  6a55                 push 0x55
// 007e70f9  50                   push eax
// 007e70fa  ff1554bc9e00         call dword ptr [0x9ebc54]
// 007e7100  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e7103  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007e7106  6a00                 push 0
// 007e7108  6a00                 push 0
// 007e710a  52                   push edx
// 007e710b  ff1578ba9e00         call dword ptr [0x9eba78]
// 007e7111  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007e7114  e8570efcff           call 0x7a7f70
// 007e7119  5e                   pop esi
// 007e711a  83c410               add esp, 0x10
// 007e711d  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnMouseMove@CXTTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
