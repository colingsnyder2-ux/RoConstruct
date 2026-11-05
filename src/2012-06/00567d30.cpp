// roc 2012-06 00567d30  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567d30
//
// 00567d30  56                   push esi
// 00567d31  6a01                 push 1
// 00567d33  8bf1                 mov esi, ecx
// 00567d35  e836fcffff           call 0x567970
// 00567d3a  8b06                 mov eax, dword ptr [esi]
// 00567d3c  a807                 test al, 7
// 00567d3e  750a                 jne 0x567d4a
// 00567d40  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00567d43  c1e803               shr eax, 3
// 00567d46  c6040800             mov byte ptr [eax + ecx], 0
// 00567d4a  ff06                 inc dword ptr [esi]
// 00567d4c  5e                   pop esi
// 00567d4d  c3                   ret 
// copied from an identical function in another client (function ?Write0@BitStream@RakNet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp