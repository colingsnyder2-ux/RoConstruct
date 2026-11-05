// from server: 100% by auto
// roc 2010-06 006206c0  unit: RBX::DropperTool  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006206c0
//
// 006206c0  8bc1                 mov eax, ecx
// 006206c2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006206c6  8908                 mov dword ptr [eax], ecx
// 006206c8  c20400               ret 4
// standard library vector<ptr> (function ??0_Aux_cont@std@@QAE@QBV_Container_base_aux@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
