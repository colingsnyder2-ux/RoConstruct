// from server: 100% by auto
// roc 2009-06 00403260  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403260
//
// 00403260  51                   push ecx
// 00403261  55                   push ebp
// 00403262  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00403266  894c2404             mov dword ptr [esp + 4], ecx
// 0040326a  85ed                 test ebp, ebp
// 0040326c  7508                 jne 0x403276
// 0040326e  8d450d               lea eax, [ebp + 0xd]
// 00403271  5d                   pop ebp
// 00403272  59                   pop ecx
// 00403273  c20800               ret 8
// 00403276  53                   push ebx
// 00403277  8b1de0e18900         mov ebx, dword ptr [0x89e1e0]
// 0040327d  56                   push esi
// 0040327e  57                   push edi
// 0040327f  33ff                 xor edi, edi
// 00403281  8bf5                 mov esi, ebp
// 00403283  56                   push esi
// 00403284  ffd3                 call ebx
// 00403286  40                   inc eax
// 00403287  03f0                 add esi, eax
// 00403289  03f8                 add edi, eax
// 0040328b  83f801               cmp eax, 1
// 0040328e  75f3                 jne 0x403283
// 00403290  8b442418             mov eax, dword ptr [esp + 0x18]
// 00403294  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403298  8b11                 mov edx, dword ptr [ecx]
// 0040329a  57                   push edi
// 0040329b  55                   push ebp
// 0040329c  6a07                 push 7
// 0040329e  6a00                 push 0
// 004032a0  50                   push eax
// 004032a1  52                   push edx
// 004032a2  ff1514e08900         call dword ptr [0x89e014]
// 004032a8  5f                   pop edi
// 004032a9  5e                   pop esi
// 004032aa  5b                   pop ebx
// 004032ab  5d                   pop ebp
// 004032ac  59                   pop ecx
// 004032ad  c20800               ret 8
// library atl-9.0/atl.cpp (function ?SetMultiStringValue@CRegKey@ATL@@QAEJPBD0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
