// from server: 100% by auto
// roc 2012-06 00425240  unit: RBX::FunctionMarshaller  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00425240
//
// 00425240  57                   push edi
// 00425241  8b7c2408             mov edi, dword ptr [esp + 8]
// 00425245  85ff                 test edi, edi
// 00425247  7506                 jne 0x42524f
// 00425249  33c0                 xor eax, eax
// 0042524b  5f                   pop edi
// 0042524c  c20400               ret 4
// 0042524f  53                   push ebx
// 00425250  55                   push ebp
// 00425251  56                   push esi
// 00425252  8d6f04               lea ebp, [edi + 4]
// 00425255  55                   push ebp
// 00425256  33db                 xor ebx, ebx
// 00425258  ff15b821b200         call dword ptr [0xb221b8]
// 0042525e  8b771c               mov esi, dword ptr [edi + 0x1c]
// 00425261  85f6                 test esi, esi
// 00425263  744d                 je 0x4252b2
// 00425265  ff15a021b200         call dword ptr [0xb221a0]
// 0042526b  33c9                 xor ecx, ecx
// 0042526d  8d4900               lea ecx, [ecx]
// 00425270  394604               cmp dword ptr [esi + 4], eax
// 00425273  7419                 je 0x42528e
// 00425275  8bce                 mov ecx, esi
// 00425277  8b7608               mov esi, dword ptr [esi + 8]
// 0042527a  85f6                 test esi, esi
// 0042527c  75f2                 jne 0x425270
// 0042527e  55                   push ebp
// 0042527f  ff15b421b200         call dword ptr [0xb221b4]
// 00425285  5e                   pop esi
// 00425286  5d                   pop ebp
// 00425287  8bc3                 mov eax, ebx
// 00425289  5b                   pop ebx
// 0042528a  5f                   pop edi
// 0042528b  c20400               ret 4
// 0042528e  85c9                 test ecx, ecx
// 00425290  7518                 jne 0x4252aa
// 00425292  8b4608               mov eax, dword ptr [esi + 8]
// 00425295  89471c               mov dword ptr [edi + 0x1c], eax
// 00425298  8b1e                 mov ebx, dword ptr [esi]
// 0042529a  55                   push ebp
// 0042529b  ff15b421b200         call dword ptr [0xb221b4]
// 004252a1  5e                   pop esi
// 004252a2  5d                   pop ebp
// 004252a3  8bc3                 mov eax, ebx
// 004252a5  5b                   pop ebx
// 004252a6  5f                   pop edi
// 004252a7  c20400               ret 4
// 004252aa  8b5608               mov edx, dword ptr [esi + 8]
// 004252ad  895108               mov dword ptr [ecx + 8], edx
// 004252b0  8b1e                 mov ebx, dword ptr [esi]
// 004252b2  55                   push ebp
// 004252b3  ff15b421b200         call dword ptr [0xb221b4]
// 004252b9  5e                   pop esi
// 004252ba  5d                   pop ebp
// 004252bb  8bc3                 mov eax, ebx
// 004252bd  5b                   pop ebx
// 004252be  5f                   pop edi
// 004252bf  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlWinModuleExtractCreateWndData@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
