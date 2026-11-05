// from server: 100% by auto
// roc 2007-08 005459e0  unit: RBX::MD5HasherImpl  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005459e0
//
// 005459e0  8b542404             mov edx, dword ptr [esp + 4]
// 005459e4  8b02                 mov eax, dword ptr [edx]
// 005459e6  56                   push esi
// 005459e7  8b7008               mov esi, dword ptr [eax + 8]
// 005459ea  8932                 mov dword ptr [edx], esi
// 005459ec  8b7008               mov esi, dword ptr [eax + 8]
// 005459ef  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005459f3  7503                 jne 0x5459f8
// 005459f5  895604               mov dword ptr [esi + 4], edx
// 005459f8  8b7204               mov esi, dword ptr [edx + 4]
// 005459fb  897004               mov dword ptr [eax + 4], esi
// 005459fe  8b4904               mov ecx, dword ptr [ecx + 4]
// 00545a01  3b5104               cmp edx, dword ptr [ecx + 4]
// 00545a04  5e                   pop esi
// 00545a05  750c                 jne 0x545a13
// 00545a07  894104               mov dword ptr [ecx + 4], eax
// 00545a0a  895008               mov dword ptr [eax + 8], edx
// 00545a0d  894204               mov dword ptr [edx + 4], eax
// 00545a10  c20400               ret 4
// 00545a13  8b4a04               mov ecx, dword ptr [edx + 4]
// 00545a16  3b5108               cmp edx, dword ptr [ecx + 8]
// 00545a19  750c                 jne 0x545a27
// 00545a1b  894108               mov dword ptr [ecx + 8], eax
// 00545a1e  895008               mov dword ptr [eax + 8], edx
// 00545a21  894204               mov dword ptr [edx + 4], eax
// 00545a24  c20400               ret 4
// 00545a27  8901                 mov dword ptr [ecx], eax
// 00545a29  895008               mov dword ptr [eax + 8], edx
// 00545a2c  894204               mov dword ptr [edx + 4], eax
// 00545a2f  c20400               ret 4
// standard library set<pod48> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
