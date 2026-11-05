// roc 2012-06 00567b70  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567b70
//
// 00567b70  56                   push esi
// 00567b71  6a08                 push 8
// 00567b73  8bf1                 mov esi, ecx
// 00567b75  e8f6fdffff           call 0x567970
// 00567b7a  8b06                 mov eax, dword ptr [esi]
// 00567b7c  8b542408             mov edx, dword ptr [esp + 8]
// 00567b80  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00567b83  8a12                 mov dl, byte ptr [edx]
// 00567b85  c1e803               shr eax, 3
// 00567b88  881408               mov byte ptr [eax + ecx], dl
// 00567b8b  830608               add dword ptr [esi], 8
// 00567b8e  5e                   pop esi
// 00567b8f  c20400               ret 4
// copied from an identical function in another client (function ?WriteAlignedVar8@BitStream@RakNet@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp