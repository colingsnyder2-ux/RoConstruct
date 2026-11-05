// from server: 100% by auto
// roc 2009-12 00570170  unit: CSHA1  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00570170
//
// 00570170  53                   push ebx
// 00570171  55                   push ebp
// 00570172  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00570176  837d00ff             cmp dword ptr [ebp], -1
// 0057017a  56                   push esi
// 0057017b  57                   push edi
// 0057017c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00570180  8d7708               lea esi, [edi + 8]
// 00570183  8d9f34060000         lea ebx, [edi + 0x634]
// 00570189  7d0d                 jge 0x570198
// 0057018b  6805110000           push 0x1105
// 00570190  e89bffffff           call 0x570130
// 00570195  83c404               add esp, 4
// 00570198  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057019c  c745006f020000       mov dword ptr [ebp], 0x26f
// 005701a3  8d4704               lea eax, [edi + 4]
// 005701a6  8901                 mov dword ptr [ecx], eax
// 005701a8  8b0f                 mov ecx, dword ptr [edi]
// 005701aa  8b00                 mov eax, dword ptr [eax]
// 005701ac  8bd3                 mov edx, ebx
// 005701ae  bde3000000           mov ebp, 0xe3
// 005701b3  2bd6                 sub edx, esi
// 005701b5  8bd8                 mov ebx, eax
// 005701b7  33d9                 xor ebx, ecx
// 005701b9  81e3feffff7f         and ebx, 0x7ffffffe
// 005701bf  33d9                 xor ebx, ecx
// 005701c1  8bc8                 mov ecx, eax
// 005701c3  80e101               and cl, 1
// 005701c6  0fb6c9               movzx ecx, cl
// 005701c9  d1eb                 shr ebx, 1
// 005701cb  f7d9                 neg ecx
// 005701cd  1bc9                 sbb ecx, ecx
// 005701cf  81e1dfb00899         and ecx, 0x9908b0df
// 005701d5  33d9                 xor ebx, ecx
// 005701d7  331c32               xor ebx, dword ptr [edx + esi]
// 005701da  8bc8                 mov ecx, eax
// 005701dc  891f                 mov dword ptr [edi], ebx
// 005701de  8b06                 mov eax, dword ptr [esi]
// 005701e0  83c704               add edi, 4
// 005701e3  83c604               add esi, 4
// 005701e6  83ed01               sub ebp, 1
// 005701e9  75ca                 jne 0x5701b5
// 005701eb  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005701ef  bd8c010000           mov ebp, 0x18c
// 005701f4  8bd0                 mov edx, eax
// 005701f6  33d1                 xor edx, ecx
// 005701f8  81e2feffff7f         and edx, 0x7ffffffe
// 005701fe  33d1                 xor edx, ecx
// 00570200  8bc8                 mov ecx, eax
// 00570202  80e101               and cl, 1
// 00570205  0fb6c9               movzx ecx, cl
// 00570208  d1ea                 shr edx, 1
// 0057020a  f7d9                 neg ecx
// 0057020c  1bc9                 sbb ecx, ecx
// 0057020e  81e1dfb00899         and ecx, 0x9908b0df
// 00570214  33d1                 xor edx, ecx
// 00570216  3313                 xor edx, dword ptr [ebx]
// 00570218  8bc8                 mov ecx, eax
// 0057021a  8917                 mov dword ptr [edi], edx
// 0057021c  8b06                 mov eax, dword ptr [esi]
// 0057021e  83c704               add edi, 4
// 00570221  83c304               add ebx, 4
// 00570224  83c604               add esi, 4
// 00570227  83ed01               sub ebp, 1
// 0057022a  75c8                 jne 0x5701f4
// 0057022c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00570230  8b12                 mov edx, dword ptr [edx]
// 00570232  8bc2                 mov eax, edx
// 00570234  33c1                 xor eax, ecx
// 00570236  25feffff7f           and eax, 0x7ffffffe
// 0057023b  33c1                 xor eax, ecx
// 0057023d  8bca                 mov ecx, edx
// 0057023f  80e101               and cl, 1
// 00570242  d1e8                 shr eax, 1
// 00570244  0fb6c9               movzx ecx, cl
// 00570247  f7d9                 neg ecx
// 00570249  1bc9                 sbb ecx, ecx
// 0057024b  81e1dfb00899         and ecx, 0x9908b0df
// 00570251  33c1                 xor eax, ecx
// 00570253  3303                 xor eax, dword ptr [ebx]
// 00570255  8907                 mov dword ptr [edi], eax
// 00570257  8bc2                 mov eax, edx
// 00570259  c1e80b               shr eax, 0xb
// 0057025c  33d0                 xor edx, eax
// 0057025e  8bca                 mov ecx, edx
// 00570260  81e1ad583aff         and ecx, 0xff3a58ad
// 00570266  c1e107               shl ecx, 7
// 00570269  33d1                 xor edx, ecx
// 0057026b  8bc2                 mov eax, edx
// 0057026d  258cdfffff           and eax, 0xffffdf8c
// 00570272  c1e00f               shl eax, 0xf
// 00570275  33d0                 xor edx, eax
// 00570277  5f                   pop edi
// 00570278  5e                   pop esi
// 00570279  8bc2                 mov eax, edx
// 0057027b  c1e812               shr eax, 0x12
// 0057027e  5d                   pop ebp
// 0057027f  33c2                 xor eax, edx
// 00570281  5b                   pop ebx
// 00570282  c3                   ret 
// library raknet-4.081/Rand.cpp (function ?reloadMT@@YAIPAIAAPAIAAH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp
