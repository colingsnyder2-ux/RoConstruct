// from server: 100% by auto
// roc 2009-12 00832ec0  unit: CXTTreeBase  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832ec0
//
// 00832ec0  83ec10               sub esp, 0x10
// 00832ec3  56                   push esi
// 00832ec4  8bf1                 mov esi, ecx
// 00832ec6  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00832ec9  e8a4350f00           call 0x926472
// 00832ece  a900020000           test eax, 0x200
// 00832ed3  747c                 je 0x832f51
// 00832ed5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00832ed9  33c0                 xor eax, eax
// 00832edb  89442404             mov dword ptr [esp + 4], eax
// 00832edf  89442408             mov dword ptr [esp + 8], eax
// 00832ee3  8944240c             mov dword ptr [esp + 0xc], eax
// 00832ee7  89442410             mov dword ptr [esp + 0x10], eax
// 00832eeb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00832eef  8d542404             lea edx, [esp + 4]
// 00832ef3  52                   push edx
// 00832ef4  89442408             mov dword ptr [esp + 8], eax
// 00832ef8  8b4634               mov eax, dword ptr [esi + 0x34]
// 00832efb  6a00                 push 0
// 00832efd  894c2410             mov dword ptr [esp + 0x10], ecx
// 00832f01  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00832f04  6811110000           push 0x1111
// 00832f09  51                   push ecx
// 00832f0a  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832f10  8b442410             mov eax, dword ptr [esp + 0x10]
// 00832f14  85c0                 test eax, eax
// 00832f16  7407                 je 0x832f1f
// 00832f18  f644240c46           test byte ptr [esp + 0xc], 0x46
// 00832f1d  7502                 jne 0x832f21
// 00832f1f  33c0                 xor eax, eax
// 00832f21  394614               cmp dword ptr [esi + 0x14], eax
// 00832f24  742b                 je 0x832f51
// 00832f26  894614               mov dword ptr [esi + 0x14], eax
// 00832f29  85c0                 test eax, eax
// 00832f2b  7413                 je 0x832f40
// 00832f2d  8b5634               mov edx, dword ptr [esi + 0x34]
// 00832f30  8b4220               mov eax, dword ptr [edx + 0x20]
// 00832f33  6a00                 push 0
// 00832f35  6a37                 push 0x37
// 00832f37  6a55                 push 0x55
// 00832f39  50                   push eax
// 00832f3a  ff1558cc9800         call dword ptr [0x98cc58]
// 00832f40  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00832f43  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00832f46  6a00                 push 0
// 00832f48  6a00                 push 0
// 00832f4a  52                   push edx
// 00832f4b  ff15e8cb9800         call dword ptr [0x98cbe8]
// 00832f51  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00832f54  e8d70efcff           call 0x7f3e30
// 00832f59  5e                   pop esi
// 00832f5a  83c410               add esp, 0x10
// 00832f5d  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnMouseMove@CXTPTreeBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
