// from server: 100% by auto
// roc 2009-06 00424620  unit: MainLogManager  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424620
//
// 00424620  51                   push ecx
// 00424621  8b542410             mov edx, dword ptr [esp + 0x10]
// 00424625  56                   push esi
// 00424626  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042462a  57                   push edi
// 0042462b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042462f  c644240800           mov byte ptr [esp + 8], 0
// 00424634  8b442408             mov eax, dword ptr [esp + 8]
// 00424638  50                   push eax
// 00424639  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042463d  52                   push edx
// 0042463e  83c108               add ecx, 8
// 00424641  51                   push ecx
// 00424642  50                   push eax
// 00424643  56                   push esi
// 00424644  57                   push edi
// 00424645  e846fdffff           call 0x424390
// 0042464a  83c418               add esp, 0x18
// 0042464d  8d0cf500000000       lea ecx, [esi*8]
// 00424654  2bce                 sub ecx, esi
// 00424656  8d048f               lea eax, [edi + ecx*4]
// 00424659  5f                   pop edi
// 0042465a  5e                   pop esi
// 0042465b  59                   pop ecx
// 0042465c  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
