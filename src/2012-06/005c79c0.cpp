// roc 2012-06 005c79c0  unit: RakNet::RakPeer  size: 275 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c79c0
//
// 005c79c0  53                   push ebx
// 005c79c1  55                   push ebp
// 005c79c2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005c79c6  837d00ff             cmp dword ptr [ebp], -1
// 005c79ca  56                   push esi
// 005c79cb  57                   push edi
// 005c79cc  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005c79d0  8d7708               lea esi, [edi + 8]
// 005c79d3  8d9f34060000         lea ebx, [edi + 0x634]
// 005c79d9  7d0d                 jge 0x5c79e8
// 005c79db  6805110000           push 0x1105
// 005c79e0  e89bffffff           call 0x5c7980
// 005c79e5  83c404               add esp, 4
// 005c79e8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005c79ec  c745006f020000       mov dword ptr [ebp], 0x26f
// 005c79f3  8d4704               lea eax, [edi + 4]
// 005c79f6  8901                 mov dword ptr [ecx], eax
// 005c79f8  8b0f                 mov ecx, dword ptr [edi]
// 005c79fa  8b00                 mov eax, dword ptr [eax]
// 005c79fc  8bd3                 mov edx, ebx
// 005c79fe  bde3000000           mov ebp, 0xe3
// 005c7a03  2bd6                 sub edx, esi
// 005c7a05  8bd8                 mov ebx, eax
// 005c7a07  33d9                 xor ebx, ecx
// 005c7a09  81e3feffff7f         and ebx, 0x7ffffffe
// 005c7a0f  33d9                 xor ebx, ecx
// 005c7a11  8bc8                 mov ecx, eax
// 005c7a13  80e101               and cl, 1
// 005c7a16  0fb6c9               movzx ecx, cl
// 005c7a19  d1eb                 shr ebx, 1
// 005c7a1b  f7d9                 neg ecx
// 005c7a1d  1bc9                 sbb ecx, ecx
// 005c7a1f  81e1dfb00899         and ecx, 0x9908b0df
// 005c7a25  33d9                 xor ebx, ecx
// 005c7a27  331c32               xor ebx, dword ptr [edx + esi]
// 005c7a2a  8bc8                 mov ecx, eax
// 005c7a2c  891f                 mov dword ptr [edi], ebx
// 005c7a2e  8b06                 mov eax, dword ptr [esi]
// 005c7a30  83c704               add edi, 4
// 005c7a33  83c604               add esi, 4
// 005c7a36  83ed01               sub ebp, 1
// 005c7a39  75ca                 jne 0x5c7a05
// 005c7a3b  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005c7a3f  bd8c010000           mov ebp, 0x18c
// 005c7a44  8bd0                 mov edx, eax
// 005c7a46  33d1                 xor edx, ecx
// 005c7a48  81e2feffff7f         and edx, 0x7ffffffe
// 005c7a4e  33d1                 xor edx, ecx
// 005c7a50  8bc8                 mov ecx, eax
// 005c7a52  80e101               and cl, 1
// 005c7a55  0fb6c9               movzx ecx, cl
// 005c7a58  d1ea                 shr edx, 1
// 005c7a5a  f7d9                 neg ecx
// 005c7a5c  1bc9                 sbb ecx, ecx
// 005c7a5e  81e1dfb00899         and ecx, 0x9908b0df
// 005c7a64  33d1                 xor edx, ecx
// 005c7a66  3313                 xor edx, dword ptr [ebx]
// 005c7a68  8bc8                 mov ecx, eax
// 005c7a6a  8917                 mov dword ptr [edi], edx
// 005c7a6c  8b06                 mov eax, dword ptr [esi]
// 005c7a6e  83c704               add edi, 4
// 005c7a71  83c304               add ebx, 4
// 005c7a74  83c604               add esi, 4
// 005c7a77  83ed01               sub ebp, 1
// 005c7a7a  75c8                 jne 0x5c7a44
// 005c7a7c  8b542414             mov edx, dword ptr [esp + 0x14]
// 005c7a80  8b12                 mov edx, dword ptr [edx]
// 005c7a82  8bc2                 mov eax, edx
// 005c7a84  33c1                 xor eax, ecx
// 005c7a86  25feffff7f           and eax, 0x7ffffffe
// 005c7a8b  33c1                 xor eax, ecx
// 005c7a8d  8bca                 mov ecx, edx
// 005c7a8f  80e101               and cl, 1
// 005c7a92  d1e8                 shr eax, 1
// 005c7a94  0fb6c9               movzx ecx, cl
// 005c7a97  f7d9                 neg ecx
// 005c7a99  1bc9                 sbb ecx, ecx
// 005c7a9b  81e1dfb00899         and ecx, 0x9908b0df
// 005c7aa1  33c1                 xor eax, ecx
// 005c7aa3  3303                 xor eax, dword ptr [ebx]
// 005c7aa5  8907                 mov dword ptr [edi], eax
// 005c7aa7  8bc2                 mov eax, edx
// 005c7aa9  c1e80b               shr eax, 0xb
// 005c7aac  33d0                 xor edx, eax
// 005c7aae  8bca                 mov ecx, edx
// 005c7ab0  81e1ad583aff         and ecx, 0xff3a58ad
// 005c7ab6  c1e107               shl ecx, 7
// 005c7ab9  33d1                 xor edx, ecx
// 005c7abb  8bc2                 mov eax, edx
// 005c7abd  258cdfffff           and eax, 0xffffdf8c
// 005c7ac2  c1e00f               shl eax, 0xf
// 005c7ac5  33d0                 xor edx, eax
// 005c7ac7  5f                   pop edi
// 005c7ac8  5e                   pop esi
// 005c7ac9  8bc2                 mov eax, edx
// 005c7acb  c1e812               shr eax, 0x12
// 005c7ace  5d                   pop ebp
// 005c7acf  33c2                 xor eax, edx
// 005c7ad1  5b                   pop ebx
// 005c7ad2  c3                   ret 
// copied from an identical function in another client (function ?reloadMT@@YAIPAIAAPAIAAH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp