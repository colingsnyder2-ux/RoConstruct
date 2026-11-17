// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005b1720 (placeholder name for 005b1720 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include "util/Name.h"
#include "v8datamodel/FlagStand.h"

namespace RBX {

typedef boost::_bi::bind_t<
    void,
    boost::_mfi::mf1<void, FlagStand, boost::shared_ptr<Instance> >,
    boost::_bi::list2<boost::_bi::value<FlagStand*>, boost::arg<1> >
> FlagStandInstanceBinder;

void sub_005b1720(boost::detail::function::function_buffer& function_obj_ptr, boost::shared_ptr<Instance> a0)
{
    FlagStandInstanceBinder* f = reinterpret_cast<FlagStandInstanceBinder*>(&function_obj_ptr.data);
    (*f)(a0);
}

}
