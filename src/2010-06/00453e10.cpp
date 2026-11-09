// from server: 100% by auto
// roc 2010-06 00453e10  unit: CRobloxControlColorSelector  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00453e10
//
// 00453e10  51                   push ecx
// 00453e11  8b542410             mov edx, dword ptr [esp + 0x10]
// 00453e15  56                   push esi
// 00453e16  8b742410             mov esi, dword ptr [esp + 0x10]
// 00453e1a  57                   push edi
// 00453e1b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00453e1f  c644240800           mov byte ptr [esp + 8], 0
// 00453e24  8b442408             mov eax, dword ptr [esp + 8]
// 00453e28  50                   push eax
// 00453e29  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00453e2d  52                   push edx
// 00453e2e  83c108               add ecx, 8
// 00453e31  51                   push ecx
// 00453e32  50                   push eax
// 00453e33  56                   push esi
// 00453e34  57                   push edi
// 00453e35  e836ffffff           call 0x453d70
// 00453e3a  8d0c76               lea ecx, [esi + esi*2]
// 00453e3d  83c418               add esp, 0x18
// 00453e40  8d048f               lea eax, [edi + ecx*4]
// 00453e43  5f                   pop edi
// 00453e44  5e                   pop esi
// 00453e45  59                   pop ecx
// 00453e46  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
