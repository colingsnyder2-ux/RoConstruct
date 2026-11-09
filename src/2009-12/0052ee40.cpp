// from server: 100% by auto
// roc 2009-12 0052ee40  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052ee40
//
// 0052ee40  8b442404             mov eax, dword ptr [esp + 4]
// 0052ee44  8d14c500000000       lea edx, [eax*8]
// 0052ee4b  015108               add dword ptr [ecx + 8], edx
// 0052ee4e  c20400               ret 4
// library raknet-4.081/BitStream.cpp (function ?IgnoreBytes@BitStream@RakNet@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
