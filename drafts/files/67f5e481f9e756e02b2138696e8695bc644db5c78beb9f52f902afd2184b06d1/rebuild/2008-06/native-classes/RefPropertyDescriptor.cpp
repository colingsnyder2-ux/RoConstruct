// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "reflection/property.h"
#include "reflection/type.h"
#include <boost/shared_ptr.hpp>
namespace RBX { namespace Reflection {
// 005da5b0: obtain a temporary shared reference, dispatch setRefValue, release it.
void RefPropertyDescriptor::setVariant(DescribedBase* instance, const Value& value) const
{
    boost::shared_ptr<DescribedBase> reference = value.get<boost::shared_ptr<DescribedBase> >();
    setRefValue(instance, reference.get());
}
} }
