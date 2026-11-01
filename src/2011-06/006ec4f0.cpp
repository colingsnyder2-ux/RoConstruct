// from server: 100% by auto
// roc 2011-06 006ec4f0  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006ec4f0
//
// 006ec4f0  51                   push ecx
// 006ec4f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 006ec4f5  56                   push esi
// 006ec4f6  8b742410             mov esi, dword ptr [esp + 0x10]
// 006ec4fa  57                   push edi
// 006ec4fb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006ec4ff  c644240800           mov byte ptr [esp + 8], 0
// 006ec504  8b442408             mov eax, dword ptr [esp + 8]
// 006ec508  50                   push eax
// 006ec509  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ec50d  52                   push edx
// 006ec50e  51                   push ecx
// 006ec50f  50                   push eax
// 006ec510  56                   push esi
// 006ec511  57                   push edi
// 006ec512  e8f9fcffff           call 0x6ec210
// 006ec517  8d0cb6               lea ecx, [esi + esi*4]
// 006ec51a  83c418               add esp, 0x18
// 006ec51d  8d04cf               lea eax, [edi + ecx*8]
// 006ec520  5f                   pop edi
// 006ec521  5e                   pop esi
// 006ec522  59                   pop ecx
// 006ec523  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?_Ufill@?$vector@VVertex@?$ConvexClipper@N@Wml@@V?$allocator@VVertex@?$ConvexClipper@N@Wml@@@std@@@std@@IAEPAVVertex@?$ConvexClipper@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
