// from server: 100% by auto
// roc 2008-06 0044e670  unit: CRobloxControlColorSelector  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044e670
//
// 0044e670  51                   push ecx
// 0044e671  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044e675  56                   push esi
// 0044e676  8b742410             mov esi, dword ptr [esp + 0x10]
// 0044e67a  57                   push edi
// 0044e67b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0044e67f  c644240800           mov byte ptr [esp + 8], 0
// 0044e684  8b442408             mov eax, dword ptr [esp + 8]
// 0044e688  50                   push eax
// 0044e689  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044e68d  52                   push edx
// 0044e68e  83c108               add ecx, 8
// 0044e691  51                   push ecx
// 0044e692  50                   push eax
// 0044e693  56                   push esi
// 0044e694  57                   push edi
// 0044e695  e836ffffff           call 0x44e5d0
// 0044e69a  8d0c76               lea ecx, [esi + esi*2]
// 0044e69d  83c418               add esp, 0x18
// 0044e6a0  8d048f               lea eax, [edi + ecx*4]
// 0044e6a3  5f                   pop edi
// 0044e6a4  5e                   pop esi
// 0044e6a5  59                   pop ecx
// 0044e6a6  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
