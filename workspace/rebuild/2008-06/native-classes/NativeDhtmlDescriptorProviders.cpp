// Isolated descriptor providers used by CRobloxApp startup aliases.
#include "AppLeaves2008/DHTMLWindow2008.h"

template class RBX::Reflection::Described<DHTMLWindow, sDHTMLWindow,
	RBX::NonFactoryProduct<RBX::Instance, sDHTMLWindow> >;
template class RBX::Reflection::Described<DHTMLWindowService, sDHTMLWindowService,
	RBX::FactoryProduct<DHTMLWindowService, RBX::Instance, sDHTMLWindowService> >;
