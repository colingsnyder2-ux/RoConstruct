// from server: 100% by auto
// roc 2009-12 00702f70  unit: RBX::Assembly  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00702f70
//
// 00702f70  8b542404             mov edx, dword ptr [esp + 4]
// 00702f74  8b4208               mov eax, dword ptr [edx + 8]
// 00702f77  56                   push esi
// 00702f78  8b30                 mov esi, dword ptr [eax]
// 00702f7a  897208               mov dword ptr [edx + 8], esi
// 00702f7d  8b30                 mov esi, dword ptr [eax]
// 00702f7f  807e5100             cmp byte ptr [esi + 0x51], 0
// 00702f83  7503                 jne 0x702f88
// 00702f85  895604               mov dword ptr [esi + 4], edx
// 00702f88  8b7204               mov esi, dword ptr [edx + 4]
// 00702f8b  897004               mov dword ptr [eax + 4], esi
// 00702f8e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00702f91  5e                   pop esi
// 00702f92  3b5104               cmp edx, dword ptr [ecx + 4]
// 00702f95  750b                 jne 0x702fa2
// 00702f97  894104               mov dword ptr [ecx + 4], eax
// 00702f9a  8910                 mov dword ptr [eax], edx
// 00702f9c  894204               mov dword ptr [edx + 4], eax
// 00702f9f  c20400               ret 4
// 00702fa2  8b4a04               mov ecx, dword ptr [edx + 4]
// 00702fa5  3b11                 cmp edx, dword ptr [ecx]
// 00702fa7  750a                 jne 0x702fb3
// 00702fa9  8901                 mov dword ptr [ecx], eax
// 00702fab  8910                 mov dword ptr [eax], edx
// 00702fad  894204               mov dword ptr [edx + 4], eax
// 00702fb0  c20400               ret 4
// 00702fb3  894108               mov dword ptr [ecx + 8], eax
// 00702fb6  8910                 mov dword ptr [eax], edx
// 00702fb8  894204               mov dword ptr [edx + 4], eax
// 00702fbb  c20400               ret 4
// standard library map_int<pod64> (function ?_Lrotate@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@@Z)

// stl: map_int<pod64>
struct E { int v[16]; };
#include <map>
template class std::map<int, E>;
