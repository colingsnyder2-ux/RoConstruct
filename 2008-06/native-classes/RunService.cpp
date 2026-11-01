#include "util/RunStateOwner.h"

namespace RBX {
// 00556b00: constructor fields recovered from native initialization.
RunService::RunService()
    : framePeriod(1.0f / 30.0f), runState(RS_NORMAL),
      unknown0x1b8(0.0), unknown0x1c8(0.0), unknown0x1d0(0.0),
      unknown0x1d8(0.0), unknown0x1e0(0.0), invalidRunViewCount(0), stopRequested(false) {
    setName("Run Service");
    stopwatch.tick();
}

// 00554da0: enforce native state transitions and notify listeners.
void RunService::setRunState(RunState next) {
    if (next == RS_RUNNING) {
        if (runState != RS_NORMAL && runState != RS_PAUSED) return;
    } else if (next == RS_PAUSED) {
        if (runState != RS_RUNNING) return;
    } else if (next == RS_NORMAL) {
        unknown0x1b8 = 0.0;
    }
    RunState old = runState;
    if (old != next) {
        runState = next;
        Notifier<RunService, RunState>::raise(next);
        Notifier<RunService, RunTransition>::raise(RunTransition(old, next));
    }
}
}

void RBX::RunService::invalidateRunViews() {
    boost::mutex::scoped_lock guard(viewMutex);
    if (invalidRunViewCount != 0) return;
    invalidRunViewCount = views.size();
    if (invalidRunViewCount > 0) {
        for (std::map<IRunView*, bool>::iterator it = views.begin(); it != views.end(); ++it) {
            it->first->InvalidateRunView();
            it->second = false;
        }
        runViewsDoneCondition.notify_all();
    }
}
