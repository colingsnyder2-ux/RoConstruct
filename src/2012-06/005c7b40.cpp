// roc 2012-06 005c7b40  unit: RakNet::RakPeer  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c7b40
//
// 005c7b40  832d0c16d90001       sub dword ptr [0xd9160c], 1
// 005c7b47  7918                 jns 0x5c7b61
// 005c7b49  680c16d900           push 0xd9160c
// 005c7b4e  686069e200           push 0xe26960
// 005c7b53  686869e200           push 0xe26968
// 005c7b58  e863feffff           call 0x5c79c0
// 005c7b5d  83c40c               add esp, 0xc
// 005c7b60  c3                   ret 
// 005c7b61  a16069e200           mov eax, dword ptr [0xe26960]
// 005c7b66  8b08                 mov ecx, dword ptr [eax]
// 005c7b68  83c004               add eax, 4
// 005c7b6b  a36069e200           mov dword ptr [0xe26960], eax
// 005c7b70  8bc1                 mov eax, ecx
// 005c7b72  c1e80b               shr eax, 0xb
// 005c7b75  33c8                 xor ecx, eax
// 005c7b77  8bd1                 mov edx, ecx
// 005c7b79  81e2ad583aff         and edx, 0xff3a58ad
// 005c7b7f  c1e207               shl edx, 7
// 005c7b82  33ca                 xor ecx, edx
// 005c7b84  8bc1                 mov eax, ecx
// 005c7b86  258cdfffff           and eax, 0xffffdf8c
// 005c7b8b  c1e00f               shl eax, 0xf
// 005c7b8e  33c8                 xor ecx, eax
// 005c7b90  8bc1                 mov eax, ecx
// 005c7b92  c1e812               shr eax, 0x12
// 005c7b95  33c1                 xor eax, ecx
// 005c7b97  c3                   ret 
// copied from an identical function in another client (function ?randomMT@@YAIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Rand.cpp