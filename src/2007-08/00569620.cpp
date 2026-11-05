// from server: 100% by auto
// roc 2007-08 00569620  unit: RBX::ModelInstance  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00569620
//
// 00569620  8b4104               mov eax, dword ptr [ecx + 4]
// 00569623  56                   push esi
// 00569624  8b7004               mov esi, dword ptr [eax + 4]
// 00569627  807e3100             cmp byte ptr [esi + 0x31], 0
// 0056962b  57                   push edi
// 0056962c  8bf8                 mov edi, eax
// 0056962e  7531                 jne 0x569661
// 00569630  53                   push ebx
// 00569631  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00569635  55                   push ebp
// 00569636  8b2d20e67700         mov ebp, dword ptr [0x77e620]
// 0056963c  8d642400             lea esp, [esp]
// 00569640  8d460c               lea eax, [esi + 0xc]
// 00569643  53                   push ebx
// 00569644  50                   push eax
// 00569645  ffd5                 call ebp
// 00569647  83c408               add esp, 8
// 0056964a  84c0                 test al, al
// 0056964c  7405                 je 0x569653
// 0056964e  8b7608               mov esi, dword ptr [esi + 8]
// 00569651  eb04                 jmp 0x569657
// 00569653  8bfe                 mov edi, esi
// 00569655  8b36                 mov esi, dword ptr [esi]
// 00569657  807e3100             cmp byte ptr [esi + 0x31], 0
// 0056965b  74e3                 je 0x569640
// 0056965d  5d                   pop ebp
// 0056965e  8bc7                 mov eax, edi
// 00569660  5b                   pop ebx
// 00569661  5f                   pop edi
// 00569662  5e                   pop esi
// 00569663  c20400               ret 4
// standard library map_str<pod8> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
