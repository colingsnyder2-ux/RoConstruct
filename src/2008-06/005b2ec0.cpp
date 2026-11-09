// from server: 100% by auto
// roc 2008-06 005b2ec0  unit: RBX::VHat::?$FactoryProduct  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b2ec0
//
// 005b2ec0  8b542404             mov edx, dword ptr [esp + 4]
// 005b2ec4  8b02                 mov eax, dword ptr [edx]
// 005b2ec6  56                   push esi
// 005b2ec7  8b7008               mov esi, dword ptr [eax + 8]
// 005b2eca  8932                 mov dword ptr [edx], esi
// 005b2ecc  8b7008               mov esi, dword ptr [eax + 8]
// 005b2ecf  807e2100             cmp byte ptr [esi + 0x21], 0
// 005b2ed3  7503                 jne 0x5b2ed8
// 005b2ed5  895604               mov dword ptr [esi + 4], edx
// 005b2ed8  8b7204               mov esi, dword ptr [edx + 4]
// 005b2edb  897004               mov dword ptr [eax + 4], esi
// 005b2ede  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005b2ee1  5e                   pop esi
// 005b2ee2  3b5104               cmp edx, dword ptr [ecx + 4]
// 005b2ee5  750c                 jne 0x5b2ef3
// 005b2ee7  894104               mov dword ptr [ecx + 4], eax
// 005b2eea  895008               mov dword ptr [eax + 8], edx
// 005b2eed  894204               mov dword ptr [edx + 4], eax
// 005b2ef0  c20400               ret 4
// 005b2ef3  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b2ef6  3b5108               cmp edx, dword ptr [ecx + 8]
// 005b2ef9  750c                 jne 0x5b2f07
// 005b2efb  894108               mov dword ptr [ecx + 8], eax
// 005b2efe  895008               mov dword ptr [eax + 8], edx
// 005b2f01  894204               mov dword ptr [edx + 4], eax
// 005b2f04  c20400               ret 4
// 005b2f07  8901                 mov dword ptr [ecx], eax
// 005b2f09  895008               mov dword ptr [eax + 8], edx
// 005b2f0c  894204               mov dword ptr [edx + 4], eax
// 005b2f0f  c20400               ret 4
// standard library set<pod20> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
