// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source /FIwinsock2.h /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network /GS-
#include "../native-headers/v8datamodel/Accoutrement.h"
#include "../native-headers/v8tree/Service.h"
#include "../native-headers/Replicator.h"

namespace RBX {
void Accoutrement::onAncestorChanged(const AncestorChanged& event)
{
	const ServiceProvider* first = ServiceProvider::findServiceProvider(event.oldParent);
	const ServiceProvider* second = ServiceProvider::findServiceProvider(event.newParent);

	if (first) {
		if (Network::Players::backendProcessing(first, true))
			setDesiredState(NOTHING, first);
		else
			backendAccoutrementState = NOTHING;
	}

	Instance::onAncestorChanged(event);

	if (second && Network::Players::backendProcessing(second, true))
		updateDesiredState();
}
}
