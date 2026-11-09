// from server: 100% by auto
// roc 2009-12 0055aee0  unit: RBX::Network::ServerReplicator  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055aee0
//
// 0055aee0  8b542404             mov edx, dword ptr [esp + 4]
// 0055aee4  8b02                 mov eax, dword ptr [edx]
// 0055aee6  56                   push esi
// 0055aee7  8b7008               mov esi, dword ptr [eax + 8]
// 0055aeea  8932                 mov dword ptr [edx], esi
// 0055aeec  8b7008               mov esi, dword ptr [eax + 8]
// 0055aeef  807e2500             cmp byte ptr [esi + 0x25], 0
// 0055aef3  7503                 jne 0x55aef8
// 0055aef5  895604               mov dword ptr [esi + 4], edx
// 0055aef8  8b7204               mov esi, dword ptr [edx + 4]
// 0055aefb  897004               mov dword ptr [eax + 4], esi
// 0055aefe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0055af01  5e                   pop esi
// 0055af02  3b5104               cmp edx, dword ptr [ecx + 4]
// 0055af05  750c                 jne 0x55af13
// 0055af07  894104               mov dword ptr [ecx + 4], eax
// 0055af0a  895008               mov dword ptr [eax + 8], edx
// 0055af0d  894204               mov dword ptr [edx + 4], eax
// 0055af10  c20400               ret 4
// 0055af13  8b4a04               mov ecx, dword ptr [edx + 4]
// 0055af16  3b5108               cmp edx, dword ptr [ecx + 8]
// 0055af19  750c                 jne 0x55af27
// 0055af1b  894108               mov dword ptr [ecx + 8], eax
// 0055af1e  895008               mov dword ptr [eax + 8], edx
// 0055af21  894204               mov dword ptr [edx + 4], eax
// 0055af24  c20400               ret 4
// 0055af27  8901                 mov dword ptr [ecx], eax
// 0055af29  895008               mov dword ptr [eax + 8], edx
// 0055af2c  894204               mov dword ptr [edx + 4], eax
// 0055af2f  c20400               ret 4
// standard library set<pod24> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
