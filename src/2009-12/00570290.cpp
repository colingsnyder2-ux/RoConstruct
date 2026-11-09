// from server: 100% by auto
// roc 2009-12 00570290  unit: CSHA1  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00570290
//
// 00570290  8381c8090000ff       add dword ptr [ecx + 0x9c8], -1
// 00570297  8d91c8090000         lea edx, [ecx + 0x9c8]
// 0057029d  8d81c4090000         lea eax, [ecx + 0x9c4]
// 005702a3  790c                 jns 0x5702b1
// 005702a5  52                   push edx
// 005702a6  50                   push eax
// 005702a7  51                   push ecx
// 005702a8  e8c3feffff           call 0x570170
// 005702ad  83c40c               add esp, 0xc
// 005702b0  c3                   ret 
// 005702b1  8b10                 mov edx, dword ptr [eax]
// 005702b3  8b0a                 mov ecx, dword ptr [edx]
// 005702b5  83c204               add edx, 4
// 005702b8  8910                 mov dword ptr [eax], edx
// 005702ba  8bc1                 mov eax, ecx
// 005702bc  c1e80b               shr eax, 0xb
// 005702bf  33c8                 xor ecx, eax
// 005702c1  8bd1                 mov edx, ecx
// 005702c3  81e2ad583aff         and edx, 0xff3a58ad
// 005702c9  c1e207               shl edx, 7
// 005702cc  33ca                 xor ecx, edx
// 005702ce  8bc1                 mov eax, ecx
// 005702d0  258cdfffff           and eax, 0xffffdf8c
// 005702d5  c1e00f               shl eax, 0xf
// 005702d8  33c8                 xor ecx, eax
// 005702da  8bc1                 mov eax, ecx
// 005702dc  c1e812               shr eax, 0x12
// 005702df  33c1                 xor eax, ecx
// 005702e1  c3                   ret 
// library raknet-4.081/Rand.cpp (function ?RandomMT@RakNetRandom@RakNet@@QAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp
