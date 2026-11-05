// from server: 100% by auto
// roc 2009-12 0044b170  unit: CRobloxControlColorSelector  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044b170
//
// 0044b170  57                   push edi
// 0044b171  8b7c2408             mov edi, dword ptr [esp + 8]
// 0044b175  85ff                 test edi, edi
// 0044b177  7509                 jne 0x44b182
// 0044b179  b857000780           mov eax, 0x80070057
// 0044b17e  5f                   pop edi
// 0044b17f  c20c00               ret 0xc
// 0044b182  56                   push esi
// 0044b183  8b7708               mov esi, dword ptr [edi + 8]
// 0044b186  b801000000           mov eax, 1
// 0044b18b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044b18e  732c                 jae 0x44b1bc
// 0044b190  53                   push ebx
// 0044b191  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0044b195  55                   push ebp
// 0044b196  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0044b19a  8d9b00000000         lea ebx, [ebx]
// 0044b1a0  85c0                 test eax, eax
// 0044b1a2  7c16                 jl 0x44b1ba
// 0044b1a4  8b0e                 mov ecx, dword ptr [esi]
// 0044b1a6  85c9                 test ecx, ecx
// 0044b1a8  7408                 je 0x44b1b2
// 0044b1aa  53                   push ebx
// 0044b1ab  55                   push ebp
// 0044b1ac  51                   push ecx
// 0044b1ad  e8aefeffff           call 0x44b060
// 0044b1b2  83c604               add esi, 4
// 0044b1b5  3b770c               cmp esi, dword ptr [edi + 0xc]
// 0044b1b8  72e6                 jb 0x44b1a0
// 0044b1ba  5d                   pop ebp
// 0044b1bb  5b                   pop ebx
// 0044b1bc  5e                   pop esi
// 0044b1bd  5f                   pop edi
// 0044b1be  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlComModuleRegisterClassObjects@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
