// from server: 100% by EspClaude
// from server: 99% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a0963462eb77d728.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<boost/function.hpp>, <roc_espeon_boost135functionheader672dcef995494068.cpp>)
#pragma include_alias(<boost/function/function0.hpp>, <roc_espeon_boost135functionheader57405a50c9beea11.cpp>)
#pragma include_alias(<boost/function/function1.hpp>, <roc_espeon_boost135functionheader54de262102ae7bc4.cpp>)
#pragma include_alias(<boost/function/function10.hpp>, <roc_espeon_boost135functionheader25854fd9e87eca57.cpp>)
#pragma include_alias(<boost/function/function2.hpp>, <roc_espeon_boost135functionheaderab3c4a9a8a29aee5.cpp>)
#pragma include_alias(<boost/function/function3.hpp>, <roc_espeon_boost135functionheader1d11d6b5b76997d8.cpp>)
#pragma include_alias(<boost/function/function4.hpp>, <roc_espeon_boost135functionheaderb9d89fa9f73a18fe.cpp>)
#pragma include_alias(<boost/function/function5.hpp>, <roc_espeon_boost135functionheaderc126e05698a03109.cpp>)
#pragma include_alias(<boost/function/function6.hpp>, <roc_espeon_boost135functionheader051609ba2d0c0985.cpp>)
#pragma include_alias(<boost/function/function7.hpp>, <roc_espeon_boost135functionheadere4e8b3783b4f4a3b.cpp>)
#pragma include_alias(<boost/function/function8.hpp>, <roc_espeon_boost135functionheader69f3516c99152e9d.cpp>)
#pragma include_alias(<boost/function/function9.hpp>, <roc_espeon_boost135functionheader91b96edc0e30e1e0.cpp>)
#pragma include_alias(<boost/function/function_base.hpp>, <roc_espeon_boost135functionheadera464fc73794f4fe5.cpp>)
#pragma include_alias(<boost/function/function_template.hpp>, <roc_espeon_boost135functionheader95fb4a51a884f45f.cpp>)
#pragma include_alias(<boost/function/detail/function_iterate.hpp>, <roc_espeon_boost135functionheader40cdef22debfc2b9.cpp>)
#pragma include_alias(<boost/function/detail/maybe_include.hpp>, <roc_espeon_boost135functionheaderb080037d4ec60e6a.cpp>)
#pragma include_alias(<boost/function/detail/prologue.hpp>, <roc_espeon_boost135functionheader1f7a0a92d6d4d42d.cpp>)
#include <string>
#include <vector>
#include <ostream>
#include <stddef.h>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
namespace RBX {
class Name { public: static const Name& lookup(const std::string& sName); };
struct Instance;struct XmlElement;struct IReferenceBinder;struct ServiceProvider;
struct Guid:boost::noncopyable {struct Data {const Name*scope;int index;};Data data;};
template<class T>struct GuidItem {virtual ~GuidItem();bool registeredGuid;Guid guid;static bool lookupByGuid(const Guid::Data&,T*&);};
struct Object {virtual ~Object();};template<class T>struct Creatable:Object{};
template<class T>struct AbstractFactoryProduct:Creatable<T> {virtual const Name&getClassName()const=0;};
namespace Reflection {
struct PropertyDescriptor;struct SignalSource {virtual ~SignalSource();void*signals;};
struct DescribedBase:SignalSource {void*descriptor;};
}
struct Debugable {virtual void dump(std::ostream&);};
struct RaiseRange;
template<class T,class Event>struct Listener;
template<class T,class Event>struct Notifier {
 virtual ~Notifier();std::vector<Listener<T,Event>*>listeners;RaiseRange*range;
 virtual void onAddListener(Listener<T,Event>*)const;virtual void onRemoveListener(Listener<T,Event>*)const;
};
struct ChildAdded;struct ChildRemoved;struct DescendentAdded;struct DescendentRemoving;struct PropertyChanged;struct AncestorChanged;
template<class T>struct Association {struct Item;std::vector<Item*>items;};
template<class T>struct CopyOnWrite:boost::noncopyable {boost::shared_ptr<T>object;};
struct Instance:GuidItem<Instance>,AbstractFactoryProduct<Instance>,Reflection::DescribedBase,Debugable,
 Notifier<Instance,ChildAdded>,Notifier<Instance,ChildRemoved>,Notifier<Instance,DescendentAdded>,Notifier<Instance,DescendentRemoving>,Notifier<Instance,AncestorChanged>,Notifier<Instance,PropertyChanged>,boost::enable_shared_from_this<Instance>,boost::noncopyable {
 virtual ~Instance();virtual void setName(const std::string&);
 virtual bool askAddChild(const Instance*)const;virtual bool askSetParent(const Instance*)const;
 virtual void onAncestorChanged(const AncestorChanged&);virtual void onDescendentAdded(Instance*);virtual void onDescendentRemoving(const boost::shared_ptr<Instance>&);
 virtual void onChildAdded(Instance*);virtual void onChildRemoving(Instance*);virtual void onChildRemoved(Instance*);virtual void onLastChildRemoved();
 virtual void readProperty(const XmlElement*,IReferenceBinder&);virtual void onServiceProvider(const ServiceProvider*,const ServiceProvider*);virtual boost::shared_ptr<Instance>createChild(const Name&);virtual XmlElement*write();virtual void onChildChanged(Instance*,const PropertyChanged&);
 Association<Instance>assoc;Instance*parent;CopyOnWrite<std::vector<boost::shared_ptr<Instance> > >children;std::string name;bool archivable;
 Instance* getParent() const {return parent;}
};
}
namespace RBX {
namespace Profiling {class Profiler;class CodeProfiler;}
namespace Stats {
// Native Stats::Item fields and interface. Constructor calls0045ebe0;
// all Instance base subobjects are the previously proved2008 hierarchy.
class Item : public Instance {
protected:
 double val;
 std::string sValue;
 virtual void update() {}
 virtual bool askAddChild(const Instance*) const;
public:
 Item();
 virtual const Name& getClassName() const;
 Item* createChildItem(const char*);
 template<class T> Item* createChildItem(const char*,boost::function0<T>);
 Item* createBoundChildItem(const Profiling::Profiler&);
};
}
template<class T> struct statsPtr { T* px; T& operator*() const { return *px; } };
struct StatsSleepView { char pad[0x1e0]; statsPtr<Profiling::Profiler> p1e0, p1e4, p1e8; };
template<class T> const T& statsField(const void* p,unsigned offset) {
 return *reinterpret_cast<const T*>(static_cast<const char*>(p)+offset);
}
// Receiver views, never allocated. Native inheritance supplies the observed
// Boost bind closures: World/RunService16B, Workspace24B, Kernel8B.
class StatsKernelView {public:
 int solverIterations()const;int matrixSize()const;int numBodies()const;int numConnectors()const;int numPoints()const;
 char kpad[0x20]; statsPtr<Profiling::Profiler> profiler;
};
struct Heartbeat;struct Stepped;struct RunTransition;enum RunState {StatsRunStatePlaceholder};
class Service {};
class StatsRunView : public Instance, public Service,
 public Notifier<StatsRunView,Heartbeat>,public Notifier<StatsRunView,Stepped>,
 public Notifier<StatsRunView,RunTransition>,public Notifier<StatsRunView,RunState> {public:
 double physicsCPU()const;double renderCPU()const;double uiCPU()const;double idleCPU()const;
};
struct AutoJoin;struct AutoDestroy;
class StatsWorldView : public Notifier<StatsWorldView,AutoJoin>, public Notifier<StatsWorldView,AutoDestroy> {public:
 float environmentSpeed()const;
 int numPrimitives()const;int numJoints()const;int numContacts()const;
 int getMetric(int)const;int numLinkCalls()const;int numHashNodes()const;int maxBucketSize()const;
 const StatsSleepView* getSleepStage()const;
 const StatsKernelView& getKernel()const;
};
class PartInstance;
class IControllable {public:virtual ~IControllable(){};virtual bool isControllable()const=0;};
class IPrimaryPart {public:virtual PartInstance* getPrimaryPart()=0;virtual const PartInstance* getPrimaryPartConst()const=0;};
// The genuine PVInstance base prefix fixes vbptr at134, exactly as the
// target Workspace callback invoker005a23f0. No complete Workspace layout
// or object size is claimed; no objects of this view are constructed.
class StatsWorkspaceView : public Instance,public IControllable,public virtual IPrimaryPart {public:
 double fileTimeTotal()const;double syncHttpTime()const;double xmlTime()const;double joinTime()const;
};
double statsFPS(Profiling::CodeProfiler*);
class WorkspaceStatsNative : public Stats::Item {public:
 WorkspaceStatsNative(const StatsWorkspaceView*,const StatsWorldView*,const StatsRunView*);
};
WorkspaceStatsNative::WorkspaceStatsNative(const StatsWorkspaceView* workspace,const StatsWorldView* world,const StatsRunView* runService) {
 setName("Workspace");
 createChildItem<double>("FPS",boost::bind(&statsFPS,statsField<Profiling::CodeProfiler*>(workspace,0x428)));
 createChildItem<float>("Environment Speed %",boost::bind(&StatsWorldView::environmentSpeed,world));
 createChildItem<double>("Physics CPU %",boost::bind(&StatsRunView::physicsCPU,runService));
 createChildItem<double>("Render CPU %",boost::bind(&StatsRunView::renderCPU,runService));
 createChildItem<double>("Ui CPU %",boost::bind(&StatsRunView::uiCPU,runService));
 createChildItem<double>("Idle CPU %",boost::bind(&StatsRunView::idleCPU,runService));
 Stats::Item* pDataModelStep=createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(workspace,0x428));
 Stats::Item* pWorkspaceStep=pDataModelStep->createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(workspace,0x42c));
 Stats::Item* pWorldStep=pWorkspaceStep->createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(world,0xfc));
 pWorldStep->createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(world,0x104));
 pWorldStep->createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(world,0x108));
 pWorldStep->createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(world,0x110));
 pWorldStep->createBoundChildItem(*world->getSleepStage()->p1e4);
 pWorldStep->createBoundChildItem(*world->getSleepStage()->p1e0);
 pWorldStep->createBoundChildItem(*world->getSleepStage()->p1e8);
 pWorldStep->createBoundChildItem(*world->getKernel().profiler);
 pDataModelStep->createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(workspace,0x430));
 pDataModelStep->createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(workspace,0x434));
 pDataModelStep->createBoundChildItem(*statsField<statsPtr<Profiling::Profiler> >(workspace,0x438));
 Stats::Item* w=createChildItem("World");
 w->createChildItem<int>("Primitives",boost::bind(&StatsWorldView::numPrimitives,world));
 w->createChildItem<int>("Joints",boost::bind(&StatsWorldView::numJoints,world));
 w->createChildItem<int>("Contacts",boost::bind(&StatsWorldView::numContacts,world));
 Stats::Item* contacts=createChildItem("Contacts");
 contacts->createChildItem<int>("CtctStageCtcts",boost::bind(&StatsWorldView::getMetric,world,0));
 contacts->createChildItem<int>("SteppingCtcts",boost::bind(&StatsWorldView::getMetric,world,1));
 contacts->createChildItem<int>("TouchingCtcts",boost::bind(&StatsWorldView::getMetric,world,2));
 contacts->createChildItem<int>("MaxTreeDepth",boost::bind(&StatsWorldView::getMetric,world,3));
 contacts->createChildItem<int>("# link(p)",boost::bind(&StatsWorldView::numLinkCalls,world));
 contacts->createChildItem<int>("Hash Nodes Out",boost::bind(&StatsWorldView::numHashNodes,world));
 contacts->createChildItem<int>("Max Bucket Size",boost::bind(&StatsWorldView::maxBucketSize,world));
 Stats::Item* kernelItem=createChildItem("Kernel");
 const StatsKernelView* kernel=&world->getKernel();
 kernelItem->createChildItem<int>("SolverIterations",boost::bind(&StatsKernelView::solverIterations,kernel));
 kernelItem->createChildItem<int>("MatrixSize",boost::bind(&StatsKernelView::matrixSize,kernel));
 kernelItem->createChildItem<int>("Bodies",boost::bind(&StatsKernelView::numBodies,kernel));
 kernelItem->createChildItem<int>("Constraints",boost::bind(&StatsKernelView::numConnectors,kernel));
 kernelItem->createChildItem<int>("Points",boost::bind(&StatsKernelView::numPoints,kernel));
 Stats::Item* file=createChildItem("File Operations");
 file->createChildItem<double>("Total Load Time",boost::bind(&StatsWorkspaceView::fileTimeTotal,workspace));
 file->createChildItem<double>("SyncHttpGet Time",boost::bind(&StatsWorkspaceView::syncHttpTime,workspace));
 file->createChildItem<double>("XML Load Time",boost::bind(&StatsWorkspaceView::xmlTime,workspace));
 file->createChildItem<double>("Join All Time",boost::bind(&StatsWorkspaceView::joinTime,workspace));
}
typedef char stats_instance_size[sizeof(Instance)==0x130?1:-1];
typedef char stats_item_size[sizeof(Stats::Item)==0x158?1:-1];
typedef char stats_function_size[sizeof(boost::function0<double>)==32?1:-1];
typedef char stats_world_pmf[sizeof(int (StatsWorldView::*)()const)==8?1:-1];
typedef char stats_workspace_pmf[sizeof(double (StatsWorkspaceView::*)()const)==12?1:-1];
}

