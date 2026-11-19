// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 005fdbc0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/Name.h"
#include "v8datamodel/Tool.h"

namespace RBX {

void Tool::onEvent_AddedBackend(boost::shared_ptr<Instance> instance)
{
	if (instance.get() != this)
		rebuildBackendState();
}

}
