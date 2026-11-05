// from server: 100% by auto
// roc 2012-06 005a8dc0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a8dc0
//
// 005a8dc0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005a8dc4  85c9                 test ecx, ecx
// 005a8dc6  7622                 jbe 0x5a8dea
// 005a8dc8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005a8dcc  8b442404             mov eax, dword ptr [esp + 4]
// 005a8dd0  56                   push esi
// 005a8dd1  85c0                 test eax, eax
// 005a8dd3  740c                 je 0x5a8de1
// 005a8dd5  8b32                 mov esi, dword ptr [edx]
// 005a8dd7  8930                 mov dword ptr [eax], esi
// 005a8dd9  668b7204             mov si, word ptr [edx + 4]
// 005a8ddd  66897004             mov word ptr [eax + 4], si
// 005a8de1  49                   dec ecx
// 005a8de2  83c006               add eax, 6
// 005a8de5  85c9                 test ecx, ecx
// 005a8de7  77e8                 ja 0x5a8dd1
// 005a8de9  5e                   pop esi
// 005a8dea  c3                   ret 
// standard library vector<podc6> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<podc6>
struct E { char v[6]; };
#include <vector>
template class std::vector<E>;
