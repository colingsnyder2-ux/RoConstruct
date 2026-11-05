// from server: 100% by auto
// roc 2009-06 005ccfb0  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ccfb0
//
// 005ccfb0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 005ccfb3  56                   push esi
// 005ccfb4  8b7004               mov esi, dword ptr [eax + 4]
// 005ccfb7  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005ccfbb  57                   push edi
// 005ccfbc  8bf8                 mov edi, eax
// 005ccfbe  7531                 jne 0x5ccff1
// 005ccfc0  53                   push ebx
// 005ccfc1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005ccfc5  55                   push ebp
// 005ccfc6  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 005ccfcc  8d642400             lea esp, [esp]
// 005ccfd0  8d460c               lea eax, [esi + 0xc]
// 005ccfd3  53                   push ebx
// 005ccfd4  50                   push eax
// 005ccfd5  ffd5                 call ebp
// 005ccfd7  83c408               add esp, 8
// 005ccfda  84c0                 test al, al
// 005ccfdc  7405                 je 0x5ccfe3
// 005ccfde  8b7608               mov esi, dword ptr [esi + 8]
// 005ccfe1  eb04                 jmp 0x5ccfe7
// 005ccfe3  8bfe                 mov edi, esi
// 005ccfe5  8b36                 mov esi, dword ptr [esi]
// 005ccfe7  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005ccfeb  74e3                 je 0x5ccfd0
// 005ccfed  5d                   pop ebp
// 005ccfee  8bc7                 mov eax, edi
// 005ccff0  5b                   pop ebx
// 005ccff1  5f                   pop edi
// 005ccff2  5e                   pop esi
// 005ccff3  c20400               ret 4
// standard library map_str<ptr> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
