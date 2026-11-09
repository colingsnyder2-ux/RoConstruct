// roc 2012-06 005a9f50  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a9f50
//
// 005a9f50  51                   push ecx
// 005a9f51  8b542410             mov edx, dword ptr [esp + 0x10]
// 005a9f55  56                   push esi
// 005a9f56  8b742410             mov esi, dword ptr [esp + 0x10]
// 005a9f5a  57                   push edi
// 005a9f5b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005a9f5f  c644240800           mov byte ptr [esp + 8], 0
// 005a9f64  8b442408             mov eax, dword ptr [esp + 8]
// 005a9f68  50                   push eax
// 005a9f69  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005a9f6d  52                   push edx
// 005a9f6e  51                   push ecx
// 005a9f6f  50                   push eax
// 005a9f70  56                   push esi
// 005a9f71  57                   push edi
// 005a9f72  e869fbffff           call 0x5a9ae0
// 005a9f77  8d0cb6               lea ecx, [esi + esi*4]
// 005a9f7a  83c418               add esp, 0x18
// 005a9f7d  8d04cf               lea eax, [edi + ecx*8]
// 005a9f80  5f                   pop edi
// 005a9f81  5e                   pop esi
// 005a9f82  59                   pop ecx
// 005a9f83  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?_Ufill@?$vector@VVertex@?$ConvexClipper@N@Wml@@V?$allocator@VVertex@?$ConvexClipper@N@Wml@@@std@@@std@@IAEPAVVertex@?$ConvexClipper@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
