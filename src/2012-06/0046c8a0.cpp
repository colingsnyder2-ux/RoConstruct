// from server: 100% by auto
// roc 2012-06 0046c8a0  unit: RBX::TeleportCallback  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046c8a0
//
// 0046c8a0  53                   push ebx
// 0046c8a1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0046c8a5  85db                 test ebx, ebx
// 0046c8a7  750f                 jne 0x46c8b8
// 0046c8a9  53                   push ebx
// 0046c8aa  53                   push ebx
// 0046c8ab  6a01                 push 1
// 0046c8ad  68050000c0           push 0xc0000005
// 0046c8b2  ff15c021b200         call dword ptr [0xb221c0]
// 0046c8b8  56                   push esi
// 0046c8b9  8b7308               mov esi, dword ptr [ebx + 8]
// 0046c8bc  85f6                 test esi, esi
// 0046c8be  741c                 je 0x46c8dc
// 0046c8c0  57                   push edi
// 0046c8c1  8b4604               mov eax, dword ptr [esi + 4]
// 0046c8c4  8b0e                 mov ecx, dword ptr [esi]
// 0046c8c6  50                   push eax
// 0046c8c7  ffd1                 call ecx
// 0046c8c9  8b7e08               mov edi, dword ptr [esi + 8]
// 0046c8cc  56                   push esi
// 0046c8cd  e842585100           call 0x982114
// 0046c8d2  83c404               add esp, 4
// 0046c8d5  8bf7                 mov esi, edi
// 0046c8d7  85ff                 test edi, edi
// 0046c8d9  75e6                 jne 0x46c8c1
// 0046c8db  5f                   pop edi
// 0046c8dc  5e                   pop esi
// 0046c8dd  c7430800000000       mov dword ptr [ebx + 8], 0
// 0046c8e4  5b                   pop ebx
// 0046c8e5  c20400               ret 4
// library atl-9.0/atl.cpp (function _AtlCallTermFunc@4)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
