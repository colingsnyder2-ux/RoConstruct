// from server: 100% by auto
// roc 2009-12 00558a60  unit: seg_00550000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00558a60
//
// 00558a60  56                   push esi
// 00558a61  57                   push edi
// 00558a62  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00558a66  57                   push edi
// 00558a67  8bf1                 mov esi, ecx
// 00558a69  e892ae0900           call 0x5f3900
// 00558a6e  d94724               fld dword ptr [edi + 0x24]
// 00558a71  8b442410             mov eax, dword ptr [esp + 0x10]
// 00558a75  d95e24               fstp dword ptr [esi + 0x24]
// 00558a78  d94728               fld dword ptr [edi + 0x28]
// 00558a7b  d95e28               fstp dword ptr [esi + 0x28]
// 00558a7e  d9472c               fld dword ptr [edi + 0x2c]
// 00558a81  5f                   pop edi
// 00558a82  d95e2c               fstp dword ptr [esi + 0x2c]
// 00558a85  d900                 fld dword ptr [eax]
// 00558a87  d95e30               fstp dword ptr [esi + 0x30]
// 00558a8a  d94004               fld dword ptr [eax + 4]
// 00558a8d  d95e34               fstp dword ptr [esi + 0x34]
// 00558a90  d94008               fld dword ptr [eax + 8]
// 00558a93  d95e38               fstp dword ptr [esi + 0x38]
// 00558a96  d9400c               fld dword ptr [eax + 0xc]
// 00558a99  d95e3c               fstp dword ptr [esi + 0x3c]
// 00558a9c  d94010               fld dword ptr [eax + 0x10]
// 00558a9f  d95e40               fstp dword ptr [esi + 0x40]
// 00558aa2  d94014               fld dword ptr [eax + 0x14]
// 00558aa5  8bc6                 mov eax, esi
// 00558aa7  d95e44               fstp dword ptr [esi + 0x44]
// 00558aaa  5e                   pop esi
// 00558aab  c20800               ret 8
// library rbxgs/util\PV.cpp (function ??0PV@RBX@@QAE@ABVCoordinateFrame@G3D@@ABVVelocity@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
