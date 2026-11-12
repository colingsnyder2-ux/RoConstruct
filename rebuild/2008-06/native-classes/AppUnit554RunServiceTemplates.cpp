// Inactive 2008-06 native template rows of the RunService unit (util/RunStateOwner.cpp, original 00554330..00557310)
// inside the application range 00554000..00558000, recorded by tests/record_native_app_unit554.py.
// Built against the read-only native util/RunStateOwner.h (RunService owner) with the boost-function-pod-vtable profile
// (function0(bind_t) 005564a0 stores the constant manager table 0082d51c without a guard). The RunService members
// themselves are recovered in native-classes/AppUnit54C_2008RunService.cpp; this unit holds only the explicit
// instantiations of the templates the RunService unit emits (row evidence in the recorder).
#include "util/RunStateOwner.h"
#include <boost/bind.hpp>

namespace RBX
{
	class DataModel;

	namespace Reflection
	{
		// SignalDescImpl<2, S> members the shared reflection/signal.h declares without a body (same definitions as
		// native-classes/ChangeHistoryStart.cpp).
		template<class S>
		SignalDescImpl<2, S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
			: wrapper(wrapper)
		{
		}

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

// start() 00556520: boost::bind(&RunService::runProc, shared_from(this), dataModel) (evidence name of 00555470), stored
// in a function0<void> (ctor 005564a0) for the run thread.
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, RBX::RunService, boost::shared_ptr<RBX::DataModel> >,
	boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::RunService> >,
		boost::_bi::value<boost::shared_ptr<RBX::DataModel> > > > RunProcBind;

template RunProcBind boost::bind<void, RBX::RunService, boost::shared_ptr<RBX::DataModel>,
	boost::shared_ptr<RBX::RunService>, boost::shared_ptr<RBX::DataModel> >(
	void (RBX::RunService::*)(boost::shared_ptr<RBX::DataModel>), boost::shared_ptr<RBX::RunService>,
	boost::shared_ptr<RBX::DataModel>);
template boost::function0<void, std::allocator<boost::function_base> >::function0(RunProcBind, int);

// The run-thread holder, the task queue and the timed condition waits of the RunService members: ~scoped_ptr<thread>
// 00554b70 (unwind funclets of RunService() / ~RunService on +0x27c), ~deque<function<void()> > 00555bb0 (the same
// funclets on +0x2b4), function<void()>::operator= 00554f90 (drainTasks 00555a63 item = front()) with
// function0<void>::swap 00554b90, and condition::timed_wait<scoped_lock> 00554c30 (00554e9b / 00554f45).
template boost::scoped_ptr<boost::thread>::~scoped_ptr();
template std::deque<boost::function<void()> >::~deque();
template boost::function<void()>& boost::function<void()>::operator=(const boost::function<void()>&);
template bool boost::condition::timed_wait<boost::mutex::scoped_lock>(boost::mutex::scoped_lock&, const boost::xtime&);

// The Stepped (void(float, float), vtable 0082d5f8) and Heartbeat (void(float), vtable 0082d608) event descriptors and
// the zero-argument bound function descriptor (vtable 0082d618) of the RunService unit.
template class RBX::Reflection::SignalDescImpl<2, void(float, float)>;
template class RBX::Reflection::TSignalDesc<void(float, float)>;
template RBX::Reflection::SignalDesc<RBX::RunService, void(float, float)>::SignalDesc(const char*, const char*, const char*);
template RBX::Reflection::SignalDesc<RBX::RunService, void(float)>::SignalDesc(const char*, const char*);
template class RBX::Reflection::BoundFuncDesc<RBX::RunService, void(), 0>;
