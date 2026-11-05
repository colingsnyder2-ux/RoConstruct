// roc 2012-06 00567d50  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567d50
//
// 00567d50  56                   push esi
// 00567d51  6a01                 push 1
// 00567d53  8bf1                 mov esi, ecx
// 00567d55  e816fcffff           call 0x567970
// 00567d5a  8b06                 mov eax, dword ptr [esi]
// 00567d5c  8bc8                 mov ecx, eax
// 00567d5e  c1e803               shr eax, 3
// 00567d61  83e107               and ecx, 7
// 00567d64  750b                 jne 0x567d71
// 00567d66  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00567d69  c6040880             mov byte ptr [eax + ecx], 0x80
// 00567d6d  ff06                 inc dword ptr [esi]
// 00567d6f  5e                   pop esi
// 00567d70  c3                   ret 
// 00567d71  8b560c               mov edx, dword ptr [esi + 0xc]
// 00567d74  03c2                 add eax, edx
// 00567d76  ba80000000           mov edx, 0x80
// 00567d7b  d3fa                 sar edx, cl
// 00567d7d  0810                 or byte ptr [eax], dl
// 00567d7f  ff06                 inc dword ptr [esi]
// 00567d81  5e                   pop esi
// 00567d82  c3                   ret 
// copied from an identical function in another client (function ?Write1@BitStream@RakNet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp