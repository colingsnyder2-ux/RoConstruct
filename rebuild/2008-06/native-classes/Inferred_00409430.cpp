// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00409430 (placeholder name for 00409430 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "Network/Player.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_00409430()
{
	return Creatable<Instance>::create<Network::Player>();
}

}
