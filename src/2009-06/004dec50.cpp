// from server: 100% by auto
// roc 2009-06 004dec50  unit: RBX::Network::IdSerializer  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dec50
//
// 004dec50  51                   push ecx
// 004dec51  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dec55  56                   push esi
// 004dec56  8b742410             mov esi, dword ptr [esp + 0x10]
// 004dec5a  57                   push edi
// 004dec5b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004dec5f  c644240800           mov byte ptr [esp + 8], 0
// 004dec64  8b442408             mov eax, dword ptr [esp + 8]
// 004dec68  50                   push eax
// 004dec69  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004dec6d  52                   push edx
// 004dec6e  83c108               add ecx, 8
// 004dec71  51                   push ecx
// 004dec72  50                   push eax
// 004dec73  56                   push esi
// 004dec74  57                   push edi
// 004dec75  e806fdffff           call 0x4de980
// 004dec7a  8d0c76               lea ecx, [esi + esi*2]
// 004dec7d  83c418               add esp, 0x18
// 004dec80  8d048f               lea eax, [edi + ecx*4]
// 004dec83  5f                   pop edi
// 004dec84  5e                   pop esi
// 004dec85  59                   pop ecx
// 004dec86  c20c00               ret 0xc
// standard library vector<pod12> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
