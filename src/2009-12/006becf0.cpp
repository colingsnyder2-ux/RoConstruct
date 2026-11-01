// from server: 100% by auto
// roc 2009-12 006becf0  unit: RBX::VInstance::?$NonFactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006becf0
//
// 006becf0  53                   push ebx
// 006becf1  56                   push esi
// 006becf2  57                   push edi
// 006becf3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006becf7  807f3500             cmp byte ptr [edi + 0x35], 0
// 006becfb  8bd9                 mov ebx, ecx
// 006becfd  8bf7                 mov esi, edi
// 006becff  7527                 jne 0x6bed28
// 006bed01  8b4608               mov eax, dword ptr [esi + 8]
// 006bed04  50                   push eax
// 006bed05  8bcb                 mov ecx, ebx
// 006bed07  e8e4ffffff           call 0x6becf0
// 006bed0c  8b36                 mov esi, dword ptr [esi]
// 006bed0e  8d4f0c               lea ecx, [edi + 0xc]
// 006bed11  ff15e4b69800         call dword ptr [0x98b6e4]
// 006bed17  57                   push edi
// 006bed18  e83d4b1300           call 0x7f385a
// 006bed1d  83c404               add esp, 4
// 006bed20  807e3500             cmp byte ptr [esi + 0x35], 0
// 006bed24  8bfe                 mov edi, esi
// 006bed26  74d9                 je 0x6bed01
// 006bed28  5f                   pop edi
// 006bed29  5e                   pop esi
// 006bed2a  5b                   pop ebx
// 006bed2b  c20400               ret 4
// standard library map_str<pod12> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
