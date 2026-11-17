// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005624b0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/NativeContentProvider.h"
#include "util/Name.h"

namespace RBX {

bool ContentProvider::hasContent(ContentId id)
{
	return loadContent(id, 0, 0) != 0;
}

}
