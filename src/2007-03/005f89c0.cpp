// from server: 100% by auto
// roc 2007-03 005f89c0  unit: seg_005f0000  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f89c0
//
// 005f89c0  56                   push esi
// 005f89c1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005f89c5  0fb64604             movzx eax, byte ptr [esi + 4]
// 005f89c9  806605fc             and byte ptr [esi + 5], 0xfc
// 005f89cd  83e804               sub eax, 4
// 005f89d0  83f806               cmp eax, 6
// 005f89d3  0f879d000000         ja 0x5f8a76
// 005f89d9  57                   push edi
// 005f89da  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005f89de  8bff                 mov edi, edi
// 005f89e0  ff2485788a5f00       jmp dword ptr [eax*4 + 0x5f8a78]
// 005f89e7  8b4608               mov eax, dword ptr [esi + 8]
// 005f89ea  804e0504             or byte ptr [esi + 5], 4
// 005f89ee  85c0                 test eax, eax
// 005f89f0  7410                 je 0x5f8a02
// 005f89f2  f6400503             test byte ptr [eax + 5], 3
// 005f89f6  740a                 je 0x5f8a02
// 005f89f8  50                   push eax
// 005f89f9  57                   push edi
// 005f89fa  e8c1ffffff           call 0x5f89c0
// 005f89ff  83c408               add esp, 8
// 005f8a02  8b760c               mov esi, dword ptr [esi + 0xc]
// 005f8a05  f6460503             test byte ptr [esi + 5], 3
// 005f8a09  746a                 je 0x5f8a75
// 005f8a0b  806605fc             and byte ptr [esi + 5], 0xfc
// 005f8a0f  0fb64604             movzx eax, byte ptr [esi + 4]
// 005f8a13  83e804               sub eax, 4
// 005f8a16  83f806               cmp eax, 6
// 005f8a19  76c5                 jbe 0x5f89e0
// 005f8a1b  5f                   pop edi
// 005f8a1c  5e                   pop esi
// 005f8a1d  c3                   ret 
// 005f8a1e  8b4608               mov eax, dword ptr [esi + 8]
// 005f8a21  83780804             cmp dword ptr [eax + 8], 4
// 005f8a25  7c12                 jl 0x5f8a39
// 005f8a27  8b00                 mov eax, dword ptr [eax]
// 005f8a29  f6400503             test byte ptr [eax + 5], 3
// 005f8a2d  740a                 je 0x5f8a39
// 005f8a2f  50                   push eax
// 005f8a30  57                   push edi
// 005f8a31  e88affffff           call 0x5f89c0
// 005f8a36  83c408               add esp, 8
// 005f8a39  8d4610               lea eax, [esi + 0x10]
// 005f8a3c  394608               cmp dword ptr [esi + 8], eax
// 005f8a3f  7534                 jne 0x5f8a75
// 005f8a41  804e0504             or byte ptr [esi + 5], 4
// 005f8a45  5f                   pop edi
// 005f8a46  5e                   pop esi
// 005f8a47  c3                   ret 
// 005f8a48  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 005f8a4b  894e08               mov dword ptr [esi + 8], ecx
// 005f8a4e  897724               mov dword ptr [edi + 0x24], esi
// 005f8a51  5f                   pop edi
// 005f8a52  5e                   pop esi
// 005f8a53  c3                   ret 
// 005f8a54  8b5724               mov edx, dword ptr [edi + 0x24]
// 005f8a57  895618               mov dword ptr [esi + 0x18], edx
// 005f8a5a  897724               mov dword ptr [edi + 0x24], esi
// 005f8a5d  5f                   pop edi
// 005f8a5e  5e                   pop esi
// 005f8a5f  c3                   ret 
// 005f8a60  8b4724               mov eax, dword ptr [edi + 0x24]
// 005f8a63  89466c               mov dword ptr [esi + 0x6c], eax
// 005f8a66  897724               mov dword ptr [edi + 0x24], esi
// 005f8a69  5f                   pop edi
// 005f8a6a  5e                   pop esi
// 005f8a6b  c3                   ret 
// 005f8a6c  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 005f8a6f  894e44               mov dword ptr [esi + 0x44], ecx
// 005f8a72  897724               mov dword ptr [edi + 0x24], esi
// 005f8a75  5f                   pop edi
// 005f8a76  5e                   pop esi
// 005f8a77  c3                   ret 
// 005f8a78  758a                 jne 0x5f8a04
// 005f8a7a  5f                   pop edi
// 005f8a7b  00548a5f             add byte ptr [edx + ecx*4 + 0x5f], dl
// 005f8a7f  00488a               add byte ptr [eax - 0x76], cl
// 005f8a82  5f                   pop edi
// 005f8a83  00e7                 add bh, ah
// 005f8a85  895f00               mov dword ptr [edi], ebx
// 005f8a88  60                   pushal 
// 005f8a89  8a5f00               mov bl, byte ptr [edi]
// 005f8a8c  6c                   insb byte ptr es:[edi], dx
// 005f8a8d  8a5f00               mov bl, byte ptr [edi]
// 005f8a90  1e                   push ds
// 005f8a91  8a5f00               mov bl, byte ptr [edi]
// library lua-5.1.1/lgc.c (function _reallymarkobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
