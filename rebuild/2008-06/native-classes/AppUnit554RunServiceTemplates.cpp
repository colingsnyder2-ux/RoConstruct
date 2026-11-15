// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
#include "util/RunStateOwner.h"
#include <boost/bind.hpp>

namespace RBX {
class DataModel;

namespace Reflection {
template<class S>
SignalDescImpl<2, S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
	: wrapper(wrapper) {}

template<class S>
void SignalDescImpl<2, S>::GenericSlotAdapter::operator()(
	typename boost::function_traits<S>::arg1_type a, typename boost::function_traits<S>::arg2_type b)
{
	std::vector<boost::any> args(2);
	args[0] = a;
	args[1] = b;
	wrapper->execute(args);
}

template<class S>
boost::signals::connection SignalDescImpl<2, S>::connectGeneric(
	SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const
{
	return static_cast<typename TSignalDesc<S>::TSignalInstance*>(instance)->connect(GenericSlotAdapter(wrapper), pos);
}
}
}

// start() 00556520: boost::bind(&RunService::runProc, shared_from(this), dataModel) (bind 00555470), stored
// in a function0<void> (ctor 005564a0) for the run thread.
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, RBX::RunService, boost::shared_ptr<RBX::DataModel> >,
	boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::RunService> >,
		boost::_bi::value<boost::shared_ptr<RBX::DataModel> > > > RunProcBind;

template RunProcBind boost::bind<void, RBX::RunService, boost::shared_ptr<RBX::DataModel>,
	boost::shared_ptr<RBX::RunService>, boost::shared_ptr<RBX::DataModel> >(
	void (RBX::RunService::*)(boost::shared_ptr<RBX::DataModel>), boost::shared_ptr<RBX::RunService>,
	boost::shared_ptr<RBX::DataModel>);
template boost::function0<void, std::allocator<boost::function_base> >::function0(RunProcBind, int);

template boost::scoped_ptr<boost::thread>::~scoped_ptr();
template std::deque<boost::function<void()> >::~deque();
template boost::function<void()>& boost::function<void()>::operator=(const boost::function<void()>&);
template bool boost::condition::timed_wait<boost::mutex::scoped_lock>(boost::mutex::scoped_lock&, const boost::xtime&);
template class RBX::Reflection::SignalDescImpl<2, void(float, float)>;
template class RBX::Reflection::TSignalDesc<void(float, float)>;
template RBX::Reflection::SignalDesc<RBX::RunService, void(float, float)>::SignalDesc(const char*, const char*, const char*);
template RBX::Reflection::SignalDesc<RBX::RunService, void(float)>::SignalDesc(const char*, const char*);
template class RBX::Reflection::BoundFuncDesc<RBX::RunService, void(), 0>;
