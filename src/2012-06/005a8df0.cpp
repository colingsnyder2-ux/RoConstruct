// from server: 100% by auto
// roc 2012-06 005a8df0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a8df0
//
// 005a8df0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005a8df4  8b542408             mov edx, dword ptr [esp + 8]
// 005a8df8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005a8dfc  3bca                 cmp ecx, edx
// 005a8dfe  741c                 je 0x5a8e1c
// 005a8e00  56                   push esi
// 005a8e01  85c0                 test eax, eax
// 005a8e03  740c                 je 0x5a8e11
// 005a8e05  8b31                 mov esi, dword ptr [ecx]
// 005a8e07  8930                 mov dword ptr [eax], esi
// 005a8e09  668b7104             mov si, word ptr [ecx + 4]
// 005a8e0d  66897004             mov word ptr [eax + 4], si
// 005a8e11  83c106               add ecx, 6
// 005a8e14  83c006               add eax, 6
// 005a8e17  3bca                 cmp ecx, edx
// 005a8e19  75e6                 jne 0x5a8e01
// 005a8e1b  5e                   pop esi
// 005a8e1c  c3                   ret 
// standard library vector<podc6> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<podc6>
struct E { char v[6]; };
#include <vector>
template class std::vector<E>;
