// from server: 100% by auto
// roc 2009-06 0045a380  unit: CRobloxWnd::PartDropTarget  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045a380
//
// 0045a380  8bc1                 mov eax, ecx
// 0045a382  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045a386  8908                 mov dword ptr [eax], ecx
// 0045a388  c20400               ret 4
// standard library vector<ptr> (function ??0_Aux_cont@std@@QAE@QBV_Container_base_aux@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
