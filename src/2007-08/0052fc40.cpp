// from server: 100% by auto
// roc 2007-08 0052fc40  unit: RBX::VRunService::?$SignalDesc  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0052fc40
//
// 0052fc40  8b442408             mov eax, dword ptr [esp + 8]
// 0052fc44  83ec48               sub esp, 0x48
// 0052fc47  56                   push esi
// 0052fc48  8bf1                 mov esi, ecx
// 0052fc4a  50                   push eax
// 0052fc4b  8d4c2420             lea ecx, [esp + 0x20]
// 0052fc4f  51                   push ecx
// 0052fc50  8bce                 mov ecx, esi
// 0052fc52  e8a935f4ff           call 0x473200
// 0052fc57  8d542440             lea edx, [esp + 0x40]
// 0052fc5b  52                   push edx
// 0052fc5c  8d442408             lea eax, [esp + 8]
// 0052fc60  50                   push eax
// 0052fc61  8bce                 mov ecx, esi
// 0052fc63  e868ffffff           call 0x52fbd0
// 0052fc68  8b742450             mov esi, dword ptr [esp + 0x50]
// 0052fc6c  8d4c241c             lea ecx, [esp + 0x1c]
// 0052fc70  51                   push ecx
// 0052fc71  8bce                 mov ecx, esi
// 0052fc73  e85899fdff           call 0x5095d0
// 0052fc78  d9442440             fld dword ptr [esp + 0x40]
// 0052fc7c  d95e24               fstp dword ptr [esi + 0x24]
// 0052fc7f  8bc6                 mov eax, esi
// 0052fc81  d9442444             fld dword ptr [esp + 0x44]
// 0052fc85  d95e28               fstp dword ptr [esi + 0x28]
// 0052fc88  d9442448             fld dword ptr [esp + 0x48]
// 0052fc8c  d95e2c               fstp dword ptr [esi + 0x2c]
// 0052fc8f  d9442404             fld dword ptr [esp + 4]
// 0052fc93  d95e30               fstp dword ptr [esi + 0x30]
// 0052fc96  d9442408             fld dword ptr [esp + 8]
// 0052fc9a  d95e34               fstp dword ptr [esi + 0x34]
// 0052fc9d  d944240c             fld dword ptr [esp + 0xc]
// 0052fca1  d95e38               fstp dword ptr [esi + 0x38]
// 0052fca4  d9442410             fld dword ptr [esp + 0x10]
// 0052fca8  d95e3c               fstp dword ptr [esi + 0x3c]
// 0052fcab  d9442414             fld dword ptr [esp + 0x14]
// 0052fcaf  d95e40               fstp dword ptr [esi + 0x40]
// 0052fcb2  d9442418             fld dword ptr [esp + 0x18]
// 0052fcb6  d95e44               fstp dword ptr [esi + 0x44]
// 0052fcb9  5e                   pop esi
// 0052fcba  83c448               add esp, 0x48
// 0052fcbd  c20800               ret 8
// library rbxgs/util\PV.cpp (function ?pvAtLocalCoord@PV@RBX@@QBE?AV12@ABVCoordinateFrame@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
