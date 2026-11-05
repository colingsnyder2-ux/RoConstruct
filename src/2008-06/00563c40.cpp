// from server: 100% by auto
// roc 2008-06 00563c40  unit: RBX::VDebugSettings::?$FactoryProduct  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00563c40
//
// 00563c40  8b442404             mov eax, dword ptr [esp + 4]
// 00563c44  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00563c48  3bc1                 cmp eax, ecx
// 00563c4a  7411                 je 0x563c5d
// 00563c4c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00563c50  56                   push esi
// 00563c51  8b32                 mov esi, dword ptr [edx]
// 00563c53  8930                 mov dword ptr [eax], esi
// 00563c55  83c004               add eax, 4
// 00563c58  3bc1                 cmp eax, ecx
// 00563c5a  75f5                 jne 0x563c51
// 00563c5c  5e                   pop esi
// 00563c5d  c3                   ret 
// standard library vector<ptr> (function ??$_Fill@PAPAUT@@PAU1@@std@@YAXPAPAUT@@0ABQAU1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
