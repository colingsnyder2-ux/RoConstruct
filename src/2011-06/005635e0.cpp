// from server: 100% by auto
// roc 2011-06 005635e0  unit: G3D::Random  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005635e0
//
// 005635e0  51                   push ecx
// 005635e1  8b01                 mov eax, dword ptr [ecx]
// 005635e3  8b5008               mov edx, dword ptr [eax + 8]
// 005635e6  56                   push esi
// 005635e7  ffd2                 call edx
// 005635e9  89442404             mov dword ptr [esp + 4], eax
// 005635ed  db442404             fild dword ptr [esp + 4]
// 005635f1  85c0                 test eax, eax
// 005635f3  7d06                 jge 0x5635fb
// 005635f5  dc059062a600         fadd qword ptr [0xa66290]
// 005635fb  8b742410             mov esi, dword ptr [esp + 0x10]
// 005635ff  8bc6                 mov eax, esi
// 00563601  2b44240c             sub eax, dword ptr [esp + 0xc]
// 00563605  83ec08               sub esp, 8
// 00563608  40                   inc eax
// 00563609  89442418             mov dword ptr [esp + 0x18], eax
// 0056360d  db442418             fild dword ptr [esp + 0x18]
// 00563611  dec9                 fmulp st(1)
// 00563613  dc0d1058a800         fmul qword ptr [0xa85810]
// 00563619  da442414             fiadd dword ptr [esp + 0x14]
// 0056361d  dd1c24               fstp qword ptr [esp]
// 00563620  e8e1822a00           call 0x80b906
// 00563625  83c408               add esp, 8
// 00563628  e8037f2a00           call 0x80b530
// 0056362d  3bc6                 cmp eax, esi
// 0056362f  7e02                 jle 0x563633
// 00563631  8bc6                 mov eax, esi
// 00563633  5e                   pop esi
// 00563634  59                   pop ecx
// 00563635  c20800               ret 8
// library rbx2016-g3d/Random.cpp (function ?integer@Random@G3D@@UAEHHH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Random.cpp
