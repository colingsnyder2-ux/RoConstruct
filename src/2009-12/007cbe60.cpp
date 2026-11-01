// from server: 100% by auto
// roc 2009-12 007cbe60  unit: RBX::EquationDisplay  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cbe60
//
// 007cbe60  8b442404             mov eax, dword ptr [esp + 4]
// 007cbe64  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007cbe68  3bc1                 cmp eax, ecx
// 007cbe6a  7411                 je 0x7cbe7d
// 007cbe6c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007cbe70  56                   push esi
// 007cbe71  8b32                 mov esi, dword ptr [edx]
// 007cbe73  8930                 mov dword ptr [eax], esi
// 007cbe75  83c004               add eax, 4
// 007cbe78  3bc1                 cmp eax, ecx
// 007cbe7a  75f5                 jne 0x7cbe71
// 007cbe7c  5e                   pop esi
// 007cbe7d  c3                   ret 
// standard library vector<ptr> (function ??$_Fill@PAPAUT@@PAU1@@std@@YAXPAPAUT@@0ABQAU1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
