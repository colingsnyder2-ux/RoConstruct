// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_004ac550 (placeholder name for 004ac550 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <boost/shared_ptr.hpp>
#include "util/Name.h"
#include "v8tree/Instance.h"

namespace RBX {

typedef bool (Instance::*InstanceBoolSharedFn)(boost::shared_ptr<Instance>);

bool __fastcall sub_004ac550(const InstanceBoolSharedFn* self, int /*edx*/, Instance* p, boost::shared_ptr<Instance> a)
{
    return (p->*(*self))(a);
}

}
