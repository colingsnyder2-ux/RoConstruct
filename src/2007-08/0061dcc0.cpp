// from server: 100% by auto
// roc 2007-08 0061dcc0  unit: RBX::ScoreHud  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061dcc0
//
// 0061dcc0  8b4104               mov eax, dword ptr [ecx + 4]
// 0061dcc3  56                   push esi
// 0061dcc4  8b7004               mov esi, dword ptr [eax + 4]
// 0061dcc7  807e3500             cmp byte ptr [esi + 0x35], 0
// 0061dccb  57                   push edi
// 0061dccc  8bf8                 mov edi, eax
// 0061dcce  7531                 jne 0x61dd01
// 0061dcd0  53                   push ebx
// 0061dcd1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0061dcd5  55                   push ebp
// 0061dcd6  8b2d20e67700         mov ebp, dword ptr [0x77e620]
// 0061dcdc  8d642400             lea esp, [esp]
// 0061dce0  8d460c               lea eax, [esi + 0xc]
// 0061dce3  53                   push ebx
// 0061dce4  50                   push eax
// 0061dce5  ffd5                 call ebp
// 0061dce7  83c408               add esp, 8
// 0061dcea  84c0                 test al, al
// 0061dcec  7405                 je 0x61dcf3
// 0061dcee  8b7608               mov esi, dword ptr [esi + 8]
// 0061dcf1  eb04                 jmp 0x61dcf7
// 0061dcf3  8bfe                 mov edi, esi
// 0061dcf5  8b36                 mov esi, dword ptr [esi]
// 0061dcf7  807e3500             cmp byte ptr [esi + 0x35], 0
// 0061dcfb  74e3                 je 0x61dce0
// 0061dcfd  5d                   pop ebp
// 0061dcfe  8bc7                 mov eax, edi
// 0061dd00  5b                   pop ebx
// 0061dd01  5f                   pop edi
// 0061dd02  5e                   pop esi
// 0061dd03  c20400               ret 4
// standard library map_str<pod12> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
