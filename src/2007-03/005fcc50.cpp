// from server: 100% by auto
// roc 2007-03 005fcc50  unit: seg_005f0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fcc50
//
// 005fcc50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005fcc54  8b5138               mov edx, dword ptr [ecx + 0x38]
// 005fcc57  53                   push ebx
// 005fcc58  56                   push esi
// 005fcc59  33c0                 xor eax, eax
// 005fcc5b  85d2                 test edx, edx
// 005fcc5d  57                   push edi
// 005fcc5e  7e28                 jle 0x5fcc88
// 005fcc60  8b5918               mov ebx, dword ptr [ecx + 0x18]
// 005fcc63  8b742418             mov esi, dword ptr [esp + 0x18]
// 005fcc67  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005fcc6b  8d4b08               lea ecx, [ebx + 8]
// 005fcc6e  8bff                 mov edi, edi
// 005fcc70  3971fc               cmp dword ptr [ecx - 4], esi
// 005fcc73  7f13                 jg 0x5fcc88
// 005fcc75  3b31                 cmp esi, dword ptr [ecx]
// 005fcc77  7d05                 jge 0x5fcc7e
// 005fcc79  83ef01               sub edi, 1
// 005fcc7c  7410                 je 0x5fcc8e
// 005fcc7e  83c001               add eax, 1
// 005fcc81  83c10c               add ecx, 0xc
// 005fcc84  3bc2                 cmp eax, edx
// 005fcc86  7ce8                 jl 0x5fcc70
// 005fcc88  5f                   pop edi
// 005fcc89  5e                   pop esi
// 005fcc8a  33c0                 xor eax, eax
// 005fcc8c  5b                   pop ebx
// 005fcc8d  c3                   ret 
// 005fcc8e  8d0440               lea eax, [eax + eax*2]
// 005fcc91  8b0483               mov eax, dword ptr [ebx + eax*4]
// 005fcc94  5f                   pop edi
// 005fcc95  5e                   pop esi
// 005fcc96  83c010               add eax, 0x10
// 005fcc99  5b                   pop ebx
// 005fcc9a  c3                   ret 
// library lua-5.1.1/lfunc.c (function _luaF_getlocalname)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lfunc.c
