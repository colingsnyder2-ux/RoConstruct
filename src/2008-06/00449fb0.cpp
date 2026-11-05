// from server: 100% by auto
// roc 2008-06 00449fb0  unit: CIDEDocManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00449fb0
//
// 00449fb0  57                   push edi
// 00449fb1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00449fb5  85ff                 test edi, edi
// 00449fb7  7509                 jne 0x449fc2
// 00449fb9  b857000780           mov eax, 0x80070057
// 00449fbe  5f                   pop edi
// 00449fbf  c20c00               ret 0xc
// 00449fc2  56                   push esi
// 00449fc3  8b7708               mov esi, dword ptr [edi + 8]
// 00449fc6  b801000000           mov eax, 1
// 00449fcb  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00449fce  732c                 jae 0x449ffc
// 00449fd0  53                   push ebx
// 00449fd1  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00449fd5  55                   push ebp
// 00449fd6  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00449fda  8d9b00000000         lea ebx, [ebx]
// 00449fe0  85c0                 test eax, eax
// 00449fe2  7c16                 jl 0x449ffa
// 00449fe4  8b0e                 mov ecx, dword ptr [esi]
// 00449fe6  85c9                 test ecx, ecx
// 00449fe8  7408                 je 0x449ff2
// 00449fea  53                   push ebx
// 00449feb  55                   push ebp
// 00449fec  51                   push ecx
// 00449fed  e83efeffff           call 0x449e30
// 00449ff2  83c604               add esi, 4
// 00449ff5  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00449ff8  72e6                 jb 0x449fe0
// 00449ffa  5d                   pop ebp
// 00449ffb  5b                   pop ebx
// 00449ffc  5e                   pop esi
// 00449ffd  5f                   pop edi
// 00449ffe  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlComModuleRegisterClassObjects@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
