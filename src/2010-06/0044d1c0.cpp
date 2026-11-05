// from server: 100% by auto
// roc 2010-06 0044d1c0  unit: CRobloxApp  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044d1c0
//
// 0044d1c0  53                   push ebx
// 0044d1c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0044d1c5  85db                 test ebx, ebx
// 0044d1c7  750f                 jne 0x44d1d8
// 0044d1c9  53                   push ebx
// 0044d1ca  53                   push ebx
// 0044d1cb  6a01                 push 1
// 0044d1cd  68050000c0           push 0xc0000005
// 0044d1d2  ff15a4a39e00         call dword ptr [0x9ea3a4]
// 0044d1d8  56                   push esi
// 0044d1d9  8b7308               mov esi, dword ptr [ebx + 8]
// 0044d1dc  85f6                 test esi, esi
// 0044d1de  741c                 je 0x44d1fc
// 0044d1e0  57                   push edi
// 0044d1e1  8b4604               mov eax, dword ptr [esi + 4]
// 0044d1e4  8b0e                 mov ecx, dword ptr [esi]
// 0044d1e6  50                   push eax
// 0044d1e7  ffd1                 call ecx
// 0044d1e9  8b7e08               mov edi, dword ptr [esi + 8]
// 0044d1ec  56                   push esi
// 0044d1ed  e8a8a73500           call 0x7a799a
// 0044d1f2  83c404               add esp, 4
// 0044d1f5  8bf7                 mov esi, edi
// 0044d1f7  85ff                 test edi, edi
// 0044d1f9  75e6                 jne 0x44d1e1
// 0044d1fb  5f                   pop edi
// 0044d1fc  5e                   pop esi
// 0044d1fd  c7430800000000       mov dword ptr [ebx + 8], 0
// 0044d204  5b                   pop ebx
// 0044d205  c20400               ret 4
// library atl-9.0/atl.cpp (function _AtlCallTermFunc@4)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
