// from server: 100% by auto
// roc 2007-08 0044c3a0  unit: CRobloxControlColorSelector  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c3a0
//
// 0044c3a0  51                   push ecx
// 0044c3a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c3a5  56                   push esi
// 0044c3a6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044c3aa  57                   push edi
// 0044c3ab  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0044c3af  c644240800           mov byte ptr [esp + 8], 0
// 0044c3b4  8b442408             mov eax, dword ptr [esp + 8]
// 0044c3b8  50                   push eax
// 0044c3b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044c3bd  52                   push edx
// 0044c3be  51                   push ecx
// 0044c3bf  50                   push eax
// 0044c3c0  56                   push esi
// 0044c3c1  57                   push edi
// 0044c3c2  e829ffffff           call 0x44c2f0
// 0044c3c7  8d0c76               lea ecx, [esi + esi*2]
// 0044c3ca  83c418               add esp, 0x18
// 0044c3cd  8d048f               lea eax, [edi + ecx*4]
// 0044c3d0  5f                   pop edi
// 0044c3d1  5e                   pop esi
// 0044c3d2  59                   pop ecx
// 0044c3d3  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
