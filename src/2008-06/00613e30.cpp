// from server: 100% by auto
// roc 2008-06 00613e30  unit: RBX::RevoluteLink  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00613e30
//
// 00613e30  56                   push esi
// 00613e31  57                   push edi
// 00613e32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00613e36  57                   push edi
// 00613e37  8bf1                 mov esi, ecx
// 00613e39  e8e2f3efff           call 0x513220
// 00613e3e  d94724               fld dword ptr [edi + 0x24]
// 00613e41  8b442410             mov eax, dword ptr [esp + 0x10]
// 00613e45  d95e24               fstp dword ptr [esi + 0x24]
// 00613e48  d94728               fld dword ptr [edi + 0x28]
// 00613e4b  d95e28               fstp dword ptr [esi + 0x28]
// 00613e4e  d9472c               fld dword ptr [edi + 0x2c]
// 00613e51  5f                   pop edi
// 00613e52  d95e2c               fstp dword ptr [esi + 0x2c]
// 00613e55  d900                 fld dword ptr [eax]
// 00613e57  d95e30               fstp dword ptr [esi + 0x30]
// 00613e5a  d94004               fld dword ptr [eax + 4]
// 00613e5d  d95e34               fstp dword ptr [esi + 0x34]
// 00613e60  d94008               fld dword ptr [eax + 8]
// 00613e63  d95e38               fstp dword ptr [esi + 0x38]
// 00613e66  d9400c               fld dword ptr [eax + 0xc]
// 00613e69  d95e3c               fstp dword ptr [esi + 0x3c]
// 00613e6c  d94010               fld dword ptr [eax + 0x10]
// 00613e6f  d95e40               fstp dword ptr [esi + 0x40]
// 00613e72  d94014               fld dword ptr [eax + 0x14]
// 00613e75  8bc6                 mov eax, esi
// 00613e77  d95e44               fstp dword ptr [esi + 0x44]
// 00613e7a  5e                   pop esi
// 00613e7b  c20800               ret 8
// library rbxgs/util\PV.cpp (function ??0PV@RBX@@QAE@ABVCoordinateFrame@G3D@@ABVVelocity@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
