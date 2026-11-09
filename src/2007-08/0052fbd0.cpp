// from server: 100% by colin
// roc 2007-08 0052fbd0  unit: RBX::VRunService::?$SignalDesc  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0052fbd0
//
// 0052fbd0  8b442408             mov eax, dword ptr [esp + 8]
// 0052fbd4  d900                 fld dword ptr [eax]
// 0052fbd6  d86124               fsub dword ptr [ecx + 0x24]
// 0052fbd9  d94004               fld dword ptr [eax + 4]
// 0052fbdc  d86128               fsub dword ptr [ecx + 0x28]
// 0052fbdf  d94008               fld dword ptr [eax + 8]
// 0052fbe2  8b442404             mov eax, dword ptr [esp + 4]
// 0052fbe6  d8612c               fsub dword ptr [ecx + 0x2c]
// 0052fbe9  d94140               fld dword ptr [ecx + 0x40]
// 0052fbec  d8c9                 fmul st(1)
// 0052fbee  d94144               fld dword ptr [ecx + 0x44]
// 0052fbf1  d8cb                 fmul st(3)
// 0052fbf3  dee9                 fsubp st(1)
// 0052fbf5  d94144               fld dword ptr [ecx + 0x44]
// 0052fbf8  d8cc                 fmul st(4)
// 0052fbfa  d9413c               fld dword ptr [ecx + 0x3c]
// 0052fbfd  decb                 fmulp st(3)
// 0052fbff  dee2                 fsubrp st(2)
// 0052fc01  d9413c               fld dword ptr [ecx + 0x3c]
// 0052fc04  decb                 fmulp st(3)
// 0052fc06  d94140               fld dword ptr [ecx + 0x40]
// 0052fc09  decc                 fmulp st(4)
// 0052fc0b  d9ca                 fxch st(2)
// 0052fc0d  dee3                 fsubrp st(3)
// 0052fc0f  d94130               fld dword ptr [ecx + 0x30]
// 0052fc12  dec2                 faddp st(2)
// 0052fc14  d84134               fadd dword ptr [ecx + 0x34]
// 0052fc17  d94138               fld dword ptr [ecx + 0x38]
// 0052fc1a  dec3                 faddp st(3)
// 0052fc1c  d9c9                 fxch st(1)
// 0052fc1e  d918                 fstp dword ptr [eax]
// 0052fc20  d95804               fstp dword ptr [eax + 4]
// 0052fc23  d95808               fstp dword ptr [eax + 8]
// 0052fc26  d9413c               fld dword ptr [ecx + 0x3c]
// 0052fc29  d9580c               fstp dword ptr [eax + 0xc]
// 0052fc2c  d94140               fld dword ptr [ecx + 0x40]
// 0052fc2f  d95810               fstp dword ptr [eax + 0x10]
// 0052fc32  d94144               fld dword ptr [ecx + 0x44]
// 0052fc35  d95814               fstp dword ptr [eax + 0x14]
// 0052fc38  c20800               ret 8
// copied from an identical function in another client (function ?velocityAtPoint@PV@RBX@@QBE?AVVelocity@2@ABVVector3@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll util/PV.cpp