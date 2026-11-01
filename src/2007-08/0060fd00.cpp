// from server: 100% by auto
// roc 2007-08 0060fd00  unit: RBX::Ball  size: 256 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060fd00
//
// 0060fd00  55                   push ebp
// 0060fd01  56                   push esi
// 0060fd02  8bf0                 mov esi, eax
// 0060fd04  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0060fd07  0fb64515             movzx eax, byte ptr [ebp + 0x15]
// 0060fd0b  83f804               cmp eax, 4
// 0060fd0e  57                   push edi
// 0060fd0f  0f87cf000000         ja 0x60fde4
// 0060fd15  ff2485ecfd6000       jmp dword ptr [eax*4 + 0x60fdec]
// 0060fd1c  8bfe                 mov edi, esi
// 0060fd1e  e8adfdffff           call 0x60fad0
// 0060fd23  5f                   pop edi
// 0060fd24  5e                   pop esi
// 0060fd25  33c0                 xor eax, eax
// 0060fd27  5d                   pop ebp
// 0060fd28  c3                   ret 
// 0060fd29  837d2400             cmp dword ptr [ebp + 0x24], 0
// 0060fd2d  740a                 je 0x60fd39
// 0060fd2f  5f                   pop edi
// 0060fd30  5e                   pop esi
// 0060fd31  8bc5                 mov eax, ebp
// 0060fd33  5d                   pop ebp
// 0060fd34  e987f8ffff           jmp 0x60f5c0
// 0060fd39  56                   push esi
// 0060fd3a  e841feffff           call 0x60fb80
// 0060fd3f  83c404               add esp, 4
// 0060fd42  5f                   pop edi
// 0060fd43  5e                   pop esi
// 0060fd44  33c0                 xor eax, eax
// 0060fd46  5d                   pop ebp
// 0060fd47  c3                   ret 
// 0060fd48  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0060fd4b  8b4d00               mov ecx, dword ptr [ebp]
// 0060fd4e  8b7d44               mov edi, dword ptr [ebp + 0x44]
// 0060fd51  8d0c81               lea ecx, [ecx + eax*4]
// 0060fd54  6afd                 push -3
// 0060fd56  51                   push ecx
// 0060fd57  83c001               add eax, 1
// 0060fd5a  56                   push esi
// 0060fd5b  894518               mov dword ptr [ebp + 0x18], eax
// 0060fd5e  e8fdfaffff           call 0x60f860
// 0060fd63  8b5518               mov edx, dword ptr [ebp + 0x18]
// 0060fd66  83c40c               add esp, 0xc
// 0060fd69  3b5508               cmp edx, dword ptr [ebp + 8]
// 0060fd6c  7c04                 jl 0x60fd72
// 0060fd6e  c6451503             mov byte ptr [ebp + 0x15], 3
// 0060fd72  8b4544               mov eax, dword ptr [ebp + 0x44]
// 0060fd75  2bc7                 sub eax, edi
// 0060fd77  014548               add dword ptr [ebp + 0x48], eax
// 0060fd7a  5f                   pop edi
// 0060fd7b  5e                   pop esi
// 0060fd7c  b80a000000           mov eax, 0xa
// 0060fd81  5d                   pop ebp
// 0060fd82  c3                   ret 
// 0060fd83  8b4d20               mov ecx, dword ptr [ebp + 0x20]
// 0060fd86  8b7d44               mov edi, dword ptr [ebp + 0x44]
// 0060fd89  6a28                 push 0x28
// 0060fd8b  51                   push ecx
// 0060fd8c  56                   push esi
// 0060fd8d  e8cefaffff           call 0x60f860
// 0060fd92  83c40c               add esp, 0xc
// 0060fd95  894520               mov dword ptr [ebp + 0x20], eax
// 0060fd98  833800               cmp dword ptr [eax], 0
// 0060fd9b  750d                 jne 0x60fdaa
// 0060fd9d  53                   push ebx
// 0060fd9e  8bde                 mov ebx, esi
// 0060fda0  e84bfbffff           call 0x60f8f0
// 0060fda5  c6451504             mov byte ptr [ebp + 0x15], 4
// 0060fda9  5b                   pop ebx
// 0060fdaa  8b5544               mov edx, dword ptr [ebp + 0x44]
// 0060fdad  2bd7                 sub edx, edi
// 0060fdaf  015548               add dword ptr [ebp + 0x48], edx
// 0060fdb2  5f                   pop edi
// 0060fdb3  5e                   pop esi
// 0060fdb4  b890010000           mov eax, 0x190
// 0060fdb9  5d                   pop ebp
// 0060fdba  c3                   ret 
// 0060fdbb  33c0                 xor eax, eax
// 0060fdbd  394530               cmp dword ptr [ebp + 0x30], eax
// 0060fdc0  741c                 je 0x60fdde
// 0060fdc2  e899fbffff           call 0x60f960
// 0060fdc7  8b4548               mov eax, dword ptr [ebp + 0x48]
// 0060fdca  83f864               cmp eax, 0x64
// 0060fdcd  7606                 jbe 0x60fdd5
// 0060fdcf  83c09c               add eax, -0x64
// 0060fdd2  894548               mov dword ptr [ebp + 0x48], eax
// 0060fdd5  5f                   pop edi
// 0060fdd6  5e                   pop esi
// 0060fdd7  b864000000           mov eax, 0x64
// 0060fddc  5d                   pop ebp
// 0060fddd  c3                   ret 
// 0060fdde  884515               mov byte ptr [ebp + 0x15], al
// 0060fde1  89454c               mov dword ptr [ebp + 0x4c], eax
// 0060fde4  5f                   pop edi
// 0060fde5  5e                   pop esi
// 0060fde6  33c0                 xor eax, eax
// 0060fde8  5d                   pop ebp
// 0060fde9  c3                   ret 
// 0060fdea  8bff                 mov edi, edi
// 0060fdec  1cfd                 sbb al, 0xfd
// 0060fdee  60                   pushal 
// 0060fdef  0029                 add byte ptr [ecx], ch
// 0060fdf1  fd                   std 
// 0060fdf2  60                   pushal 
// 0060fdf3  0048fd               add byte ptr [eax - 3], cl
// 0060fdf6  60                   pushal 
// 0060fdf7  0083fd6000bb         add byte ptr [ebx - 0x44ff9f03], al
// 0060fdfd  fd                   std 
// 0060fdfe  60                   pushal 
// library lua-5.1.1/lgc.c (function _singlestep)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
