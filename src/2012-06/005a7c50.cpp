// roc 2012-06 005a7c50  unit: RBX::Image  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a7c50
//
// 005a7c50  53                   push ebx
// 005a7c51  57                   push edi
// 005a7c52  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005a7c56  8bd9                 mov ebx, ecx
// 005a7c58  85ff                 test edi, edi
// 005a7c5a  7435                 je 0x5a7c91
// 005a7c5c  803f00               cmp byte ptr [edi], 0
// 005a7c5f  7430                 je 0x5a7c91
// 005a7c61  8bc7                 mov eax, edi
// 005a7c63  8d5001               lea edx, [eax + 1]
// 005a7c66  8a08                 mov cl, byte ptr [eax]
// 005a7c68  40                   inc eax
// 005a7c69  84c9                 test cl, cl
// 005a7c6b  75f9                 jne 0x5a7c66
// 005a7c6d  56                   push esi
// 005a7c6e  2bc2                 sub eax, edx
// 005a7c70  8d7001               lea esi, [eax + 1]
// 005a7c73  56                   push esi
// 005a7c74  8bcb                 mov ecx, ebx
// 005a7c76  e855feffff           call 0x5a7ad0
// 005a7c7b  8b03                 mov eax, dword ptr [ebx]
// 005a7c7d  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005a7c80  56                   push esi
// 005a7c81  57                   push edi
// 005a7c82  51                   push ecx
// 005a7c83  e8d4b93d00           call 0x98365c
// 005a7c88  83c40c               add esp, 0xc
// 005a7c8b  5e                   pop esi
// 005a7c8c  5f                   pop edi
// 005a7c8d  5b                   pop ebx
// 005a7c8e  c20400               ret 4
// 005a7c91  5f                   pop edi
// 005a7c92  c703b804d900         mov dword ptr [ebx], 0xd904b8
// 005a7c98  5b                   pop ebx
// 005a7c99  c20400               ret 4
// copied from an identical function in another client (function ?Assign@RakString@RakNet@@IAEXPBD@Z)

// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakString.cpp