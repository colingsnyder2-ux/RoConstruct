// from server: 100% by auto
// roc 2009-06 006e1fa0  unit: RBX::ChatOutput  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e1fa0
//
// 006e1fa0  8b542404             mov edx, dword ptr [esp + 4]
// 006e1fa4  8b02                 mov eax, dword ptr [edx]
// 006e1fa6  56                   push esi
// 006e1fa7  8b7008               mov esi, dword ptr [eax + 8]
// 006e1faa  8932                 mov dword ptr [edx], esi
// 006e1fac  8b7008               mov esi, dword ptr [eax + 8]
// 006e1faf  807e3100             cmp byte ptr [esi + 0x31], 0
// 006e1fb3  7503                 jne 0x6e1fb8
// 006e1fb5  895604               mov dword ptr [esi + 4], edx
// 006e1fb8  8b7204               mov esi, dword ptr [edx + 4]
// 006e1fbb  897004               mov dword ptr [eax + 4], esi
// 006e1fbe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006e1fc1  5e                   pop esi
// 006e1fc2  3b5104               cmp edx, dword ptr [ecx + 4]
// 006e1fc5  750c                 jne 0x6e1fd3
// 006e1fc7  894104               mov dword ptr [ecx + 4], eax
// 006e1fca  895008               mov dword ptr [eax + 8], edx
// 006e1fcd  894204               mov dword ptr [edx + 4], eax
// 006e1fd0  c20400               ret 4
// 006e1fd3  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e1fd6  3b5108               cmp edx, dword ptr [ecx + 8]
// 006e1fd9  750c                 jne 0x6e1fe7
// 006e1fdb  894108               mov dword ptr [ecx + 8], eax
// 006e1fde  895008               mov dword ptr [eax + 8], edx
// 006e1fe1  894204               mov dword ptr [edx + 4], eax
// 006e1fe4  c20400               ret 4
// 006e1fe7  8901                 mov dword ptr [ecx], eax
// 006e1fe9  895008               mov dword ptr [eax + 8], edx
// 006e1fec  894204               mov dword ptr [edx + 4], eax
// 006e1fef  c20400               ret 4
// standard library set<pod36> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
