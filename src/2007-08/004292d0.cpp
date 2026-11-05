// from server: 100% by auto
// roc 2007-08 004292d0  unit: ThreadLogManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004292d0
//
// 004292d0  51                   push ecx
// 004292d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004292d5  56                   push esi
// 004292d6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004292da  57                   push edi
// 004292db  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004292df  c644240800           mov byte ptr [esp + 8], 0
// 004292e4  8b442408             mov eax, dword ptr [esp + 8]
// 004292e8  50                   push eax
// 004292e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004292ed  52                   push edx
// 004292ee  51                   push ecx
// 004292ef  50                   push eax
// 004292f0  56                   push esi
// 004292f1  57                   push edi
// 004292f2  e8c9fcffff           call 0x428fc0
// 004292f7  83c418               add esp, 0x18
// 004292fa  8d0cf500000000       lea ecx, [esi*8]
// 00429301  2bce                 sub ecx, esi
// 00429303  8d048f               lea eax, [edi + ecx*4]
// 00429306  5f                   pop edi
// 00429307  5e                   pop esi
// 00429308  59                   pop ecx
// 00429309  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
