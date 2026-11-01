// from server: 100% by auto
// roc 2009-12 007c65d0  unit: RBX::ScoreHud  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c65d0
//
// 007c65d0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007c65d3  56                   push esi
// 007c65d4  8b7004               mov esi, dword ptr [eax + 4]
// 007c65d7  807e4900             cmp byte ptr [esi + 0x49], 0
// 007c65db  57                   push edi
// 007c65dc  8bf8                 mov edi, eax
// 007c65de  7531                 jne 0x7c6611
// 007c65e0  53                   push ebx
// 007c65e1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007c65e5  55                   push ebp
// 007c65e6  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 007c65ec  8d642400             lea esp, [esp]
// 007c65f0  8d460c               lea eax, [esi + 0xc]
// 007c65f3  53                   push ebx
// 007c65f4  50                   push eax
// 007c65f5  ffd5                 call ebp
// 007c65f7  83c408               add esp, 8
// 007c65fa  84c0                 test al, al
// 007c65fc  7405                 je 0x7c6603
// 007c65fe  8b7608               mov esi, dword ptr [esi + 8]
// 007c6601  eb04                 jmp 0x7c6607
// 007c6603  8bfe                 mov edi, esi
// 007c6605  8b36                 mov esi, dword ptr [esi]
// 007c6607  807e4900             cmp byte ptr [esi + 0x49], 0
// 007c660b  74e3                 je 0x7c65f0
// 007c660d  5d                   pop ebp
// 007c660e  8bc7                 mov eax, edi
// 007c6610  5b                   pop ebx
// 007c6611  5f                   pop edi
// 007c6612  5e                   pop esi
// 007c6613  c20400               ret 4
// standard library map_str<pod32> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
