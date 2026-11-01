// from server: 100% by auto
// roc 2007-03 005b9550  unit: seg_005b0000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9550
//
// 005b9550  8b442408             mov eax, dword ptr [esp + 8]
// 005b9554  53                   push ebx
// 005b9555  56                   push esi
// 005b9556  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b955a  57                   push edi
// 005b955b  8bce                 mov ecx, esi
// 005b955d  e84ef3ffff           call 0x5b88b0
// 005b9562  8b7e08               mov edi, dword ptr [esi + 8]
// 005b9565  8bd8                 mov ebx, eax
// 005b9567  8b0b                 mov ecx, dword ptr [ebx]
// 005b9569  8d47e0               lea eax, [edi - 0x20]
// 005b956c  50                   push eax
// 005b956d  51                   push ecx
// 005b956e  56                   push esi
// 005b956f  e8fc290400           call 0x5fbf70
// 005b9574  8b57f0               mov edx, dword ptr [edi - 0x10]
// 005b9577  8910                 mov dword ptr [eax], edx
// 005b9579  8b4ff4               mov ecx, dword ptr [edi - 0xc]
// 005b957c  894804               mov dword ptr [eax + 4], ecx
// 005b957f  8b57f8               mov edx, dword ptr [edi - 8]
// 005b9582  895008               mov dword ptr [eax + 8], edx
// 005b9585  8b4608               mov eax, dword ptr [esi + 8]
// 005b9588  b904000000           mov ecx, 4
// 005b958d  83c40c               add esp, 0xc
// 005b9590  3948f8               cmp dword ptr [eax - 8], ecx
// 005b9593  7c1a                 jl 0x5b95af
// 005b9595  8b40f0               mov eax, dword ptr [eax - 0x10]
// 005b9598  f6400503             test byte ptr [eax + 5], 3
// 005b959c  7411                 je 0x5b95af
// 005b959e  8b1b                 mov ebx, dword ptr [ebx]
// 005b95a0  844b05               test byte ptr [ebx + 5], cl
// 005b95a3  740a                 je 0x5b95af
// 005b95a5  53                   push ebx
// 005b95a6  56                   push esi
// 005b95a7  e834030400           call 0x5f98e0
// 005b95ac  83c408               add esp, 8
// 005b95af  834608e0             add dword ptr [esi + 8], -0x20
// 005b95b3  5f                   pop edi
// 005b95b4  5e                   pop esi
// 005b95b5  5b                   pop ebx
// 005b95b6  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_rawset)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
