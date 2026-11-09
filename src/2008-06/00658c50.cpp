// from server: 100% by auto
// roc 2008-06 00658c50  unit: RBX::ArrowButton  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00658c50
//
// 00658c50  83ec30               sub esp, 0x30
// 00658c53  56                   push esi
// 00658c54  57                   push edi
// 00658c55  8bf1                 mov esi, ecx
// 00658c57  e8c4b1ebff           call 0x513e20
// 00658c5c  50                   push eax
// 00658c5d  8d4c240c             lea ecx, [esp + 0xc]
// 00658c61  e8baa5ebff           call 0x513220
// 00658c66  8b442440             mov eax, dword ptr [esp + 0x40]
// 00658c6a  d900                 fld dword ptr [eax]
// 00658c6c  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 00658c70  d95c242c             fstp dword ptr [esp + 0x2c]
// 00658c74  8bce                 mov ecx, esi
// 00658c76  d94004               fld dword ptr [eax + 4]
// 00658c79  d95c2430             fstp dword ptr [esp + 0x30]
// 00658c7d  d94008               fld dword ptr [eax + 8]
// 00658c80  8d442408             lea eax, [esp + 8]
// 00658c84  50                   push eax
// 00658c85  d95c2438             fstp dword ptr [esp + 0x38]
// 00658c89  57                   push edi
// 00658c8a  e871fdffff           call 0x658a00
// 00658c8f  8bc7                 mov eax, edi
// 00658c91  5f                   pop edi
// 00658c92  5e                   pop esi
// 00658c93  83c430               add esp, 0x30
// 00658c96  c20800               ret 8
// library rbxgs/util\PV.cpp (function ?pvAtLocalOffset@PV@RBX@@QBE?AV12@ABVVector3@G3D@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs util/PV.cpp
