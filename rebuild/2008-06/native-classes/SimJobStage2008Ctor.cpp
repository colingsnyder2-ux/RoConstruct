// 2008-06 native RBX::SimJobStage constructor (inactive); evidence in native-headers/v8world/SimJobStage2008.h.
// Split from native-classes/SimJobStage2008.cpp because it news the 2008 Kernel (native-headers/v8kernel/Kernel2008.h,
// 0x24), which cannot share a unit with the donor v8world/Edge.h (IPipelined.h includes the donor v8kernel/Kernel.h).
// Verified by tests/record_native_kernel_stages.py: the constructor 0064d300 and the scalar deleting destructor
// 0064d380 (the destructor is inline; vtable 0084b174 is emitted here).
#include "v8world/SimJobStage2008.h"
#include "v8world/SimJob2008.h"
#include "v8kernel/Kernel2008.h"

namespace RBX
{
	// 0064d300
	SimJobStage::SimJobStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new Kernel(this), world)
	{
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::SimJob *> >;
template class std::allocator<RBX::SimJob *>;
template class std::allocator<std::_List_nod<RBX::SimJob *,std::allocator<RBX::SimJob *> >::_Node *>;
template class std::allocator<std::_List_nod<RBX::SimJob *,std::allocator<RBX::SimJob *> >::_Node>;
