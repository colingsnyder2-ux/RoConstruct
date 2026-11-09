// from server: 100% by auto
// roc 2007-03 005af8d0  unit: seg_005a0000  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005af8d0
//
// 005af8d0  56                   push esi
// 005af8d1  57                   push edi
// 005af8d2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005af8d6  57                   push edi
// 005af8d7  8bf1                 mov esi, ecx
// 005af8d9  e8a2f0f4ff           call 0x4fe980
// 005af8de  d94724               fld dword ptr [edi + 0x24]
// 005af8e1  8b442410             mov eax, dword ptr [esp + 0x10]
// 005af8e5  d95e24               fstp dword ptr [esi + 0x24]
// 005af8e8  d94728               fld dword ptr [edi + 0x28]
// 005af8eb  d95e28               fstp dword ptr [esi + 0x28]
// 005af8ee  d9472c               fld dword ptr [edi + 0x2c]
// 005af8f1  5f                   pop edi
// 005af8f2  d95e2c               fstp dword ptr [esi + 0x2c]
// 005af8f5  d900                 fld dword ptr [eax]
// 005af8f7  d95e30               fstp dword ptr [esi + 0x30]
// 005af8fa  d94004               fld dword ptr [eax + 4]
// 005af8fd  d95e34               fstp dword ptr [esi + 0x34]
// 005af900  d94008               fld dword ptr [eax + 8]
// 005af903  d95e38               fstp dword ptr [esi + 0x38]
// 005af906  d9400c               fld dword ptr [eax + 0xc]
// 005af909  d95e3c               fstp dword ptr [esi + 0x3c]
// 005af90c  d94010               fld dword ptr [eax + 0x10]
// 005af90f  d95e40               fstp dword ptr [esi + 0x40]
// 005af912  d94014               fld dword ptr [eax + 0x14]
// 005af915  8bc6                 mov eax, esi
// 005af917  d95e44               fstp dword ptr [esi + 0x44]
// 005af91a  5e                   pop esi
// 005af91b  c20800               ret 8
// library rbxgs/util\PV.cpp (function ??0PV@RBX@@QAE@ABVCoordinateFrame@G3D@@ABVVelocity@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
