// from server: 100% by auto
// roc 2012-06 006465b0  unit: seg_00640000  size: 258 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006465b0
//
// 006465b0  837c240400           cmp dword ptr [esp + 4], 0
// 006465b5  0f84f6000000         je 0x6466b1
// 006465bb  56                   push esi
// 006465bc  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006465c0  85f6                 test esi, esi
// 006465c2  0f84e8000000         je 0x6466b0
// 006465c8  dd442410             fld qword ptr [esp + 0x10]
// 006465cc  d99680000000         fst dword ptr [esi + 0x80]
// 006465d2  dd442418             fld qword ptr [esp + 0x18]
// 006465d6  d99684000000         fst dword ptr [esi + 0x84]
// 006465dc  dd442420             fld qword ptr [esp + 0x20]
// 006465e0  d99688000000         fst dword ptr [esi + 0x88]
// 006465e6  dd442428             fld qword ptr [esp + 0x28]
// 006465ea  d9968c000000         fst dword ptr [esi + 0x8c]
// 006465f0  dd442430             fld qword ptr [esp + 0x30]
// 006465f4  d99690000000         fst dword ptr [esi + 0x90]
// 006465fa  dd442438             fld qword ptr [esp + 0x38]
// 006465fe  d99e94000000         fstp dword ptr [esi + 0x94]
// 00646604  dd442440             fld qword ptr [esp + 0x40]
// 00646608  d99e98000000         fstp dword ptr [esi + 0x98]
// 0064660e  dd442448             fld qword ptr [esp + 0x48]
// 00646612  d99e9c000000         fstp dword ptr [esi + 0x9c]
// 00646618  dd05e03ab500         fld qword ptr [0xb53ae0]
// 0064661e  dccd                 fmul st(5), st(0)
// 00646620  dd0500a2b600         fld qword ptr [0xb6a200]
// 00646626  dcc6                 fadd st(6), st(0)
// 00646628  d9ce                 fxch st(6)
// 0064662a  e881cf3300           call 0x9835b0
// 0064662f  dccc                 fmul st(4), st(0)
// 00646631  d9cc                 fxch st(4)
// 00646633  898600010000         mov dword ptr [esi + 0x100], eax
// 00646639  d8c5                 fadd st(5)
// 0064663b  e870cf3300           call 0x9835b0
// 00646640  d9ca                 fxch st(2)
// 00646642  d8cb                 fmul st(3)
// 00646644  898604010000         mov dword ptr [esi + 0x104], eax
// 0064664a  d8c4                 fadd st(4)
// 0064664c  e85fcf3300           call 0x9835b0
// 00646651  d8ca                 fmul st(2)
// 00646653  898608010000         mov dword ptr [esi + 0x108], eax
// 00646659  d8c3                 fadd st(3)
// 0064665b  e850cf3300           call 0x9835b0
// 00646660  d8c9                 fmul st(1)
// 00646662  89860c010000         mov dword ptr [esi + 0x10c], eax
// 00646668  d8c2                 fadd st(2)
// 0064666a  e841cf3300           call 0x9835b0
// 0064666f  dd442438             fld qword ptr [esp + 0x38]
// 00646673  d8c9                 fmul st(1)
// 00646675  898610010000         mov dword ptr [esi + 0x110], eax
// 0064667b  d8c2                 fadd st(2)
// 0064667d  e82ecf3300           call 0x9835b0
// 00646682  dd442440             fld qword ptr [esp + 0x40]
// 00646686  d8c9                 fmul st(1)
// 00646688  898614010000         mov dword ptr [esi + 0x114], eax
// 0064668e  d8c2                 fadd st(2)
// 00646690  e81bcf3300           call 0x9835b0
// 00646695  dc4c2448             fmul qword ptr [esp + 0x48]
// 00646699  898618010000         mov dword ptr [esi + 0x118], eax
// 0064669f  dec1                 faddp st(1)
// 006466a1  e80acf3300           call 0x9835b0
// 006466a6  834e0804             or dword ptr [esi + 8], 4
// 006466aa  89861c010000         mov dword ptr [esi + 0x11c], eax
// 006466b0  5e                   pop esi
// 006466b1  c3                   ret 
// library libpng-1.2.35/pngset.c (function _png_set_cHRM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngset.c
