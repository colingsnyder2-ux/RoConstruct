// from server: 100% by auto
// roc 2009-06 008181f0  unit: CXTPDockingPaneAutoHidePanel  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008181f0
//
// 008181f0  53                   push ebx
// 008181f1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 008181f5  3bd9                 cmp ebx, ecx
// 008181f7  7509                 jne 0x818202
// 008181f9  b801000000           mov eax, 1
// 008181fe  5b                   pop ebx
// 008181ff  c20400               ret 4
// 00818202  56                   push esi
// 00818203  8b713c               mov esi, dword ptr [ecx + 0x3c]
// 00818206  57                   push edi
// 00818207  85f6                 test esi, esi
// 00818209  741e                 je 0x818229
// 0081820b  eb03                 jmp 0x818210
// 0081820d  8d4900               lea ecx, [ecx]
// 00818210  8bc6                 mov eax, esi
// 00818212  8b4808               mov ecx, dword ptr [eax + 8]
// 00818215  8b01                 mov eax, dword ptr [ecx]
// 00818217  8b5008               mov edx, dword ptr [eax + 8]
// 0081821a  8bfe                 mov edi, esi
// 0081821c  8b36                 mov esi, dword ptr [esi]
// 0081821e  53                   push ebx
// 0081821f  ffd2                 call edx
// 00818221  85c0                 test eax, eax
// 00818223  750c                 jne 0x818231
// 00818225  85f6                 test esi, esi
// 00818227  75e7                 jne 0x818210
// 00818229  5f                   pop edi
// 0081822a  5e                   pop esi
// 0081822b  33c0                 xor eax, eax
// 0081822d  5b                   pop ebx
// 0081822e  c20400               ret 4
// 00818231  8bc7                 mov eax, edi
// 00818233  5f                   pop edi
// 00818234  5e                   pop esi
// 00818235  5b                   pop ebx
// 00818236  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?ContainPane@CXTPDockingPaneBaseContainer@@UBEPAU__POSITION@@PAVCXTPDockingPaneBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
