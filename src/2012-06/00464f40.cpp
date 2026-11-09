// from server: 100% by auto
// roc 2012-06 00464f40  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00464f40
//
// 00464f40  8b442404             mov eax, dword ptr [esp + 4]
// 00464f44  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00464f48  3bc1                 cmp eax, ecx
// 00464f4a  7411                 je 0x464f5d
// 00464f4c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00464f50  56                   push esi
// 00464f51  8b32                 mov esi, dword ptr [edx]
// 00464f53  8930                 mov dword ptr [eax], esi
// 00464f55  83c004               add eax, 4
// 00464f58  3bc1                 cmp eax, ecx
// 00464f5a  75f5                 jne 0x464f51
// 00464f5c  5e                   pop esi
// 00464f5d  c3                   ret 
// standard library vector<ptr> (function ??$_Fill@PAPAUT@@PAU1@@std@@YAXPAPAUT@@0ABQAU1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
