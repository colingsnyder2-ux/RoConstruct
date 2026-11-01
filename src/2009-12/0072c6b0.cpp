// from server: 100% by auto
// roc 2009-12 0072c6b0  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072c6b0
//
// 0072c6b0  51                   push ecx
// 0072c6b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072c6b5  56                   push esi
// 0072c6b6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0072c6ba  57                   push edi
// 0072c6bb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0072c6bf  c644240800           mov byte ptr [esp + 8], 0
// 0072c6c4  8b442408             mov eax, dword ptr [esp + 8]
// 0072c6c8  50                   push eax
// 0072c6c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0072c6cd  52                   push edx
// 0072c6ce  83c108               add ecx, 8
// 0072c6d1  51                   push ecx
// 0072c6d2  50                   push eax
// 0072c6d3  56                   push esi
// 0072c6d4  57                   push edi
// 0072c6d5  e886fcffff           call 0x72c360
// 0072c6da  8d0cb6               lea ecx, [esi + esi*4]
// 0072c6dd  83c418               add esp, 0x18
// 0072c6e0  8d04cf               lea eax, [edi + ecx*8]
// 0072c6e3  5f                   pop edi
// 0072c6e4  5e                   pop esi
// 0072c6e5  59                   pop ecx
// 0072c6e6  c20c00               ret 0xc
// standard library vector<pod40> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
