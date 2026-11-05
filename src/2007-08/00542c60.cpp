// from server: 100% by auto
// roc 2007-08 00542c60  unit: RBX::VInstance::?$SignalDesc  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00542c60
//
// 00542c60  8b4104               mov eax, dword ptr [ecx + 4]
// 00542c63  56                   push esi
// 00542c64  8b7004               mov esi, dword ptr [eax + 4]
// 00542c67  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00542c6b  57                   push edi
// 00542c6c  8bf8                 mov edi, eax
// 00542c6e  7531                 jne 0x542ca1
// 00542c70  53                   push ebx
// 00542c71  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00542c75  55                   push ebp
// 00542c76  8b2d20e67700         mov ebp, dword ptr [0x77e620]
// 00542c7c  8d642400             lea esp, [esp]
// 00542c80  8d460c               lea eax, [esi + 0xc]
// 00542c83  53                   push ebx
// 00542c84  50                   push eax
// 00542c85  ffd5                 call ebp
// 00542c87  83c408               add esp, 8
// 00542c8a  84c0                 test al, al
// 00542c8c  7405                 je 0x542c93
// 00542c8e  8b7608               mov esi, dword ptr [esi + 8]
// 00542c91  eb04                 jmp 0x542c97
// 00542c93  8bfe                 mov edi, esi
// 00542c95  8b36                 mov esi, dword ptr [esi]
// 00542c97  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00542c9b  74e3                 je 0x542c80
// 00542c9d  5d                   pop ebp
// 00542c9e  8bc7                 mov eax, edi
// 00542ca0  5b                   pop ebx
// 00542ca1  5f                   pop edi
// 00542ca2  5e                   pop esi
// 00542ca3  c20400               ret 4
// standard library map_str<ptr> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
