// from server: 100% by auto
// roc 2009-06 0050c220  unit: RBX::Network::RoundRobinPhysicsSender  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0050c220
//
// 0050c220  56                   push esi
// 0050c221  57                   push edi
// 0050c222  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0050c226  57                   push edi
// 0050c227  8bf1                 mov esi, ecx
// 0050c229  e852ddf8ff           call 0x499f80
// 0050c22e  d94724               fld dword ptr [edi + 0x24]
// 0050c231  8b442410             mov eax, dword ptr [esp + 0x10]
// 0050c235  d95e24               fstp dword ptr [esi + 0x24]
// 0050c238  d94728               fld dword ptr [edi + 0x28]
// 0050c23b  d95e28               fstp dword ptr [esi + 0x28]
// 0050c23e  d9472c               fld dword ptr [edi + 0x2c]
// 0050c241  5f                   pop edi
// 0050c242  d95e2c               fstp dword ptr [esi + 0x2c]
// 0050c245  d900                 fld dword ptr [eax]
// 0050c247  d95e30               fstp dword ptr [esi + 0x30]
// 0050c24a  d94004               fld dword ptr [eax + 4]
// 0050c24d  d95e34               fstp dword ptr [esi + 0x34]
// 0050c250  d94008               fld dword ptr [eax + 8]
// 0050c253  d95e38               fstp dword ptr [esi + 0x38]
// 0050c256  d9400c               fld dword ptr [eax + 0xc]
// 0050c259  d95e3c               fstp dword ptr [esi + 0x3c]
// 0050c25c  d94010               fld dword ptr [eax + 0x10]
// 0050c25f  d95e40               fstp dword ptr [esi + 0x40]
// 0050c262  d94014               fld dword ptr [eax + 0x14]
// 0050c265  8bc6                 mov eax, esi
// 0050c267  d95e44               fstp dword ptr [esi + 0x44]
// 0050c26a  5e                   pop esi
// 0050c26b  c20800               ret 8
// library rbxgs/util\PV.cpp (function ??0PV@RBX@@QAE@ABVCoordinateFrame@G3D@@ABVVelocity@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
