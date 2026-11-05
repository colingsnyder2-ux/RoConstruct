// from server: 100% by auto
// roc 2009-12 005dd570  unit: RBX::ImmediateMeshGenAdapter  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dd570
//
// 005dd570  51                   push ecx
// 005dd571  8b542410             mov edx, dword ptr [esp + 0x10]
// 005dd575  56                   push esi
// 005dd576  8b742410             mov esi, dword ptr [esp + 0x10]
// 005dd57a  57                   push edi
// 005dd57b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005dd57f  c644240800           mov byte ptr [esp + 8], 0
// 005dd584  8b442408             mov eax, dword ptr [esp + 8]
// 005dd588  50                   push eax
// 005dd589  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005dd58d  52                   push edx
// 005dd58e  83c108               add ecx, 8
// 005dd591  51                   push ecx
// 005dd592  50                   push eax
// 005dd593  56                   push esi
// 005dd594  57                   push edi
// 005dd595  e856ffffff           call 0x5dd4f0
// 005dd59a  8d0c76               lea ecx, [esi + esi*2]
// 005dd59d  83c418               add esp, 0x18
// 005dd5a0  8d04cf               lea eax, [edi + ecx*8]
// 005dd5a3  5f                   pop edi
// 005dd5a4  5e                   pop esi
// 005dd5a5  59                   pop ecx
// 005dd5a6  c20c00               ret 0xc
// standard library vector<pod24> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
