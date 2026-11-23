#include "util/RunStateOwner.h"
#include "util/StandardOut.h"
#include <exception>
#include "v8datamodel/DataModel.h"

namespace RBX
{
	// INFERRED: native wrapper has priority parameter absent from donor header.
	boost::function0<void> background_function(const boost::function0<void>& threadfunc, const char* name, int priority);

	void RunService::start()
	{
		boost::shared_ptr<DataModel> dataModel = shared_from(dynamic_cast<DataModel*>(getParent()));
		runThread.reset(new boost::thread(background_function(boost::bind(&RunService::runProc, shared_from(this), dataModel), "rbx_runProc", -1)));
	}

	RunService::RunService()
		: framePeriod(1.0f / 30.0f),
		  runState(RS_NORMAL),
		  unknown0x1b8(0.0),
		  unknown0x1c8(0.0),
		  unknown0x1d0(0.0),
		  unknown0x1d8(0.0),
		  unknown0x1e0(0.0),
		  invalidRunViewCount(0),
		  stopRequested(false)
	{
		setName("Run Service");
		stopwatch.tick();
	}

	RunService::~RunService()
	{
		stopwatch.tock();
	}

	void RunService::enqueueTask(boost::function<void()> task)
	{
		boost::mutex::scoped_lock lock(unknownMutex0x2ac);
		unknownQueue0x2b4.push_back(task);
	}

	void RunService::drainTasks()
	{
		while (true)
		{
			boost::function<void()> item;
			{
				boost::mutex::scoped_lock lock(unknownMutex0x2ac);
				if (unknownQueue0x2b4.empty())
					return;
				item = unknownQueue0x2b4.front();
				unknownQueue0x2b4.pop_front();
			}
			try
			{
				item();
			}
			catch (std::exception& e)
			{
				StandardOut::singleton()->print(MESSAGE_ERROR, "%s", e.what());
			}
		}
	}

	void RunService::onAncestorChanged(const AncestorChanged&)
	{
		if (!getParent())
		{
			stopRequested = true;
			stateChangedCondition.notify_all();
		}
	}

	void RunService::setRunState(RunState next)
	{
		if (next == RS_RUNNING)
		{
			if (runState != RS_NORMAL && runState != RS_PAUSED)
				return;
		}
		else if (next == RS_PAUSED)
		{
			if (runState != RS_RUNNING)
				return;
		}
		else if (next == RS_NORMAL)
		{
			unknown0x1b8 = 0.0;
		}
		RunState old = runState;
		if (old != next)
		{
			runState = next;
			Notifier<RunService, RunState>::raise(next);
			Notifier<RunService, RunTransition>::raise(RunTransition(old, next));
		}
	}

	void RunService::invalidateRunViews()
	{
		boost::mutex::scoped_lock guard(viewMutex);
		if (invalidRunViewCount != 0)
			return;
		invalidRunViewCount = views.size();
		if (invalidRunViewCount > 0)
		{
			for (std::map<IRunView*, bool>::iterator it = views.begin(); it != views.end(); ++it)
			{
				it->first->InvalidateRunView();
				it->second = false;
			}
			runViewsDoneCondition.notify_all();
		}
	}

	void RunService::runViewValid(IRunView* view)
	{
		boost::mutex::scoped_lock guard(viewMutex);
		if (invalidRunViewCount == 0)
			return;
		std::map<IRunView*, bool>::iterator it = views.find(view);
		if (it != views.end())
		{
			if (!(*it).second)
			{
				--invalidRunViewCount;
				it->second = true;
			}
		}
		if (invalidRunViewCount == 0)
			runViewsDoneCondition.notify_all();
	}

	void RunService::addRunView(IRunView* view)
	{
		boost::mutex::scoped_lock guard(viewMutex);
		views[view] = true;
	}

	void RunService::removeRunView(IRunView* view)
	{
		boost::mutex::scoped_lock guard(viewMutex);
		runViewValid(view);
		views.erase(view);
	}
}

