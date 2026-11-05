// from server: 100% by auto
// roc 2012-06 00404510  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404510
//
// 00404510  8b442404             mov eax, dword ptr [esp + 4]
// 00404514  83f864               cmp eax, 0x64
// 00404517  56                   push esi
// 00404518  8bf1                 mov esi, ecx
// 0040451a  7d05                 jge 0x404521
// 0040451c  b8e8030000           mov eax, 0x3e8
// 00404521  33c9                 xor ecx, ecx
// 00404523  c70600000000         mov dword ptr [esi], 0
// 00404529  894604               mov dword ptr [esi + 4], eax
// 0040452c  7705                 ja 0x404533
// 0040452e  83f8ff               cmp eax, -1
// 00404531  7604                 jbe 0x404537
// 00404533  33c0                 xor eax, eax
// 00404535  eb07                 jmp 0x40453e
// 00404537  50                   push eax
// 00404538  ff150851b200         call dword ptr [0xb25108]
// 0040453e  894608               mov dword ptr [esi + 8], eax
// 00404541  85c0                 test eax, eax
// 00404543  7403                 je 0x404548
// 00404545  c60000               mov byte ptr [eax], 0
// 00404548  8bc6                 mov eax, esi
// 0040454a  5e                   pop esi
// 0040454b  c20400               ret 4
// library atl-9.0/atl.cpp (function ??0CParseBuffer@CRegParser@ATL@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
