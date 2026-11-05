// roc 2012-06 005e0710  unit: RBX::BeveledBlockBuilder  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005e0710
//
// 005e0710  51                   push ecx
// 005e0711  8b542410             mov edx, dword ptr [esp + 0x10]
// 005e0715  56                   push esi
// 005e0716  8b742410             mov esi, dword ptr [esp + 0x10]
// 005e071a  57                   push edi
// 005e071b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005e071f  c644240800           mov byte ptr [esp + 8], 0
// 005e0724  8b442408             mov eax, dword ptr [esp + 8]
// 005e0728  50                   push eax
// 005e0729  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005e072d  52                   push edx
// 005e072e  51                   push ecx
// 005e072f  50                   push eax
// 005e0730  56                   push esi
// 005e0731  57                   push edi
// 005e0732  e889ffffff           call 0x5e06c0
// 005e0737  8d0c76               lea ecx, [esi + esi*2]
// 005e073a  83c418               add esp, 0x18
// 005e073d  8d04cf               lea eax, [edi + ecx*8]
// 005e0740  5f                   pop edi
// 005e0741  5e                   pop esi
// 005e0742  59                   pop ecx
// 005e0743  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
