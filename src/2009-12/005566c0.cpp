// from server: 100% by auto
// roc 2009-12 005566c0  unit: RBX::Network::ClientReplicator  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005566c0
//
// 005566c0  6aff                 push -1
// 005566c2  6858ae9300           push 0x93ae58
// 005566c7  64a100000000         mov eax, dword ptr fs:[0]
// 005566cd  50                   push eax
// 005566ce  64892500000000       mov dword ptr fs:[0], esp
// 005566d5  51                   push ecx
// 005566d6  56                   push esi
// 005566d7  8bf1                 mov esi, ecx
// 005566d9  57                   push edi
// 005566da  89742408             mov dword ptr [esp + 8], esi
// 005566de  837e0800             cmp dword ptr [esi + 8], 0
// 005566e2  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005566ea  7437                 je 0x556723
// 005566ec  8b06                 mov eax, dword ptr [esi]
// 005566ee  85c0                 test eax, eax
// 005566f0  741d                 je 0x55670f
// 005566f2  8b48fc               mov ecx, dword ptr [eax - 4]
// 005566f5  8d78fc               lea edi, [eax - 4]
// 005566f8  68904a8500           push 0x854a90
// 005566fd  51                   push ecx
// 005566fe  6a08                 push 8
// 00556700  50                   push eax
// 00556701  e89ee22900           call 0x7f49a4
// 00556706  57                   push edi
// 00556707  e8fad32900           call 0x7f3b06
// 0055670c  83c404               add esp, 4
// 0055670f  c7460800000000       mov dword ptr [esi + 8], 0
// 00556716  c70600000000         mov dword ptr [esi], 0
// 0055671c  c7460400000000       mov dword ptr [esi + 4], 0
// 00556723  837e0800             cmp dword ptr [esi + 8], 0
// 00556727  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0055672f  7623                 jbe 0x556754
// 00556731  8b36                 mov esi, dword ptr [esi]
// 00556733  85f6                 test esi, esi
// 00556735  741d                 je 0x556754
// 00556737  8b56fc               mov edx, dword ptr [esi - 4]
// 0055673a  68904a8500           push 0x854a90
// 0055673f  8d7efc               lea edi, [esi - 4]
// 00556742  52                   push edx
// 00556743  6a08                 push 8
// 00556745  56                   push esi
// 00556746  e859e22900           call 0x7f49a4
// 0055674b  57                   push edi
// 0055674c  e8b5d32900           call 0x7f3b06
// 00556751  83c404               add esp, 4
// 00556754  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00556758  5f                   pop edi
// 00556759  5e                   pop esi
// 0055675a  64890d00000000       mov dword ptr fs:[0], ecx
// 00556761  83c410               add esp, 0x10
// 00556764  c3                   ret 
// library raknet-4.081/CloudServer.cpp (function ??1?$OrderedList@UCloudKey@RakNet@@U12@$1?CloudKeyComp@2@YAHABU12@0@Z@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudServer.cpp
