// from server: 100% by auto
// roc 2007-03 005bfd20  unit: seg_005b0000  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bfd20
//
// 005bfd20  83ec64               sub esp, 0x64
// 005bfd23  56                   push esi
// 005bfd24  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005bfd28  8b4640               mov eax, dword ptr [esi + 0x40]
// 005bfd2b  85c0                 test eax, eax
// 005bfd2d  8944246c             mov dword ptr [esp + 0x6c], eax
// 005bfd31  0f84bc000000         je 0x5bfdf3
// 005bfd37  807e3700             cmp byte ptr [esi + 0x37], 0
// 005bfd3b  0f84b2000000         je 0x5bfdf3
// 005bfd41  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005bfd44  8b4614               mov eax, dword ptr [esi + 0x14]
// 005bfd47  8b542474             mov edx, dword ptr [esp + 0x74]
// 005bfd4b  53                   push ebx
// 005bfd4c  8b5e08               mov ebx, dword ptr [esi + 8]
// 005bfd4f  55                   push ebp
// 005bfd50  8b6808               mov ebp, dword ptr [eax + 8]
// 005bfd53  57                   push edi
// 005bfd54  8bfb                 mov edi, ebx
// 005bfd56  2bf9                 sub edi, ecx
// 005bfd58  2be9                 sub ebp, ecx
// 005bfd5a  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 005bfd5e  83f904               cmp ecx, 4
// 005bfd61  894c2410             mov dword ptr [esp + 0x10], ecx
// 005bfd65  89542424             mov dword ptr [esp + 0x24], edx
// 005bfd69  750a                 jne 0x5bfd75
// 005bfd6b  c744247000000000     mov dword ptr [esp + 0x70], 0
// 005bfd73  eb1a                 jmp 0x5bfd8f
// 005bfd75  2b4628               sub eax, dword ptr [esi + 0x28]
// 005bfd78  8bc8                 mov ecx, eax
// 005bfd7a  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005bfd7f  f7e9                 imul ecx
// 005bfd81  c1fa02               sar edx, 2
// 005bfd84  8bc2                 mov eax, edx
// 005bfd86  c1e81f               shr eax, 0x1f
// 005bfd89  03c2                 add eax, edx
// 005bfd8b  89442470             mov dword ptr [esp + 0x70], eax
// 005bfd8f  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005bfd92  2bcb                 sub ecx, ebx
// 005bfd94  81f940010000         cmp ecx, 0x140
// 005bfd9a  7f1b                 jg 0x5bfdb7
// 005bfd9c  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005bfd9f  83f814               cmp eax, 0x14
// 005bfda2  7c06                 jl 0x5bfdaa
// 005bfda4  8d1400               lea edx, [eax + eax]
// 005bfda7  52                   push edx
// 005bfda8  eb04                 jmp 0x5bfdae
// 005bfdaa  83c014               add eax, 0x14
// 005bfdad  50                   push eax
// 005bfdae  56                   push esi
// 005bfdaf  e85cfeffff           call 0x5bfc10
// 005bfdb4  83c408               add esp, 8
// 005bfdb7  8b4608               mov eax, dword ptr [esi + 8]
// 005bfdba  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005bfdbd  8d542410             lea edx, [esp + 0x10]
// 005bfdc1  0540010000           add eax, 0x140
// 005bfdc6  52                   push edx
// 005bfdc7  894108               mov dword ptr [ecx + 8], eax
// 005bfdca  56                   push esi
// 005bfdcb  c6463700             mov byte ptr [esi + 0x37], 0
// 005bfdcf  ff942480000000       call dword ptr [esp + 0x80]
// 005bfdd6  8b4620               mov eax, dword ptr [esi + 0x20]
// 005bfdd9  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005bfddc  03c5                 add eax, ebp
// 005bfdde  83c408               add esp, 8
// 005bfde1  c6463701             mov byte ptr [esi + 0x37], 1
// 005bfde5  894108               mov dword ptr [ecx + 8], eax
// 005bfde8  8b5620               mov edx, dword ptr [esi + 0x20]
// 005bfdeb  03d7                 add edx, edi
// 005bfded  5f                   pop edi
// 005bfdee  5d                   pop ebp
// 005bfdef  895608               mov dword ptr [esi + 8], edx
// 005bfdf2  5b                   pop ebx
// 005bfdf3  5e                   pop esi
// 005bfdf4  83c464               add esp, 0x64
// 005bfdf7  c3                   ret 
// library lua-5.1.1/ldo.c (function _luaD_callhook)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
