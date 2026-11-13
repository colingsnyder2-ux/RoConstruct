// Inactive 2008-06 native RunService unit (util/RunStateOwner.cpp, original 00554330..00557310), recorded by
// tests/record_native_app_unit54c_2008.py. Built against the read-only native util/RunStateOwner.h (layout 0x2d8: the
// size create<RunService> 00405fbf passes to new; fields from the ctor 00556b00 and dtor 00555c00).
// Bodies follow the target bytes; the class and member names are those of the native header.
// >>> native-status (generated) -- do not edit >>>
// AppUnit54C_2008RunService | 2008-06 | 3 byte-exact, inactive (not link-selected)
// 3/10 mapped addresses byte-exact | 7 unproved | 1 referenced strings (not rechecked) | by king_originala (+5) (mixed 4)
// <<< native-status | src baae8879 | roc native-status --write
#include "util/RunStateOwner.h"
#include "util/StandardOut.h"
#include <exception>

namespace RBX
{
	// 00556b00: Run Service name, framePeriod 1/30 (float constant 0082d634), state and timers zeroed, stopwatch tick.
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

	// 00555c00: Stopwatch::tock 00511df0, then the member and base destructors.
	RunService::~RunService()
	{
		stopwatch.tock();
	}

	// 00555900: push_back under unknownMutex0x2ac (do_lock 00594ce0, deque push_back 00419ae0, do_unlock 00594d00).
	void RunService::enqueueTask(boost::function<void()> task)
	{
		boost::mutex::scoped_lock lock(unknownMutex0x2ac);
		unknownQueue0x2b4.push_back(task);
	}

	// 005559a0 (catch funclet 00555afb): pop one task under the mutex, run it outside, print std::exception text.
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

	// 00554440: stopRequested +0x248, stateChangedCondition +0x264 notify_all (005f1d30).
	void RunService::onAncestorChanged(const AncestorChanged&)
	{
		if (!getParent())
		{
			stopRequested = true;
			stateChangedCondition.notify_all();
		}
	}

	// 00554da0: guarded transitions; RS_NORMAL clears the game time +0x1b8; raises RunState (00554ae0) then
	// RunTransition (00554a60) only when the state changes.
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

	// 00555350: under viewMutex +0x280, invalidate every view of the map +0x288 and wake runViewsDoneCondition.
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

	// 005555e0: under viewMutex, mark one invalidated view valid again; wake runViewsDoneCondition +0x24c when the
	// last invalidated view reports.
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

	// 005557c0: views[view] = true under viewMutex (map operator[] 005556d0).
	void RunService::addRunView(IRunView* view)
	{
		boost::mutex::scoped_lock guard(viewMutex);
		views[view] = true;
	}

	// 00555830: under viewMutex, runViewValid(view) (005555e0) then erase the key (ICF erase 00405ce0).
	void RunService::removeRunView(IRunView* view)
	{
		boost::mutex::scoped_lock guard(viewMutex);
		runViewValid(view);
		views.erase(view);
	}
}

// 00554960 / 005549e0: the Heartbeat (+0x130) and Stepped (+0x150) notifier raises of this unit. Their callers
// 00557150 / 005571b0 take one float (ret 4), unlike the header's raiseHeartbeat/raiseStepped(float, float), so the
// raises are instantiated explicitly here.
template void RBX::Notifier<RBX::RunService, RBX::Heartbeat>::raise(RBX::Heartbeat) const;
template void RBX::Notifier<RBX::RunService, RBX::Stepped>::raise(RBX::Stepped) const;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
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
