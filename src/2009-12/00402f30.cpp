// from server: 100% by auto
// roc 2009-12 00402f30  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402f30
//
// 00402f30  51                   push ecx
// 00402f31  55                   push ebp
// 00402f32  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00402f36  894c2404             mov dword ptr [esp + 4], ecx
// 00402f3a  85ed                 test ebp, ebp
// 00402f3c  7508                 jne 0x402f46
// 00402f3e  8d450d               lea eax, [ebp + 0xd]
// 00402f41  5d                   pop ebp
// 00402f42  59                   pop ecx
// 00402f43  c20800               ret 8
// 00402f46  53                   push ebx
// 00402f47  8b1d18b29800         mov ebx, dword ptr [0x98b218]
// 00402f4d  56                   push esi
// 00402f4e  57                   push edi
// 00402f4f  33ff                 xor edi, edi
// 00402f51  8bf5                 mov esi, ebp
// 00402f53  56                   push esi
// 00402f54  ffd3                 call ebx
// 00402f56  40                   inc eax
// 00402f57  03f0                 add esi, eax
// 00402f59  03f8                 add edi, eax
// 00402f5b  83f801               cmp eax, 1
// 00402f5e  75f3                 jne 0x402f53
// 00402f60  8b442418             mov eax, dword ptr [esp + 0x18]
// 00402f64  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00402f68  8b11                 mov edx, dword ptr [ecx]
// 00402f6a  57                   push edi
// 00402f6b  55                   push ebp
// 00402f6c  6a07                 push 7
// 00402f6e  6a00                 push 0
// 00402f70  50                   push eax
// 00402f71  52                   push edx
// 00402f72  ff1514b09800         call dword ptr [0x98b014]
// 00402f78  5f                   pop edi
// 00402f79  5e                   pop esi
// 00402f7a  5b                   pop ebx
// 00402f7b  5d                   pop ebp
// 00402f7c  59                   pop ecx
// 00402f7d  c20800               ret 8
// library atl-9.0/atl.cpp (function ?SetMultiStringValue@CRegKey@ATL@@QAEJPBD0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
