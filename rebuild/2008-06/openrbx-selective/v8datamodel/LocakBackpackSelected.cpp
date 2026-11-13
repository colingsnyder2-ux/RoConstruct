// PORT: 2008 MSVC build uses original API; no modern-compiler compatibility prelude.
#include "network/Player.h"
#include "network/Players.h"
#include "util/Events.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/LocalBackpack.h"

#include <algorithm>

namespace RBX {

// PORT: selective unit; remaining functions use the 2008 object.

void LocalBackpack::removeBackpackItem(BackpackItem* item)
{
	for (unsigned int i = 0; i < numChildren(); ++i) {
		LocalBackpackItem* localItem = static_cast<LocalBackpackItem*>(getChild(i));
		if (localItem->getItem() == item) {
			lastRemovedIndex = i;
			localItem->setParent(NULL);
			if (item == pendingClick.get()) {
				pendingClick.reset();
			}
			return;
		}
	}

	debugAssert(false);
}

} // namespace RBX
