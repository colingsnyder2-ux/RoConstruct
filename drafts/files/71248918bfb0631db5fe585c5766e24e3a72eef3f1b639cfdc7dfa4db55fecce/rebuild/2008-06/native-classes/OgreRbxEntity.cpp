// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "OgreRbx/RbxEntity2008.h"
#include <OgreSubEntity.h>

namespace Ogre
{
	// 0067c6a0: slot 54 of vtable 0084e45c.  The name remains an address
	// placeholder; receiver, bool argument, base SubEntityList iteration and
	// virtual setVisible call are all target-derived.
	void RbxEntity::func_0067c6a0(bool visible)
	{
		for (int i = 0; i < (int)mSubEntityList.size(); ++i)
			mSubEntityList[i]->setVisible(visible);
	}
}
