// from server: 100% by auto
// roc 2007-03 0050a0d0  unit: seg_00500000  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a0d0
//
// 0050a0d0  57                   push edi
// 0050a0d1  8b7c2408             mov edi, dword ptr [esp + 8]
// 0050a0d5  85ff                 test edi, edi
// 0050a0d7  0f8480000000         je 0x50a15d
// 0050a0dd  56                   push esi
// 0050a0de  8b742410             mov esi, dword ptr [esp + 0x10]
// 0050a0e2  85f6                 test esi, esi
// 0050a0e4  7476                 je 0x50a15c
// 0050a0e6  53                   push ebx
// 0050a0e7  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0050a0eb  55                   push ebp
// 0050a0ec  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0050a0f0  85ed                 test ebp, ebp
// 0050a0f2  743a                 je 0x50a12e
// 0050a0f4  6a00                 push 0
// 0050a0f6  6800200000           push 0x2000
// 0050a0fb  56                   push esi
// 0050a0fc  57                   push edi
// 0050a0fd  e87e060000           call 0x50a780
// 0050a102  6800010000           push 0x100
// 0050a107  57                   push edi
// 0050a108  e893ee0000           call 0x518fa0
// 0050a10d  89464c               mov dword ptr [esi + 0x4c], eax
// 0050a110  53                   push ebx
// 0050a111  898788010000         mov dword ptr [edi + 0x188], eax
// 0050a117  8b464c               mov eax, dword ptr [esi + 0x4c]
// 0050a11a  55                   push ebp
// 0050a11b  50                   push eax
// 0050a11c  e8c1501100           call 0x61f1e2
// 0050a121  83c424               add esp, 0x24
// 0050a124  818eb800000000200000 or dword ptr [esi + 0xb8], 0x2000
// 0050a12e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0050a132  85c0                 test eax, eax
// 0050a134  741c                 je 0x50a152
// 0050a136  85db                 test ebx, ebx
// 0050a138  8b08                 mov ecx, dword ptr [eax]
// 0050a13a  894e50               mov dword ptr [esi + 0x50], ecx
// 0050a13d  8b5004               mov edx, dword ptr [eax + 4]
// 0050a140  895654               mov dword ptr [esi + 0x54], edx
// 0050a143  668b4008             mov ax, word ptr [eax + 8]
// 0050a147  66894658             mov word ptr [esi + 0x58], ax
// 0050a14b  7505                 jne 0x50a152
// 0050a14d  bb01000000           mov ebx, 1
// 0050a152  834e0810             or dword ptr [esi + 8], 0x10
// 0050a156  5d                   pop ebp
// 0050a157  66895e16             mov word ptr [esi + 0x16], bx
// 0050a15b  5b                   pop ebx
// 0050a15c  5e                   pop esi
// 0050a15d  5f                   pop edi
// 0050a15e  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_tRNS)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
