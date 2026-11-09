// from server: 100% by auto
// roc 2008-06 00429440  unit: ThreadLogManager  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00429440
//
// 00429440  51                   push ecx
// 00429441  8b542410             mov edx, dword ptr [esp + 0x10]
// 00429445  56                   push esi
// 00429446  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042944a  57                   push edi
// 0042944b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0042944f  c644240800           mov byte ptr [esp + 8], 0
// 00429454  8b442408             mov eax, dword ptr [esp + 8]
// 00429458  50                   push eax
// 00429459  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042945d  52                   push edx
// 0042945e  83c108               add ecx, 8
// 00429461  51                   push ecx
// 00429462  50                   push eax
// 00429463  56                   push esi
// 00429464  57                   push edi
// 00429465  e846fbffff           call 0x428fb0
// 0042946a  83c418               add esp, 0x18
// 0042946d  8d0cf500000000       lea ecx, [esi*8]
// 00429474  2bce                 sub ecx, esi
// 00429476  8d048f               lea eax, [edi + ecx*4]
// 00429479  5f                   pop edi
// 0042947a  5e                   pop esi
// 0042947b  59                   pop ecx
// 0042947c  c20c00               ret 0xc
// standard library vector<string> (function ?_Ufill@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@PAV32@IABV32@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
