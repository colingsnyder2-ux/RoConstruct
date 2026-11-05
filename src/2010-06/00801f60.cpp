// from server: 100% by auto
// roc 2010-06 00801f60  unit: CXTPPropertyGrid  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00801f60
//
// 00801f60  53                   push ebx
// 00801f61  8b1d4cba9e00         mov ebx, dword ptr [0x9eba4c]
// 00801f67  56                   push esi
// 00801f68  57                   push edi
// 00801f69  8bf9                 mov edi, ecx
// 00801f6b  8b4720               mov eax, dword ptr [edi + 0x20]
// 00801f6e  50                   push eax
// 00801f6f  ffd3                 call ebx
// 00801f71  50                   push eax
// 00801f72  e8f35cfaff           call 0x7a7c6a
// 00801f77  8bf0                 mov esi, eax
// 00801f79  85f6                 test esi, esi
// 00801f7b  7453                 je 0x801fd0
// 00801f7d  8bce                 mov ecx, esi
// 00801f7f  e860ae1700           call 0x97cde4
// 00801f84  a900000100           test eax, 0x10000
// 00801f89  741c                 je 0x801fa7
// 00801f8b  8bce                 mov ecx, esi
// 00801f8d  e84cae1700           call 0x97cdde
// 00801f92  a900000040           test eax, 0x40000000
// 00801f97  740e                 je 0x801fa7
// 00801f99  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00801f9c  51                   push ecx
// 00801f9d  ffd3                 call ebx
// 00801f9f  50                   push eax
// 00801fa0  e8c55cfaff           call 0x7a7c6a
// 00801fa5  8bf0                 mov esi, eax
// 00801fa7  8b542410             mov edx, dword ptr [esp + 0x10]
// 00801fab  8b4720               mov eax, dword ptr [edi + 0x20]
// 00801fae  52                   push edx
// 00801faf  50                   push eax
// 00801fb0  8b4620               mov eax, dword ptr [esi + 0x20]
// 00801fb3  50                   push eax
// 00801fb4  ff15bcba9e00         call dword ptr [0x9ebabc]
// 00801fba  50                   push eax
// 00801fbb  e8aa5cfaff           call 0x7a7c6a
// 00801fc0  8bc8                 mov ecx, eax
// 00801fc2  2bc7                 sub eax, edi
// 00801fc4  f7d8                 neg eax
// 00801fc6  5f                   pop edi
// 00801fc7  1bc0                 sbb eax, eax
// 00801fc9  5e                   pop esi
// 00801fca  23c1                 and eax, ecx
// 00801fcc  5b                   pop ebx
// 00801fcd  c20400               ret 4
// 00801fd0  5f                   pop edi
// 00801fd1  5e                   pop esi
// 00801fd2  33c0                 xor eax, eax
// 00801fd4  5b                   pop ebx
// 00801fd5  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?GetNextGridTabItem@CXTPPropertyGrid@@AAEPAVCWnd@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
