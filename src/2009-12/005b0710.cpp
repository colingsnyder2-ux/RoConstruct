// from server: 100% by auto
// roc 2009-12 005b0710  unit: seg_005b0000  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0710
//
// 005b0710  51                   push ecx
// 005b0711  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b0715  56                   push esi
// 005b0716  8b742410             mov esi, dword ptr [esp + 0x10]
// 005b071a  57                   push edi
// 005b071b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b071f  c644240800           mov byte ptr [esp + 8], 0
// 005b0724  8b442408             mov eax, dword ptr [esp + 8]
// 005b0728  50                   push eax
// 005b0729  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b072d  52                   push edx
// 005b072e  83c108               add ecx, 8
// 005b0731  51                   push ecx
// 005b0732  50                   push eax
// 005b0733  56                   push esi
// 005b0734  57                   push edi
// 005b0735  e8a6ffffff           call 0x5b06e0
// 005b073a  8d0c76               lea ecx, [esi + esi*2]
// 005b073d  83c418               add esp, 0x18
// 005b0740  8d048f               lea eax, [edi + ecx*4]
// 005b0743  5f                   pop edi
// 005b0744  5e                   pop esi
// 005b0745  59                   pop ecx
// 005b0746  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
