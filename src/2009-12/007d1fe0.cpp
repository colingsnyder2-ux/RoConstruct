// from server: 100% by auto
// roc 2009-12 007d1fe0  unit: seg_007d0000  size: 465 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1fe0
//
// 007d1fe0  53                   push ebx
// 007d1fe1  55                   push ebp
// 007d1fe2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007d1fe6  8b5d34               mov ebx, dword ptr [ebp + 0x34]
// 007d1fe9  56                   push esi
// 007d1fea  57                   push edi
// 007d1feb  8b7d30               mov edi, dword ptr [ebp + 0x30]
// 007d1fee  8b37                 mov esi, dword ptr [edi]
// 007d1ff0  33d2                 xor edx, edx
// 007d1ff2  8bc5                 mov eax, ebp
// 007d1ff4  e8b7faffff           call 0x7d1ab0
// 007d1ff9  52                   push edx
// 007d1ffa  52                   push edx
// 007d1ffb  57                   push edi
// 007d1ffc  e8cfa70000           call 0x7dc7d0
// 007d2001  8b4718               mov eax, dword ptr [edi + 0x18]
// 007d2004  8d4801               lea ecx, [eax + 1]
// 007d2007  83c40c               add esp, 0xc
// 007d200a  81f9ffffff3f         cmp ecx, 0x3fffffff
// 007d2010  771f                 ja 0x7d2031
// 007d2012  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d2015  8d148500000000       lea edx, [eax*4]
// 007d201c  8b462c               mov eax, dword ptr [esi + 0x2c]
// 007d201f  52                   push edx
// 007d2020  03c0                 add eax, eax
// 007d2022  03c0                 add eax, eax
// 007d2024  50                   push eax
// 007d2025  51                   push ecx
// 007d2026  53                   push ebx
// 007d2027  e884f7ffff           call 0x7d17b0
// 007d202c  83c410               add esp, 0x10
// 007d202f  eb09                 jmp 0x7d203a
// 007d2031  53                   push ebx
// 007d2032  e859f7ffff           call 0x7d1790
// 007d2037  83c404               add esp, 4
// 007d203a  89460c               mov dword ptr [esi + 0xc], eax
// 007d203d  8b5718               mov edx, dword ptr [edi + 0x18]
// 007d2040  89562c               mov dword ptr [esi + 0x2c], edx
// 007d2043  8b4718               mov eax, dword ptr [edi + 0x18]
// 007d2046  40                   inc eax
// 007d2047  3dffffff3f           cmp eax, 0x3fffffff
// 007d204c  771f                 ja 0x7d206d
// 007d204e  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007d2051  8b5630               mov edx, dword ptr [esi + 0x30]
// 007d2054  8b4614               mov eax, dword ptr [esi + 0x14]
// 007d2057  03c9                 add ecx, ecx
// 007d2059  03c9                 add ecx, ecx
// 007d205b  51                   push ecx
// 007d205c  03d2                 add edx, edx
// 007d205e  03d2                 add edx, edx
// 007d2060  52                   push edx
// 007d2061  50                   push eax
// 007d2062  53                   push ebx
// 007d2063  e848f7ffff           call 0x7d17b0
// 007d2068  83c410               add esp, 0x10
// 007d206b  eb09                 jmp 0x7d2076
// 007d206d  53                   push ebx
// 007d206e  e81df7ffff           call 0x7d1790
// 007d2073  83c404               add esp, 4
// 007d2076  894614               mov dword ptr [esi + 0x14], eax
// 007d2079  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007d207c  894e30               mov dword ptr [esi + 0x30], ecx
// 007d207f  8b4728               mov eax, dword ptr [edi + 0x28]
// 007d2082  8d5001               lea edx, [eax + 1]
// 007d2085  81faffffff0f         cmp edx, 0xfffffff
// 007d208b  771a                 ja 0x7d20a7
// 007d208d  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d2090  c1e004               shl eax, 4
// 007d2093  50                   push eax
// 007d2094  8b4628               mov eax, dword ptr [esi + 0x28]
// 007d2097  c1e004               shl eax, 4
// 007d209a  50                   push eax
// 007d209b  51                   push ecx
// 007d209c  53                   push ebx
// 007d209d  e80ef7ffff           call 0x7d17b0
// 007d20a2  83c410               add esp, 0x10
// 007d20a5  eb09                 jmp 0x7d20b0
// 007d20a7  53                   push ebx
// 007d20a8  e8e3f6ffff           call 0x7d1790
// 007d20ad  83c404               add esp, 4
// 007d20b0  894608               mov dword ptr [esi + 8], eax
// 007d20b3  8b5728               mov edx, dword ptr [edi + 0x28]
// 007d20b6  895628               mov dword ptr [esi + 0x28], edx
// 007d20b9  8b472c               mov eax, dword ptr [edi + 0x2c]
// 007d20bc  8d4801               lea ecx, [eax + 1]
// 007d20bf  81f9ffffff3f         cmp ecx, 0x3fffffff
// 007d20c5  771f                 ja 0x7d20e6
// 007d20c7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007d20ca  8d148500000000       lea edx, [eax*4]
// 007d20d1  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d20d4  52                   push edx
// 007d20d5  03c0                 add eax, eax
// 007d20d7  03c0                 add eax, eax
// 007d20d9  50                   push eax
// 007d20da  51                   push ecx
// 007d20db  53                   push ebx
// 007d20dc  e8cff6ffff           call 0x7d17b0
// 007d20e1  83c410               add esp, 0x10
// 007d20e4  eb09                 jmp 0x7d20ef
// 007d20e6  53                   push ebx
// 007d20e7  e8a4f6ffff           call 0x7d1790
// 007d20ec  83c404               add esp, 4
// 007d20ef  894610               mov dword ptr [esi + 0x10], eax
// 007d20f2  8b572c               mov edx, dword ptr [edi + 0x2c]
// 007d20f5  895634               mov dword ptr [esi + 0x34], edx
// 007d20f8  0fbf4730             movsx eax, word ptr [edi + 0x30]
// 007d20fc  8d4801               lea ecx, [eax + 1]
// 007d20ff  81f955555515         cmp ecx, 0x15555555
// 007d2105  7722                 ja 0x7d2129
// 007d2107  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007d210a  8d1440               lea edx, [eax + eax*2]
// 007d210d  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d2110  8d0440               lea eax, [eax + eax*2]
// 007d2113  03d2                 add edx, edx
// 007d2115  03d2                 add edx, edx
// 007d2117  52                   push edx
// 007d2118  03c0                 add eax, eax
// 007d211a  03c0                 add eax, eax
// 007d211c  50                   push eax
// 007d211d  51                   push ecx
// 007d211e  53                   push ebx
// 007d211f  e88cf6ffff           call 0x7d17b0
// 007d2124  83c410               add esp, 0x10
// 007d2127  eb09                 jmp 0x7d2132
// 007d2129  53                   push ebx
// 007d212a  e861f6ffff           call 0x7d1790
// 007d212f  83c404               add esp, 4
// 007d2132  894618               mov dword ptr [esi + 0x18], eax
// 007d2135  0fb64648             movzx eax, byte ptr [esi + 0x48]
// 007d2139  0fbf5730             movsx edx, word ptr [edi + 0x30]
// 007d213d  8d4801               lea ecx, [eax + 1]
// 007d2140  895638               mov dword ptr [esi + 0x38], edx
// 007d2143  81f9ffffff3f         cmp ecx, 0x3fffffff
// 007d2149  771f                 ja 0x7d216a
// 007d214b  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 007d214e  8d148500000000       lea edx, [eax*4]
// 007d2155  8b4624               mov eax, dword ptr [esi + 0x24]
// 007d2158  52                   push edx
// 007d2159  03c0                 add eax, eax
// 007d215b  03c0                 add eax, eax
// 007d215d  50                   push eax
// 007d215e  51                   push ecx
// 007d215f  53                   push ebx
// 007d2160  e84bf6ffff           call 0x7d17b0
// 007d2165  83c410               add esp, 0x10
// 007d2168  eb09                 jmp 0x7d2173
// 007d216a  53                   push ebx
// 007d216b  e820f6ffff           call 0x7d1790
// 007d2170  83c404               add esp, 4
// 007d2173  0fb65648             movzx edx, byte ptr [esi + 0x48]
// 007d2177  89461c               mov dword ptr [esi + 0x1c], eax
// 007d217a  895624               mov dword ptr [esi + 0x24], edx
// 007d217d  8b4708               mov eax, dword ptr [edi + 8]
// 007d2180  894530               mov dword ptr [ebp + 0x30], eax
// 007d2183  834308e0             add dword ptr [ebx + 8], -0x20
// 007d2187  8b4510               mov eax, dword ptr [ebp + 0x10]
// 007d218a  3d1d010000           cmp eax, 0x11d
// 007d218f  7407                 je 0x7d2198
// 007d2191  3d1e010000           cmp eax, 0x11e
// 007d2196  7514                 jne 0x7d21ac
// 007d2198  8b4518               mov eax, dword ptr [ebp + 0x18]
// 007d219b  8b480c               mov ecx, dword ptr [eax + 0xc]
// 007d219e  51                   push ecx
// 007d219f  83c010               add eax, 0x10
// 007d21a2  50                   push eax
// 007d21a3  55                   push ebp
// 007d21a4  e8b7310000           call 0x7d5360
// 007d21a9  83c40c               add esp, 0xc
// 007d21ac  5f                   pop edi
// 007d21ad  5e                   pop esi
// 007d21ae  5d                   pop ebp
// 007d21af  5b                   pop ebx
// 007d21b0  c3                   ret 
// library lua-5.1/lparser.c (function _close_func)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
