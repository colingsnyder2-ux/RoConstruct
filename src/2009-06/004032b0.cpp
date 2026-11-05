// from server: 100% by auto
// roc 2009-06 004032b0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004032b0
//
// 004032b0  8b442404             mov eax, dword ptr [esp + 4]
// 004032b4  83f864               cmp eax, 0x64
// 004032b7  56                   push esi
// 004032b8  8bf1                 mov esi, ecx
// 004032ba  7d05                 jge 0x4032c1
// 004032bc  b8e8030000           mov eax, 0x3e8
// 004032c1  33c9                 xor ecx, ecx
// 004032c3  c70600000000         mov dword ptr [esi], 0
// 004032c9  894604               mov dword ptr [esi + 4], eax
// 004032cc  7705                 ja 0x4032d3
// 004032ce  83f8ff               cmp eax, -1
// 004032d1  7604                 jbe 0x4032d7
// 004032d3  33c0                 xor eax, eax
// 004032d5  eb07                 jmp 0x4032de
// 004032d7  50                   push eax
// 004032d8  ff150c038a00         call dword ptr [0x8a030c]
// 004032de  894608               mov dword ptr [esi + 8], eax
// 004032e1  85c0                 test eax, eax
// 004032e3  7403                 je 0x4032e8
// 004032e5  c60000               mov byte ptr [eax], 0
// 004032e8  8bc6                 mov eax, esi
// 004032ea  5e                   pop esi
// 004032eb  c20400               ret 4
// library atl-9.0/atl.cpp (function ??0CParseBuffer@CRegParser@ATL@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
