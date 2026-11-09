// from server: 100% by auto
// roc 2010-06 00402f80  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402f80
//
// 00402f80  51                   push ecx
// 00402f81  55                   push ebp
// 00402f82  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00402f86  894c2404             mov dword ptr [esp + 4], ecx
// 00402f8a  85ed                 test ebp, ebp
// 00402f8c  7508                 jne 0x402f96
// 00402f8e  8d450d               lea eax, [ebp + 0xd]
// 00402f91  5d                   pop ebp
// 00402f92  59                   pop ecx
// 00402f93  c20800               ret 8
// 00402f96  53                   push ebx
// 00402f97  8b1d88a39e00         mov ebx, dword ptr [0x9ea388]
// 00402f9d  56                   push esi
// 00402f9e  57                   push edi
// 00402f9f  33ff                 xor edi, edi
// 00402fa1  8bf5                 mov esi, ebp
// 00402fa3  56                   push esi
// 00402fa4  ffd3                 call ebx
// 00402fa6  40                   inc eax
// 00402fa7  03f0                 add esi, eax
// 00402fa9  03f8                 add edi, eax
// 00402fab  83f801               cmp eax, 1
// 00402fae  75f3                 jne 0x402fa3
// 00402fb0  8b442418             mov eax, dword ptr [esp + 0x18]
// 00402fb4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00402fb8  8b11                 mov edx, dword ptr [ecx]
// 00402fba  57                   push edi
// 00402fbb  55                   push ebp
// 00402fbc  6a07                 push 7
// 00402fbe  6a00                 push 0
// 00402fc0  50                   push eax
// 00402fc1  52                   push edx
// 00402fc2  ff151ca09e00         call dword ptr [0x9ea01c]
// 00402fc8  5f                   pop edi
// 00402fc9  5e                   pop esi
// 00402fca  5b                   pop ebx
// 00402fcb  5d                   pop ebp
// 00402fcc  59                   pop ecx
// 00402fcd  c20800               ret 8
// library atl-9.0/atl.cpp (function ?SetMultiStringValue@CRegKey@ATL@@QAEJPBD0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
