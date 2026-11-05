// from server: 100% by auto
// roc 2009-12 006ce820  unit: RBX::PartInstance  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ce820
//
// 006ce820  51                   push ecx
// 006ce821  8b542410             mov edx, dword ptr [esp + 0x10]
// 006ce825  56                   push esi
// 006ce826  8b742410             mov esi, dword ptr [esp + 0x10]
// 006ce82a  57                   push edi
// 006ce82b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006ce82f  c644240800           mov byte ptr [esp + 8], 0
// 006ce834  8b442408             mov eax, dword ptr [esp + 8]
// 006ce838  50                   push eax
// 006ce839  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ce83d  52                   push edx
// 006ce83e  83c108               add ecx, 8
// 006ce841  51                   push ecx
// 006ce842  50                   push eax
// 006ce843  56                   push esi
// 006ce844  57                   push edi
// 006ce845  e816edffff           call 0x6cd560
// 006ce84a  83c418               add esp, 0x18
// 006ce84d  8d04f7               lea eax, [edi + esi*8]
// 006ce850  5f                   pop edi
// 006ce851  5e                   pop esi
// 006ce852  59                   pop ecx
// 006ce853  c20c00               ret 0xc
// standard library vector<pod8> (function ?_Ufill@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEPAUE@@PAU3@IABU3@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
