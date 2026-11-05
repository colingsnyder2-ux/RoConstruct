// from server: 100% by auto
// roc 2010-06 006597c0  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006597c0
//
// 006597c0  51                   push ecx
// 006597c1  8b542410             mov edx, dword ptr [esp + 0x10]
// 006597c5  56                   push esi
// 006597c6  8b742410             mov esi, dword ptr [esp + 0x10]
// 006597ca  57                   push edi
// 006597cb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006597cf  c644240800           mov byte ptr [esp + 8], 0
// 006597d4  8b442408             mov eax, dword ptr [esp + 8]
// 006597d8  50                   push eax
// 006597d9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006597dd  52                   push edx
// 006597de  83c108               add ecx, 8
// 006597e1  51                   push ecx
// 006597e2  50                   push eax
// 006597e3  56                   push esi
// 006597e4  57                   push edi
// 006597e5  e8c6f1ffff           call 0x6589b0
// 006597ea  83c418               add esp, 0x18
// 006597ed  8d0cf500000000       lea ecx, [esi*8]
// 006597f4  2bce                 sub ecx, esi
// 006597f6  8d048f               lea eax, [edi + ecx*4]
// 006597f9  5f                   pop edi
// 006597fa  5e                   pop esi
// 006597fb  59                   pop ecx
// 006597fc  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
