// from server: 100% by auto
// roc 2009-06 00574e90  unit: G3D::BinaryInput  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574e90
//
// 00574e90  8b442404             mov eax, dword ptr [esp + 4]
// 00574e94  8b00                 mov eax, dword ptr [eax]
// 00574e96  c3                   ret 
// standard library vector<ptr> (function ??$_Checked_base@PAPAUT@@@std@@YAPAPAUT@@AAPAPAU1@U_Unchanged_checked_iterator_base_type_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
