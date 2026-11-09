// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <map>
#include <deque>
namespace G3D { class Stopwatch { char data[0x58]; public: Stopwatch(); void tick(); }; }
namespace boost {
class mutex { void* m; bool locked; public: mutex(); ~mutex(); };
class condition { void* data[6]; public: condition(); ~condition(); };
class thread;
template<class T> class scoped_ptr { T* p; public: scoped_ptr(): p(0) {} ~scoped_ptr(); };
}
namespace RBX {
class Base00 { public: virtual ~Base00(); char d[0xc]; };
class Base10 { public: virtual ~Base10(); };
class Base14 { public: virtual ~Base14(); char d[8]; };
class Base20 { public: virtual ~Base20(); };
template<int N> class InstNotifier { public: virtual ~InstNotifier(); char d[0x1c]; };
class Instance : public Base00, public Base10, public Base14, public Base20,
	public InstNotifier<0>, public InstNotifier<1>, public InstNotifier<2>, public InstNotifier<3>, public InstNotifier<4>, public InstNotifier<5>
{ public: char rest[0x130 - 0xe4]; void setName(const std::string&); };
class RunService;
template<class Class, class Event> class Notifier { protected: Notifier(); public: virtual ~Notifier(); char d[0x1c]; };
template<class Class, class Base> class DescribedCreatable : public Base { protected: DescribedCreatable(); public: virtual ~DescribedCreatable(); };
class Service { void* unknown0x1b0; }; // 2008: 4 bytes at 0x1b0 before runState (0x1b4), never touched by the ctor
class Heartbeat; class Stepped; class RunTransition; enum RunState { RS_NORMAL, RS_RUNNING, RS_PAUSED };
class IRunView;
class RunService : public DescribedCreatable<RunService, Instance>,
	public Service,
	public Notifier<RunService, Heartbeat>,
	public Notifier<RunService, Stepped>,
	public Notifier<RunService, RunTransition>,
	public Notifier<RunService, RunState>
{
	RunState runState;
	double unknown0x1b8;
	float framePeriod;
	double unknown0x1c8;
	double unknown0x1d0;
	double unknown0x1d8;
	double unknown0x1e0;
	G3D::Stopwatch stopwatch;
	boost::mutex runMutex;
	bool stopRequested;
	boost::condition runViewsDoneCondition;
	boost::condition stateChangedCondition;
	boost::scoped_ptr<boost::thread> runThread;
	boost::mutex viewMutex;
	std::map<IRunView*, bool> views;
	int invalidRunViewCount;
	boost::mutex unknownMutex0x2ac;
	std::deque<void*> unknownQueue0x2b4;
public:
	RunService();
	virtual ~RunService();
};
RunService::RunService()
	: framePeriod(1.0f/30.0f),
	  runState(RS_NORMAL),
	  unknown0x1b8(0.0), unknown0x1c8(0.0), unknown0x1d0(0.0), unknown0x1d8(0.0), unknown0x1e0(0.0),
	  invalidRunViewCount(0),
	  stopRequested(false)
{
	setName("Run Service");
	stopwatch.tick();
}
}
