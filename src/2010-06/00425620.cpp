// from server: 100% by auto
// roc 2010-06 00425620  unit: MainLogManager  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425620
//
// 00425620  51                   push ecx
// 00425621  8b542410             mov edx, dword ptr [esp + 0x10]
// 00425625  56                   push esi
// 00425626  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042562a  57                   push edi
// 0042562b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042562f  c644240800           mov byte ptr [esp + 8], 0
// 00425634  8b442408             mov eax, dword ptr [esp + 8]
// 00425638  50                   push eax
// 00425639  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042563d  52                   push edx
// 0042563e  83c108               add ecx, 8
// 00425641  51                   push ecx
// 00425642  50                   push eax
// 00425643  56                   push esi
// 00425644  57                   push edi
// 00425645  e876faffff           call 0x4250c0
// 0042564a  83c418               add esp, 0x18
// 0042564d  8d0cf500000000       lea ecx, [esi*8]
// 00425654  2bce                 sub ecx, esi
// 00425656  8d048f               lea eax, [edi + ecx*4]
// 00425659  5f                   pop edi
// 0042565a  5e                   pop esi
// 0042565b  59                   pop ecx
// 0042565c  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
