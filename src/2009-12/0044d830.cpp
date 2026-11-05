// from server: 100% by auto
// roc 2009-12 0044d830  unit: CRbxPlayDocTemplate  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044d830
//
// 0044d830  55                   push ebp
// 0044d831  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0044d835  85ed                 test ebp, ebp
// 0044d837  7509                 jne 0x44d842
// 0044d839  b857000780           mov eax, 0x80070057
// 0044d83e  5d                   pop ebp
// 0044d83f  c20c00               ret 0xc
// 0044d842  53                   push ebx
// 0044d843  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0044d846  56                   push esi
// 0044d847  57                   push edi
// 0044d848  33ff                 xor edi, edi
// 0044d84a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044d84d  734e                 jae 0x44d89d
// 0044d84f  90                   nop 
// 0044d850  8b33                 mov esi, dword ptr [ebx]
// 0044d852  85f6                 test esi, esi
// 0044d854  743b                 je 0x44d891
// 0044d856  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044d85a  85c0                 test eax, eax
// 0044d85c  7410                 je 0x44d86e
// 0044d85e  8b0e                 mov ecx, dword ptr [esi]
// 0044d860  51                   push ecx
// 0044d861  50                   push eax
// 0044d862  e8f9b9fcff           call 0x419260
// 0044d867  83c408               add esp, 8
// 0044d86a  85c0                 test eax, eax
// 0044d86c  7423                 je 0x44d891
// 0044d86e  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0044d871  6a00                 push 0
// 0044d873  ffd2                 call edx
// 0044d875  50                   push eax
// 0044d876  8b06                 mov eax, dword ptr [esi]
// 0044d878  50                   push eax
// 0044d879  e822faffff           call 0x44d2a0
// 0044d87e  8bf8                 mov edi, eax
// 0044d880  85ff                 test edi, edi
// 0044d882  7c2d                 jl 0x44d8b1
// 0044d884  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044d887  6a00                 push 0
// 0044d889  ffd1                 call ecx
// 0044d88b  8bf8                 mov edi, eax
// 0044d88d  85ff                 test edi, edi
// 0044d88f  7c20                 jl 0x44d8b1
// 0044d891  83c304               add ebx, 4
// 0044d894  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044d897  72b7                 jb 0x44d850
// 0044d899  85ff                 test edi, edi
// 0044d89b  7c14                 jl 0x44d8b1
// 0044d89d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0044d8a2  740d                 je 0x44d8b1
// 0044d8a4  8b5504               mov edx, dword ptr [ebp + 4]
// 0044d8a7  6a00                 push 0
// 0044d8a9  52                   push edx
// 0044d8aa  e801fdffff           call 0x44d5b0
// 0044d8af  8bf8                 mov edi, eax
// 0044d8b1  8bc7                 mov eax, edi
// 0044d8b3  5f                   pop edi
// 0044d8b4  5e                   pop esi
// 0044d8b5  5b                   pop ebx
// 0044d8b6  5d                   pop ebp
// 0044d8b7  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleUnregisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
