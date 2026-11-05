// from server: 100% by auto
// roc 2009-06 006d6390  unit: RBX::Mechanism  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d6390
//
// 006d6390  51                   push ecx
// 006d6391  8b542410             mov edx, dword ptr [esp + 0x10]
// 006d6395  56                   push esi
// 006d6396  8b742410             mov esi, dword ptr [esp + 0x10]
// 006d639a  57                   push edi
// 006d639b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006d639f  c644240800           mov byte ptr [esp + 8], 0
// 006d63a4  8b442408             mov eax, dword ptr [esp + 8]
// 006d63a8  50                   push eax
// 006d63a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006d63ad  52                   push edx
// 006d63ae  83c108               add ecx, 8
// 006d63b1  51                   push ecx
// 006d63b2  50                   push eax
// 006d63b3  56                   push esi
// 006d63b4  57                   push edi
// 006d63b5  e846feffff           call 0x6d6200
// 006d63ba  83c418               add esp, 0x18
// 006d63bd  8d0cf500000000       lea ecx, [esi*8]
// 006d63c4  2bce                 sub ecx, esi
// 006d63c6  8d048f               lea eax, [edi + ecx*4]
// 006d63c9  5f                   pop edi
// 006d63ca  5e                   pop esi
// 006d63cb  59                   pop ecx
// 006d63cc  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
