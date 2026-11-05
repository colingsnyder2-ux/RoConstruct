// from server: 100% by auto
// roc 2009-06 004149c0  unit: CopyVerb  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004149c0
//
// 004149c0  64a100000000         mov eax, dword ptr fs:[0]
// 004149c6  6aff                 push -1
// 004149c8  68592a8700           push 0x872a59
// 004149cd  50                   push eax
// 004149ce  64892500000000       mov dword ptr fs:[0], esp
// 004149d5  53                   push ebx
// 004149d6  55                   push ebp
// 004149d7  56                   push esi
// 004149d8  57                   push edi
// 004149d9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004149dd  807f4500             cmp byte ptr [edi + 0x45], 0
// 004149e1  8bd9                 mov ebx, ecx
// 004149e3  8bf7                 mov esi, edi
// 004149e5  7546                 jne 0x414a2d
// 004149e7  8b4608               mov eax, dword ptr [esi + 8]
// 004149ea  50                   push eax
// 004149eb  8bcb                 mov ecx, ebx
// 004149ed  e8ceffffff           call 0x4149c0
// 004149f2  8b36                 mov esi, dword ptr [esi]
// 004149f4  8d6f0c               lea ebp, [edi + 0xc]
// 004149f7  896c2420             mov dword ptr [esp + 0x20], ebp
// 004149fb  8d4d1c               lea ecx, [ebp + 0x1c]
// 004149fe  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00414a06  ff15c4e48900         call dword ptr [0x89e4c4]
// 00414a0c  8bcd                 mov ecx, ebp
// 00414a0e  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00414a16  ff15c4e48900         call dword ptr [0x89e4c4]
// 00414a1c  57                   push edi
// 00414a1d  e810403000           call 0x718a32
// 00414a22  83c404               add esp, 4
// 00414a25  807e4500             cmp byte ptr [esi + 0x45], 0
// 00414a29  8bfe                 mov edi, esi
// 00414a2b  74ba                 je 0x4149e7
// 00414a2d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00414a31  5f                   pop edi
// 00414a32  5e                   pop esi
// 00414a33  5d                   pop ebp
// 00414a34  64890d00000000       mov dword ptr fs:[0], ecx
// 00414a3b  5b                   pop ebx
// 00414a3c  83c40c               add esp, 0xc
// 00414a3f  c20400               ret 4
// standard library map_str<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
