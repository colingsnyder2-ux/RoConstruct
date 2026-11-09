// from server: 100% by auto
// roc 2008-06 004a7c60  unit: RBX::VHint::?$FactoryProduct::Creator  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a7c60
//
// 004a7c60  51                   push ecx
// 004a7c61  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a7c65  56                   push esi
// 004a7c66  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a7c6a  57                   push edi
// 004a7c6b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a7c6f  c644240800           mov byte ptr [esp + 8], 0
// 004a7c74  8b442408             mov eax, dword ptr [esp + 8]
// 004a7c78  50                   push eax
// 004a7c79  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a7c7d  52                   push edx
// 004a7c7e  83c108               add ecx, 8
// 004a7c81  51                   push ecx
// 004a7c82  50                   push eax
// 004a7c83  56                   push esi
// 004a7c84  57                   push edi
// 004a7c85  e806fdffff           call 0x4a7990
// 004a7c8a  8d0c76               lea ecx, [esi + esi*2]
// 004a7c8d  83c418               add esp, 0x18
// 004a7c90  8d048f               lea eax, [edi + ecx*4]
// 004a7c93  5f                   pop edi
// 004a7c94  5e                   pop esi
// 004a7c95  59                   pop ecx
// 004a7c96  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
