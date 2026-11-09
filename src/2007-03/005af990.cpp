// from server: 100% by auto
// roc 2007-03 005af990  unit: seg_005a0000  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005af990
//
// 005af990  8b442408             mov eax, dword ptr [esp + 8]
// 005af994  83ec48               sub esp, 0x48
// 005af997  56                   push esi
// 005af998  8bf1                 mov esi, ecx
// 005af99a  50                   push eax
// 005af99b  8d4c2420             lea ecx, [esp + 0x20]
// 005af99f  51                   push ecx
// 005af9a0  8bce                 mov ecx, esi
// 005af9a2  e84939ecff           call 0x4732f0
// 005af9a7  8d542440             lea edx, [esp + 0x40]
// 005af9ab  52                   push edx
// 005af9ac  8d442408             lea eax, [esp + 8]
// 005af9b0  50                   push eax
// 005af9b1  8bce                 mov ecx, esi
// 005af9b3  e868ffffff           call 0x5af920
// 005af9b8  8b742450             mov esi, dword ptr [esp + 0x50]
// 005af9bc  8d4c241c             lea ecx, [esp + 0x1c]
// 005af9c0  51                   push ecx
// 005af9c1  8bce                 mov ecx, esi
// 005af9c3  e8b8eff4ff           call 0x4fe980
// 005af9c8  d9442440             fld dword ptr [esp + 0x40]
// 005af9cc  d95e24               fstp dword ptr [esi + 0x24]
// 005af9cf  8bc6                 mov eax, esi
// 005af9d1  d9442444             fld dword ptr [esp + 0x44]
// 005af9d5  d95e28               fstp dword ptr [esi + 0x28]
// 005af9d8  d9442448             fld dword ptr [esp + 0x48]
// 005af9dc  d95e2c               fstp dword ptr [esi + 0x2c]
// 005af9df  d9442404             fld dword ptr [esp + 4]
// 005af9e3  d95e30               fstp dword ptr [esi + 0x30]
// 005af9e6  d9442408             fld dword ptr [esp + 8]
// 005af9ea  d95e34               fstp dword ptr [esi + 0x34]
// 005af9ed  d944240c             fld dword ptr [esp + 0xc]
// 005af9f1  d95e38               fstp dword ptr [esi + 0x38]
// 005af9f4  d9442410             fld dword ptr [esp + 0x10]
// 005af9f8  d95e3c               fstp dword ptr [esi + 0x3c]
// 005af9fb  d9442414             fld dword ptr [esp + 0x14]
// 005af9ff  d95e40               fstp dword ptr [esi + 0x40]
// 005afa02  d9442418             fld dword ptr [esp + 0x18]
// 005afa06  d95e44               fstp dword ptr [esi + 0x44]
// 005afa09  5e                   pop esi
// 005afa0a  83c448               add esp, 0x48
// 005afa0d  c20800               ret 8
// library rbxgs/util\PV.cpp (function ?pvAtLocalCoord@PV@RBX@@QBE?AV12@ABVCoordinateFrame@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
