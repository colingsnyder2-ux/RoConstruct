// from server: 100% by auto
// roc 2007-08 0061a2b0  unit: RBX::ContactConnector  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061a2b0
//
// 0061a2b0  83ec30               sub esp, 0x30
// 0061a2b3  56                   push esi
// 0061a2b4  57                   push edi
// 0061a2b5  8bf1                 mov esi, ecx
// 0061a2b7  e84402efff           call 0x50a500
// 0061a2bc  50                   push eax
// 0061a2bd  8d4c240c             lea ecx, [esp + 0xc]
// 0061a2c1  e80af3eeff           call 0x5095d0
// 0061a2c6  8b442440             mov eax, dword ptr [esp + 0x40]
// 0061a2ca  d900                 fld dword ptr [eax]
// 0061a2cc  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 0061a2d0  d95c242c             fstp dword ptr [esp + 0x2c]
// 0061a2d4  8bce                 mov ecx, esi
// 0061a2d6  d94004               fld dword ptr [eax + 4]
// 0061a2d9  d95c2430             fstp dword ptr [esp + 0x30]
// 0061a2dd  d94008               fld dword ptr [eax + 8]
// 0061a2e0  8d442408             lea eax, [esp + 8]
// 0061a2e4  50                   push eax
// 0061a2e5  d95c2438             fstp dword ptr [esp + 0x38]
// 0061a2e9  57                   push edi
// 0061a2ea  e85159f1ff           call 0x52fc40
// 0061a2ef  8bc7                 mov eax, edi
// 0061a2f1  5f                   pop edi
// 0061a2f2  5e                   pop esi
// 0061a2f3  83c430               add esp, 0x30
// 0061a2f6  c20800               ret 8
// library rbxgs/util\PV.cpp (function ?pvAtLocalOffset@PV@RBX@@QBE?AV12@ABVVector3@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
