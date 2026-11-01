// from server: 100% by auto
// roc 2011-06 007f3350  unit: RBX::AdvLuaDragTool  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007f3350
//
// 007f3350  56                   push esi
// 007f3351  57                   push edi
// 007f3352  e8d9f6ffff           call 0x7f2a30
// 007f3357  8b06                 mov eax, dword ptr [esi]
// 007f3359  48                   dec eax
// 007f335a  83c408               add esp, 8
// 007f335d  83f80b               cmp eax, 0xb
// 007f3360  776a                 ja 0x7f33cc
// 007f3362  0fb68004347f00       movzx eax, byte ptr [eax + 0x7f3404]
// 007f3369  ff2485f0337f00       jmp dword ptr [eax*4 + 0x7f33f0]
// 007f3370  c70602000000         mov dword ptr [esi], 2
// 007f3376  eb54                 jmp 0x7f33cc
// 007f3378  c70603000000         mov dword ptr [esi], 3
// 007f337e  eb4c                 jmp 0x7f33cc
// 007f3380  8bc6                 mov eax, esi
// 007f3382  8bcf                 mov ecx, edi
// 007f3384  e817f2ffff           call 0x7f25a0
// 007f3389  eb41                 jmp 0x7f33cc
// 007f338b  56                   push esi
// 007f338c  8bc7                 mov eax, edi
// 007f338e  e8bdf8ffff           call 0x7f2c50
// 007f3393  83c404               add esp, 4
// 007f3396  833e0c               cmp dword ptr [esi], 0xc
// 007f3399  7515                 jne 0x7f33b0
// 007f339b  8b4608               mov eax, dword ptr [esi + 8]
// 007f339e  a900010000           test eax, 0x100
// 007f33a3  750b                 jne 0x7f33b0
// 007f33a5  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 007f33a9  3bc1                 cmp eax, ecx
// 007f33ab  7c03                 jl 0x7f33b0
// 007f33ad  ff4f24               dec dword ptr [edi + 0x24]
// 007f33b0  8b5608               mov edx, dword ptr [esi + 8]
// 007f33b3  6a00                 push 0
// 007f33b5  52                   push edx
// 007f33b6  6a00                 push 0
// 007f33b8  6a13                 push 0x13
// 007f33ba  57                   push edi
// 007f33bb  e8f0f3ffff           call 0x7f27b0
// 007f33c0  83c414               add esp, 0x14
// 007f33c3  894608               mov dword ptr [esi + 8], eax
// 007f33c6  c7060b000000         mov dword ptr [esi], 0xb
// 007f33cc  8b4614               mov eax, dword ptr [esi + 0x14]
// 007f33cf  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007f33d2  894610               mov dword ptr [esi + 0x10], eax
// 007f33d5  57                   push edi
// 007f33d6  8bc1                 mov eax, ecx
// 007f33d8  894e14               mov dword ptr [esi + 0x14], ecx
// 007f33db  e820edffff           call 0x7f2100
// 007f33e0  8b4610               mov eax, dword ptr [esi + 0x10]
// 007f33e3  57                   push edi
// 007f33e4  e817edffff           call 0x7f2100
// 007f33e9  83c408               add esp, 8
// 007f33ec  c3                   ret 
// 007f33ed  8d4900               lea ecx, [ecx]
// 007f33f0  7033                 jo 0x7f3425
// 007f33f2  7f00                 jg 0x7f33f4
// 007f33f4  7833                 js 0x7f3429
// 007f33f6  7f00                 jg 0x7f33f8
// 007f33f8  80337f               xor byte ptr [ebx], 0x7f
// 007f33fb  008b337f00cc         add byte ptr [ebx - 0x33ff80cd], cl
// 007f3401  337f00               xor edi, dword ptr [edi]
// 007f3404  0001                 add byte ptr [ecx], al
// 007f3406  0001                 add byte ptr [ecx], al
// 007f3408  010404               add dword ptr [esp + eax], eax
// 007f340b  0404                 add al, 4
// 007f340d  0203                 add al, byte ptr [ebx]
// library lua-5.1/lcode.c (function _codenot)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