#ifdef NATIVE_RUNSERVICE_LAYOUT_PENDING
// boost::thread::join 005a6850; start 00556520 stores it there) in place of the INFERRED `Workspace* workspace`, and
#include "AppUnit5F0_2008/RealTime2008.h"
#include <algorithm>

namespace RBX
{
	extern bool throttleAt30Fps; // 00946790 (defined with the DebugSettings rows)

	void RunService::runProc(boost::shared_ptr<DataModel> dataModel)
	{
		double throttle = 0.0;
		double desiredTime = getRealTime();
		while (true)
		{
			if (throttleAt30Fps)
				desiredTime = std::max(desiredTime, getRealTime() - framePeriod) + framePeriod;
			else
				desiredTime = getRealTime();
			if (stopRequested)
				return;
			sub_00554880(dataModel);
			if (stopRequested)
				return;
			sub_00554ed0();
			if (stopRequested)
				return;
			throttle = (desiredTime - getRealTime() + throttle) * 0.5;
			sub_005550a0(throttle);
			if (throttle > 0.0)
				sub_00554e10(throttle);
			if (stopRequested)
				return;
			stopwatch.tock();
			stopwatch.tick();
			unknown0x1d8 = unknown0x1e0;
			unknown0x1e0 = 0.0;
		}
	}
}
#endif

template void RBX::Notifier<RBX::RunService, RBX::Heartbeat>::raise(RBX::Heartbeat) const;
template void RBX::Notifier<RBX::RunService, RBX::Stepped>::raise(RBX::Stepped) const;

template class boost::function<void __cdecl(void),std::allocator<void> >;
template class boost::scoped_ptr<boost::thread>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::RunService,RBX::Heartbeat> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::RunService,RBX::Stepped> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::RunService,enum RBX::RunState> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<boost::function<void __cdecl(void),std::allocator<void> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::IRunView * const,bool> > >;
template class std::_Deque_const_iterator<boost::function<void __cdecl(void),std::allocator<void> >,std::allocator<boost::function<void __cdecl(void),std::allocator<void> > >,1>;
template class std::_Deque_iterator<boost::function<void __cdecl(void),std::allocator<void> >,std::allocator<boost::function<void __cdecl(void),std::allocator<void> > >,1>;
template class std::_Tmap_traits<RBX::IRunView *,bool,std::less<RBX::IRunView *>,std::allocator<std::pair<RBX::IRunView * const,bool> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::IRunView *,bool,std::less<RBX::IRunView *>,std::allocator<std::pair<RBX::IRunView * const,bool> >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::IRunView *,bool,std::less<RBX::IRunView *>,std::allocator<std::pair<RBX::IRunView * const,bool> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::IRunView * const,bool> >;
template class std::vector<RBX::Listener<RBX::RunService,RBX::Heartbeat> *,std::allocator<RBX::Listener<RBX::RunService,RBX::Heartbeat> *> >;
template class std::vector<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;
template class std::vector<RBX::Listener<RBX::RunService,RBX::Stepped> *,std::allocator<RBX::Listener<RBX::RunService,RBX::Stepped> *> >;
template class std::vector<RBX::Listener<RBX::RunService,enum RBX::RunState> *,std::allocator<RBX::Listener<RBX::RunService,enum RBX::RunState> *> >;

#ifdef RUNSERVICE_HEADER_DECLARES_STEP_RAISES
namespace RBX
{
	void RunService::raiseHeartbeat(float step)
	{
		drainTasks();
		Notifier<RunService, Heartbeat>::raise(Heartbeat(gameTime(), step));
		event_Heartbeat.fire(this, step);
	}

	void RunService::raiseStepped(float step)
	{
		float time = static_cast<float>(unknown0x1b8 += step);
		Notifier<RunService, Stepped>::raise(Stepped(time, step));
		event_Stepped.fire(this, time, step);
	}
}
#endif
