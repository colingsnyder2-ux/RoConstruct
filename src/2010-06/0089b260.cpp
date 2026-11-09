// from server: 100% by auto
// roc 2010-06 0089b260  unit: CXTPScrollBase  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089b260
//
// 0089b260  56                   push esi
// 0089b261  57                   push edi
// 0089b262  8bf9                 mov edi, ecx
// 0089b264  8b7760               mov esi, dword ptr [edi + 0x60]
// 0089b267  85f6                 test esi, esi
// 0089b269  7473                 je 0x89b2de
// 0089b26b  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0089b272  ff158cbc9e00         call dword ptr [0x9ebc8c]
// 0089b278  837e3000             cmp dword ptr [esi + 0x30], 0
// 0089b27c  743a                 je 0x89b2b8
// 0089b27e  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0089b283  7409                 je 0x89b28e
// 0089b285  8b4634               mov eax, dword ptr [esi + 0x34]
// 0089b288  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0089b28b  894e24               mov dword ptr [esi + 0x24], ecx
// 0089b28e  8b4624               mov eax, dword ptr [esi + 0x24]
// 0089b291  8b17                 mov edx, dword ptr [edi]
// 0089b293  8b5218               mov edx, dword ptr [edx + 0x18]
// 0089b296  50                   push eax
// 0089b297  6a04                 push 4
// 0089b299  8bcf                 mov ecx, edi
// 0089b29b  ffd2                 call edx
// 0089b29d  8b07                 mov eax, dword ptr [edi]
// 0089b29f  8b501c               mov edx, dword ptr [eax + 0x1c]
// 0089b2a2  8bcf                 mov ecx, edi
// 0089b2a4  ffd2                 call edx
// 0089b2a6  8b17                 mov edx, dword ptr [edi]
// 0089b2a8  8b4218               mov eax, dword ptr [edx + 0x18]
// 0089b2ab  6a00                 push 0
// 0089b2ad  6a08                 push 8
// 0089b2af  8bcf                 mov ecx, edi
// 0089b2b1  ffd0                 call eax
// 0089b2b3  5f                   pop edi
// 0089b2b4  5e                   pop esi
// 0089b2b5  c20400               ret 4
// 0089b2b8  8b4618               mov eax, dword ptr [esi + 0x18]
// 0089b2bb  85c0                 test eax, eax
// 0089b2bd  7412                 je 0x89b2d1
// 0089b2bf  50                   push eax
// 0089b2c0  8b462c               mov eax, dword ptr [esi + 0x2c]
// 0089b2c3  50                   push eax
// 0089b2c4  ff1560ba9e00         call dword ptr [0x9eba60]
// 0089b2ca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0089b2d1  8b17                 mov edx, dword ptr [edi]
// 0089b2d3  8b4218               mov eax, dword ptr [edx + 0x18]
// 0089b2d6  6a00                 push 0
// 0089b2d8  6a08                 push 8
// 0089b2da  8bcf                 mov ecx, edi
// 0089b2dc  ffd0                 call eax
// 0089b2de  5f                   pop edi
// 0089b2df  5e                   pop esi
// 0089b2e0  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?EndScroll@CXTPScrollBase@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
