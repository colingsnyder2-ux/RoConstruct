// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0063cc30 (placeholder name for 0063cc30 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include "util/Name.h"
#include "v8datamodel/Seat.h"

namespace RBX
{
	typedef boost::_bi::bind_t<
		void,
		boost::_mfi::mf1<void, Seat, boost::shared_ptr<Instance> >,
		boost::_bi::list2<boost::_bi::value<Seat*>, boost::arg<1> >
	> SeatTouchedBinder;

	void sub_0063cc30(boost::detail::function::function_buffer& function_obj_ptr, boost::shared_ptr<Instance> a0)
	{
		SeatTouchedBinder* f = reinterpret_cast<SeatTouchedBinder*>(&function_obj_ptr.data);
		(*f)(a0);
	}
}
