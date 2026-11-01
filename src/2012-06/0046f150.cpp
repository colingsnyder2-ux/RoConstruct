// from server: 100% by auto
// roc 2012-06 0046f150  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046f150
//
// 0046f150  55                   push ebp
// 0046f151  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0046f155  85ed                 test ebp, ebp
// 0046f157  7509                 jne 0x46f162
// 0046f159  b857000780           mov eax, 0x80070057
// 0046f15e  5d                   pop ebp
// 0046f15f  c20c00               ret 0xc
// 0046f162  53                   push ebx
// 0046f163  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0046f166  56                   push esi
// 0046f167  57                   push edi
// 0046f168  33ff                 xor edi, edi
// 0046f16a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0046f16d  734e                 jae 0x46f1bd
// 0046f16f  90                   nop 
// 0046f170  8b33                 mov esi, dword ptr [ebx]
// 0046f172  85f6                 test esi, esi
// 0046f174  743b                 je 0x46f1b1
// 0046f176  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046f17a  85c0                 test eax, eax
// 0046f17c  7410                 je 0x46f18e
// 0046f17e  8b0e                 mov ecx, dword ptr [esi]
// 0046f180  51                   push ecx
// 0046f181  50                   push eax
// 0046f182  e8690bfbff           call 0x41fcf0
// 0046f187  83c408               add esp, 8
// 0046f18a  85c0                 test eax, eax
// 0046f18c  7423                 je 0x46f1b1
// 0046f18e  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0046f191  6a00                 push 0
// 0046f193  ffd2                 call edx
// 0046f195  50                   push eax
// 0046f196  8b06                 mov eax, dword ptr [esi]
// 0046f198  50                   push eax
// 0046f199  e822faffff           call 0x46ebc0
// 0046f19e  8bf8                 mov edi, eax
// 0046f1a0  85ff                 test edi, edi
// 0046f1a2  7c2d                 jl 0x46f1d1
// 0046f1a4  8b4e04               mov ecx, dword ptr [esi + 4]
// 0046f1a7  6a00                 push 0
// 0046f1a9  ffd1                 call ecx
// 0046f1ab  8bf8                 mov edi, eax
// 0046f1ad  85ff                 test edi, edi
// 0046f1af  7c20                 jl 0x46f1d1
// 0046f1b1  83c304               add ebx, 4
// 0046f1b4  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0046f1b7  72b7                 jb 0x46f170
// 0046f1b9  85ff                 test edi, edi
// 0046f1bb  7c14                 jl 0x46f1d1
// 0046f1bd  837c241800           cmp dword ptr [esp + 0x18], 0
// 0046f1c2  740d                 je 0x46f1d1
// 0046f1c4  8b5504               mov edx, dword ptr [ebp + 4]
// 0046f1c7  6a00                 push 0
// 0046f1c9  52                   push edx
// 0046f1ca  e801fdffff           call 0x46eed0
// 0046f1cf  8bf8                 mov edi, eax
// 0046f1d1  8bc7                 mov eax, edi
// 0046f1d3  5f                   pop edi
// 0046f1d4  5e                   pop esi
// 0046f1d5  5b                   pop ebx
// 0046f1d6  5d                   pop ebp
// 0046f1d7  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleUnregisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
