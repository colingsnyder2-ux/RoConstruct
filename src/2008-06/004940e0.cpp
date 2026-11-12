// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/RunStateOwner.cpp

// Candidate translation unit (score above; library headers required).
#include "util/RunStateOwner.h"

#include "util/Timer.h"
#include "util/boost.hpp"
#include "v8datamodel/DataModel.h"

#include <algorithm>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>

namespace RBX {

const char sRunService[] = "RunService";

Reflection::SignalDesc<RunService, void(float, float)> RunService::event_Stepped("Stepped", "time", "step");

static Reflection::SignalDesc<RunService, void(float)> event_Heartbeat("Heartbeat", "interval");

static Reflection::BoundFuncDesc<RunService, void(), 0> runFunction(
	&RunService::run, "Run", Reflection::FunctionDescriptor::NeedTrustedCaller
);

static Reflection::BoundFuncDesc<RunService, void(), 0> pauseFunction(
	&RunService::pause, "Pause", Reflection::FunctionDescriptor::NeedTrustedCaller
);

static Reflection::BoundFuncDesc<RunService, void(), 0> resetFunction(
	&RunService::reset, "Reset", Reflection::FunctionDescriptor::NeedTrustedCaller
);

// FUNCTION: WEBSERVICE 0x10054320
// FUNCTION: ROBLOX 0x00568ae0
void RunService::endRunThread(bool join)
{
	stopRequested = true;
	stateChangedCondition.notify_all();

	if (join) {
		runThread->join();
	}
}

// FUNCTION: WEBSERVICE 0x100543b0
// FUNCTION: ROBLOX 0x00568b20
void RunService::onAncestorChanged(const AncestorChanged& event)
{
	if (getParent() == NULL) {
		endRunThread(false);
	}
}

// FUNCTION: ROBLOX 0x00569480
void RunService::FUN_00569480(RunState state)
{
	if (state == RS_RUNNING) {
		if (!isEditState() && !isPauseState()) {
			return;
		}
	}
	else if (state == RS_PAUSED) {
		if (!isRunState()) {
			return;
		}
	}

	setRunState(state);
}

// FUNCTION: WEBSERVICE 0x10054cb0
// FUNCTION: ROBLOX 0x005694e0
void RunService::runProc(boost::shared_ptr<DataModel> dataModel)
{
	double desiredTime = getRealTime();

	while (true) {
		const double timeLeft = desiredTime - getRealTime();

		{
			boost::mutex::scoped_lock lock(viewMutex);

			for (Views::iterator iter = views.begin(); iter != views.end(); ++iter) {
				iter->first->AdjustThrottle(timeLeft);
			}
		}

		const double waitTime = std::max(0.0, timeLeft);

		boost::xtime xt;

		boost::xtime_get(&xt, boost::TIME_UTC);
		xt.nsec += (int) (waitTime * 1000000000.0);

		bool signalled;

		{
			boost::mutex::scoped_lock lock(runMutex);

			signalled = stateChangedCondition.timed_wait(lock, xt);
		}

		if (!signalled) {
			boost::xtime xt;

			boost::xtime_get(&xt, boost::TIME_UTC);
			xt.sec += 1;

			boost::mutex::scoped_lock lock(runMutex);

			if (invalidRunViewCount != 0) {
				runViewsDoneCondition.timed_wait(lock, xt);
			}
		}

		if (timeLeft <= 0.0) {
			desiredTime = getRealTime();
		}

		{
			DataModel::Lock lock(dataModel);

			if (stopRequested) {
				break;
			}

			dataModel->step(framePeriod);
		}

		desiredTime += framePeriod;
	}
}

// FUNCTION: WEBSERVICE 0x10054fd0
// FUNCTION: ROBLOX 0x00569800
void RunService::invalidateRunViews()
{
	boost::mutex::scoped_lock lock(viewMutex);

	if (invalidRunViewCount != 0) {
		return;
	}

	invalidRunViewCount = views.size();

	if (invalidRunViewCount > 0) {
		for (Views::iterator iter = views.begin(); iter != views.end(); ++iter) {
			iter->first->InvalidateRunView();
			iter->second = false;
		}

		runViewsDoneCondition.notify_all();
	}
}

// FUNCTION: ROBLOX 0x00569930
void RunService::runViewValid(IRunView* runView)
{
	boost::mutex::scoped_lock lock(viewMutex);

	if (invalidRunViewCount == 0) {
		return;
	}

	Views::iterator iter = views.find(runView);

	if (iter != views.end() && !iter->second) {
		invalidRunViewCount--;
		iter->second = true;
	}

	if (invalidRunViewCount == 0) {
		runViewsDoneCondition.notify_all();
	}
}

// FUNCTION: WEBSERVICE 0x10055380
// FUNCTION: ROBLOX 0x00569c40
RunService::~RunService()
{
}

// FUNCTION: ROBLOX 0x00569ef0
void RunService::removeRunView(IRunView* runView)
{
	boost::mutex::scoped_lock lock(viewMutex);

	runViewValid(runView);
	views.erase(runView);
}

// FUNCTION: ROBLOX 0x0056a100
void RunService::addRunView(IRunView* runView)
{
	boost::mutex::scoped_lock lock(viewMutex);

	views[runView] = true;
}

// FUNCTION: WEBSERVICE 0x10056950
// FUNCTION: ROBLOX 0x0056add0
RunService::RunService()
	: runState(RS_NORMAL), stopRequested(false), framePeriod(1.0f / 30.0f), runThread(NULL), invalidRunViewCount(0),
	  runDisabled(false)
{
	setName("Run Service");
}

// FUNCTION: WEBSERVICE 0x100573e0
// FUNCTION: ROBLOX 0x0056b4e0
void RunService::start()
{
	boost::shared_ptr<DataModel> dataModel = shared_from(dynamic_cast<DataModel*>(getParent()));

	runThread.reset(new boost::thread(
		background_function(boost::bind(&RunService::runProc, shared_from(this), dataModel), "rbx_runProc")
	));
}

// FUNCTION: WEBSERVICE 0x100577f0
// FUNCTION: ROBLOX 0x0056b7d0
void RunService::raiseHeartbeat(float time, float step)
{
	Notifier<RunService, Heartbeat>::raise(Heartbeat(time, step));
	event_Heartbeat.fire(this, step);
}

// FUNCTION: WEBSERVICE 0x10057860
// FUNCTION: ROBLOX 0x0056b840
void RunService::raiseStepped(float time, float step)
{
	Notifier<RunService, Stepped>::raise(Stepped(time, step));
	event_Stepped.fire(this, time, step);
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::RunService, RBX::Instance, RBX::sRunService>;
template class RBX::Reflection::Described<
	RBX::RunService,
	RBX::sRunService,
	RBX::FactoryProduct<RBX::RunService, RBX::Instance, RBX::sRunService> >;
template class RBX::DescribedCreatable<RBX::RunService, RBX::Instance, RBX::sRunService>;
