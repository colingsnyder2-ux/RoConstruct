// from server: 100% by auto
// roc 2009-12 007d1080  unit: seg_007d0000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1080
//
// 007d1080  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d1084  8b5138               mov edx, dword ptr [ecx + 0x38]
// 007d1087  53                   push ebx
// 007d1088  56                   push esi
// 007d1089  33c0                 xor eax, eax
// 007d108b  57                   push edi
// 007d108c  85d2                 test edx, edx
// 007d108e  7e26                 jle 0x7d10b6
// 007d1090  8b5918               mov ebx, dword ptr [ecx + 0x18]
// 007d1093  8b742418             mov esi, dword ptr [esp + 0x18]
// 007d1097  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007d109b  8d4b08               lea ecx, [ebx + 8]
// 007d109e  8bff                 mov edi, edi
// 007d10a0  3971fc               cmp dword ptr [ecx - 4], esi
// 007d10a3  7f11                 jg 0x7d10b6
// 007d10a5  3b31                 cmp esi, dword ptr [ecx]
// 007d10a7  7d05                 jge 0x7d10ae
// 007d10a9  83ef01               sub edi, 1
// 007d10ac  740e                 je 0x7d10bc
// 007d10ae  40                   inc eax
// 007d10af  83c10c               add ecx, 0xc
// 007d10b2  3bc2                 cmp eax, edx
// 007d10b4  7cea                 jl 0x7d10a0
// 007d10b6  5f                   pop edi
// 007d10b7  5e                   pop esi
// 007d10b8  33c0                 xor eax, eax
// 007d10ba  5b                   pop ebx
// 007d10bb  c3                   ret 
// 007d10bc  8d0440               lea eax, [eax + eax*2]
// 007d10bf  8b0483               mov eax, dword ptr [ebx + eax*4]
// 007d10c2  5f                   pop edi
// 007d10c3  5e                   pop esi
// 007d10c4  83c010               add eax, 0x10
// 007d10c7  5b                   pop ebx
// 007d10c8  c3                   ret 
// library lua-5.1/lfunc.c (function _luaF_getlocalname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lfunc.c
