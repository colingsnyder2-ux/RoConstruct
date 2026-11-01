// from server: 100% by auto
// roc 2009-12 008f2e90  unit: CXTPDockingPaneAutoHidePanel  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2e90
//
// 008f2e90  53                   push ebx
// 008f2e91  8b5c2408             mov ebx, dword ptr [esp + 8]
// 008f2e95  3bd9                 cmp ebx, ecx
// 008f2e97  7509                 jne 0x8f2ea2
// 008f2e99  b801000000           mov eax, 1
// 008f2e9e  5b                   pop ebx
// 008f2e9f  c20400               ret 4
// 008f2ea2  56                   push esi
// 008f2ea3  8b713c               mov esi, dword ptr [ecx + 0x3c]
// 008f2ea6  57                   push edi
// 008f2ea7  85f6                 test esi, esi
// 008f2ea9  741e                 je 0x8f2ec9
// 008f2eab  eb03                 jmp 0x8f2eb0
// 008f2ead  8d4900               lea ecx, [ecx]
// 008f2eb0  8bc6                 mov eax, esi
// 008f2eb2  8b4808               mov ecx, dword ptr [eax + 8]
// 008f2eb5  8b01                 mov eax, dword ptr [ecx]
// 008f2eb7  8b5008               mov edx, dword ptr [eax + 8]
// 008f2eba  8bfe                 mov edi, esi
// 008f2ebc  8b36                 mov esi, dword ptr [esi]
// 008f2ebe  53                   push ebx
// 008f2ebf  ffd2                 call edx
// 008f2ec1  85c0                 test eax, eax
// 008f2ec3  750c                 jne 0x8f2ed1
// 008f2ec5  85f6                 test esi, esi
// 008f2ec7  75e7                 jne 0x8f2eb0
// 008f2ec9  5f                   pop edi
// 008f2eca  5e                   pop esi
// 008f2ecb  33c0                 xor eax, eax
// 008f2ecd  5b                   pop ebx
// 008f2ece  c20400               ret 4
// 008f2ed1  8bc7                 mov eax, edi
// 008f2ed3  5f                   pop edi
// 008f2ed4  5e                   pop esi
// 008f2ed5  5b                   pop ebx
// 008f2ed6  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?ContainPane@CXTPDockingPaneBaseContainer@@UBEPAU__POSITION@@PAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
