// from server: 100% by auto
// roc 2010-06 007876e0  unit: RBX::HUMAN::GettingUp  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007876e0
//
// 007876e0  51                   push ecx
// 007876e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007876e5  56                   push esi
// 007876e6  8b742410             mov esi, dword ptr [esp + 0x10]
// 007876ea  57                   push edi
// 007876eb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007876ef  c644240800           mov byte ptr [esp + 8], 0
// 007876f4  8b442408             mov eax, dword ptr [esp + 8]
// 007876f8  50                   push eax
// 007876f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007876fd  52                   push edx
// 007876fe  83c108               add ecx, 8
// 00787701  51                   push ecx
// 00787702  50                   push eax
// 00787703  56                   push esi
// 00787704  57                   push edi
// 00787705  e856feffff           call 0x787560
// 0078770a  8d0cb6               lea ecx, [esi + esi*4]
// 0078770d  83c418               add esp, 0x18
// 00787710  8d048f               lea eax, [edi + ecx*4]
// 00787713  5f                   pop edi
// 00787714  5e                   pop esi
// 00787715  59                   pop ecx
// 00787716  c20c00               ret 0xc
// standard library vector<pod20> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
