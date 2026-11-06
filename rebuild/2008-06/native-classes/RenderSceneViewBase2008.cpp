// 2008-06 native RBX::ViewBase (inactive; document-swap flags, /O2). Rows: ctor 004d8a20, dtor 004d8920 and ??_G
// 004d8ac0 (emitted with the vtable, calls the dtor out of line). The dtor deletes the materialFactory auto_ptr through
// the out-of-line ~MaterialFactory 004d7460 (ViewNew/MaterialFactory2008.h declares only that destructor).
#include "RenderLib/ViewBase2008.h"

namespace RBX
{
	ViewBase::ViewBase(boost::shared_ptr<DataModel> dataModel)
		: dataModel(dataModel),
		  lightingValid(false)
	{
	}

	ViewBase::~ViewBase()
	{
	}
}
