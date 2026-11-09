// from server: 100% by auto
// roc 2011-06 007e8920  unit: RBX::AdvRotateTool  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e8920
//
// 007e8920  51                   push ecx
// 007e8921  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e8925  56                   push esi
// 007e8926  8b742410             mov esi, dword ptr [esp + 0x10]
// 007e892a  57                   push edi
// 007e892b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e892f  c644240800           mov byte ptr [esp + 8], 0
// 007e8934  8b442408             mov eax, dword ptr [esp + 8]
// 007e8938  50                   push eax
// 007e8939  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e893d  52                   push edx
// 007e893e  51                   push ecx
// 007e893f  50                   push eax
// 007e8940  56                   push esi
// 007e8941  57                   push edi
// 007e8942  e819feffff           call 0x7e8760
// 007e8947  8d0cb6               lea ecx, [esi + esi*4]
// 007e894a  83c418               add esp, 0x18
// 007e894d  8d04cf               lea eax, [edi + ecx*8]
// 007e8950  5f                   pop edi
// 007e8951  5e                   pop esi
// 007e8952  59                   pop ecx
// 007e8953  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?_Ufill@?$vector@VVertex@?$ConvexClipper@N@Wml@@V?$allocator@VVertex@?$ConvexClipper@N@Wml@@@std@@@std@@IAEPAVVertex@?$ConvexClipper@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
