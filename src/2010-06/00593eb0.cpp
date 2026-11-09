// from server: 100% by auto
// roc 2010-06 00593eb0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00593eb0
//
// 00593eb0  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00593eb3  56                   push esi
// 00593eb4  8b7004               mov esi, dword ptr [eax + 4]
// 00593eb7  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00593ebb  57                   push edi
// 00593ebc  8bf8                 mov edi, eax
// 00593ebe  7531                 jne 0x593ef1
// 00593ec0  53                   push ebx
// 00593ec1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00593ec5  55                   push ebp
// 00593ec6  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 00593ecc  8d642400             lea esp, [esp]
// 00593ed0  8d460c               lea eax, [esi + 0xc]
// 00593ed3  53                   push ebx
// 00593ed4  50                   push eax
// 00593ed5  ffd5                 call ebp
// 00593ed7  83c408               add esp, 8
// 00593eda  84c0                 test al, al
// 00593edc  7405                 je 0x593ee3
// 00593ede  8b7608               mov esi, dword ptr [esi + 8]
// 00593ee1  eb04                 jmp 0x593ee7
// 00593ee3  8bfe                 mov edi, esi
// 00593ee5  8b36                 mov esi, dword ptr [esi]
// 00593ee7  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00593eeb  74e3                 je 0x593ed0
// 00593eed  5d                   pop ebp
// 00593eee  8bc7                 mov eax, edi
// 00593ef0  5b                   pop ebx
// 00593ef1  5f                   pop edi
// 00593ef2  5e                   pop esi
// 00593ef3  c20400               ret 4
// standard library map_str<ptr> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
