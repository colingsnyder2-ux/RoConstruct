// from server: 100% by auto
// roc 2009-06 004475d0  unit: CBrowserDocManager  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004475d0
//
// 004475d0  55                   push ebp
// 004475d1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 004475d5  85ed                 test ebp, ebp
// 004475d7  7509                 jne 0x4475e2
// 004475d9  b857000780           mov eax, 0x80070057
// 004475de  5d                   pop ebp
// 004475df  c20c00               ret 0xc
// 004475e2  53                   push ebx
// 004475e3  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004475e6  56                   push esi
// 004475e7  57                   push edi
// 004475e8  33ff                 xor edi, edi
// 004475ea  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 004475ed  734e                 jae 0x44763d
// 004475ef  90                   nop 
// 004475f0  8b33                 mov esi, dword ptr [ebx]
// 004475f2  85f6                 test esi, esi
// 004475f4  743b                 je 0x447631
// 004475f6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004475fa  85c0                 test eax, eax
// 004475fc  7410                 je 0x44760e
// 004475fe  8b0e                 mov ecx, dword ptr [esi]
// 00447600  51                   push ecx
// 00447601  50                   push eax
// 00447602  e82918fdff           call 0x418e30
// 00447607  83c408               add esp, 8
// 0044760a  85c0                 test eax, eax
// 0044760c  7423                 je 0x447631
// 0044760e  8b5604               mov edx, dword ptr [esi + 4]
// 00447611  6a01                 push 1
// 00447613  ffd2                 call edx
// 00447615  8bf8                 mov edi, eax
// 00447617  85ff                 test edi, edi
// 00447619  7c36                 jl 0x447651
// 0044761b  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044761e  6a01                 push 1
// 00447620  ffd0                 call eax
// 00447622  8b0e                 mov ecx, dword ptr [esi]
// 00447624  50                   push eax
// 00447625  51                   push ecx
// 00447626  e8a5faffff           call 0x4470d0
// 0044762b  8bf8                 mov edi, eax
// 0044762d  85ff                 test edi, edi
// 0044762f  7c20                 jl 0x447651
// 00447631  83c304               add ebx, 4
// 00447634  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 00447637  72b7                 jb 0x4475f0
// 00447639  85ff                 test edi, edi
// 0044763b  7c14                 jl 0x447651
// 0044763d  837c241800           cmp dword ptr [esp + 0x18], 0
// 00447642  740d                 je 0x447651
// 00447644  8b5504               mov edx, dword ptr [ebp + 4]
// 00447647  6a00                 push 0
// 00447649  52                   push edx
// 0044764a  e861feffff           call 0x4474b0
// 0044764f  8bf8                 mov edi, eax
// 00447651  8bc7                 mov eax, edi
// 00447653  5f                   pop edi
// 00447654  5e                   pop esi
// 00447655  5b                   pop ebx
// 00447656  5d                   pop ebp
// 00447657  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
