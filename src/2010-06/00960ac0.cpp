// from server: 100% by auto
// roc 2010-06 00960ac0  unit: RBX::SphereBuilder  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00960ac0
//
// 00960ac0  8b542404             mov edx, dword ptr [esp + 4]
// 00960ac4  8b02                 mov eax, dword ptr [edx]
// 00960ac6  56                   push esi
// 00960ac7  8b7008               mov esi, dword ptr [eax + 8]
// 00960aca  8932                 mov dword ptr [edx], esi
// 00960acc  8b7008               mov esi, dword ptr [eax + 8]
// 00960acf  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00960ad3  7503                 jne 0x960ad8
// 00960ad5  895604               mov dword ptr [esi + 4], edx
// 00960ad8  8b7204               mov esi, dword ptr [edx + 4]
// 00960adb  897004               mov dword ptr [eax + 4], esi
// 00960ade  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00960ae1  5e                   pop esi
// 00960ae2  3b5104               cmp edx, dword ptr [ecx + 4]
// 00960ae5  750c                 jne 0x960af3
// 00960ae7  894104               mov dword ptr [ecx + 4], eax
// 00960aea  895008               mov dword ptr [eax + 8], edx
// 00960aed  894204               mov dword ptr [edx + 4], eax
// 00960af0  c20400               ret 4
// 00960af3  8b4a04               mov ecx, dword ptr [edx + 4]
// 00960af6  3b5108               cmp edx, dword ptr [ecx + 8]
// 00960af9  750c                 jne 0x960b07
// 00960afb  894108               mov dword ptr [ecx + 8], eax
// 00960afe  895008               mov dword ptr [eax + 8], edx
// 00960b01  894204               mov dword ptr [edx + 4], eax
// 00960b04  c20400               ret 4
// 00960b07  8901                 mov dword ptr [ecx], eax
// 00960b09  895008               mov dword ptr [eax + 8], edx
// 00960b0c  894204               mov dword ptr [edx + 4], eax
// 00960b0f  c20400               ret 4
// standard library set<pod32> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
