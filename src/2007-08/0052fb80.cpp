// from server: 100% by auto
// roc 2007-08 0052fb80  unit: RBX::VRunService::?$SignalDesc  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0052fb80
//
// 0052fb80  56                   push esi
// 0052fb81  57                   push edi
// 0052fb82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0052fb86  57                   push edi
// 0052fb87  8bf1                 mov esi, ecx
// 0052fb89  e8429afdff           call 0x5095d0
// 0052fb8e  d94724               fld dword ptr [edi + 0x24]
// 0052fb91  8b442410             mov eax, dword ptr [esp + 0x10]
// 0052fb95  d95e24               fstp dword ptr [esi + 0x24]
// 0052fb98  d94728               fld dword ptr [edi + 0x28]
// 0052fb9b  d95e28               fstp dword ptr [esi + 0x28]
// 0052fb9e  d9472c               fld dword ptr [edi + 0x2c]
// 0052fba1  5f                   pop edi
// 0052fba2  d95e2c               fstp dword ptr [esi + 0x2c]
// 0052fba5  d900                 fld dword ptr [eax]
// 0052fba7  d95e30               fstp dword ptr [esi + 0x30]
// 0052fbaa  d94004               fld dword ptr [eax + 4]
// 0052fbad  d95e34               fstp dword ptr [esi + 0x34]
// 0052fbb0  d94008               fld dword ptr [eax + 8]
// 0052fbb3  d95e38               fstp dword ptr [esi + 0x38]
// 0052fbb6  d9400c               fld dword ptr [eax + 0xc]
// 0052fbb9  d95e3c               fstp dword ptr [esi + 0x3c]
// 0052fbbc  d94010               fld dword ptr [eax + 0x10]
// 0052fbbf  d95e40               fstp dword ptr [esi + 0x40]
// 0052fbc2  d94014               fld dword ptr [eax + 0x14]
// 0052fbc5  8bc6                 mov eax, esi
// 0052fbc7  d95e44               fstp dword ptr [esi + 0x44]
// 0052fbca  5e                   pop esi
// 0052fbcb  c20800               ret 8
// library rbxgs/util\PV.cpp (function ??0PV@RBX@@QAE@ABVCoordinateFrame@G3D@@ABVVelocity@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
