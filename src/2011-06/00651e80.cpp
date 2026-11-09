// from server: 100% by auto
// roc 2011-06 00651e80  unit: std::D::DU?$char_traits::DV?$basic_streambuf::?$lexical_stream_limited_src  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00651e80
//
// 00651e80  8bc1                 mov eax, ecx
// 00651e82  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00651e86  8908                 mov dword ptr [eax], ecx
// 00651e88  c20400               ret 4
// standard library vector<ptr> (function ??0_Aux_cont@std@@QAE@QBV_Container_base_aux@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
