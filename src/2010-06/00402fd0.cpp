// from server: 100% by auto
// roc 2010-06 00402fd0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402fd0
//
// 00402fd0  8b442404             mov eax, dword ptr [esp + 4]
// 00402fd4  83f864               cmp eax, 0x64
// 00402fd7  56                   push esi
// 00402fd8  8bf1                 mov esi, ecx
// 00402fda  7d05                 jge 0x402fe1
// 00402fdc  b8e8030000           mov eax, 0x3e8
// 00402fe1  33c9                 xor ecx, ecx
// 00402fe3  c70600000000         mov dword ptr [esi], 0
// 00402fe9  894604               mov dword ptr [esi + 4], eax
// 00402fec  7705                 ja 0x402ff3
// 00402fee  83f8ff               cmp eax, -1
// 00402ff1  7604                 jbe 0x402ff7
// 00402ff3  33c0                 xor eax, eax
// 00402ff5  eb07                 jmp 0x402ffe
// 00402ff7  50                   push eax
// 00402ff8  ff15c4d09e00         call dword ptr [0x9ed0c4]
// 00402ffe  894608               mov dword ptr [esi + 8], eax
// 00403001  85c0                 test eax, eax
// 00403003  7403                 je 0x403008
// 00403005  c60000               mov byte ptr [eax], 0
// 00403008  8bc6                 mov eax, esi
// 0040300a  5e                   pop esi
// 0040300b  c20400               ret 4
// library atl-9.0/atl.cpp (function ??0CParseBuffer@CRegParser@ATL@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
