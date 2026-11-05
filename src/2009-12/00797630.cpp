// from server: 100% by auto
// roc 2009-12 00797630  unit: lua_exception  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797630
//
// 00797630  8b4614               mov eax, dword ptr [esi + 0x14]
// 00797633  53                   push ebx
// 00797634  57                   push edi
// 00797635  8b38                 mov edi, dword ptr [eax]
// 00797637  8bc2                 mov eax, edx
// 00797639  897e08               mov dword ptr [esi + 8], edi
// 0079763c  8d5801               lea ebx, [eax + 1]
// 0079763f  90                   nop 
// 00797640  8a08                 mov cl, byte ptr [eax]
// 00797642  40                   inc eax
// 00797643  84c9                 test cl, cl
// 00797645  75f9                 jne 0x797640
// 00797647  2bc3                 sub eax, ebx
// 00797649  50                   push eax
// 0079764a  52                   push edx
// 0079764b  56                   push esi
// 0079764c  e83f950300           call 0x7d0b90
// 00797651  8907                 mov dword ptr [edi], eax
// 00797653  c7470804000000       mov dword ptr [edi + 8], 4
// 0079765a  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0079765d  2b4e08               sub ecx, dword ptr [esi + 8]
// 00797660  bf10000000           mov edi, 0x10
// 00797665  83c40c               add esp, 0xc
// 00797668  3bcf                 cmp ecx, edi
// 0079766a  7f2b                 jg 0x797697
// 0079766c  8b462c               mov eax, dword ptr [esi + 0x2c]
// 0079766f  83f801               cmp eax, 1
// 00797672  7c18                 jl 0x79768c
// 00797674  8d1400               lea edx, [eax + eax]
// 00797677  52                   push edx
// 00797678  56                   push esi
// 00797679  e8d2fbffff           call 0x797250
// 0079767e  83c408               add esp, 8
// 00797681  017e08               add dword ptr [esi + 8], edi
// 00797684  5f                   pop edi
// 00797685  b802000000           mov eax, 2
// 0079768a  5b                   pop ebx
// 0079768b  c3                   ret 
// 0079768c  40                   inc eax
// 0079768d  50                   push eax
// 0079768e  56                   push esi
// 0079768f  e8bcfbffff           call 0x797250
// 00797694  83c408               add esp, 8
// 00797697  017e08               add dword ptr [esi + 8], edi
// 0079769a  5f                   pop edi
// 0079769b  b802000000           mov eax, 2
// 007976a0  5b                   pop ebx
// 007976a1  c3                   ret 
// library lua-5.1/ldo.c (function _resume_error)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
