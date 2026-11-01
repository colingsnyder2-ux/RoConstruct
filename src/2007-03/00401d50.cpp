// from server: 100% by auto
// roc 2007-03 00401d50  unit: seg_00400000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401d50
//
// 00401d50  51                   push ecx
// 00401d51  55                   push ebp
// 00401d52  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00401d56  85ed                 test ebp, ebp
// 00401d58  894c2404             mov dword ptr [esp + 4], ecx
// 00401d5c  750a                 jne 0x401d68
// 00401d5e  6805400080           push 0x80004005
// 00401d63  e898f2ffff           call 0x401000
// 00401d68  53                   push ebx
// 00401d69  8b1db4d27700         mov ebx, dword ptr [0x77d2b4]
// 00401d6f  56                   push esi
// 00401d70  57                   push edi
// 00401d71  33ff                 xor edi, edi
// 00401d73  8bf5                 mov esi, ebp
// 00401d75  56                   push esi
// 00401d76  ffd3                 call ebx
// 00401d78  83c001               add eax, 1
// 00401d7b  03f0                 add esi, eax
// 00401d7d  03f8                 add edi, eax
// 00401d7f  83f801               cmp eax, 1
// 00401d82  75f1                 jne 0x401d75
// 00401d84  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401d88  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00401d8c  8b11                 mov edx, dword ptr [ecx]
// 00401d8e  57                   push edi
// 00401d8f  55                   push ebp
// 00401d90  6a07                 push 7
// 00401d92  6a00                 push 0
// 00401d94  50                   push eax
// 00401d95  52                   push edx
// 00401d96  ff1520d07700         call dword ptr [0x77d020]
// 00401d9c  5f                   pop edi
// 00401d9d  5e                   pop esi
// 00401d9e  5b                   pop ebx
// 00401d9f  5d                   pop ebp
// 00401da0  59                   pop ecx
// 00401da1  c20800               ret 8
// library atl-8.0/atl.cpp (function ?SetMultiStringValue@CRegKey@ATL@@QAEJPBD0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
