// from server: 100% by auto
// roc 2007-08 005de4c0  unit: RBX::VMotorFeature::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005de4c0
//
// 005de4c0  8b542404             mov edx, dword ptr [esp + 4]
// 005de4c4  8b4208               mov eax, dword ptr [edx + 8]
// 005de4c7  56                   push esi
// 005de4c8  8b30                 mov esi, dword ptr [eax]
// 005de4ca  897208               mov dword ptr [edx + 8], esi
// 005de4cd  8b30                 mov esi, dword ptr [eax]
// 005de4cf  807e1900             cmp byte ptr [esi + 0x19], 0
// 005de4d3  7503                 jne 0x5de4d8
// 005de4d5  895604               mov dword ptr [esi + 4], edx
// 005de4d8  8b7204               mov esi, dword ptr [edx + 4]
// 005de4db  897004               mov dword ptr [eax + 4], esi
// 005de4de  8b4904               mov ecx, dword ptr [ecx + 4]
// 005de4e1  3b5104               cmp edx, dword ptr [ecx + 4]
// 005de4e4  5e                   pop esi
// 005de4e5  750b                 jne 0x5de4f2
// 005de4e7  894104               mov dword ptr [ecx + 4], eax
// 005de4ea  8910                 mov dword ptr [eax], edx
// 005de4ec  894204               mov dword ptr [edx + 4], eax
// 005de4ef  c20400               ret 4
// 005de4f2  8b4a04               mov ecx, dword ptr [edx + 4]
// 005de4f5  3b11                 cmp edx, dword ptr [ecx]
// 005de4f7  750a                 jne 0x5de503
// 005de4f9  8901                 mov dword ptr [ecx], eax
// 005de4fb  8910                 mov dword ptr [eax], edx
// 005de4fd  894204               mov dword ptr [edx + 4], eax
// 005de500  c20400               ret 4
// 005de503  894108               mov dword ptr [ecx + 8], eax
// 005de506  8910                 mov dword ptr [eax], edx
// 005de508  894204               mov dword ptr [edx + 4], eax
// 005de50b  c20400               ret 4
// standard library set<double> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
