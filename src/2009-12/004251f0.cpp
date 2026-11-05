// from server: 100% by auto
// roc 2009-12 004251f0  unit: MainLogManager  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004251f0
//
// 004251f0  51                   push ecx
// 004251f1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004251f5  56                   push esi
// 004251f6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004251fa  57                   push edi
// 004251fb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004251ff  c644240800           mov byte ptr [esp + 8], 0
// 00425204  8b442408             mov eax, dword ptr [esp + 8]
// 00425208  50                   push eax
// 00425209  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042520d  52                   push edx
// 0042520e  83c108               add ecx, 8
// 00425211  51                   push ecx
// 00425212  50                   push eax
// 00425213  56                   push esi
// 00425214  57                   push edi
// 00425215  e876faffff           call 0x424c90
// 0042521a  83c418               add esp, 0x18
// 0042521d  8d0cf500000000       lea ecx, [esi*8]
// 00425224  2bce                 sub ecx, esi
// 00425226  8d048f               lea eax, [edi + ecx*4]
// 00425229  5f                   pop edi
// 0042522a  5e                   pop esi
// 0042522b  59                   pop ecx
// 0042522c  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
