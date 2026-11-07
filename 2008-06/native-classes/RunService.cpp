// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string /I{headers}/runservice-events
#include "util/RunStateOwner.h"
#include "util/StandardOut.h"
#include <exception>

namespace RBX {
// 00556b00: constructor fields recovered from native initialization.
RunService::RunService()
    : framePeriod(1.0f / 30.0f), runState(RS_NORMAL),
      unknown0x1b8(0.0), unknown0x1c8(0.0), unknown0x1d0(0.0),
      unknown0x1d8(0.0), unknown0x1e0(0.0), invalidRunViewCount(0), stopRequested(false) {
    setName("Run Service");
    stopwatch.tick();
}

RunService::~RunService() {
    stopwatch.tock();
}

void RunService::enqueueTask(boost::function<void()> task) {
    boost::mutex::scoped_lock lock(unknownMutex0x2ac);
    unknownQueue0x2b4.push_back(task);
}

void RunService::drainTasks() {
    while (true) {
        boost::function<void()> item;
        {
            boost::mutex::scoped_lock lock(unknownMutex0x2ac);
            if (unknownQueue0x2b4.empty()) return;
            item = unknownQueue0x2b4.front();
            unknownQueue0x2b4.pop_front();
        }
        try {
            item();
        } catch (std::exception& e) {
            StandardOut::singleton()->print(MESSAGE_ERROR, "%s", e.what());
        }
    }
}

void RunService::onAncestorChanged(const AncestorChanged&) {
    if (!getParent()) {
        stopRequested = true;
        stateChangedCondition.notify_all();
    }
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

// 00555830: detach a view while preserving its pending-invalidation accounting.
void RBX::RunService::removeRunView(IRunView* view) {
    boost::mutex::scoped_lock lock(viewMutex);
    runViewValid(view);
    views.erase(view);
}

void RBX::RunService::runViewValid(IRunView* view) {
    boost::mutex::scoped_lock lock(viewMutex);
    if (!invalidRunViewCount) return;
    std::map<IRunView*, bool>::iterator it = views.find(view);
    if (it != views.end() && !it->second) {
        --invalidRunViewCount;
        it->second = true;
    }
    if (!invalidRunViewCount) runViewsDoneCondition.notify_all();
}
