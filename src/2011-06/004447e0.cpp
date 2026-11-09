// from server: 100% by auto
// roc 2011-06 004447e0  unit: IIHAAH::?$CMap  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004447e0
//
// 004447e0  8b442404             mov eax, dword ptr [esp + 4]
// 004447e4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004447e8  3bc1                 cmp eax, ecx
// 004447ea  7411                 je 0x4447fd
// 004447ec  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004447f0  56                   push esi
// 004447f1  8b32                 mov esi, dword ptr [edx]
// 004447f3  8930                 mov dword ptr [eax], esi
// 004447f5  83c004               add eax, 4
// 004447f8  3bc1                 cmp eax, ecx
// 004447fa  75f5                 jne 0x4447f1
// 004447fc  5e                   pop esi
// 004447fd  c3                   ret 
// standard library vector<ptr> (function ??$_Fill@PAPAUT@@PAU1@@std@@YAXPAPAUT@@0ABQAU1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
