// from server: 100% by auto
// roc 2009-06 0044c750  unit: CRobloxControlColorSelector  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044c750
//
// 0044c750  51                   push ecx
// 0044c751  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c755  56                   push esi
// 0044c756  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044c75a  57                   push edi
// 0044c75b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0044c75f  c644240800           mov byte ptr [esp + 8], 0
// 0044c764  8b442408             mov eax, dword ptr [esp + 8]
// 0044c768  50                   push eax
// 0044c769  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044c76d  52                   push edx
// 0044c76e  83c108               add ecx, 8
// 0044c771  51                   push ecx
// 0044c772  50                   push eax
// 0044c773  56                   push esi
// 0044c774  57                   push edi
// 0044c775  e836ffffff           call 0x44c6b0
// 0044c77a  8d0c76               lea ecx, [esi + esi*2]
// 0044c77d  83c418               add esp, 0x18
// 0044c780  8d048f               lea eax, [edi + ecx*4]
// 0044c783  5f                   pop edi
// 0044c784  5e                   pop esi
// 0044c785  59                   pop ecx
// 0044c786  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
