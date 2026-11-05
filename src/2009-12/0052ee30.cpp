// from server: 100% by auto
// roc 2009-12 0052ee30  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052ee30
//
// 0052ee30  8b442404             mov eax, dword ptr [esp + 4]
// 0052ee34  014108               add dword ptr [ecx + 8], eax
// 0052ee37  c20400               ret 4
// library raknet-4.081/BitStream.cpp (function ?IgnoreBits@BitStream@RakNet@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
