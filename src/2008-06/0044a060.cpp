// from server: 100% by auto
// roc 2008-06 0044a060  unit: CIDEDocManager  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044a060
//
// 0044a060  53                   push ebx
// 0044a061  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0044a065  85db                 test ebx, ebx
// 0044a067  750f                 jne 0x44a078
// 0044a069  53                   push ebx
// 0044a06a  53                   push ebx
// 0044a06b  6a01                 push 1
// 0044a06d  68050000c0           push 0xc0000005
// 0044a072  ff15e4228000         call dword ptr [0x8022e4]
// 0044a078  56                   push esi
// 0044a079  8b7308               mov esi, dword ptr [ebx + 8]
// 0044a07c  85f6                 test esi, esi
// 0044a07e  741c                 je 0x44a09c
// 0044a080  57                   push edi
// 0044a081  8b4604               mov eax, dword ptr [esi + 4]
// 0044a084  8b0e                 mov ecx, dword ptr [esi]
// 0044a086  50                   push eax
// 0044a087  ffd1                 call ecx
// 0044a089  8b7e08               mov edi, dword ptr [esi + 8]
// 0044a08c  56                   push esi
// 0044a08d  e8e8652500           call 0x6a067a
// 0044a092  83c404               add esp, 4
// 0044a095  8bf7                 mov esi, edi
// 0044a097  85ff                 test edi, edi
// 0044a099  75e6                 jne 0x44a081
// 0044a09b  5f                   pop edi
// 0044a09c  5e                   pop esi
// 0044a09d  c7430800000000       mov dword ptr [ebx + 8], 0
// 0044a0a4  5b                   pop ebx
// 0044a0a5  c20400               ret 4
// library atl-9.0/atl.cpp (function _AtlCallTermFunc@4)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
