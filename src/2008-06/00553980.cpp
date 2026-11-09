// from server: 100% by auto
// roc 2008-06 00553980  unit: RBX::RenderBase::AggregateChunk  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00553980
//
// 00553980  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00553983  56                   push esi
// 00553984  8b7004               mov esi, dword ptr [eax + 4]
// 00553987  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0055398b  57                   push edi
// 0055398c  8bf8                 mov edi, eax
// 0055398e  7531                 jne 0x5539c1
// 00553990  53                   push ebx
// 00553991  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00553995  55                   push ebp
// 00553996  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 0055399c  8d642400             lea esp, [esp]
// 005539a0  8d460c               lea eax, [esi + 0xc]
// 005539a3  53                   push ebx
// 005539a4  50                   push eax
// 005539a5  ffd5                 call ebp
// 005539a7  83c408               add esp, 8
// 005539aa  84c0                 test al, al
// 005539ac  7405                 je 0x5539b3
// 005539ae  8b7608               mov esi, dword ptr [esi + 8]
// 005539b1  eb04                 jmp 0x5539b7
// 005539b3  8bfe                 mov edi, esi
// 005539b5  8b36                 mov esi, dword ptr [esi]
// 005539b7  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005539bb  74e3                 je 0x5539a0
// 005539bd  5d                   pop ebp
// 005539be  8bc7                 mov eax, edi
// 005539c0  5b                   pop ebx
// 005539c1  5f                   pop edi
// 005539c2  5e                   pop esi
// 005539c3  c20400               ret 4
// standard library map_str<ptr> (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
