// roc 2012-06 00567f80  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567f80
//
// 00567f80  8b442404             mov eax, dword ptr [esp + 4]
// 00567f84  8b10                 mov edx, dword ptr [eax]
// 00567f86  2b5008               sub edx, dword ptr [eax + 8]
// 00567f89  52                   push edx
// 00567f8a  50                   push eax
// 00567f8b  e890fcffff           call 0x567c20
// 00567f90  c20400               ret 4
// copied from an identical function in another client (function ?Write@BitStream@RakNet@@QAEXPAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp