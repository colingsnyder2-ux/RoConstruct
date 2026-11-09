// from server: 100% by auto
// roc 2008-06 0044b740  unit: CRobloxApp  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044b740
//
// 0044b740  55                   push ebp
// 0044b741  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0044b745  85ed                 test ebp, ebp
// 0044b747  7509                 jne 0x44b752
// 0044b749  b857000780           mov eax, 0x80070057
// 0044b74e  5d                   pop ebp
// 0044b74f  c20c00               ret 0xc
// 0044b752  53                   push ebx
// 0044b753  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0044b756  56                   push esi
// 0044b757  57                   push edi
// 0044b758  33ff                 xor edi, edi
// 0044b75a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044b75d  734e                 jae 0x44b7ad
// 0044b75f  90                   nop 
// 0044b760  8b33                 mov esi, dword ptr [ebx]
// 0044b762  85f6                 test esi, esi
// 0044b764  743b                 je 0x44b7a1
// 0044b766  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044b76a  85c0                 test eax, eax
// 0044b76c  7410                 je 0x44b77e
// 0044b76e  8b0e                 mov ecx, dword ptr [esi]
// 0044b770  51                   push ecx
// 0044b771  50                   push eax
// 0044b772  e8c9f5fdff           call 0x42ad40
// 0044b777  83c408               add esp, 8
// 0044b77a  85c0                 test eax, eax
// 0044b77c  7423                 je 0x44b7a1
// 0044b77e  8b561c               mov edx, dword ptr [esi + 0x1c]
// 0044b781  6a00                 push 0
// 0044b783  ffd2                 call edx
// 0044b785  50                   push eax
// 0044b786  8b06                 mov eax, dword ptr [esi]
// 0044b788  50                   push eax
// 0044b789  e822faffff           call 0x44b1b0
// 0044b78e  8bf8                 mov edi, eax
// 0044b790  85ff                 test edi, edi
// 0044b792  7c2d                 jl 0x44b7c1
// 0044b794  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044b797  6a00                 push 0
// 0044b799  ffd1                 call ecx
// 0044b79b  8bf8                 mov edi, eax
// 0044b79d  85ff                 test edi, edi
// 0044b79f  7c20                 jl 0x44b7c1
// 0044b7a1  83c304               add ebx, 4
// 0044b7a4  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044b7a7  72b7                 jb 0x44b760
// 0044b7a9  85ff                 test edi, edi
// 0044b7ab  7c14                 jl 0x44b7c1
// 0044b7ad  837c241800           cmp dword ptr [esp + 0x18], 0
// 0044b7b2  740d                 je 0x44b7c1
// 0044b7b4  8b5504               mov edx, dword ptr [ebp + 4]
// 0044b7b7  6a00                 push 0
// 0044b7b9  52                   push edx
// 0044b7ba  e801fdffff           call 0x44b4c0
// 0044b7bf  8bf8                 mov edi, eax
// 0044b7c1  8bc7                 mov eax, edi
// 0044b7c3  5f                   pop edi
// 0044b7c4  5e                   pop esi
// 0044b7c5  5b                   pop ebx
// 0044b7c6  5d                   pop ebp
// 0044b7c7  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleUnregisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
