// from server: 100% by auto
// roc 2009-12 007e8240  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e8240
//
// 007e8240  51                   push ecx
// 007e8241  8b542410             mov edx, dword ptr [esp + 0x10]
// 007e8245  56                   push esi
// 007e8246  8b742410             mov esi, dword ptr [esp + 0x10]
// 007e824a  57                   push edi
// 007e824b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e824f  c644240800           mov byte ptr [esp + 8], 0
// 007e8254  8b442408             mov eax, dword ptr [esp + 8]
// 007e8258  50                   push eax
// 007e8259  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e825d  52                   push edx
// 007e825e  83c108               add ecx, 8
// 007e8261  51                   push ecx
// 007e8262  50                   push eax
// 007e8263  56                   push esi
// 007e8264  57                   push edi
// 007e8265  e8c6fbeaff           call 0x697e30
// 007e826a  83c418               add esp, 0x18
// 007e826d  8d04f7               lea eax, [edi + esi*8]
// 007e8270  5f                   pop edi
// 007e8271  5e                   pop esi
// 007e8272  59                   pop ecx
// 007e8273  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
