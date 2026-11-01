// from server: 100% by auto
// roc 2007-03 005fd3f0  unit: seg_005f0000  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd3f0
//
// 005fd3f0  53                   push ebx
// 005fd3f1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005fd3f5  56                   push esi
// 005fd3f6  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005fd3fa  8bc6                 mov eax, esi
// 005fd3fc  99                   cdq 
// 005fd3fd  57                   push edi
// 005fd3fe  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005fd402  8b0f                 mov ecx, dword ptr [edi]
// 005fd404  2bc2                 sub eax, edx
// 005fd406  d1f8                 sar eax, 1
// 005fd408  3bc8                 cmp ecx, eax
// 005fd40a  7c14                 jl 0x5fd420
// 005fd40c  3bce                 cmp ecx, esi
// 005fd40e  7c1d                 jl 0x5fd42d
// 005fd410  8b442424             mov eax, dword ptr [esp + 0x24]
// 005fd414  50                   push eax
// 005fd415  53                   push ebx
// 005fd416  e8955cfcff           call 0x5c30b0
// 005fd41b  83c408               add esp, 8
// 005fd41e  eb0d                 jmp 0x5fd42d
// 005fd420  8d3409               lea esi, [ecx + ecx]
// 005fd423  83fe04               cmp esi, 4
// 005fd426  7d05                 jge 0x5fd42d
// 005fd428  be04000000           mov esi, 4
// 005fd42d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005fd431  33d2                 xor edx, edx
// 005fd433  b8fdffffff           mov eax, 0xfffffffd
// 005fd438  f7f1                 div ecx
// 005fd43a  55                   push ebp
// 005fd43b  8d6e01               lea ebp, [esi + 1]
// 005fd43e  3be8                 cmp ebp, eax
// 005fd440  5d                   pop ebp
// 005fd441  7720                 ja 0x5fd463
// 005fd443  8b07                 mov eax, dword ptr [edi]
// 005fd445  8bd6                 mov edx, esi
// 005fd447  0fafc1               imul eax, ecx
// 005fd44a  0fafd1               imul edx, ecx
// 005fd44d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005fd451  52                   push edx
// 005fd452  50                   push eax
// 005fd453  51                   push ecx
// 005fd454  53                   push ebx
// 005fd455  e846ffffff           call 0x5fd3a0
// 005fd45a  83c410               add esp, 0x10
// 005fd45d  8937                 mov dword ptr [edi], esi
// 005fd45f  5f                   pop edi
// 005fd460  5e                   pop esi
// 005fd461  5b                   pop ebx
// 005fd462  c3                   ret 
// 005fd463  68e0037c00           push 0x7c03e0
// 005fd468  53                   push ebx
// 005fd469  e8425cfcff           call 0x5c30b0
// 005fd46e  83c408               add esp, 8
// 005fd471  8937                 mov dword ptr [edi], esi
// 005fd473  5f                   pop edi
// 005fd474  5e                   pop esi
// 005fd475  33c0                 xor eax, eax
// 005fd477  5b                   pop ebx
// 005fd478  c3                   ret 
// library lua-5.1.1/lmem.c (function _luaM_growaux_)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lmem.c
