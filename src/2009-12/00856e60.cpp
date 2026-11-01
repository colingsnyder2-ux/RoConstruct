// from server: 100% by auto
// roc 2009-12 00856e60  unit: CXTPTabClientWnd::CWorkspace  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00856e60
//
// 00856e60  53                   push ebx
// 00856e61  56                   push esi
// 00856e62  57                   push edi
// 00856e63  8bf9                 mov edi, ecx
// 00856e65  8b475c               mov eax, dword ptr [edi + 0x5c]
// 00856e68  33f6                 xor esi, esi
// 00856e6a  85c0                 test eax, eax
// 00856e6c  7e2c                 jle 0x856e9a
// 00856e6e  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00856e72  85f6                 test esi, esi
// 00856e74  7c11                 jl 0x856e87
// 00856e76  3bf0                 cmp esi, eax
// 00856e78  7d0d                 jge 0x856e87
// 00856e7a  3b775c               cmp esi, dword ptr [edi + 0x5c]
// 00856e7d  7d23                 jge 0x856ea2
// 00856e7f  8b4758               mov eax, dword ptr [edi + 0x58]
// 00856e82  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 00856e85  eb02                 jmp 0x856e89
// 00856e87  33c9                 xor ecx, ecx
// 00856e89  e8f295eeff           call 0x740480
// 00856e8e  3bc3                 cmp eax, ebx
// 00856e90  7415                 je 0x856ea7
// 00856e92  8b475c               mov eax, dword ptr [edi + 0x5c]
// 00856e95  46                   inc esi
// 00856e96  3bf0                 cmp esi, eax
// 00856e98  7cd8                 jl 0x856e72
// 00856e9a  5f                   pop edi
// 00856e9b  5e                   pop esi
// 00856e9c  33c0                 xor eax, eax
// 00856e9e  5b                   pop ebx
// 00856e9f  c20400               ret 4
// 00856ea2  e865ccf9ff           call 0x7f3b0c
// 00856ea7  85f6                 test esi, esi
// 00856ea9  7cef                 jl 0x856e9a
// 00856eab  3b775c               cmp esi, dword ptr [edi + 0x5c]
// 00856eae  7dea                 jge 0x856e9a
// 00856eb0  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 00856eb3  8b04b1               mov eax, dword ptr [ecx + esi*4]
// 00856eb6  5f                   pop edi
// 00856eb7  5e                   pop esi
// 00856eb8  5b                   pop ebx
// 00856eb9  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?FindItem@CWorkspace@CXTPTabClientWnd@@IBEPAVCXTPTabManagerItem@@QAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
