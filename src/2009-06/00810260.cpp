// from server: 100% by auto
// roc 2009-06 00810260  unit: CXTPScrollBase  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00810260
//
// 00810260  56                   push esi
// 00810261  57                   push edi
// 00810262  8bf9                 mov edi, ecx
// 00810264  8b7760               mov esi, dword ptr [edi + 0x60]
// 00810267  85f6                 test esi, esi
// 00810269  7473                 je 0x8102de
// 0081026b  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00810272  ff1544ee8900         call dword ptr [0x89ee44]
// 00810278  837e3000             cmp dword ptr [esi + 0x30], 0
// 0081027c  743a                 je 0x8102b8
// 0081027e  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00810283  7409                 je 0x81028e
// 00810285  8b4634               mov eax, dword ptr [esi + 0x34]
// 00810288  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0081028b  894e24               mov dword ptr [esi + 0x24], ecx
// 0081028e  8b4624               mov eax, dword ptr [esi + 0x24]
// 00810291  8b17                 mov edx, dword ptr [edi]
// 00810293  8b5218               mov edx, dword ptr [edx + 0x18]
// 00810296  50                   push eax
// 00810297  6a04                 push 4
// 00810299  8bcf                 mov ecx, edi
// 0081029b  ffd2                 call edx
// 0081029d  8b07                 mov eax, dword ptr [edi]
// 0081029f  8b501c               mov edx, dword ptr [eax + 0x1c]
// 008102a2  8bcf                 mov ecx, edi
// 008102a4  ffd2                 call edx
// 008102a6  8b17                 mov edx, dword ptr [edi]
// 008102a8  8b4218               mov eax, dword ptr [edx + 0x18]
// 008102ab  6a00                 push 0
// 008102ad  6a08                 push 8
// 008102af  8bcf                 mov ecx, edi
// 008102b1  ffd0                 call eax
// 008102b3  5f                   pop edi
// 008102b4  5e                   pop esi
// 008102b5  c20400               ret 4
// 008102b8  8b4618               mov eax, dword ptr [esi + 0x18]
// 008102bb  85c0                 test eax, eax
// 008102bd  7412                 je 0x8102d1
// 008102bf  50                   push eax
// 008102c0  8b462c               mov eax, dword ptr [esi + 0x2c]
// 008102c3  50                   push eax
// 008102c4  ff1584ee8900         call dword ptr [0x89ee84]
// 008102ca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 008102d1  8b17                 mov edx, dword ptr [edi]
// 008102d3  8b4218               mov eax, dword ptr [edx + 0x18]
// 008102d6  6a00                 push 0
// 008102d8  6a08                 push 8
// 008102da  8bcf                 mov ecx, edi
// 008102dc  ffd0                 call eax
// 008102de  5f                   pop edi
// 008102df  5e                   pop esi
// 008102e0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?EndScroll@CXTPScrollBase@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
