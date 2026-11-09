// from server: 100% by auto
// roc 2008-06 00612710  unit: seg_00610000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612710
//
// 00612710  8b442408             mov eax, dword ptr [esp + 8]
// 00612714  53                   push ebx
// 00612715  56                   push esi
// 00612716  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0061271a  57                   push edi
// 0061271b  8bce                 mov ecx, esi
// 0061271d  e86ef3ffff           call 0x611a90
// 00612722  8b7e08               mov edi, dword ptr [esi + 8]
// 00612725  8bd8                 mov ebx, eax
// 00612727  8b0b                 mov ecx, dword ptr [ebx]
// 00612729  8d47e0               lea eax, [edi - 0x20]
// 0061272c  50                   push eax
// 0061272d  51                   push ecx
// 0061272e  56                   push esi
// 0061272f  e81cc40400           call 0x65eb50
// 00612734  8b57f0               mov edx, dword ptr [edi - 0x10]
// 00612737  8910                 mov dword ptr [eax], edx
// 00612739  8b4ff4               mov ecx, dword ptr [edi - 0xc]
// 0061273c  894804               mov dword ptr [eax + 4], ecx
// 0061273f  8b57f8               mov edx, dword ptr [edi - 8]
// 00612742  895008               mov dword ptr [eax + 8], edx
// 00612745  8b4608               mov eax, dword ptr [esi + 8]
// 00612748  b904000000           mov ecx, 4
// 0061274d  83c40c               add esp, 0xc
// 00612750  3948f8               cmp dword ptr [eax - 8], ecx
// 00612753  7c1a                 jl 0x61276f
// 00612755  8b40f0               mov eax, dword ptr [eax - 0x10]
// 00612758  f6400503             test byte ptr [eax + 5], 3
// 0061275c  7411                 je 0x61276f
// 0061275e  8b1b                 mov ebx, dword ptr [ebx]
// 00612760  844b05               test byte ptr [ebx + 5], cl
// 00612763  740a                 je 0x61276f
// 00612765  53                   push ebx
// 00612766  56                   push esi
// 00612767  e8549d0400           call 0x65c4c0
// 0061276c  83c408               add esp, 8
// 0061276f  834608e0             add dword ptr [esi + 8], -0x20
// 00612773  5f                   pop edi
// 00612774  5e                   pop esi
// 00612775  5b                   pop ebx
// 00612776  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawset)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
