// from server: 100% by auto
// roc 2009-12 00666410  unit: RBX::DataModel::PAVGenericJob::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00666410
//
// 00666410  8b542404             mov edx, dword ptr [esp + 4]
// 00666414  8b4208               mov eax, dword ptr [edx + 8]
// 00666417  56                   push esi
// 00666418  8b30                 mov esi, dword ptr [eax]
// 0066641a  897208               mov dword ptr [edx + 8], esi
// 0066641d  8b30                 mov esi, dword ptr [eax]
// 0066641f  807e1900             cmp byte ptr [esi + 0x19], 0
// 00666423  7503                 jne 0x666428
// 00666425  895604               mov dword ptr [esi + 4], edx
// 00666428  8b7204               mov esi, dword ptr [edx + 4]
// 0066642b  897004               mov dword ptr [eax + 4], esi
// 0066642e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00666431  5e                   pop esi
// 00666432  3b5104               cmp edx, dword ptr [ecx + 4]
// 00666435  750b                 jne 0x666442
// 00666437  894104               mov dword ptr [ecx + 4], eax
// 0066643a  8910                 mov dword ptr [eax], edx
// 0066643c  894204               mov dword ptr [edx + 4], eax
// 0066643f  c20400               ret 4
// 00666442  8b4a04               mov ecx, dword ptr [edx + 4]
// 00666445  3b11                 cmp edx, dword ptr [ecx]
// 00666447  750a                 jne 0x666453
// 00666449  8901                 mov dword ptr [ecx], eax
// 0066644b  8910                 mov dword ptr [eax], edx
// 0066644d  894204               mov dword ptr [edx + 4], eax
// 00666450  c20400               ret 4
// 00666453  894108               mov dword ptr [ecx + 8], eax
// 00666456  8910                 mov dword ptr [eax], edx
// 00666458  894204               mov dword ptr [edx + 4], eax
// 0066645b  c20400               ret 4
// standard library set<double> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
