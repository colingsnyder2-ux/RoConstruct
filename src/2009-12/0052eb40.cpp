// from server: 100% by auto
// roc 2009-12 0052eb40  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052eb40
//
// 0052eb40  c70100000000         mov dword ptr [ecx], 0
// 0052eb46  c7410800000000       mov dword ptr [ecx + 8], 0
// 0052eb4d  c3                   ret 
// library raknet-4.081/BitStream.cpp (function ?Reset@BitStream@RakNet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
