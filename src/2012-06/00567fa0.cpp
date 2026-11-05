// roc 2012-06 00567fa0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567fa0
//
// 00567fa0  8b01                 mov eax, dword ptr [ecx]
// 00567fa2  8d50ff               lea edx, [eax - 1]
// 00567fa5  83e207               and edx, 7
// 00567fa8  2bc2                 sub eax, edx
// 00567faa  83c007               add eax, 7
// 00567fad  8901                 mov dword ptr [ecx], eax
// 00567faf  e95cffffff           jmp 0x567f10
// copied from an identical function in another client (function ?WriteAlignedBytes@BitStream@RakNet@@QAEXPBEI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp