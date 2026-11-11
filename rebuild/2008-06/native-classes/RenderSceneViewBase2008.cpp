// 2008-06 native RBX::ViewBase (inactive; document-swap flags, /O2). Rows: ctor 004d8a20, dtor 004d8920 and ??_G
// 004d8ac0 (emitted with the vtable, calls the dtor out of line). The dtor deletes the materialFactory auto_ptr through
// the out-of-line ~MaterialFactory 004d7460 (ViewNew/MaterialFactory2008.h declares only that destructor).
// >>> native-status (generated) -- do not edit >>>
// RenderSceneViewBase2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 9e391949 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<G3D::Texture>;
template class std::auto_ptr<G3D::TextureManager>;
template class std::auto_ptr<RBX::RenderBase::SceneManager>;
template class std::auto_ptr<RBX::ViewNew::MaterialFactory>;
