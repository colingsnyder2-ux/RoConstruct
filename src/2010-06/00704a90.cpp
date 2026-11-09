// from server: 100% by auto
// roc 2010-06 00704a90  unit: RBX::VInstance::?$NonFactoryProduct  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704a90
//
// 00704a90  51                   push ecx
// 00704a91  8b542410             mov edx, dword ptr [esp + 0x10]
// 00704a95  56                   push esi
// 00704a96  8b742410             mov esi, dword ptr [esp + 0x10]
// 00704a9a  57                   push edi
// 00704a9b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00704a9f  c644240800           mov byte ptr [esp + 8], 0
// 00704aa4  8b442408             mov eax, dword ptr [esp + 8]
// 00704aa8  50                   push eax
// 00704aa9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00704aad  52                   push edx
// 00704aae  83c108               add ecx, 8
// 00704ab1  51                   push ecx
// 00704ab2  50                   push eax
// 00704ab3  56                   push esi
// 00704ab4  57                   push edi
// 00704ab5  e886fcffff           call 0x704740
// 00704aba  8d0cf6               lea ecx, [esi + esi*8]
// 00704abd  83c418               add esp, 0x18
// 00704ac0  8d048f               lea eax, [edi + ecx*4]
// 00704ac3  5f                   pop edi
// 00704ac4  5e                   pop esi
// 00704ac5  59                   pop ecx
// 00704ac6  c20c00               ret 0xc
// standard library vector<pod36> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
