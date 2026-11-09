// from server: 100% by auto
// roc 2008-06 00401d40  unit: VCWorkspace::?$CComObject  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401d40
//
// 00401d40  51                   push ecx
// 00401d41  55                   push ebp
// 00401d42  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00401d46  894c2404             mov dword ptr [esp + 4], ecx
// 00401d4a  85ed                 test ebp, ebp
// 00401d4c  7508                 jne 0x401d56
// 00401d4e  8d450d               lea eax, [ebp + 0xd]
// 00401d51  5d                   pop ebp
// 00401d52  59                   pop ecx
// 00401d53  c20800               ret 8
// 00401d56  53                   push ebx
// 00401d57  8b1db8218000         mov ebx, dword ptr [0x8021b8]
// 00401d5d  56                   push esi
// 00401d5e  57                   push edi
// 00401d5f  33ff                 xor edi, edi
// 00401d61  8bf5                 mov esi, ebp
// 00401d63  56                   push esi
// 00401d64  ffd3                 call ebx
// 00401d66  40                   inc eax
// 00401d67  03f0                 add esi, eax
// 00401d69  03f8                 add edi, eax
// 00401d6b  83f801               cmp eax, 1
// 00401d6e  75f3                 jne 0x401d63
// 00401d70  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401d74  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00401d78  8b11                 mov edx, dword ptr [ecx]
// 00401d7a  57                   push edi
// 00401d7b  55                   push ebp
// 00401d7c  6a07                 push 7
// 00401d7e  6a00                 push 0
// 00401d80  50                   push eax
// 00401d81  52                   push edx
// 00401d82  ff1514208000         call dword ptr [0x802014]
// 00401d88  5f                   pop edi
// 00401d89  5e                   pop esi
// 00401d8a  5b                   pop ebx
// 00401d8b  5d                   pop ebp
// 00401d8c  59                   pop ecx
// 00401d8d  c20800               ret 8
// library atl-9.0/atl.cpp (function ?SetMultiStringValue@CRegKey@ATL@@QAEJPBD0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
