// from server: 100% by auto
// roc 2009-06 006e9ac0  unit: RBX::PartDropTool  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e9ac0
//
// 006e9ac0  55                   push ebp
// 006e9ac1  56                   push esi
// 006e9ac2  8bf0                 mov esi, eax
// 006e9ac4  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 006e9ac7  0fb64515             movzx eax, byte ptr [ebp + 0x15]
// 006e9acb  57                   push edi
// 006e9acc  83f804               cmp eax, 4
// 006e9acf  0f87cd000000         ja 0x6e9ba2
// 006e9ad5  ff2485a89b6e00       jmp dword ptr [eax*4 + 0x6e9ba8]
// 006e9adc  8bfe                 mov edi, esi
// 006e9ade  e8adfdffff           call 0x6e9890
// 006e9ae3  5f                   pop edi
// 006e9ae4  5e                   pop esi
// 006e9ae5  33c0                 xor eax, eax
// 006e9ae7  5d                   pop ebp
// 006e9ae8  c3                   ret 
// 006e9ae9  837d2400             cmp dword ptr [ebp + 0x24], 0
// 006e9aed  740a                 je 0x6e9af9
// 006e9aef  5f                   pop edi
// 006e9af0  5e                   pop esi
// 006e9af1  8bc5                 mov eax, ebp
// 006e9af3  5d                   pop ebp
// 006e9af4  e997f8ffff           jmp 0x6e9390
// 006e9af9  56                   push esi
// 006e9afa  e841feffff           call 0x6e9940
// 006e9aff  83c404               add esp, 4
// 006e9b02  5f                   pop edi
// 006e9b03  5e                   pop esi
// 006e9b04  33c0                 xor eax, eax
// 006e9b06  5d                   pop ebp
// 006e9b07  c3                   ret 
// 006e9b08  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006e9b0b  8b4d00               mov ecx, dword ptr [ebp]
// 006e9b0e  8b7d44               mov edi, dword ptr [ebp + 0x44]
// 006e9b11  8d0c81               lea ecx, [ecx + eax*4]
// 006e9b14  6afd                 push -3
// 006e9b16  51                   push ecx
// 006e9b17  40                   inc eax
// 006e9b18  56                   push esi
// 006e9b19  894518               mov dword ptr [ebp + 0x18], eax
// 006e9b1c  e80ffbffff           call 0x6e9630
// 006e9b21  8b5518               mov edx, dword ptr [ebp + 0x18]
// 006e9b24  83c40c               add esp, 0xc
// 006e9b27  3b5508               cmp edx, dword ptr [ebp + 8]
// 006e9b2a  7c04                 jl 0x6e9b30
// 006e9b2c  c6451503             mov byte ptr [ebp + 0x15], 3
// 006e9b30  8b4544               mov eax, dword ptr [ebp + 0x44]
// 006e9b33  2bc7                 sub eax, edi
// 006e9b35  014548               add dword ptr [ebp + 0x48], eax
// 006e9b38  5f                   pop edi
// 006e9b39  5e                   pop esi
// 006e9b3a  b80a000000           mov eax, 0xa
// 006e9b3f  5d                   pop ebp
// 006e9b40  c3                   ret 
// 006e9b41  8b4d20               mov ecx, dword ptr [ebp + 0x20]
// 006e9b44  8b7d44               mov edi, dword ptr [ebp + 0x44]
// 006e9b47  6a28                 push 0x28
// 006e9b49  51                   push ecx
// 006e9b4a  56                   push esi
// 006e9b4b  e8e0faffff           call 0x6e9630
// 006e9b50  83c40c               add esp, 0xc
// 006e9b53  894520               mov dword ptr [ebp + 0x20], eax
// 006e9b56  833800               cmp dword ptr [eax], 0
// 006e9b59  750d                 jne 0x6e9b68
// 006e9b5b  53                   push ebx
// 006e9b5c  8bde                 mov ebx, esi
// 006e9b5e  e85dfbffff           call 0x6e96c0
// 006e9b63  c6451504             mov byte ptr [ebp + 0x15], 4
// 006e9b67  5b                   pop ebx
// 006e9b68  8b5544               mov edx, dword ptr [ebp + 0x44]
// 006e9b6b  2bd7                 sub edx, edi
// 006e9b6d  015548               add dword ptr [ebp + 0x48], edx
// 006e9b70  5f                   pop edi
// 006e9b71  5e                   pop esi
// 006e9b72  b890010000           mov eax, 0x190
// 006e9b77  5d                   pop ebp
// 006e9b78  c3                   ret 
// 006e9b79  33c0                 xor eax, eax
// 006e9b7b  394530               cmp dword ptr [ebp + 0x30], eax
// 006e9b7e  741c                 je 0x6e9b9c
// 006e9b80  e8abfbffff           call 0x6e9730
// 006e9b85  8b4548               mov eax, dword ptr [ebp + 0x48]
// 006e9b88  83f864               cmp eax, 0x64
// 006e9b8b  7606                 jbe 0x6e9b93
// 006e9b8d  83c09c               add eax, -0x64
// 006e9b90  894548               mov dword ptr [ebp + 0x48], eax
// 006e9b93  5f                   pop edi
// 006e9b94  5e                   pop esi
// 006e9b95  b864000000           mov eax, 0x64
// 006e9b9a  5d                   pop ebp
// 006e9b9b  c3                   ret 
// 006e9b9c  884515               mov byte ptr [ebp + 0x15], al
// 006e9b9f  89454c               mov dword ptr [ebp + 0x4c], eax
// 006e9ba2  5f                   pop edi
// 006e9ba3  5e                   pop esi
// 006e9ba4  33c0                 xor eax, eax
// 006e9ba6  5d                   pop ebp
// 006e9ba7  c3                   ret 
// 006e9ba8  dc9a6e00e99a         fcomp qword ptr [edx - 0x6516ff92]
// 006e9bae  6e                   outsb dx, byte ptr [esi]
// 006e9baf  0008                 add byte ptr [eax], cl
// 006e9bb1  9b                   wait 
// 006e9bb2  6e                   outsb dx, byte ptr [esi]
// 006e9bb3  00419b               add byte ptr [ecx - 0x65], al
// 006e9bb6  6e                   outsb dx, byte ptr [esi]
// 006e9bb7  00799b               add byte ptr [ecx - 0x65], bh
// 006e9bba  6e                   outsb dx, byte ptr [esi]
// library lua-5.1.1/lgc.c (function _singlestep)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
