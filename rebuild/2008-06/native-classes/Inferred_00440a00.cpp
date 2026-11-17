// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_00440a00 (placeholder name for 00440a00 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "SoundChannel/SoundChannel.h"
#include "v8tree/Instance.h"
#include "util/Object.h"
#include "boost/shared_ptr.hpp"
#include "util/Name.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_00440a00()
{
	return Creatable<Instance>::create<Soundscape::SoundService>();
}

}
