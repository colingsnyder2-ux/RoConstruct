// from server: 100% by auto
// roc 2009-12 007b3650  unit: RBX::Assembly  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b3650
//
// 007b3650  51                   push ecx
// 007b3651  8b542410             mov edx, dword ptr [esp + 0x10]
// 007b3655  56                   push esi
// 007b3656  8b742410             mov esi, dword ptr [esp + 0x10]
// 007b365a  57                   push edi
// 007b365b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007b365f  c644240800           mov byte ptr [esp + 8], 0
// 007b3664  8b442408             mov eax, dword ptr [esp + 8]
// 007b3668  50                   push eax
// 007b3669  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007b366d  52                   push edx
// 007b366e  83c108               add ecx, 8
// 007b3671  51                   push ecx
// 007b3672  50                   push eax
// 007b3673  56                   push esi
// 007b3674  57                   push edi
// 007b3675  e806feffff           call 0x7b3480
// 007b367a  83c418               add esp, 0x18
// 007b367d  8d0cf500000000       lea ecx, [esi*8]
// 007b3684  2bce                 sub ecx, esi
// 007b3686  8d048f               lea eax, [edi + ecx*4]
// 007b3689  5f                   pop edi
// 007b368a  5e                   pop esi
// 007b368b  59                   pop ecx
// 007b368c  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
