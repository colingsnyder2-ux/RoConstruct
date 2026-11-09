// from server: 100% by auto
// roc 2009-12 00702b60  unit: RBX::Assembly  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00702b60
//
// 00702b60  8b542404             mov edx, dword ptr [esp + 4]
// 00702b64  8b02                 mov eax, dword ptr [edx]
// 00702b66  56                   push esi
// 00702b67  8b7008               mov esi, dword ptr [eax + 8]
// 00702b6a  8932                 mov dword ptr [edx], esi
// 00702b6c  8b7008               mov esi, dword ptr [eax + 8]
// 00702b6f  807e5100             cmp byte ptr [esi + 0x51], 0
// 00702b73  7503                 jne 0x702b78
// 00702b75  895604               mov dword ptr [esi + 4], edx
// 00702b78  8b7204               mov esi, dword ptr [edx + 4]
// 00702b7b  897004               mov dword ptr [eax + 4], esi
// 00702b7e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00702b81  5e                   pop esi
// 00702b82  3b5104               cmp edx, dword ptr [ecx + 4]
// 00702b85  750c                 jne 0x702b93
// 00702b87  894104               mov dword ptr [ecx + 4], eax
// 00702b8a  895008               mov dword ptr [eax + 8], edx
// 00702b8d  894204               mov dword ptr [edx + 4], eax
// 00702b90  c20400               ret 4
// 00702b93  8b4a04               mov ecx, dword ptr [edx + 4]
// 00702b96  3b5108               cmp edx, dword ptr [ecx + 8]
// 00702b99  750c                 jne 0x702ba7
// 00702b9b  894108               mov dword ptr [ecx + 8], eax
// 00702b9e  895008               mov dword ptr [eax + 8], edx
// 00702ba1  894204               mov dword ptr [edx + 4], eax
// 00702ba4  c20400               ret 4
// 00702ba7  8901                 mov dword ptr [ecx], eax
// 00702ba9  895008               mov dword ptr [eax + 8], edx
// 00702bac  894204               mov dword ptr [edx + 4], eax
// 00702baf  c20400               ret 4
// standard library map_int<pod64> (function ?_Rrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod64>
struct E { int v[16]; };
#include <map>
template class std::map<int, E>;
