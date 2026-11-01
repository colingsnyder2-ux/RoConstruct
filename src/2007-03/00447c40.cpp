// from server: 100% by auto
// roc 2007-03 00447c40  unit: seg_00440000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00447c40
//
// 00447c40  53                   push ebx
// 00447c41  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00447c45  85db                 test ebx, ebx
// 00447c47  750f                 jne 0x447c58
// 00447c49  53                   push ebx
// 00447c4a  53                   push ebx
// 00447c4b  6a01                 push 1
// 00447c4d  68050000c0           push 0xc0000005
// 00447c52  ff15ccd27700         call dword ptr [0x77d2cc]
// 00447c58  56                   push esi
// 00447c59  8b7308               mov esi, dword ptr [ebx + 8]
// 00447c5c  85f6                 test esi, esi
// 00447c5e  741c                 je 0x447c7c
// 00447c60  57                   push edi
// 00447c61  8b4604               mov eax, dword ptr [esi + 4]
// 00447c64  8b0e                 mov ecx, dword ptr [esi]
// 00447c66  50                   push eax
// 00447c67  ffd1                 call ecx
// 00447c69  8b7e08               mov edi, dword ptr [esi + 8]
// 00447c6c  56                   push esi
// 00447c6d  e87e641d00           call 0x61e0f0
// 00447c72  83c404               add esp, 4
// 00447c75  85ff                 test edi, edi
// 00447c77  8bf7                 mov esi, edi
// 00447c79  75e6                 jne 0x447c61
// 00447c7b  5f                   pop edi
// 00447c7c  5e                   pop esi
// 00447c7d  c7430800000000       mov dword ptr [ebx + 8], 0
// 00447c84  5b                   pop ebx
// 00447c85  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlCallTermFunc@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
