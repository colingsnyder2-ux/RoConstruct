// from server: 100% by auto
// roc 2012-06 00633bc0  unit: G3D::Random  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00633bc0
//
// 00633bc0  51                   push ecx
// 00633bc1  8b01                 mov eax, dword ptr [ecx]
// 00633bc3  8b5008               mov edx, dword ptr [eax + 8]
// 00633bc6  56                   push esi
// 00633bc7  ffd2                 call edx
// 00633bc9  89442404             mov dword ptr [esp + 4], eax
// 00633bcd  db442404             fild dword ptr [esp + 4]
// 00633bd1  85c0                 test eax, eax
// 00633bd3  7d06                 jge 0x633bdb
// 00633bd5  dc0578fdb400         fadd qword ptr [0xb4fd78]
// 00633bdb  8b742410             mov esi, dword ptr [esp + 0x10]
// 00633bdf  8bc6                 mov eax, esi
// 00633be1  2b44240c             sub eax, dword ptr [esp + 0xc]
// 00633be5  83ec08               sub esp, 8
// 00633be8  40                   inc eax
// 00633be9  89442418             mov dword ptr [esp + 0x18], eax
// 00633bed  db442418             fild dword ptr [esp + 0x18]
// 00633bf1  dec9                 fmulp st(1)
// 00633bf3  dc0d983bb800         fmul qword ptr [0xb83b98]
// 00633bf9  da442414             fiadd dword ptr [esp + 0x14]
// 00633bfd  dd1c24               fstp qword ptr [esp]
// 00633c00  e831ff3400           call 0x983b36
// 00633c05  83c408               add esp, 8
// 00633c08  e8a3f93400           call 0x9835b0
// 00633c0d  3bc6                 cmp eax, esi
// 00633c0f  7e02                 jle 0x633c13
// 00633c11  8bc6                 mov eax, esi
// 00633c13  5e                   pop esi
// 00633c14  59                   pop ecx
// 00633c15  c20800               ret 8
// library rbx2016-g3d/Random.cpp (function ?integer@Random@G3D@@UAEHHH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Random.cpp
