// from server: 100% by auto
// roc 2008-06 0044b6b0  unit: CRobloxApp  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044b6b0
//
// 0044b6b0  55                   push ebp
// 0044b6b1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0044b6b5  85ed                 test ebp, ebp
// 0044b6b7  7509                 jne 0x44b6c2
// 0044b6b9  b857000780           mov eax, 0x80070057
// 0044b6be  5d                   pop ebp
// 0044b6bf  c20c00               ret 0xc
// 0044b6c2  53                   push ebx
// 0044b6c3  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0044b6c6  56                   push esi
// 0044b6c7  57                   push edi
// 0044b6c8  33ff                 xor edi, edi
// 0044b6ca  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044b6cd  734e                 jae 0x44b71d
// 0044b6cf  90                   nop 
// 0044b6d0  8b33                 mov esi, dword ptr [ebx]
// 0044b6d2  85f6                 test esi, esi
// 0044b6d4  743b                 je 0x44b711
// 0044b6d6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044b6da  85c0                 test eax, eax
// 0044b6dc  7410                 je 0x44b6ee
// 0044b6de  8b0e                 mov ecx, dword ptr [esi]
// 0044b6e0  51                   push ecx
// 0044b6e1  50                   push eax
// 0044b6e2  e859f6fdff           call 0x42ad40
// 0044b6e7  83c408               add esp, 8
// 0044b6ea  85c0                 test eax, eax
// 0044b6ec  7423                 je 0x44b711
// 0044b6ee  8b5604               mov edx, dword ptr [esi + 4]
// 0044b6f1  6a01                 push 1
// 0044b6f3  ffd2                 call edx
// 0044b6f5  8bf8                 mov edi, eax
// 0044b6f7  85ff                 test edi, edi
// 0044b6f9  7c36                 jl 0x44b731
// 0044b6fb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044b6fe  6a01                 push 1
// 0044b700  ffd0                 call eax
// 0044b702  8b0e                 mov ecx, dword ptr [esi]
// 0044b704  50                   push eax
// 0044b705  51                   push ecx
// 0044b706  e8a5faffff           call 0x44b1b0
// 0044b70b  8bf8                 mov edi, eax
// 0044b70d  85ff                 test edi, edi
// 0044b70f  7c20                 jl 0x44b731
// 0044b711  83c304               add ebx, 4
// 0044b714  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044b717  72b7                 jb 0x44b6d0
// 0044b719  85ff                 test edi, edi
// 0044b71b  7c14                 jl 0x44b731
// 0044b71d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0044b722  740d                 je 0x44b731
// 0044b724  8b5504               mov edx, dword ptr [ebp + 4]
// 0044b727  6a00                 push 0
// 0044b729  52                   push edx
// 0044b72a  e861feffff           call 0x44b590
// 0044b72f  8bf8                 mov edi, eax
// 0044b731  8bc7                 mov eax, edi
// 0044b733  5f                   pop edi
// 0044b734  5e                   pop esi
// 0044b735  5b                   pop ebx
// 0044b736  5d                   pop ebp
// 0044b737  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
