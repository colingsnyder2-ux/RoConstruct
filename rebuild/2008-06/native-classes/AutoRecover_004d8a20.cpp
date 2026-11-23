// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// RenderSceneViewBase2008.cpp
// 2008-06 native RBX::ViewBase constructor 004d8a20.
#include "RenderLib/ViewBase2008.h"

namespace RBX
{
	ViewBase::ViewBase(boost::shared_ptr<DataModel> dataModel)
		: dataModel(dataModel),
		  lightingValid(false)
	{
	}
}
