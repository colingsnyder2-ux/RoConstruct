// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0041ea40 (placeholder name for 0041ea40 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0041ea40()
{
	return Creatable<Instance>::create<PartInstance>();
}

}
