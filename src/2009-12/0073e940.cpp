// from server: 100% by auto
// roc 2009-12 0073e940  unit: RBX::VCollectionService::?$FactoryProduct  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073e940
//
// 0073e940  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0073e943  56                   push esi
// 0073e944  8b7004               mov esi, dword ptr [eax + 4]
// 0073e947  807e3100             cmp byte ptr [esi + 0x31], 0
// 0073e94b  57                   push edi
// 0073e94c  8bf8                 mov edi, eax
// 0073e94e  7531                 jne 0x73e981
// 0073e950  53                   push ebx
// 0073e951  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0073e955  55                   push ebp
// 0073e956  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 0073e95c  8d642400             lea esp, [esp]
// 0073e960  8d460c               lea eax, [esi + 0xc]
// 0073e963  53                   push ebx
// 0073e964  50                   push eax
// 0073e965  ffd5                 call ebp
// 0073e967  83c408               add esp, 8
// 0073e96a  84c0                 test al, al
// 0073e96c  7405                 je 0x73e973
// 0073e96e  8b7608               mov esi, dword ptr [esi + 8]
// 0073e971  eb04                 jmp 0x73e977
// 0073e973  8bfe                 mov edi, esi
// 0073e975  8b36                 mov esi, dword ptr [esi]
// 0073e977  807e3100             cmp byte ptr [esi + 0x31], 0
// 0073e97b  74e3                 je 0x73e960
// 0073e97d  5d                   pop ebp
// 0073e97e  8bc7                 mov eax, edi
// 0073e980  5b                   pop ebx
// 0073e981  5f                   pop edi
// 0073e982  5e                   pop esi
// 0073e983  c20400               ret 4
// standard library map_str<pod8> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
