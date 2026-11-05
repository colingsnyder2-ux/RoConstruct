// from server: 100% by auto
// roc 2010-06 0050fec0  unit: RBX::VInstance::?$Association::Item  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0050fec0
//
// 0050fec0  8b442404             mov eax, dword ptr [esp + 4]
// 0050fec4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0050fec8  3bc1                 cmp eax, ecx
// 0050feca  7411                 je 0x50fedd
// 0050fecc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0050fed0  56                   push esi
// 0050fed1  8b32                 mov esi, dword ptr [edx]
// 0050fed3  8930                 mov dword ptr [eax], esi
// 0050fed5  83c004               add eax, 4
// 0050fed8  3bc1                 cmp eax, ecx
// 0050feda  75f5                 jne 0x50fed1
// 0050fedc  5e                   pop esi
// 0050fedd  c3                   ret 
// standard library vector<ptr> (function ??$_Fill@PAPAUT@@PAU1@@std@@YAXPAPAUT@@0ABQAU1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
