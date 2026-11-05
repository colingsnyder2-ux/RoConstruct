// from server: 100% by auto
// roc 2010-06 0044d110  unit: CRobloxApp  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044d110
//
// 0044d110  57                   push edi
// 0044d111  8b7c2408             mov edi, dword ptr [esp + 8]
// 0044d115  85ff                 test edi, edi
// 0044d117  7509                 jne 0x44d122
// 0044d119  b857000780           mov eax, 0x80070057
// 0044d11e  5f                   pop edi
// 0044d11f  c20c00               ret 0xc
// 0044d122  56                   push esi
// 0044d123  8b7708               mov esi, dword ptr [edi + 8]
// 0044d126  b801000000           mov eax, 1
// 0044d12b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044d12e  732c                 jae 0x44d15c
// 0044d130  53                   push ebx
// 0044d131  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0044d135  55                   push ebp
// 0044d136  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0044d13a  8d9b00000000         lea ebx, [ebx]
// 0044d140  85c0                 test eax, eax
// 0044d142  7c16                 jl 0x44d15a
// 0044d144  8b0e                 mov ecx, dword ptr [esi]
// 0044d146  85c9                 test ecx, ecx
// 0044d148  7408                 je 0x44d152
// 0044d14a  53                   push ebx
// 0044d14b  55                   push ebp
// 0044d14c  51                   push ecx
// 0044d14d  e8aefeffff           call 0x44d000
// 0044d152  83c604               add esi, 4
// 0044d155  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044d158  72e6                 jb 0x44d140
// 0044d15a  5d                   pop ebp
// 0044d15b  5b                   pop ebx
// 0044d15c  5e                   pop esi
// 0044d15d  5f                   pop edi
// 0044d15e  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlComModuleRegisterClassObjects@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
