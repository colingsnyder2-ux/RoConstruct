// from server: 100% by auto
// roc 2009-12 00402f80  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402f80
//
// 00402f80  8b442404             mov eax, dword ptr [esp + 4]
// 00402f84  83f864               cmp eax, 0x64
// 00402f87  56                   push esi
// 00402f88  8bf1                 mov esi, ecx
// 00402f8a  7d05                 jge 0x402f91
// 00402f8c  b8e8030000           mov eax, 0x3e8
// 00402f91  33c9                 xor ecx, ecx
// 00402f93  c70600000000         mov dword ptr [esi], 0
// 00402f99  894604               mov dword ptr [esi + 4], eax
// 00402f9c  7705                 ja 0x402fa3
// 00402f9e  83f8ff               cmp eax, -1
// 00402fa1  7604                 jbe 0x402fa7
// 00402fa3  33c0                 xor eax, eax
// 00402fa5  eb07                 jmp 0x402fae
// 00402fa7  50                   push eax
// 00402fa8  ff1598e09800         call dword ptr [0x98e098]
// 00402fae  894608               mov dword ptr [esi + 8], eax
// 00402fb1  85c0                 test eax, eax
// 00402fb3  7403                 je 0x402fb8
// 00402fb5  c60000               mov byte ptr [eax], 0
// 00402fb8  8bc6                 mov eax, esi
// 00402fba  5e                   pop esi
// 00402fbb  c20400               ret 4
// library atl-9.0/atl.cpp (function ??0CParseBuffer@CRegParser@ATL@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
