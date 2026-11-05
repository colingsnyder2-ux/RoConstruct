// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_9fcf1aaf140cd5f6.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8datamodel/RootInstance.h", "roc_unit_24e59ff16dfbccb3.cpp")
#pragma include_alias("v8world/World.h", "roc_unit_dd7760670f6bcddb.cpp")
#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "tool/Dragger.h"
#include "v8world/ContactManager.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/MouseCommand.h"

namespace RBX
{
	MegaDragger::MegaDragger(PartInstance* mousePartPtr, const std::vector<PVInstance*>& pvInstances, RootInstance* rootInstance)
		: mousePart(shared_from(mousePartPtr)),
		  dragParts(),
		  joined(true),
		  rootInstance(rootInstance),
          contactManager(rootInstance->getWorld()->getContactManager())
	{
		DragUtilities::pvsToParts(pvInstances, dragParts);
	}

	MegaDragger::MegaDragger(PartInstance* mousePartPtr, const std::vector<boost::weak_ptr<PartInstance>>& partArray, RootInstance* rootInstance)
		: mousePart(shared_from(mousePartPtr)),
		  dragParts(partArray),
		  rootInstance(rootInstance),
		  joined(true),
		  contactManager(rootInstance->getWorld()->getContactManager())
	{
	}


}
