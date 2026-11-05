// from server: 100% by auto
// roc 2010-06 006abb60  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006abb60
//
// 006abb60  51                   push ecx
// 006abb61  8b542410             mov edx, dword ptr [esp + 0x10]
// 006abb65  56                   push esi
// 006abb66  8b742410             mov esi, dword ptr [esp + 0x10]
// 006abb6a  57                   push edi
// 006abb6b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006abb6f  c644240800           mov byte ptr [esp + 8], 0
// 006abb74  8b442408             mov eax, dword ptr [esp + 8]
// 006abb78  50                   push eax
// 006abb79  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006abb7d  52                   push edx
// 006abb7e  83c108               add ecx, 8
// 006abb81  51                   push ecx
// 006abb82  50                   push eax
// 006abb83  56                   push esi
// 006abb84  57                   push edi
// 006abb85  e8d6f8ffff           call 0x6ab460
// 006abb8a  8d0cb6               lea ecx, [esi + esi*4]
// 006abb8d  83c418               add esp, 0x18
// 006abb90  8d04cf               lea eax, [edi + ecx*8]
// 006abb93  5f                   pop edi
// 006abb94  5e                   pop esi
// 006abb95  59                   pop ecx
// 006abb96  c20c00               ret 0xc
// standard library vector<pod40> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
