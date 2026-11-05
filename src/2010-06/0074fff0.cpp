// from server: 100% by auto
// roc 2010-06 0074fff0  unit: RBX::Humanoid  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0074fff0
//
// 0074fff0  51                   push ecx
// 0074fff1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074fff5  56                   push esi
// 0074fff6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0074fffa  57                   push edi
// 0074fffb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0074ffff  c644240800           mov byte ptr [esp + 8], 0
// 00750004  8b442408             mov eax, dword ptr [esp + 8]
// 00750008  50                   push eax
// 00750009  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0075000d  52                   push edx
// 0075000e  83c108               add ecx, 8
// 00750011  51                   push ecx
// 00750012  50                   push eax
// 00750013  56                   push esi
// 00750014  57                   push edi
// 00750015  e806feffff           call 0x74fe20
// 0075001a  83c418               add esp, 0x18
// 0075001d  8d0cf500000000       lea ecx, [esi*8]
// 00750024  2bce                 sub ecx, esi
// 00750026  8d048f               lea eax, [edi + ecx*4]
// 00750029  5f                   pop edi
// 0075002a  5e                   pop esi
// 0075002b  59                   pop ecx
// 0075002c  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
