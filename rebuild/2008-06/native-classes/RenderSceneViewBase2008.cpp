// 2008-06 native RBX::ViewBase (inactive; document-swap flags, /O2). Rows: ctor 004d8a20 and ??_G 004d8ac0 (emitted
// with the vtable, calls the dtor out of line). The dtor 004d8920 deletes the materialFactory auto_ptr, whose 2008 class
// (0x10 bytes, dtor 004d7460) is not declared: it is built only with NATIVE_VIEWBASE_PENDING.
#include "RenderLib/ViewBase2008.h"
#ifdef NATIVE_VIEWBASE_PENDING
// Pending: a complete 2008 ViewNew::MaterialFactory (0x10 bytes, out-of-line dtor 004d7460) is needed by the
// auto_ptr<MaterialFactory> member's destructor. The recorder generates this header under out/ for the pending build.
#include "ViewNewMaterialFactoryPending.h"
#endif

namespace RBX
{
	ViewBase::ViewBase(boost::shared_ptr<DataModel> dataModel)
		: dataModel(dataModel),
		  lightingValid(false)
	{
	}

#ifdef NATIVE_VIEWBASE_PENDING
	ViewBase::~ViewBase()
	{
	}
#endif
}
