// roc 2012-06 008b98e0  unit: seg_008b0000  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008b98e0
//
// 008b98e0  51                   push ecx
// 008b98e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008b98e5  56                   push esi
// 008b98e6  8b742410             mov esi, dword ptr [esp + 0x10]
// 008b98ea  57                   push edi
// 008b98eb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008b98ef  c644240800           mov byte ptr [esp + 8], 0
// 008b98f4  8b442408             mov eax, dword ptr [esp + 8]
// 008b98f8  50                   push eax
// 008b98f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008b98fd  52                   push edx
// 008b98fe  51                   push ecx
// 008b98ff  50                   push eax
// 008b9900  56                   push esi
// 008b9901  57                   push edi
// 008b9902  e8e9f9ffff           call 0x8b92f0
// 008b9907  8d0cb6               lea ecx, [esi + esi*4]
// 008b990a  83c418               add esp, 0x18
// 008b990d  8d04cf               lea eax, [edi + ecx*8]
// 008b9910  5f                   pop edi
// 008b9911  5e                   pop esi
// 008b9912  59                   pop ecx
// 008b9913  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?_Ufill@?$vector@VVertex@?$ConvexClipper@N@Wml@@V?$allocator@VVertex@?$ConvexClipper@N@Wml@@@std@@@std@@IAEPAVVertex@?$ConvexClipper@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
