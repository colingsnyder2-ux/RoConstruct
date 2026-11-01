// from server: 100% by auto
// roc 2011-06 00796a10  unit: RBX::VHttp::?$sp_counted_impl_p  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00796a10
//
// 00796a10  51                   push ecx
// 00796a11  8b542410             mov edx, dword ptr [esp + 0x10]
// 00796a15  56                   push esi
// 00796a16  8b742410             mov esi, dword ptr [esp + 0x10]
// 00796a1a  57                   push edi
// 00796a1b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00796a1f  c644240800           mov byte ptr [esp + 8], 0
// 00796a24  8b442408             mov eax, dword ptr [esp + 8]
// 00796a28  50                   push eax
// 00796a29  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00796a2d  52                   push edx
// 00796a2e  51                   push ecx
// 00796a2f  50                   push eax
// 00796a30  56                   push esi
// 00796a31  57                   push edi
// 00796a32  e859f9ffff           call 0x796390
// 00796a37  8d0cb6               lea ecx, [esi + esi*4]
// 00796a3a  83c418               add esp, 0x18
// 00796a3d  8d04cf               lea eax, [edi + ecx*8]
// 00796a40  5f                   pop edi
// 00796a41  5e                   pop esi
// 00796a42  59                   pop ecx
// 00796a43  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?_Ufill@?$vector@VVertex@?$ConvexClipper@N@Wml@@V?$allocator@VVertex@?$ConvexClipper@N@Wml@@@std@@@std@@IAEPAVVertex@?$ConvexClipper@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
