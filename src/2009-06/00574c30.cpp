// from server: 100% by auto
// roc 2009-06 00574c30  unit: G3D::GCamera  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574c30
//
// 00574c30  51                   push ecx
// 00574c31  8a442403             mov al, byte ptr [esp + 3]
// 00574c35  59                   pop ecx
// 00574c36  c3                   ret 
// standard library vector<ptr> (function ??$_Ptr_cat@PAPAUT@@PAPAU1@@std@@YA?AU_Scalar_ptr_iterator_tag@0@AAPAPAUT@@0@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
