// roc 2012-06 005a9f90  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a9f90
//
// 005a9f90  51                   push ecx
// 005a9f91  8b542410             mov edx, dword ptr [esp + 0x10]
// 005a9f95  56                   push esi
// 005a9f96  8b742410             mov esi, dword ptr [esp + 0x10]
// 005a9f9a  57                   push edi
// 005a9f9b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005a9f9f  c644240800           mov byte ptr [esp + 8], 0
// 005a9fa4  8b442408             mov eax, dword ptr [esp + 8]
// 005a9fa8  50                   push eax
// 005a9fa9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005a9fad  52                   push edx
// 005a9fae  51                   push ecx
// 005a9faf  50                   push eax
// 005a9fb0  56                   push esi
// 005a9fb1  57                   push edi
// 005a9fb2  e899feffff           call 0x5a9e50
// 005a9fb7  8d0c76               lea ecx, [esi + esi*2]
// 005a9fba  83c418               add esp, 0x18
// 005a9fbd  8d04cf               lea eax, [edi + ecx*8]
// 005a9fc0  5f                   pop edi
// 005a9fc1  5e                   pop esi
// 005a9fc2  59                   pop ecx
// 005a9fc3  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
