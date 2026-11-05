// from server: 100% by auto
// roc 2010-06 00955770  unit: seg_00950000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00955770
//
// 00955770  51                   push ecx
// 00955771  8b542410             mov edx, dword ptr [esp + 0x10]
// 00955775  56                   push esi
// 00955776  8b742410             mov esi, dword ptr [esp + 0x10]
// 0095577a  57                   push edi
// 0095577b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0095577f  c644240800           mov byte ptr [esp + 8], 0
// 00955784  8b442408             mov eax, dword ptr [esp + 8]
// 00955788  50                   push eax
// 00955789  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0095578d  52                   push edx
// 0095578e  83c108               add ecx, 8
// 00955791  51                   push ecx
// 00955792  50                   push eax
// 00955793  56                   push esi
// 00955794  57                   push edi
// 00955795  e876ffffff           call 0x955710
// 0095579a  8d0c76               lea ecx, [esi + esi*2]
// 0095579d  83c418               add esp, 0x18
// 009557a0  8d048f               lea eax, [edi + ecx*4]
// 009557a3  5f                   pop edi
// 009557a4  5e                   pop esi
// 009557a5  59                   pop ecx
// 009557a6  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
