// from server: 100% by auto
// roc 2010-06 00526ac0  unit: RBX::ViewG3D  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00526ac0
//
// 00526ac0  8b542404             mov edx, dword ptr [esp + 4]
// 00526ac4  8b02                 mov eax, dword ptr [edx]
// 00526ac6  56                   push esi
// 00526ac7  8b7008               mov esi, dword ptr [eax + 8]
// 00526aca  8932                 mov dword ptr [edx], esi
// 00526acc  8b7008               mov esi, dword ptr [eax + 8]
// 00526acf  807e2500             cmp byte ptr [esi + 0x25], 0
// 00526ad3  7503                 jne 0x526ad8
// 00526ad5  895604               mov dword ptr [esi + 4], edx
// 00526ad8  8b7204               mov esi, dword ptr [edx + 4]
// 00526adb  897004               mov dword ptr [eax + 4], esi
// 00526ade  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00526ae1  5e                   pop esi
// 00526ae2  3b5104               cmp edx, dword ptr [ecx + 4]
// 00526ae5  750c                 jne 0x526af3
// 00526ae7  894104               mov dword ptr [ecx + 4], eax
// 00526aea  895008               mov dword ptr [eax + 8], edx
// 00526aed  894204               mov dword ptr [edx + 4], eax
// 00526af0  c20400               ret 4
// 00526af3  8b4a04               mov ecx, dword ptr [edx + 4]
// 00526af6  3b5108               cmp edx, dword ptr [ecx + 8]
// 00526af9  750c                 jne 0x526b07
// 00526afb  894108               mov dword ptr [ecx + 8], eax
// 00526afe  895008               mov dword ptr [eax + 8], edx
// 00526b01  894204               mov dword ptr [edx + 4], eax
// 00526b04  c20400               ret 4
// 00526b07  8901                 mov dword ptr [ecx], eax
// 00526b09  895008               mov dword ptr [eax + 8], edx
// 00526b0c  894204               mov dword ptr [edx + 4], eax
// 00526b0f  c20400               ret 4
// standard library set<pod24> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
