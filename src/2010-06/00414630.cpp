// from server: 100% by auto
// roc 2010-06 00414630  unit: CopyVerb  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00414630
//
// 00414630  64a100000000         mov eax, dword ptr fs:[0]
// 00414636  6aff                 push -1
// 00414638  6869b59900           push 0x99b569
// 0041463d  50                   push eax
// 0041463e  64892500000000       mov dword ptr fs:[0], esp
// 00414645  53                   push ebx
// 00414646  55                   push ebp
// 00414647  56                   push esi
// 00414648  57                   push edi
// 00414649  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041464d  807f4500             cmp byte ptr [edi + 0x45], 0
// 00414651  8bd9                 mov ebx, ecx
// 00414653  8bf7                 mov esi, edi
// 00414655  7546                 jne 0x41469d
// 00414657  8b4608               mov eax, dword ptr [esi + 8]
// 0041465a  50                   push eax
// 0041465b  8bcb                 mov ecx, ebx
// 0041465d  e8ceffffff           call 0x414630
// 00414662  8b36                 mov esi, dword ptr [esi]
// 00414664  8d6f0c               lea ebp, [edi + 0xc]
// 00414667  896c2420             mov dword ptr [esp + 0x20], ebp
// 0041466b  8d4d1c               lea ecx, [ebp + 0x1c]
// 0041466e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00414676  ff1500a49e00         call dword ptr [0x9ea400]
// 0041467c  8bcd                 mov ecx, ebp
// 0041467e  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00414686  ff1500a49e00         call dword ptr [0x9ea400]
// 0041468c  57                   push edi
// 0041468d  e808333900           call 0x7a799a
// 00414692  83c404               add esp, 4
// 00414695  807e4500             cmp byte ptr [esi + 0x45], 0
// 00414699  8bfe                 mov edi, esi
// 0041469b  74ba                 je 0x414657
// 0041469d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004146a1  5f                   pop edi
// 004146a2  5e                   pop esi
// 004146a3  5d                   pop ebp
// 004146a4  64890d00000000       mov dword ptr fs:[0], ecx
// 004146ab  5b                   pop ebx
// 004146ac  83c40c               add esp, 0xc
// 004146af  c20400               ret 4
// standard library map_str<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
