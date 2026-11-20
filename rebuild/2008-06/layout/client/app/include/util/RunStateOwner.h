#pragma once
#include "reflection/reflection.h"
#include "reflection/signal.h"
#include "util/Events.h"
#include "v8tree/Service.h"
#include <boost/thread/condition.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/function.hpp>
#include <G3D/Stopwatch.h>
#include <deque>

namespace RBX
{
	extern char sRunService[];

	class DataModel;

	enum RunState
	{
		RS_NORMAL,
		RS_RUNNING,
		RS_PAUSED
	};

	class RunTransition
	{
	public:
		RunState oldState;
		RunState newState;

		RunTransition(RunState oldState, RunState newState)
			: oldState(oldState),
			  newState(newState)
		{
		}

		bool startEvent();
		bool resetEvent();
	};

	class Heartbeat
	{
	public:
		const float time;
		const float step;

		Heartbeat(float time, float step)
			: time(time),
			step(step)
		{
		}
	};

	class Stepped
	{
	public:
		const float time;
		const float step;

		Stepped(float time, float step)
			: time(time),
			step(step)
		{
		}
	};

	class IRunView
	{
	public:
		virtual void InvalidateRunView() = 0;
		virtual void AdjustThrottle(double) = 0;
	};

	class RunService : public DescribedCreatable<RunService, Instance, sRunService>,
					   public Service,
					   public Notifier<RunService, Heartbeat>,
					   public Notifier<RunService, Stepped>,
					   public Notifier<RunService, RunTransition>,
					   public Notifier<RunService, RunState>
	{
		friend class DataModel;
	private:
		RunState runState;
		double unknown0x1b8;
		float framePeriod;
		double unknown0x1c8, unknown0x1d0, unknown0x1d8, unknown0x1e0;
		G3D::Stopwatch stopwatch;
		boost::mutex runMutex;
		bool stopRequested;                                      // +0x248
		boost::condition runViewsDoneCondition;                  // +0x24c
		boost::condition stateChangedCondition;                  // +0x264
		// INFERRED: workspace pointer at +0x27c accessed by RunService::stop (00554460)
		class Workspace* workspace;                              // +0x27c
		boost::mutex viewMutex;                                  // +0x280
		std::map<IRunView*, bool> views;                         // +0x288
		boost::scoped_ptr<boost::thread> runThread;
		int invalidRunViewCount;
		boost::mutex unknownMutex0x2ac;
		// Original enqueue and drain paths store zero-argument callables; return type remains inferred.
		std::deque<boost::function<void()> > unknownQueue0x2b4;
	public:
		bool runDisabled;
		static Reflection::SignalDesc<RunService, void(float, float)> event_Stepped;
	private:
		void start();
	public:
		RunService();
		virtual ~RunService();
		void setRunState(RunState newState);
		void enqueueTask(boost::function<void()> task); // 00555900; name provisional.
		void drainTasks(); // 005559a0; name provisional.
		void stop(); // 00554460

		void run()
		{
			if (!runDisabled && (runState == RS_NORMAL || runState == RS_PAUSED) && runState != RS_RUNNING)
				setRunState(RS_RUNNING);
		}

		void pause()
		{
			if (runState == RS_RUNNING)
				setRunState(RS_PAUSED);
		}

		void reset()
		{
			if (runState != RS_NORMAL)
				setRunState(RS_NORMAL);
		}

		void endRunThread(bool join);
		void raiseHeartbeat(float time, float step);
		void raiseStepped(float time, float step);
		RunState getRunState() const { return runState; }
		double gameTime() const { return unknown0x1b8; }
		double frameRate() const { return stopwatch.smoothFPS(); }
		double dutyCycle() const { return (unknown0x1d8 + unknown0x1d0 + unknown0x1c8) * (1.0 / framePeriod); }
		// INFERRED: 005a0090/005a00b0/005a00d0 are the RunService CPU-percent callbacks bound by the
		double getPhysicsCpuPercent() const; // 005a0090
		double getRenderCpuPercent() const;  // 005a00b0
		double getUiCpuPercent() const;      // 005a00d0
		bool isEditState() const;
		bool isRunState() const;
		bool isPauseState() const;
		void setPeriod(float);
		float getPeriod();
		void addRunView(IRunView*);
		void removeRunView(IRunView*);
		void invalidateRunViews();
		void runViewValid(IRunView*);
		virtual void onAncestorChanged(const AncestorChanged& event);
		// INFERRED: name is a placeholder (identity tier). Body byte-proved: unconditionally set stopRequested
		void requestStop();                       // 00554330
	private:
		void runProc(boost::shared_ptr<DataModel> dataModel);
	public:
		void sub_005550a0(double throttle);   // INFERRED: 005550a0, placeholder name (identity tier), body byte-proved (Inferred_005550a0.cpp)
	};
}
