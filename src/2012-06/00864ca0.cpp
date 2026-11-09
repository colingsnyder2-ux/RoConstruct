// roc 2012-06 00864ca0  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00864ca0
//
// 00864ca0  51                   push ecx
// 00864ca1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00864ca5  56                   push esi
// 00864ca6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00864caa  57                   push edi
// 00864cab  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00864caf  c644240800           mov byte ptr [esp + 8], 0
// 00864cb4  8b442408             mov eax, dword ptr [esp + 8]
// 00864cb8  50                   push eax
// 00864cb9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00864cbd  52                   push edx
// 00864cbe  51                   push ecx
// 00864cbf  50                   push eax
// 00864cc0  56                   push esi
// 00864cc1  57                   push edi
// 00864cc2  e899fcffff           call 0x864960
// 00864cc7  8d0cb6               lea ecx, [esi + esi*4]
// 00864cca  83c418               add esp, 0x18
// 00864ccd  8d04cf               lea eax, [edi + ecx*8]
// 00864cd0  5f                   pop edi
// 00864cd1  5e                   pop esi
// 00864cd2  59                   pop ecx
// 00864cd3  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?_Ufill@?$vector@VVertex@?$ConvexClipper@N@Wml@@V?$allocator@VVertex@?$ConvexClipper@N@Wml@@@std@@@std@@IAEPAVVertex@?$ConvexClipper@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
