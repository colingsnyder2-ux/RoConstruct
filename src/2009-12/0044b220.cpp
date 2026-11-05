// from server: 100% by auto
// roc 2009-12 0044b220  unit: CRobloxControlColorSelector  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044b220
//
// 0044b220  53                   push ebx
// 0044b221  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0044b225  85db                 test ebx, ebx
// 0044b227  750f                 jne 0x44b238
// 0044b229  53                   push ebx
// 0044b22a  53                   push ebx
// 0044b22b  6a01                 push 1
// 0044b22d  68050000c0           push 0xc0000005
// 0044b232  ff1534b29800         call dword ptr [0x98b234]
// 0044b238  56                   push esi
// 0044b239  8b7308               mov esi, dword ptr [ebx + 8]
// 0044b23c  85f6                 test esi, esi
// 0044b23e  741c                 je 0x44b25c
// 0044b240  57                   push edi
// 0044b241  8b4604               mov eax, dword ptr [esi + 4]
// 0044b244  8b0e                 mov ecx, dword ptr [esi]
// 0044b246  50                   push eax
// 0044b247  ffd1                 call ecx
// 0044b249  8b7e08               mov edi, dword ptr [esi + 8]
// 0044b24c  56                   push esi
// 0044b24d  e808863a00           call 0x7f385a
// 0044b252  83c404               add esp, 4
// 0044b255  8bf7                 mov esi, edi
// 0044b257  85ff                 test edi, edi
// 0044b259  75e6                 jne 0x44b241
// 0044b25b  5f                   pop edi
// 0044b25c  5e                   pop esi
// 0044b25d  c7430800000000       mov dword ptr [ebx + 8], 0
// 0044b264  5b                   pop ebx
// 0044b265  c20400               ret 4
// library atl-9.0/atl.cpp (function _AtlCallTermFunc@4)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
