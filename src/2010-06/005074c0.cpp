// from server: 100% by auto
// roc 2010-06 005074c0  unit: seg_00500000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005074c0
//
// 005074c0  56                   push esi
// 005074c1  57                   push edi
// 005074c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005074c6  57                   push edi
// 005074c7  8bf1                 mov esi, ecx
// 005074c9  e8a2eb0400           call 0x556070
// 005074ce  d94724               fld dword ptr [edi + 0x24]
// 005074d1  8b442410             mov eax, dword ptr [esp + 0x10]
// 005074d5  d95e24               fstp dword ptr [esi + 0x24]
// 005074d8  d94728               fld dword ptr [edi + 0x28]
// 005074db  d95e28               fstp dword ptr [esi + 0x28]
// 005074de  d9472c               fld dword ptr [edi + 0x2c]
// 005074e1  5f                   pop edi
// 005074e2  d95e2c               fstp dword ptr [esi + 0x2c]
// 005074e5  d900                 fld dword ptr [eax]
// 005074e7  d95e30               fstp dword ptr [esi + 0x30]
// 005074ea  d94004               fld dword ptr [eax + 4]
// 005074ed  d95e34               fstp dword ptr [esi + 0x34]
// 005074f0  d94008               fld dword ptr [eax + 8]
// 005074f3  d95e38               fstp dword ptr [esi + 0x38]
// 005074f6  d9400c               fld dword ptr [eax + 0xc]
// 005074f9  d95e3c               fstp dword ptr [esi + 0x3c]
// 005074fc  d94010               fld dword ptr [eax + 0x10]
// 005074ff  d95e40               fstp dword ptr [esi + 0x40]
// 00507502  d94014               fld dword ptr [eax + 0x14]
// 00507505  8bc6                 mov eax, esi
// 00507507  d95e44               fstp dword ptr [esi + 0x44]
// 0050750a  5e                   pop esi
// 0050750b  c20800               ret 8
// library rbxgs/util\PV.cpp (function ??0PV@RBX@@QAE@ABVCoordinateFrame@G3D@@ABVVelocity@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
