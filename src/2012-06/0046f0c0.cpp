// from server: 100% by auto
// roc 2012-06 0046f0c0  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046f0c0
//
// 0046f0c0  55                   push ebp
// 0046f0c1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0046f0c5  85ed                 test ebp, ebp
// 0046f0c7  7509                 jne 0x46f0d2
// 0046f0c9  b857000780           mov eax, 0x80070057
// 0046f0ce  5d                   pop ebp
// 0046f0cf  c20c00               ret 0xc
// 0046f0d2  53                   push ebx
// 0046f0d3  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0046f0d6  56                   push esi
// 0046f0d7  57                   push edi
// 0046f0d8  33ff                 xor edi, edi
// 0046f0da  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0046f0dd  734e                 jae 0x46f12d
// 0046f0df  90                   nop 
// 0046f0e0  8b33                 mov esi, dword ptr [ebx]
// 0046f0e2  85f6                 test esi, esi
// 0046f0e4  743b                 je 0x46f121
// 0046f0e6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046f0ea  85c0                 test eax, eax
// 0046f0ec  7410                 je 0x46f0fe
// 0046f0ee  8b0e                 mov ecx, dword ptr [esi]
// 0046f0f0  51                   push ecx
// 0046f0f1  50                   push eax
// 0046f0f2  e8f90bfbff           call 0x41fcf0
// 0046f0f7  83c408               add esp, 8
// 0046f0fa  85c0                 test eax, eax
// 0046f0fc  7423                 je 0x46f121
// 0046f0fe  8b5604               mov edx, dword ptr [esi + 4]
// 0046f101  6a01                 push 1
// 0046f103  ffd2                 call edx
// 0046f105  8bf8                 mov edi, eax
// 0046f107  85ff                 test edi, edi
// 0046f109  7c36                 jl 0x46f141
// 0046f10b  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0046f10e  6a01                 push 1
// 0046f110  ffd0                 call eax
// 0046f112  8b0e                 mov ecx, dword ptr [esi]
// 0046f114  50                   push eax
// 0046f115  51                   push ecx
// 0046f116  e8a5faffff           call 0x46ebc0
// 0046f11b  8bf8                 mov edi, eax
// 0046f11d  85ff                 test edi, edi
// 0046f11f  7c20                 jl 0x46f141
// 0046f121  83c304               add ebx, 4
// 0046f124  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0046f127  72b7                 jb 0x46f0e0
// 0046f129  85ff                 test edi, edi
// 0046f12b  7c14                 jl 0x46f141
// 0046f12d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0046f132  740d                 je 0x46f141
// 0046f134  8b5504               mov edx, dword ptr [ebp + 4]
// 0046f137  6a00                 push 0
// 0046f139  52                   push edx
// 0046f13a  e861feffff           call 0x46efa0
// 0046f13f  8bf8                 mov edi, eax
// 0046f141  8bc7                 mov eax, edi
// 0046f143  5f                   pop edi
// 0046f144  5e                   pop esi
// 0046f145  5b                   pop ebx
// 0046f146  5d                   pop ebp
// 0046f147  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleRegisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
