// from server: 100% by auto
// roc 2011-06 004162a0  unit: CopyVerb  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004162a0
//
// 004162a0  64a100000000         mov eax, dword ptr fs:[0]
// 004162a6  6aff                 push -1
// 004162a8  68e942a100           push 0xa142e9
// 004162ad  50                   push eax
// 004162ae  64892500000000       mov dword ptr fs:[0], esp
// 004162b5  53                   push ebx
// 004162b6  55                   push ebp
// 004162b7  56                   push esi
// 004162b8  57                   push edi
// 004162b9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004162bd  807f4500             cmp byte ptr [edi + 0x45], 0
// 004162c1  8bd9                 mov ebx, ecx
// 004162c3  8bf7                 mov esi, edi
// 004162c5  7546                 jne 0x41630d
// 004162c7  8b4608               mov eax, dword ptr [esi + 8]
// 004162ca  50                   push eax
// 004162cb  8bcb                 mov ecx, ebx
// 004162cd  e8ceffffff           call 0x4162a0
// 004162d2  8b36                 mov esi, dword ptr [esi]
// 004162d4  8d6f0c               lea ebp, [edi + 0xc]
// 004162d7  896c2420             mov dword ptr [esp + 0x20], ebp
// 004162db  8d4d1c               lea ecx, [ebp + 0x1c]
// 004162de  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004162e6  ff15d004a400         call dword ptr [0xa404d0]
// 004162ec  8bcd                 mov ecx, ebp
// 004162ee  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004162f6  ff15d004a400         call dword ptr [0xa404d0]
// 004162fc  57                   push edi
// 004162fd  e8563d3f00           call 0x80a058
// 00416302  83c404               add esp, 4
// 00416305  807e4500             cmp byte ptr [esi + 0x45], 0
// 00416309  8bfe                 mov edi, esi
// 0041630b  74ba                 je 0x4162c7
// 0041630d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00416311  5f                   pop edi
// 00416312  5e                   pop esi
// 00416313  5d                   pop ebp
// 00416314  64890d00000000       mov dword ptr fs:[0], ecx
// 0041631b  5b                   pop ebx
// 0041631c  83c40c               add esp, 0xc
// 0041631f  c20400               ret 4
// standard library map_str<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
