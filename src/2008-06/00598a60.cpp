// from server: 100% by auto
// roc 2008-06 00598a60  unit: RBX::NullController  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00598a60
//
// 00598a60  8b442408             mov eax, dword ptr [esp + 8]
// 00598a64  d900                 fld dword ptr [eax]
// 00598a66  d86124               fsub dword ptr [ecx + 0x24]
// 00598a69  d94004               fld dword ptr [eax + 4]
// 00598a6c  d86128               fsub dword ptr [ecx + 0x28]
// 00598a6f  d94008               fld dword ptr [eax + 8]
// 00598a72  8b442404             mov eax, dword ptr [esp + 4]
// 00598a76  d8612c               fsub dword ptr [ecx + 0x2c]
// 00598a79  d94140               fld dword ptr [ecx + 0x40]
// 00598a7c  d8c9                 fmul st(1)
// 00598a7e  d94144               fld dword ptr [ecx + 0x44]
// 00598a81  d8cb                 fmul st(3)
// 00598a83  dee9                 fsubp st(1)
// 00598a85  d94144               fld dword ptr [ecx + 0x44]
// 00598a88  d8cc                 fmul st(4)
// 00598a8a  d9413c               fld dword ptr [ecx + 0x3c]
// 00598a8d  decb                 fmulp st(3)
// 00598a8f  dee2                 fsubrp st(2)
// 00598a91  d9413c               fld dword ptr [ecx + 0x3c]
// 00598a94  decb                 fmulp st(3)
// 00598a96  d94140               fld dword ptr [ecx + 0x40]
// 00598a99  decc                 fmulp st(4)
// 00598a9b  d9ca                 fxch st(2)
// 00598a9d  dee3                 fsubrp st(3)
// 00598a9f  d94130               fld dword ptr [ecx + 0x30]
// 00598aa2  dec2                 faddp st(2)
// 00598aa4  d84134               fadd dword ptr [ecx + 0x34]
// 00598aa7  d94138               fld dword ptr [ecx + 0x38]
// 00598aaa  dec3                 faddp st(3)
// 00598aac  d9c9                 fxch st(1)
// 00598aae  d918                 fstp dword ptr [eax]
// 00598ab0  d95804               fstp dword ptr [eax + 4]
// 00598ab3  d95808               fstp dword ptr [eax + 8]
// 00598ab6  d9413c               fld dword ptr [ecx + 0x3c]
// 00598ab9  d9580c               fstp dword ptr [eax + 0xc]
// 00598abc  d94140               fld dword ptr [ecx + 0x40]
// 00598abf  d95810               fstp dword ptr [eax + 0x10]
// 00598ac2  d94144               fld dword ptr [ecx + 0x44]
// 00598ac5  d95814               fstp dword ptr [eax + 0x14]
// 00598ac8  c20800               ret 8
// library rbxgs-dll/util\PV.cpp (function ?velocityAtPoint@PV@RBX@@QBE?AVVelocity@2@ABVVector3@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll util/PV.cpp
