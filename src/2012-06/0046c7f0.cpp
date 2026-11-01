// from server: 100% by auto
// roc 2012-06 0046c7f0  unit: RBX::TeleportCallback  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046c7f0
//
// 0046c7f0  57                   push edi
// 0046c7f1  8b7c2408             mov edi, dword ptr [esp + 8]
// 0046c7f5  85ff                 test edi, edi
// 0046c7f7  7509                 jne 0x46c802
// 0046c7f9  b857000780           mov eax, 0x80070057
// 0046c7fe  5f                   pop edi
// 0046c7ff  c20c00               ret 0xc
// 0046c802  56                   push esi
// 0046c803  8b7708               mov esi, dword ptr [edi + 8]
// 0046c806  b801000000           mov eax, 1
// 0046c80b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0046c80e  732c                 jae 0x46c83c
// 0046c810  53                   push ebx
// 0046c811  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0046c815  55                   push ebp
// 0046c816  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0046c81a  8d9b00000000         lea ebx, [ebx]
// 0046c820  85c0                 test eax, eax
// 0046c822  7c16                 jl 0x46c83a
// 0046c824  8b0e                 mov ecx, dword ptr [esi]
// 0046c826  85c9                 test ecx, ecx
// 0046c828  7408                 je 0x46c832
// 0046c82a  53                   push ebx
// 0046c82b  55                   push ebp
// 0046c82c  51                   push ecx
// 0046c82d  e86efeffff           call 0x46c6a0
// 0046c832  83c604               add esi, 4
// 0046c835  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0046c838  72e6                 jb 0x46c820
// 0046c83a  5d                   pop ebp
// 0046c83b  5b                   pop ebx
// 0046c83c  5e                   pop esi
// 0046c83d  5f                   pop edi
// 0046c83e  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlComModuleRegisterClassObjects@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
