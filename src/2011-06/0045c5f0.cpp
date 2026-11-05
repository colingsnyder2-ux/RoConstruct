// from server: 100% by auto
// roc 2011-06 0045c5f0  unit: VCRoblox3D::?$CComObject  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045c5f0
//
// 0045c5f0  55                   push ebp
// 0045c5f1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0045c5f5  85ed                 test ebp, ebp
// 0045c5f7  7509                 jne 0x45c602
// 0045c5f9  b857000780           mov eax, 0x80070057
// 0045c5fe  5d                   pop ebp
// 0045c5ff  c20c00               ret 0xc
// 0045c602  53                   push ebx
// 0045c603  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0045c606  56                   push esi
// 0045c607  57                   push edi
// 0045c608  33ff                 xor edi, edi
// 0045c60a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0045c60d  734e                 jae 0x45c65d
// 0045c60f  90                   nop 
// 0045c610  8b33                 mov esi, dword ptr [ebx]
// 0045c612  85f6                 test esi, esi
// 0045c614  743b                 je 0x45c651
// 0045c616  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0045c61a  85c0                 test eax, eax
// 0045c61c  7410                 je 0x45c62e
// 0045c61e  8b0e                 mov ecx, dword ptr [esi]
// 0045c620  51                   push ecx
// 0045c621  50                   push eax
// 0045c622  e8c900fcff           call 0x41c6f0
// 0045c627  83c408               add esp, 8
// 0045c62a  85c0                 test eax, eax
// 0045c62c  7423                 je 0x45c651
// 0045c62e  8b5604               mov edx, dword ptr [esi + 4]
// 0045c631  6a01                 push 1
// 0045c633  ffd2                 call edx
// 0045c635  8bf8                 mov edi, eax
// 0045c637  85ff                 test edi, edi
// 0045c639  7c36                 jl 0x45c671
// 0045c63b  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0045c63e  6a01                 push 1
// 0045c640  ffd0                 call eax
// 0045c642  8b0e                 mov ecx, dword ptr [esi]
// 0045c644  50                   push eax
// 0045c645  51                   push ecx
// 0045c646  e8a5faffff           call 0x45c0f0
// 0045c64b  8bf8                 mov edi, eax
// 0045c64d  85ff                 test edi, edi
// 0045c64f  7c20                 jl 0x45c671
// 0045c651  83c304               add ebx, 4
// 0045c654  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0045c657  72b7                 jb 0x45c610
// 0045c659  85ff                 test edi, edi
// 0045c65b  7c14                 jl 0x45c671
// 0045c65d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0045c662  740d                 je 0x45c671
// 0045c664  8b5504               mov edx, dword ptr [ebp + 4]
// 0045c667  6a00                 push 0
// 0045c669  52                   push edx
// 0045c66a  e861feffff           call 0x45c4d0
// 0045c66f  8bf8                 mov edi, eax
// 0045c671  8bc7                 mov eax, edi
// 0045c673  5f                   pop edi
// 0045c674  5e                   pop esi
// 0045c675  5b                   pop ebx
// 0045c676  5d                   pop ebp
// 0045c677  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
