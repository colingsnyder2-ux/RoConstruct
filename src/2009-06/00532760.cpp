// from server: 100% by auto
// roc 2009-06 00532760  unit: RBX::BeveledBlockBuilder  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00532760
//
// 00532760  51                   push ecx
// 00532761  8b542410             mov edx, dword ptr [esp + 0x10]
// 00532765  56                   push esi
// 00532766  8b742410             mov esi, dword ptr [esp + 0x10]
// 0053276a  57                   push edi
// 0053276b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0053276f  c644240800           mov byte ptr [esp + 8], 0
// 00532774  8b442408             mov eax, dword ptr [esp + 8]
// 00532778  50                   push eax
// 00532779  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053277d  52                   push edx
// 0053277e  83c108               add ecx, 8
// 00532781  51                   push ecx
// 00532782  50                   push eax
// 00532783  56                   push esi
// 00532784  57                   push edi
// 00532785  e856ffffff           call 0x5326e0
// 0053278a  8d0c76               lea ecx, [esi + esi*2]
// 0053278d  83c418               add esp, 0x18
// 00532790  8d04cf               lea eax, [edi + ecx*8]
// 00532793  5f                   pop edi
// 00532794  5e                   pop esi
// 00532795  59                   pop ecx
// 00532796  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
