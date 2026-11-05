// from server: 100% by auto
// roc 2011-06 00559730  unit: seg_00550000  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00559730
//
// 00559730  837c240400           cmp dword ptr [esp + 4], 0
// 00559735  0f84f6000000         je 0x559831
// 0055973b  56                   push esi
// 0055973c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00559740  85f6                 test esi, esi
// 00559742  0f84e8000000         je 0x559830
// 00559748  dd442410             fld qword ptr [esp + 0x10]
// 0055974c  d99680000000         fst dword ptr [esi + 0x80]
// 00559752  dd442418             fld qword ptr [esp + 0x18]
// 00559756  d99684000000         fst dword ptr [esi + 0x84]
// 0055975c  dd442420             fld qword ptr [esp + 0x20]
// 00559760  d99688000000         fst dword ptr [esi + 0x88]
// 00559766  dd442428             fld qword ptr [esp + 0x28]
// 0055976a  d9968c000000         fst dword ptr [esi + 0x8c]
// 00559770  dd442430             fld qword ptr [esp + 0x30]
// 00559774  d99690000000         fst dword ptr [esi + 0x90]
// 0055977a  dd442438             fld qword ptr [esp + 0x38]
// 0055977e  d99e94000000         fstp dword ptr [esi + 0x94]
// 00559784  dd442440             fld qword ptr [esp + 0x40]
// 00559788  d99e98000000         fstp dword ptr [esi + 0x98]
// 0055978e  dd442448             fld qword ptr [esp + 0x48]
// 00559792  d99e9c000000         fstp dword ptr [esi + 0x9c]
// 00559798  dd05c890a600         fld qword ptr [0xa690c8]
// 0055979e  dccd                 fmul st(5), st(0)
// 005597a0  dd0508afa700         fld qword ptr [0xa7af08]
// 005597a6  dcc6                 fadd st(6), st(0)
// 005597a8  d9ce                 fxch st(6)
// 005597aa  e8811d2b00           call 0x80b530
// 005597af  dccc                 fmul st(4), st(0)
// 005597b1  d9cc                 fxch st(4)
// 005597b3  898600010000         mov dword ptr [esi + 0x100], eax
// 005597b9  d8c5                 fadd st(5)
// 005597bb  e8701d2b00           call 0x80b530
// 005597c0  d9ca                 fxch st(2)
// 005597c2  d8cb                 fmul st(3)
// 005597c4  898604010000         mov dword ptr [esi + 0x104], eax
// 005597ca  d8c4                 fadd st(4)
// 005597cc  e85f1d2b00           call 0x80b530
// 005597d1  d8ca                 fmul st(2)
// 005597d3  898608010000         mov dword ptr [esi + 0x108], eax
// 005597d9  d8c3                 fadd st(3)
// 005597db  e8501d2b00           call 0x80b530
// 005597e0  d8c9                 fmul st(1)
// 005597e2  89860c010000         mov dword ptr [esi + 0x10c], eax
// 005597e8  d8c2                 fadd st(2)
// 005597ea  e8411d2b00           call 0x80b530
// 005597ef  dd442438             fld qword ptr [esp + 0x38]
// 005597f3  d8c9                 fmul st(1)
// 005597f5  898610010000         mov dword ptr [esi + 0x110], eax
// 005597fb  d8c2                 fadd st(2)
// 005597fd  e82e1d2b00           call 0x80b530
// 00559802  dd442440             fld qword ptr [esp + 0x40]
// 00559806  d8c9                 fmul st(1)
// 00559808  898614010000         mov dword ptr [esi + 0x114], eax
// 0055980e  d8c2                 fadd st(2)
// 00559810  e81b1d2b00           call 0x80b530
// 00559815  dc4c2448             fmul qword ptr [esp + 0x48]
// 00559819  898618010000         mov dword ptr [esi + 0x118], eax
// 0055981f  dec1                 faddp st(1)
// 00559821  e80a1d2b00           call 0x80b530
// 00559826  834e0804             or dword ptr [esi + 8], 4
// 0055982a  89861c010000         mov dword ptr [esi + 0x11c], eax
// 00559830  5e                   pop esi
// 00559831  c3                   ret 
// library libpng-1.2.35/pngset.c (function _png_set_cHRM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngset.c
