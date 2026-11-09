// from server: 100% by auto
// roc 2009-06 006c95c0  unit: seg_006c0000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c95c0
//
// 006c95c0  83ec30               sub esp, 0x30
// 006c95c3  56                   push esi
// 006c95c4  57                   push edi
// 006c95c5  8bf1                 mov esi, ecx
// 006c95c7  e8c4f1eaff           call 0x578790
// 006c95cc  50                   push eax
// 006c95cd  8d4c240c             lea ecx, [esp + 0xc]
// 006c95d1  e8aa09ddff           call 0x499f80
// 006c95d6  8b442440             mov eax, dword ptr [esp + 0x40]
// 006c95da  d900                 fld dword ptr [eax]
// 006c95dc  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 006c95e0  d95c242c             fstp dword ptr [esp + 0x2c]
// 006c95e4  8bce                 mov ecx, esi
// 006c95e6  d94004               fld dword ptr [eax + 4]
// 006c95e9  d95c2430             fstp dword ptr [esp + 0x30]
// 006c95ed  d94008               fld dword ptr [eax + 8]
// 006c95f0  8d442408             lea eax, [esp + 8]
// 006c95f4  50                   push eax
// 006c95f5  d95c2438             fstp dword ptr [esp + 0x38]
// 006c95f9  57                   push edi
// 006c95fa  e871fdffff           call 0x6c9370
// 006c95ff  8bc7                 mov eax, edi
// 006c9601  5f                   pop edi
// 006c9602  5e                   pop esi
// 006c9603  83c430               add esp, 0x30
// 006c9606  c20800               ret 8
// library rbxgs/util\PV.cpp (function ?pvAtLocalOffset@PV@RBX@@QBE?AV12@ABVVector3@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
