// from server: 100% by auto
// roc 2007-03 00619960  unit: seg_00610000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00619960
//
// 00619960  53                   push ebx
// 00619961  56                   push esi
// 00619962  57                   push edi
// 00619963  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00619967  807f2900             cmp byte ptr [edi + 0x29], 0
// 0061996b  8bd9                 mov ebx, ecx
// 0061996d  8bf7                 mov esi, edi
// 0061996f  7527                 jne 0x619998
// 00619971  8b4608               mov eax, dword ptr [esi + 8]
// 00619974  50                   push eax
// 00619975  8bcb                 mov ecx, ebx
// 00619977  e8e4ffffff           call 0x619960
// 0061997c  8b36                 mov esi, dword ptr [esi]
// 0061997e  8d4f0c               lea ecx, [edi + 0xc]
// 00619981  ff158ce77700         call dword ptr [0x77e78c]
// 00619987  57                   push edi
// 00619988  e863470000           call 0x61e0f0
// 0061998d  83c404               add esp, 4
// 00619990  807e2900             cmp byte ptr [esi + 0x29], 0
// 00619994  8bfe                 mov edi, esi
// 00619996  74d9                 je 0x619971
// 00619998  5f                   pop edi
// 00619999  5e                   pop esi
// 0061999a  5b                   pop ebx
// 0061999b  c20400               ret 4
// standard library set<string> (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
