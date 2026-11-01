// from server: 100% by auto
// roc 2009-12 005702f0  unit: CSHA1  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005702f0
//
// 005702f0  832dec08b20001       sub dword ptr [0xb208ec], 1
// 005702f7  7918                 jns 0x570311
// 005702f9  68ec08b200           push 0xb208ec
// 005702fe  68481db800           push 0xb81d48
// 00570303  68501db800           push 0xb81d50
// 00570308  e863feffff           call 0x570170
// 0057030d  83c40c               add esp, 0xc
// 00570310  c3                   ret 
// 00570311  a1481db800           mov eax, dword ptr [0xb81d48]
// 00570316  8b08                 mov ecx, dword ptr [eax]
// 00570318  83c004               add eax, 4
// 0057031b  a3481db800           mov dword ptr [0xb81d48], eax
// 00570320  8bc1                 mov eax, ecx
// 00570322  c1e80b               shr eax, 0xb
// 00570325  33c8                 xor ecx, eax
// 00570327  8bd1                 mov edx, ecx
// 00570329  81e2ad583aff         and edx, 0xff3a58ad
// 0057032f  c1e207               shl edx, 7
// 00570332  33ca                 xor ecx, edx
// 00570334  8bc1                 mov eax, ecx
// 00570336  258cdfffff           and eax, 0xffffdf8c
// 0057033b  c1e00f               shl eax, 0xf
// 0057033e  33c8                 xor ecx, eax
// 00570340  8bc1                 mov eax, ecx
// 00570342  c1e812               shr eax, 0x12
// 00570345  33c1                 xor eax, ecx
// 00570347  c3                   ret 
// library raknet-4.081/Rand.cpp (function ?randomMT@@YAIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp
