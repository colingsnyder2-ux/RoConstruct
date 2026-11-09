// from server: 100% by auto
// roc 2007-03 005f7a20  unit: seg_005f0000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f7a20
//
// 005f7a20  83ec30               sub esp, 0x30
// 005f7a23  56                   push esi
// 005f7a24  57                   push edi
// 005f7a25  8bf1                 mov esi, ecx
// 005f7a27  e8e481f0ff           call 0x4ffc10
// 005f7a2c  50                   push eax
// 005f7a2d  8d4c240c             lea ecx, [esp + 0xc]
// 005f7a31  e84a6ff0ff           call 0x4fe980
// 005f7a36  8b442440             mov eax, dword ptr [esp + 0x40]
// 005f7a3a  d900                 fld dword ptr [eax]
// 005f7a3c  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 005f7a40  d95c242c             fstp dword ptr [esp + 0x2c]
// 005f7a44  8bce                 mov ecx, esi
// 005f7a46  d94004               fld dword ptr [eax + 4]
// 005f7a49  d95c2430             fstp dword ptr [esp + 0x30]
// 005f7a4d  d94008               fld dword ptr [eax + 8]
// 005f7a50  8d442408             lea eax, [esp + 8]
// 005f7a54  50                   push eax
// 005f7a55  d95c2438             fstp dword ptr [esp + 0x38]
// 005f7a59  57                   push edi
// 005f7a5a  e8317ffbff           call 0x5af990
// 005f7a5f  8bc7                 mov eax, edi
// 005f7a61  5f                   pop edi
// 005f7a62  5e                   pop esi
// 005f7a63  83c430               add esp, 0x30
// 005f7a66  c20800               ret 8
// library rbxgs/util\PV.cpp (function ?pvAtLocalOffset@PV@RBX@@QBE?AV12@ABVVector3@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
