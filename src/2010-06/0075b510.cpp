// from server: 100% by auto
// roc 2010-06 0075b510  unit: RBX::ParallelRampPoly  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075b510
//
// 0075b510  8b542404             mov edx, dword ptr [esp + 4]
// 0075b514  8b4208               mov eax, dword ptr [edx + 8]
// 0075b517  56                   push esi
// 0075b518  8b30                 mov esi, dword ptr [eax]
// 0075b51a  897208               mov dword ptr [edx + 8], esi
// 0075b51d  8b30                 mov esi, dword ptr [eax]
// 0075b51f  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 0075b523  7503                 jne 0x75b528
// 0075b525  895604               mov dword ptr [esi + 4], edx
// 0075b528  8b7204               mov esi, dword ptr [edx + 4]
// 0075b52b  897004               mov dword ptr [eax + 4], esi
// 0075b52e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0075b531  5e                   pop esi
// 0075b532  3b5104               cmp edx, dword ptr [ecx + 4]
// 0075b535  750b                 jne 0x75b542
// 0075b537  894104               mov dword ptr [ecx + 4], eax
// 0075b53a  8910                 mov dword ptr [eax], edx
// 0075b53c  894204               mov dword ptr [edx + 4], eax
// 0075b53f  c20400               ret 4
// 0075b542  8b4a04               mov ecx, dword ptr [edx + 4]
// 0075b545  3b11                 cmp edx, dword ptr [ecx]
// 0075b547  750a                 jne 0x75b553
// 0075b549  8901                 mov dword ptr [ecx], eax
// 0075b54b  8910                 mov dword ptr [eax], edx
// 0075b54d  894204               mov dword ptr [edx + 4], eax
// 0075b550  c20400               ret 4
// 0075b553  894108               mov dword ptr [ecx + 8], eax
// 0075b556  8910                 mov dword ptr [eax], edx
// 0075b558  894204               mov dword ptr [edx + 4], eax
// 0075b55b  c20400               ret 4
// standard library set<pod16> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
