// from server: 100% by auto
// roc 2007-03 005c27c0  unit: seg_005c0000  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c27c0
//
// 005c27c0  51                   push ecx
// 005c27c1  56                   push esi
// 005c27c2  33f6                 xor esi, esi
// 005c27c4  3bde                 cmp ebx, esi
// 005c27c6  7461                 je 0x5c2829
// 005c27c8  807b0600             cmp byte ptr [ebx + 6], 0
// 005c27cc  755b                 jne 0x5c2829
// 005c27ce  55                   push ebp
// 005c27cf  56                   push esi
// 005c27d0  56                   push esi
// 005c27d1  57                   push edi
// 005c27d2  e859950300           call 0x5fbd30
// 005c27d7  8be8                 mov ebp, eax
// 005c27d9  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005c27dc  8b4814               mov ecx, dword ptr [eax + 0x14]
// 005c27df  83c40c               add esp, 0xc
// 005c27e2  397030               cmp dword ptr [eax + 0x30], esi
// 005c27e5  894c2408             mov dword ptr [esp + 8], ecx
// 005c27e9  7e2f                 jle 0x5c281a
// 005c27eb  eb03                 jmp 0x5c27f0
// 005c27ed  8d4900               lea ecx, [ecx]
// 005c27f0  8b542408             mov edx, dword ptr [esp + 8]
// 005c27f4  8b04b2               mov eax, dword ptr [edx + esi*4]
// 005c27f7  50                   push eax
// 005c27f8  55                   push ebp
// 005c27f9  57                   push edi
// 005c27fa  e8e1970300           call 0x5fbfe0
// 005c27ff  c70001000000         mov dword ptr [eax], 1
// 005c2805  c7400801000000       mov dword ptr [eax + 8], 1
// 005c280c  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 005c280f  83c601               add esi, 1
// 005c2812  83c40c               add esp, 0xc
// 005c2815  3b7130               cmp esi, dword ptr [ecx + 0x30]
// 005c2818  7cd6                 jl 0x5c27f0
// 005c281a  8b4708               mov eax, dword ptr [edi + 8]
// 005c281d  8928                 mov dword ptr [eax], ebp
// 005c281f  c7400805000000       mov dword ptr [eax + 8], 5
// 005c2826  5d                   pop ebp
// 005c2827  eb06                 jmp 0x5c282f
// 005c2829  8b5708               mov edx, dword ptr [edi + 8]
// 005c282c  897208               mov dword ptr [edx + 8], esi
// 005c282f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 005c2832  2b4708               sub eax, dword ptr [edi + 8]
// 005c2835  be10000000           mov esi, 0x10
// 005c283a  3bc6                 cmp eax, esi
// 005c283c  7f0b                 jg 0x5c2849
// 005c283e  6a01                 push 1
// 005c2840  57                   push edi
// 005c2841  e8aad4ffff           call 0x5bfcf0
// 005c2846  83c408               add esp, 8
// 005c2849  017708               add dword ptr [edi + 8], esi
// 005c284c  5e                   pop esi
// 005c284d  59                   pop ecx
// 005c284e  c3                   ret 
// library lua-5.1.1/ldebug.c (function _collectvalidlines)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
