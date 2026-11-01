// from server: 100% by auto
// roc 2011-06 00458a70  unit: CRobloxControlColorSelector  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00458a70
//
// 00458a70  57                   push edi
// 00458a71  8b7c2408             mov edi, dword ptr [esp + 8]
// 00458a75  85ff                 test edi, edi
// 00458a77  7509                 jne 0x458a82
// 00458a79  b857000780           mov eax, 0x80070057
// 00458a7e  5f                   pop edi
// 00458a7f  c20c00               ret 0xc
// 00458a82  56                   push esi
// 00458a83  8b7708               mov esi, dword ptr [edi + 8]
// 00458a86  b801000000           mov eax, 1
// 00458a8b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00458a8e  732c                 jae 0x458abc
// 00458a90  53                   push ebx
// 00458a91  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00458a95  55                   push ebp
// 00458a96  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00458a9a  8d9b00000000         lea ebx, [ebx]
// 00458aa0  85c0                 test eax, eax
// 00458aa2  7c16                 jl 0x458aba
// 00458aa4  8b0e                 mov ecx, dword ptr [esi]
// 00458aa6  85c9                 test ecx, ecx
// 00458aa8  7408                 je 0x458ab2
// 00458aaa  53                   push ebx
// 00458aab  55                   push ebp
// 00458aac  51                   push ecx
// 00458aad  e89efeffff           call 0x458950
// 00458ab2  83c604               add esi, 4
// 00458ab5  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00458ab8  72e6                 jb 0x458aa0
// 00458aba  5d                   pop ebp
// 00458abb  5b                   pop ebx
// 00458abc  5e                   pop esi
// 00458abd  5f                   pop edi
// 00458abe  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlComModuleRegisterClassObjects@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
