// roc 2012-06 00950e70  unit: RBX::AdvRotateTool  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00950e70
//
// 00950e70  51                   push ecx
// 00950e71  8b542410             mov edx, dword ptr [esp + 0x10]
// 00950e75  56                   push esi
// 00950e76  8b742410             mov esi, dword ptr [esp + 0x10]
// 00950e7a  57                   push edi
// 00950e7b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00950e7f  c644240800           mov byte ptr [esp + 8], 0
// 00950e84  8b442408             mov eax, dword ptr [esp + 8]
// 00950e88  50                   push eax
// 00950e89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00950e8d  52                   push edx
// 00950e8e  51                   push ecx
// 00950e8f  50                   push eax
// 00950e90  56                   push esi
// 00950e91  57                   push edi
// 00950e92  e8b9fcffff           call 0x950b50
// 00950e97  8d0cb6               lea ecx, [esi + esi*4]
// 00950e9a  83c418               add esp, 0x18
// 00950e9d  8d04cf               lea eax, [edi + ecx*8]
// 00950ea0  5f                   pop edi
// 00950ea1  5e                   pop esi
// 00950ea2  59                   pop ecx
// 00950ea3  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?_Ufill@?$vector@VVertex@?$ConvexClipper@N@Wml@@V?$allocator@VVertex@?$ConvexClipper@N@Wml@@@std@@@std@@IAEPAVVertex@?$ConvexClipper@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
