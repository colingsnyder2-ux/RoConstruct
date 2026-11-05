// from server: 100% by auto
// roc 2012-06 00746250  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00746250
//
// 00746250  8bc1                 mov eax, ecx
// 00746252  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00746256  8908                 mov dword ptr [eax], ecx
// 00746258  c20400               ret 4
// standard library vector<ptr> (function ??0_Aux_cont@std@@QAE@QBV_Container_base_aux@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
