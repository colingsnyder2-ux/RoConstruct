// from server: 100% by auto
// roc 2009-06 00758040  unit: CXTTreeBase  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758040
//
// 00758040  83ec10               sub esp, 0x10
// 00758043  56                   push esi
// 00758044  8bf1                 mov esi, ecx
// 00758046  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00758049  e88e3e0f00           call 0x84bedc
// 0075804e  a900020000           test eax, 0x200
// 00758053  747c                 je 0x7580d1
// 00758055  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00758059  33c0                 xor eax, eax
// 0075805b  89442404             mov dword ptr [esp + 4], eax
// 0075805f  89442408             mov dword ptr [esp + 8], eax
// 00758063  8944240c             mov dword ptr [esp + 0xc], eax
// 00758067  89442410             mov dword ptr [esp + 0x10], eax
// 0075806b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0075806f  8d542404             lea edx, [esp + 4]
// 00758073  52                   push edx
// 00758074  89442408             mov dword ptr [esp + 8], eax
// 00758078  8b4634               mov eax, dword ptr [esi + 0x34]
// 0075807b  6a00                 push 0
// 0075807d  894c2410             mov dword ptr [esp + 0x10], ecx
// 00758081  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00758084  6811110000           push 0x1111
// 00758089  51                   push ecx
// 0075808a  ff1590ee8900         call dword ptr [0x89ee90]
// 00758090  8b442410             mov eax, dword ptr [esp + 0x10]
// 00758094  85c0                 test eax, eax
// 00758096  7407                 je 0x75809f
// 00758098  f644240c46           test byte ptr [esp + 0xc], 0x46
// 0075809d  7502                 jne 0x7580a1
// 0075809f  33c0                 xor eax, eax
// 007580a1  394614               cmp dword ptr [esi + 0x14], eax
// 007580a4  742b                 je 0x7580d1
// 007580a6  894614               mov dword ptr [esi + 0x14], eax
// 007580a9  85c0                 test eax, eax
// 007580ab  7413                 je 0x7580c0
// 007580ad  8b5634               mov edx, dword ptr [esi + 0x34]
// 007580b0  8b4220               mov eax, dword ptr [edx + 0x20]
// 007580b3  6a00                 push 0
// 007580b5  6a37                 push 0x37
// 007580b7  6a55                 push 0x55
// 007580b9  50                   push eax
// 007580ba  ff150cee8900         call dword ptr [0x89ee0c]
// 007580c0  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007580c3  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007580c6  6a00                 push 0
// 007580c8  6a00                 push 0
// 007580ca  52                   push edx
// 007580cb  ff157cee8900         call dword ptr [0x89ee7c]
// 007580d1  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007580d4  e82f0ffcff           call 0x719008
// 007580d9  5e                   pop esi
// 007580da  83c410               add esp, 0x10
// 007580dd  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnMouseMove@CXTPTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
