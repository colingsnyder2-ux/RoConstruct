// from server: 100% by auto
// roc 2009-12 00453c70  unit: CRobloxControlMaterialSelector  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00453c70
//
// 00453c70  51                   push ecx
// 00453c71  8b542410             mov edx, dword ptr [esp + 0x10]
// 00453c75  56                   push esi
// 00453c76  8b742410             mov esi, dword ptr [esp + 0x10]
// 00453c7a  57                   push edi
// 00453c7b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00453c7f  c644240800           mov byte ptr [esp + 8], 0
// 00453c84  8b442408             mov eax, dword ptr [esp + 8]
// 00453c88  50                   push eax
// 00453c89  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00453c8d  52                   push edx
// 00453c8e  83c108               add ecx, 8
// 00453c91  51                   push ecx
// 00453c92  50                   push eax
// 00453c93  56                   push esi
// 00453c94  57                   push edi
// 00453c95  e836ffffff           call 0x453bd0
// 00453c9a  8d0c76               lea ecx, [esi + esi*2]
// 00453c9d  83c418               add esp, 0x18
// 00453ca0  8d048f               lea eax, [edi + ecx*4]
// 00453ca3  5f                   pop edi
// 00453ca4  5e                   pop esi
// 00453ca5  59                   pop ecx
// 00453ca6  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
