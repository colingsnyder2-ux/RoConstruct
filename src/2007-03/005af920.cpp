// from server: 100% by colin
// roc 2007-03 005af920  unit: seg_005a0000  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005af920
//
// 005af920  8b442408             mov eax, dword ptr [esp + 8]
// 005af924  d900                 fld dword ptr [eax]
// 005af926  d86124               fsub dword ptr [ecx + 0x24]
// 005af929  d94004               fld dword ptr [eax + 4]
// 005af92c  d86128               fsub dword ptr [ecx + 0x28]
// 005af92f  d94008               fld dword ptr [eax + 8]
// 005af932  8b442404             mov eax, dword ptr [esp + 4]
// 005af936  d8612c               fsub dword ptr [ecx + 0x2c]
// 005af939  d94140               fld dword ptr [ecx + 0x40]
// 005af93c  d8c9                 fmul st(1)
// 005af93e  d94144               fld dword ptr [ecx + 0x44]
// 005af941  d8cb                 fmul st(3)
// 005af943  dee9                 fsubp st(1)
// 005af945  d94144               fld dword ptr [ecx + 0x44]
// 005af948  d8cc                 fmul st(4)
// 005af94a  d9413c               fld dword ptr [ecx + 0x3c]
// 005af94d  decb                 fmulp st(3)
// 005af94f  dee2                 fsubrp st(2)
// 005af951  d9413c               fld dword ptr [ecx + 0x3c]
// 005af954  decb                 fmulp st(3)
// 005af956  d94140               fld dword ptr [ecx + 0x40]
// 005af959  decc                 fmulp st(4)
// 005af95b  d9ca                 fxch st(2)
// 005af95d  dee3                 fsubrp st(3)
// 005af95f  d94130               fld dword ptr [ecx + 0x30]
// 005af962  dec2                 faddp st(2)
// 005af964  d84134               fadd dword ptr [ecx + 0x34]
// 005af967  d94138               fld dword ptr [ecx + 0x38]
// 005af96a  dec3                 faddp st(3)
// 005af96c  d9c9                 fxch st(1)
// 005af96e  d918                 fstp dword ptr [eax]
// 005af970  d95804               fstp dword ptr [eax + 4]
// 005af973  d95808               fstp dword ptr [eax + 8]
// 005af976  d9413c               fld dword ptr [ecx + 0x3c]
// 005af979  d9580c               fstp dword ptr [eax + 0xc]
// 005af97c  d94140               fld dword ptr [ecx + 0x40]
// 005af97f  d95810               fstp dword ptr [eax + 0x10]
// 005af982  d94144               fld dword ptr [ecx + 0x44]
// 005af985  d95814               fstp dword ptr [eax + 0x14]
// 005af988  c20800               ret 8
// copied from an identical function in another client (function ?velocityAtPoint@PV@RBX@@QBE?AVVelocity@2@ABVVector3@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll util/PV.cpp