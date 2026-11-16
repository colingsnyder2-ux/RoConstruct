// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00618cd0 (placeholder name for 00618cd0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "util/Name.h"
#include "v8datamodel/FlagStand.h"

namespace RBX {

void sub_00618cd0(boost::detail::function::function_buffer& function_obj_ptr, boost::shared_ptr<Instance> a0)
{
    typedef boost::_bi::bind_t<
        void,
        boost::_mfi::mf1<void, FlagStand, boost::shared_ptr<Instance> >,
        boost::_bi::list2<boost::_bi::value<FlagStand*>, boost::arg<1> >
    > FunctionObj;

    FunctionObj* f = reinterpret_cast<FunctionObj*>(&function_obj_ptr.data);
    (*f)(a0);
}

}
