// from server: 100% by auto
// roc 2008-06 004abda0  unit: RBX::Network::Replicator  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004abda0
//
// 004abda0  8b542404             mov edx, dword ptr [esp + 4]
// 004abda4  8b4208               mov eax, dword ptr [edx + 8]
// 004abda7  56                   push esi
// 004abda8  8b30                 mov esi, dword ptr [eax]
// 004abdaa  897208               mov dword ptr [edx + 8], esi
// 004abdad  8b30                 mov esi, dword ptr [eax]
// 004abdaf  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 004abdb3  7503                 jne 0x4abdb8
// 004abdb5  895604               mov dword ptr [esi + 4], edx
// 004abdb8  8b7204               mov esi, dword ptr [edx + 4]
// 004abdbb  897004               mov dword ptr [eax + 4], esi
// 004abdbe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004abdc1  5e                   pop esi
// 004abdc2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004abdc5  750b                 jne 0x4abdd2
// 004abdc7  894104               mov dword ptr [ecx + 4], eax
// 004abdca  8910                 mov dword ptr [eax], edx
// 004abdcc  894204               mov dword ptr [edx + 4], eax
// 004abdcf  c20400               ret 4
// 004abdd2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004abdd5  3b11                 cmp edx, dword ptr [ecx]
// 004abdd7  750a                 jne 0x4abde3
// 004abdd9  8901                 mov dword ptr [ecx], eax
// 004abddb  8910                 mov dword ptr [eax], edx
// 004abddd  894204               mov dword ptr [edx + 4], eax
// 004abde0  c20400               ret 4
// 004abde3  894108               mov dword ptr [ecx + 8], eax
// 004abde6  8910                 mov dword ptr [eax], edx
// 004abde8  894204               mov dword ptr [edx + 4], eax
// 004abdeb  c20400               ret 4
// standard library set<pod48> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
