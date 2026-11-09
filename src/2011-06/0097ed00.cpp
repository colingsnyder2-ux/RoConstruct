// from server: 100% by auto
// roc 2011-06 0097ed00  unit: RBX::BeveledBlockBuilder  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0097ed00
//
// 0097ed00  51                   push ecx
// 0097ed01  8b542410             mov edx, dword ptr [esp + 0x10]
// 0097ed05  56                   push esi
// 0097ed06  8b742410             mov esi, dword ptr [esp + 0x10]
// 0097ed0a  57                   push edi
// 0097ed0b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0097ed0f  c644240800           mov byte ptr [esp + 8], 0
// 0097ed14  8b442408             mov eax, dword ptr [esp + 8]
// 0097ed18  50                   push eax
// 0097ed19  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0097ed1d  52                   push edx
// 0097ed1e  51                   push ecx
// 0097ed1f  50                   push eax
// 0097ed20  56                   push esi
// 0097ed21  57                   push edi
// 0097ed22  e879ffffff           call 0x97eca0
// 0097ed27  8d0c76               lea ecx, [esi + esi*2]
// 0097ed2a  83c418               add esp, 0x18
// 0097ed2d  8d04cf               lea eax, [edi + ecx*8]
// 0097ed30  5f                   pop edi
// 0097ed31  5e                   pop esi
// 0097ed32  59                   pop ecx
// 0097ed33  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
