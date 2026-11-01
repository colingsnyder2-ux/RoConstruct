// from server: 100% by auto
// roc 2007-03 005095c0  unit: seg_00500000  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005095c0
//
// 005095c0  57                   push edi
// 005095c1  8b7c2408             mov edi, dword ptr [esp + 8]
// 005095c5  85ff                 test edi, edi
// 005095c7  746e                 je 0x509637
// 005095c9  56                   push esi
// 005095ca  8b742410             mov esi, dword ptr [esp + 0x10]
// 005095ce  85f6                 test esi, esi
// 005095d0  7464                 je 0x509636
// 005095d2  dd05d8097a00         fld qword ptr [0x7a09d8]
// 005095d8  dd442414             fld qword ptr [esp + 0x14]
// 005095dc  d8d1                 fcom st(1)
// 005095de  dfe0                 fnstsw ax
// 005095e0  ddd9                 fstp st(1)
// 005095e2  f6c441               test ah, 0x41
// 005095e5  7516                 jne 0x5095fd
// 005095e7  68f8097a00           push 0x7a09f8
// 005095ec  ddd8                 fstp st(0)
// 005095ee  57                   push edi
// 005095ef  e8dced0000           call 0x5183d0
// 005095f4  dd05d8097a00         fld qword ptr [0x7a09d8]
// 005095fa  83c408               add esp, 8
// 005095fd  d95628               fst dword ptr [esi + 0x28]
// 00509600  dd05d0097a00         fld qword ptr [0x7a09d0]
// 00509606  d8c9                 fmul st(1)
// 00509608  dc05584f7900         fadd qword ptr [0x794f58]
// 0050960e  e8ed5b1100           call 0x61f200
// 00509613  d9ee                 fldz 
// 00509615  834e0801             or dword ptr [esi + 8], 1
// 00509619  dae9                 fucompp 
// 0050961b  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 00509621  dfe0                 fnstsw ax
// 00509623  f6c444               test ah, 0x44
// 00509626  7a0e                 jp 0x509636
// 00509628  68e8097a00           push 0x7a09e8
// 0050962d  57                   push edi
// 0050962e  e89ded0000           call 0x5183d0
// 00509633  83c408               add esp, 8
// 00509636  5e                   pop esi
// 00509637  5f                   pop edi
// 00509638  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_gAMA)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
