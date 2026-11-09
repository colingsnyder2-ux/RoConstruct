// from server: 100% by auto
// roc 2011-06 0045c680  unit: VCRoblox3D::?$CComObject  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045c680
//
// 0045c680  55                   push ebp
// 0045c681  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0045c685  85ed                 test ebp, ebp
// 0045c687  7509                 jne 0x45c692
// 0045c689  b857000780           mov eax, 0x80070057
// 0045c68e  5d                   pop ebp
// 0045c68f  c20c00               ret 0xc
// 0045c692  53                   push ebx
// 0045c693  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0045c696  56                   push esi
// 0045c697  57                   push edi
// 0045c698  33ff                 xor edi, edi
// 0045c69a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0045c69d  734e                 jae 0x45c6ed
// 0045c69f  90                   nop 
// 0045c6a0  8b33                 mov esi, dword ptr [ebx]
// 0045c6a2  85f6                 test esi, esi
// 0045c6a4  743b                 je 0x45c6e1
// 0045c6a6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0045c6aa  85c0                 test eax, eax
// 0045c6ac  7410                 je 0x45c6be
// 0045c6ae  8b0e                 mov ecx, dword ptr [esi]
// 0045c6b0  51                   push ecx
// 0045c6b1  50                   push eax
// 0045c6b2  e83900fcff           call 0x41c6f0
// 0045c6b7  83c408               add esp, 8
// 0045c6ba  85c0                 test eax, eax
// 0045c6bc  7423                 je 0x45c6e1
// 0045c6be  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0045c6c1  6a00                 push 0
// 0045c6c3  ffd2                 call edx
// 0045c6c5  50                   push eax
// 0045c6c6  8b06                 mov eax, dword ptr [esi]
// 0045c6c8  50                   push eax
// 0045c6c9  e822faffff           call 0x45c0f0
// 0045c6ce  8bf8                 mov edi, eax
// 0045c6d0  85ff                 test edi, edi
// 0045c6d2  7c2d                 jl 0x45c701
// 0045c6d4  8b4e04               mov ecx, dword ptr [esi + 4]
// 0045c6d7  6a00                 push 0
// 0045c6d9  ffd1                 call ecx
// 0045c6db  8bf8                 mov edi, eax
// 0045c6dd  85ff                 test edi, edi
// 0045c6df  7c20                 jl 0x45c701
// 0045c6e1  83c304               add ebx, 4
// 0045c6e4  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0045c6e7  72b7                 jb 0x45c6a0
// 0045c6e9  85ff                 test edi, edi
// 0045c6eb  7c14                 jl 0x45c701
// 0045c6ed  837c241800           cmp dword ptr [esp + 0x18], 0
// 0045c6f2  740d                 je 0x45c701
// 0045c6f4  8b5504               mov edx, dword ptr [ebp + 4]
// 0045c6f7  6a00                 push 0
// 0045c6f9  52                   push edx
// 0045c6fa  e801fdffff           call 0x45c400
// 0045c6ff  8bf8                 mov edi, eax
// 0045c701  8bc7                 mov eax, edi
// 0045c703  5f                   pop edi
// 0045c704  5e                   pop esi
// 0045c705  5b                   pop ebx
// 0045c706  5d                   pop ebp
// 0045c707  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleUnregisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
