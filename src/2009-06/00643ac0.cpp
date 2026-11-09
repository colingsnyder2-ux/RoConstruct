// from server: 100% by auto
// roc 2009-06 00643ac0  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00643ac0
//
// 00643ac0  8b542404             mov edx, dword ptr [esp + 4]
// 00643ac4  8b02                 mov eax, dword ptr [edx]
// 00643ac6  56                   push esi
// 00643ac7  8b7008               mov esi, dword ptr [eax + 8]
// 00643aca  8932                 mov dword ptr [edx], esi
// 00643acc  8b7008               mov esi, dword ptr [eax + 8]
// 00643acf  807e1900             cmp byte ptr [esi + 0x19], 0
// 00643ad3  7503                 jne 0x643ad8
// 00643ad5  895604               mov dword ptr [esi + 4], edx
// 00643ad8  8b7204               mov esi, dword ptr [edx + 4]
// 00643adb  897004               mov dword ptr [eax + 4], esi
// 00643ade  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00643ae1  5e                   pop esi
// 00643ae2  3b5104               cmp edx, dword ptr [ecx + 4]
// 00643ae5  750c                 jne 0x643af3
// 00643ae7  894104               mov dword ptr [ecx + 4], eax
// 00643aea  895008               mov dword ptr [eax + 8], edx
// 00643aed  894204               mov dword ptr [edx + 4], eax
// 00643af0  c20400               ret 4
// 00643af3  8b4a04               mov ecx, dword ptr [edx + 4]
// 00643af6  3b5108               cmp edx, dword ptr [ecx + 8]
// 00643af9  750c                 jne 0x643b07
// 00643afb  894108               mov dword ptr [ecx + 8], eax
// 00643afe  895008               mov dword ptr [eax + 8], edx
// 00643b01  894204               mov dword ptr [edx + 4], eax
// 00643b04  c20400               ret 4
// 00643b07  8901                 mov dword ptr [ecx], eax
// 00643b09  895008               mov dword ptr [eax + 8], edx
// 00643b0c  894204               mov dword ptr [edx + 4], eax
// 00643b0f  c20400               ret 4
// standard library set<double> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
