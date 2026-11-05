// from server: 100% by auto
// roc 2007-03 00447b90  unit: seg_00440000  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00447b90
//
// 00447b90  57                   push edi
// 00447b91  8b7c2408             mov edi, dword ptr [esp + 8]
// 00447b95  85ff                 test edi, edi
// 00447b97  7509                 jne 0x447ba2
// 00447b99  b857000780           mov eax, 0x80070057
// 00447b9e  5f                   pop edi
// 00447b9f  c20c00               ret 0xc
// 00447ba2  56                   push esi
// 00447ba3  8b7708               mov esi, dword ptr [edi + 8]
// 00447ba6  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00447ba9  b801000000           mov eax, 1
// 00447bae  732c                 jae 0x447bdc
// 00447bb0  53                   push ebx
// 00447bb1  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00447bb5  55                   push ebp
// 00447bb6  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00447bba  8d9b00000000         lea ebx, [ebx]
// 00447bc0  85c0                 test eax, eax
// 00447bc2  7c16                 jl 0x447bda
// 00447bc4  8b0e                 mov ecx, dword ptr [esi]
// 00447bc6  85c9                 test ecx, ecx
// 00447bc8  7408                 je 0x447bd2
// 00447bca  53                   push ebx
// 00447bcb  55                   push ebp
// 00447bcc  51                   push ecx
// 00447bcd  e85efeffff           call 0x447a30
// 00447bd2  83c604               add esi, 4
// 00447bd5  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00447bd8  72e6                 jb 0x447bc0
// 00447bda  5d                   pop ebp
// 00447bdb  5b                   pop ebx
// 00447bdc  5e                   pop esi
// 00447bdd  5f                   pop edi
// 00447bde  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterClassObjects@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
