// from server: 100% by auto
// roc 2009-12 0052ef80  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052ef80
//
// 0052ef80  56                   push esi
// 0052ef81  6a01                 push 1
// 0052ef83  8bf1                 mov esi, ecx
// 0052ef85  e8c6fdffff           call 0x52ed50
// 0052ef8a  8b06                 mov eax, dword ptr [esi]
// 0052ef8c  a807                 test al, 7
// 0052ef8e  750a                 jne 0x52ef9a
// 0052ef90  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0052ef93  c1e803               shr eax, 3
// 0052ef96  c6040800             mov byte ptr [eax + ecx], 0
// 0052ef9a  ff06                 inc dword ptr [esi]
// 0052ef9c  5e                   pop esi
// 0052ef9d  c3                   ret 
// library raknet-4.081/BitStream.cpp (function ?Write0@BitStream@RakNet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
