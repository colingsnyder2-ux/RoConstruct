// from server: 100% by auto
// roc 2011-06 00458b20  unit: CRobloxControlColorSelector  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00458b20
//
// 00458b20  53                   push ebx
// 00458b21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00458b25  85db                 test ebx, ebx
// 00458b27  750f                 jne 0x458b38
// 00458b29  53                   push ebx
// 00458b2a  53                   push ebx
// 00458b2b  6a01                 push 1
// 00458b2d  68050000c0           push 0xc0000005
// 00458b32  ff15ac03a400         call dword ptr [0xa403ac]
// 00458b38  56                   push esi
// 00458b39  8b7308               mov esi, dword ptr [ebx + 8]
// 00458b3c  85f6                 test esi, esi
// 00458b3e  741c                 je 0x458b5c
// 00458b40  57                   push edi
// 00458b41  8b4604               mov eax, dword ptr [esi + 4]
// 00458b44  8b0e                 mov ecx, dword ptr [esi]
// 00458b46  50                   push eax
// 00458b47  ffd1                 call ecx
// 00458b49  8b7e08               mov edi, dword ptr [esi + 8]
// 00458b4c  56                   push esi
// 00458b4d  e806153b00           call 0x80a058
// 00458b52  83c404               add esp, 4
// 00458b55  8bf7                 mov esi, edi
// 00458b57  85ff                 test edi, edi
// 00458b59  75e6                 jne 0x458b41
// 00458b5b  5f                   pop edi
// 00458b5c  5e                   pop esi
// 00458b5d  c7430800000000       mov dword ptr [ebx + 8], 0
// 00458b64  5b                   pop ebx
// 00458b65  c20400               ret 4
// library atl-9.0/atl.cpp (function _AtlCallTermFunc@4)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
