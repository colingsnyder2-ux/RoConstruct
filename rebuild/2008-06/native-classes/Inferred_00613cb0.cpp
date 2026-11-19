// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00613cb0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "v8kernel/Body2008.h"
#include "v8kernel/Link.h"
#include "util/Name.h"

namespace RBX {

void Link::dirty()
{
	if (body) {
		body->getRoot()->advanceStateIndex();
	}
}

}
