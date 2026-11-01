// from server: 100% by auto
// roc 2009-12 0044d7a0  unit: CRbxPlayDocTemplate  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044d7a0
//
// 0044d7a0  55                   push ebp
// 0044d7a1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0044d7a5  85ed                 test ebp, ebp
// 0044d7a7  7509                 jne 0x44d7b2
// 0044d7a9  b857000780           mov eax, 0x80070057
// 0044d7ae  5d                   pop ebp
// 0044d7af  c20c00               ret 0xc
// 0044d7b2  53                   push ebx
// 0044d7b3  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0044d7b6  56                   push esi
// 0044d7b7  57                   push edi
// 0044d7b8  33ff                 xor edi, edi
// 0044d7ba  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044d7bd  734e                 jae 0x44d80d
// 0044d7bf  90                   nop 
// 0044d7c0  8b33                 mov esi, dword ptr [ebx]
// 0044d7c2  85f6                 test esi, esi
// 0044d7c4  743b                 je 0x44d801
// 0044d7c6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044d7ca  85c0                 test eax, eax
// 0044d7cc  7410                 je 0x44d7de
// 0044d7ce  8b0e                 mov ecx, dword ptr [esi]
// 0044d7d0  51                   push ecx
// 0044d7d1  50                   push eax
// 0044d7d2  e889bafcff           call 0x419260
// 0044d7d7  83c408               add esp, 8
// 0044d7da  85c0                 test eax, eax
// 0044d7dc  7423                 je 0x44d801
// 0044d7de  8b5604               mov edx, dword ptr [esi + 4]
// 0044d7e1  6a01                 push 1
// 0044d7e3  ffd2                 call edx
// 0044d7e5  8bf8                 mov edi, eax
// 0044d7e7  85ff                 test edi, edi
// 0044d7e9  7c36                 jl 0x44d821
// 0044d7eb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044d7ee  6a01                 push 1
// 0044d7f0  ffd0                 call eax
// 0044d7f2  8b0e                 mov ecx, dword ptr [esi]
// 0044d7f4  50                   push eax
// 0044d7f5  51                   push ecx
// 0044d7f6  e8a5faffff           call 0x44d2a0
// 0044d7fb  8bf8                 mov edi, eax
// 0044d7fd  85ff                 test edi, edi
// 0044d7ff  7c20                 jl 0x44d821
// 0044d801  83c304               add ebx, 4
// 0044d804  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044d807  72b7                 jb 0x44d7c0
// 0044d809  85ff                 test edi, edi
// 0044d80b  7c14                 jl 0x44d821
// 0044d80d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0044d812  740d                 je 0x44d821
// 0044d814  8b5504               mov edx, dword ptr [ebp + 4]
// 0044d817  6a00                 push 0
// 0044d819  52                   push edx
// 0044d81a  e861feffff           call 0x44d680
// 0044d81f  8bf8                 mov edi, eax
// 0044d821  8bc7                 mov eax, edi
// 0044d823  5f                   pop edi
// 0044d824  5e                   pop esi
// 0044d825  5b                   pop ebx
// 0044d826  5d                   pop ebp
// 0044d827  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
