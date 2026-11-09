// roc 2012-06 005c7ae0  unit: RakNet::RakPeer  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c7ae0
//
// 005c7ae0  8381c8090000ff       add dword ptr [ecx + 0x9c8], -1
// 005c7ae7  8d91c8090000         lea edx, [ecx + 0x9c8]
// 005c7aed  8d81c4090000         lea eax, [ecx + 0x9c4]
// 005c7af3  790c                 jns 0x5c7b01
// 005c7af5  52                   push edx
// 005c7af6  50                   push eax
// 005c7af7  51                   push ecx
// 005c7af8  e8c3feffff           call 0x5c79c0
// 005c7afd  83c40c               add esp, 0xc
// 005c7b00  c3                   ret 
// 005c7b01  8b10                 mov edx, dword ptr [eax]
// 005c7b03  8b0a                 mov ecx, dword ptr [edx]
// 005c7b05  83c204               add edx, 4
// 005c7b08  8910                 mov dword ptr [eax], edx
// 005c7b0a  8bc1                 mov eax, ecx
// 005c7b0c  c1e80b               shr eax, 0xb
// 005c7b0f  33c8                 xor ecx, eax
// 005c7b11  8bd1                 mov edx, ecx
// 005c7b13  81e2ad583aff         and edx, 0xff3a58ad
// 005c7b19  c1e207               shl edx, 7
// 005c7b1c  33ca                 xor ecx, edx
// 005c7b1e  8bc1                 mov eax, ecx
// 005c7b20  258cdfffff           and eax, 0xffffdf8c
// 005c7b25  c1e00f               shl eax, 0xf
// 005c7b28  33c8                 xor ecx, eax
// 005c7b2a  8bc1                 mov eax, ecx
// 005c7b2c  c1e812               shr eax, 0x12
// 005c7b2f  33c1                 xor eax, ecx
// 005c7b31  c3                   ret 
// copied from an identical function in another client (function ?RandomMT@RakNetRandom@RakNet@@QAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp