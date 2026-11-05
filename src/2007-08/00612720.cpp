// from server: 100% by auto
// roc 2007-08 00612720  unit: seg_00610000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612720
//
// 00612720  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00612724  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 00612727  85c0                 test eax, eax
// 00612729  56                   push esi
// 0061272a  763c                 jbe 0x612768
// 0061272c  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0061272f  8bd0                 mov edx, eax
// 00612731  c1e204               shl edx, 4
// 00612734  837c32f800           cmp dword ptr [edx + esi - 8], 0
// 00612739  752d                 jne 0x612768
// 0061273b  33d2                 xor edx, edx
// 0061273d  83f801               cmp eax, 1
// 00612740  7622                 jbe 0x612764
// 00612742  57                   push edi
// 00612743  8d0c02               lea ecx, [edx + eax]
// 00612746  d1e9                 shr ecx, 1
// 00612748  8bf9                 mov edi, ecx
// 0061274a  c1e704               shl edi, 4
// 0061274d  837c37f800           cmp dword ptr [edi + esi - 8], 0
// 00612752  7504                 jne 0x612758
// 00612754  8bc1                 mov eax, ecx
// 00612756  eb02                 jmp 0x61275a
// 00612758  8bd1                 mov edx, ecx
// 0061275a  8bc8                 mov ecx, eax
// 0061275c  2bca                 sub ecx, edx
// 0061275e  83f901               cmp ecx, 1
// 00612761  77e0                 ja 0x612743
// 00612763  5f                   pop edi
// 00612764  8bc2                 mov eax, edx
// 00612766  5e                   pop esi
// 00612767  c3                   ret 
// 00612768  817910b8327c00       cmp dword ptr [ecx + 0x10], 0x7c32b8
// 0061276f  74f5                 je 0x612766
// 00612771  5e                   pop esi
// 00612772  894c2404             mov dword ptr [esp + 4], ecx
// 00612776  e905ffffff           jmp 0x612680
// library lua-5.1/ltable.c (function _luaH_getn)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
