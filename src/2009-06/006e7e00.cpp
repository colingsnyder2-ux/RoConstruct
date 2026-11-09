// from server: 100% by auto
// roc 2009-06 006e7e00  unit: RBX::EquationDisplay  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e7e00
//
// 006e7e00  8b442404             mov eax, dword ptr [esp + 4]
// 006e7e04  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e7e08  3bc1                 cmp eax, ecx
// 006e7e0a  7411                 je 0x6e7e1d
// 006e7e0c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006e7e10  56                   push esi
// 006e7e11  8b32                 mov esi, dword ptr [edx]
// 006e7e13  8930                 mov dword ptr [eax], esi
// 006e7e15  83c004               add eax, 4
// 006e7e18  3bc1                 cmp eax, ecx
// 006e7e1a  75f5                 jne 0x6e7e11
// 006e7e1c  5e                   pop esi
// 006e7e1d  c3                   ret 
// standard library vector<ptr> (function ??$_Fill@PAPAUT@@PAU1@@std@@YAXPAPAUT@@0ABQAU1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
