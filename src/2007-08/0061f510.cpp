// from server: 100% by auto
// roc 2007-08 0061f510  unit: RBX::ScoreHud  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061f510
//
// 0061f510  51                   push ecx
// 0061f511  8b542410             mov edx, dword ptr [esp + 0x10]
// 0061f515  56                   push esi
// 0061f516  8b742410             mov esi, dword ptr [esp + 0x10]
// 0061f51a  57                   push edi
// 0061f51b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0061f51f  c644240800           mov byte ptr [esp + 8], 0
// 0061f524  8b442408             mov eax, dword ptr [esp + 8]
// 0061f528  50                   push eax
// 0061f529  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061f52d  52                   push edx
// 0061f52e  51                   push ecx
// 0061f52f  50                   push eax
// 0061f530  56                   push esi
// 0061f531  57                   push edi
// 0061f532  e829f2ffff           call 0x61e760
// 0061f537  8bc6                 mov eax, esi
// 0061f539  83c418               add esp, 0x18
// 0061f53c  c1e004               shl eax, 4
// 0061f53f  03c7                 add eax, edi
// 0061f541  5f                   pop edi
// 0061f542  5e                   pop esi
// 0061f543  59                   pop ecx
// 0061f544  c20c00               ret 0xc
// standard library vector<pod16> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
