// from server: 100% by auto
// roc 2007-03 0069c180  unit: seg_00690000  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069c180
//
// 0069c180  83ec08               sub esp, 8
// 0069c183  56                   push esi
// 0069c184  57                   push edi
// 0069c185  8d442408             lea eax, [esp + 8]
// 0069c189  50                   push eax
// 0069c18a  8bf1                 mov esi, ecx
// 0069c18c  ff1524ed7700         call dword ptr [0x77ed24]
// 0069c192  8b5620               mov edx, dword ptr [esi + 0x20]
// 0069c195  8d4c2408             lea ecx, [esp + 8]
// 0069c199  51                   push ecx
// 0069c19a  52                   push edx
// 0069c19b  ff1520ed7700         call dword ptr [0x77ed20]
// 0069c1a1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0069c1a5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0069c1a9  50                   push eax
// 0069c1aa  51                   push ecx
// 0069c1ab  8bce                 mov ecx, esi
// 0069c1ad  e8bedeffff           call 0x69a070
// 0069c1b2  8bf8                 mov edi, eax
// 0069c1b4  8d57f6               lea edx, [edi - 0xa]
// 0069c1b7  83fa07               cmp edx, 7
// 0069c1ba  772f                 ja 0x69c1eb
// 0069c1bc  8bce                 mov ecx, esi
// 0069c1be  e80df7f9ff           call 0x63b8d0
// 0069c1c3  0fb74c241c           movzx ecx, word ptr [esp + 0x1c]
// 0069c1c8  8b4020               mov eax, dword ptr [eax + 0x20]
// 0069c1cb  0fb7d7               movzx edx, di
// 0069c1ce  c1e110               shl ecx, 0x10
// 0069c1d1  0bca                 or ecx, edx
// 0069c1d3  51                   push ecx
// 0069c1d4  50                   push eax
// 0069c1d5  6a20                 push 0x20
// 0069c1d7  50                   push eax
// 0069c1d8  ff1550ee7700         call dword ptr [0x77ee50]
// 0069c1de  5f                   pop edi
// 0069c1df  b801000000           mov eax, 1
// 0069c1e4  5e                   pop esi
// 0069c1e5  83c408               add esp, 8
// 0069c1e8  c20c00               ret 0xc
// 0069c1eb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0069c1ef  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0069c1f3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0069c1f7  50                   push eax
// 0069c1f8  51                   push ecx
// 0069c1f9  52                   push edx
// 0069c1fa  8bce                 mov ecx, esi
// 0069c1fc  e88f18faff           call 0x63da90
// 0069c201  5f                   pop edi
// 0069c202  5e                   pop esi
// 0069c203  83c408               add esp, 8
// 0069c206  c20c00               ret 0xc
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnSetCursor@CXTPRibbonBar@@IAEHPAVCWnd@@II@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBar.cpp
