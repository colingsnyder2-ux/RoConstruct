// from server: 100% by auto
// roc 2010-06 0044f140  unit: CRbxPlayDocTemplate  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044f140
//
// 0044f140  55                   push ebp
// 0044f141  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0044f145  85ed                 test ebp, ebp
// 0044f147  7509                 jne 0x44f152
// 0044f149  b857000780           mov eax, 0x80070057
// 0044f14e  5d                   pop ebp
// 0044f14f  c20c00               ret 0xc
// 0044f152  53                   push ebx
// 0044f153  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0044f156  56                   push esi
// 0044f157  57                   push edi
// 0044f158  33ff                 xor edi, edi
// 0044f15a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044f15d  734e                 jae 0x44f1ad
// 0044f15f  90                   nop 
// 0044f160  8b33                 mov esi, dword ptr [ebx]
// 0044f162  85f6                 test esi, esi
// 0044f164  743b                 je 0x44f1a1
// 0044f166  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044f16a  85c0                 test eax, eax
// 0044f16c  7410                 je 0x44f17e
// 0044f16e  8b0e                 mov ecx, dword ptr [esi]
// 0044f170  51                   push ecx
// 0044f171  50                   push eax
// 0044f172  e8e9a1fcff           call 0x419360
// 0044f177  83c408               add esp, 8
// 0044f17a  85c0                 test eax, eax
// 0044f17c  7423                 je 0x44f1a1
// 0044f17e  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0044f181  6a00                 push 0
// 0044f183  ffd2                 call edx
// 0044f185  50                   push eax
// 0044f186  8b06                 mov eax, dword ptr [esi]
// 0044f188  50                   push eax
// 0044f189  e822faffff           call 0x44ebb0
// 0044f18e  8bf8                 mov edi, eax
// 0044f190  85ff                 test edi, edi
// 0044f192  7c2d                 jl 0x44f1c1
// 0044f194  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044f197  6a00                 push 0
// 0044f199  ffd1                 call ecx
// 0044f19b  8bf8                 mov edi, eax
// 0044f19d  85ff                 test edi, edi
// 0044f19f  7c20                 jl 0x44f1c1
// 0044f1a1  83c304               add ebx, 4
// 0044f1a4  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044f1a7  72b7                 jb 0x44f160
// 0044f1a9  85ff                 test edi, edi
// 0044f1ab  7c14                 jl 0x44f1c1
// 0044f1ad  837c241800           cmp dword ptr [esp + 0x18], 0
// 0044f1b2  740d                 je 0x44f1c1
// 0044f1b4  8b5504               mov edx, dword ptr [ebp + 4]
// 0044f1b7  6a00                 push 0
// 0044f1b9  52                   push edx
// 0044f1ba  e801fdffff           call 0x44eec0
// 0044f1bf  8bf8                 mov edi, eax
// 0044f1c1  8bc7                 mov eax, edi
// 0044f1c3  5f                   pop edi
// 0044f1c4  5e                   pop esi
// 0044f1c5  5b                   pop ebx
// 0044f1c6  5d                   pop ebp
// 0044f1c7  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleUnregisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
