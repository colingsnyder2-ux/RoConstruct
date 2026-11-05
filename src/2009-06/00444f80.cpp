// from server: 100% by auto
// roc 2009-06 00444f80  unit: G3D::_WeakPtr  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00444f80
//
// 00444f80  53                   push ebx
// 00444f81  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00444f85  85db                 test ebx, ebx
// 00444f87  750f                 jne 0x444f98
// 00444f89  53                   push ebx
// 00444f8a  53                   push ebx
// 00444f8b  6a01                 push 1
// 00444f8d  68050000c0           push 0xc0000005
// 00444f92  ff15fce18900         call dword ptr [0x89e1fc]
// 00444f98  56                   push esi
// 00444f99  8b7308               mov esi, dword ptr [ebx + 8]
// 00444f9c  85f6                 test esi, esi
// 00444f9e  741c                 je 0x444fbc
// 00444fa0  57                   push edi
// 00444fa1  8b4604               mov eax, dword ptr [esi + 4]
// 00444fa4  8b0e                 mov ecx, dword ptr [esi]
// 00444fa6  50                   push eax
// 00444fa7  ffd1                 call ecx
// 00444fa9  8b7e08               mov edi, dword ptr [esi + 8]
// 00444fac  56                   push esi
// 00444fad  e8803a2d00           call 0x718a32
// 00444fb2  83c404               add esp, 4
// 00444fb5  8bf7                 mov esi, edi
// 00444fb7  85ff                 test edi, edi
// 00444fb9  75e6                 jne 0x444fa1
// 00444fbb  5f                   pop edi
// 00444fbc  5e                   pop esi
// 00444fbd  c7430800000000       mov dword ptr [ebx + 8], 0
// 00444fc4  5b                   pop ebx
// 00444fc5  c20400               ret 4
// library atl-9.0/atl.cpp (function _AtlCallTermFunc@4)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
