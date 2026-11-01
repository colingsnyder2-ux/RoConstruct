// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_workspace_stats_native_abi_sizes_30d01b81f3b05a7c.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_cc3dd87ed7e7c246.cpp")
#pragma include_alias("v8datamodel/Workspace.h", "roc_workspace_stats_native_api_workspace_3cd61a759ad104a7.cpp")
#pragma include_alias("v8world/World.h", "roc_workspace_stats_native_api_world_9b388d9f20c1333e.cpp")
#pragma include_alias("util/RunStateOwner.h", "roc_workspace_stats_native_api_runstateowner_ea54294ff9208ecb.cpp")
#pragma include_alias("v8kernel/Kernel.h", "roc_workspace_stats_native_api_kernel_1ba072669a27e3f8.cpp")
#define _CPPUNWIND 1
#include <windows.h>
#include "v8datamodel/Stats.h"
#include "util/RunStateOwner.h"
#include "v8world/World.h"
#include "v8world/SleepStage.h"
#include "v8kernel/Kernel.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
// Workspace is pointer-only here: its real header has multiple inheritance;
// RootInstance has virtual bases. Use its actual virtual-inheritance member-pointer model. No fields/size invented.
namespace RBX {
#pragma pointers_to_members(full_generality, virtual_inheritance)
class Workspace {
public:
    double getStatsFileTimeTotal() const;
    double getStatsSyncHttpGetTime() const;
    double getStatsXMLLoadTime() const;
    double getStatsJoinAllTime() const;
};

class World;
class WorkspaceStatsItem : public Stats::Item {
public:
    WorkspaceStatsItem(const Workspace*, const World*, const RunService*);
};
}

namespace RBX {
// Native5a02e0: free callback, profiler getData(3.0), Bucket::getActualFPS.
double workspaceStatsFps(const Profiling::Profiler*);
// These are typed pointer views, not claims about complete owner layouts.
#define PROFILE_AT(object, offset) (**reinterpret_cast<Profiling::CodeProfiler* const*>(reinterpret_cast<const char*>(object)+(offset)))

WorkspaceStatsItem::WorkspaceStatsItem(const Workspace* workspace, const World* world, const RunService* runService)
{
    setName("Workspace");
    createChildItem<double>("FPS", boost::bind(&workspaceStatsFps, &PROFILE_AT(workspace, 0x428)));
    createChildItem<float>("Environment Speed %", boost::bind(&World::getEnvironmentSpeedPercent, world));
    createChildItem<double>("Physics CPU %", boost::bind(&RunService::physicsCpuFraction, runService));
    createChildItem<double>("Render CPU %", boost::bind(&RunService::renderingCpuFraction, runService));
    createChildItem<double>("Ui CPU %", boost::bind(&RunService::uiCpuFraction, runService));
    createChildItem<double>("Idle CPU %", boost::bind(&RunService::idleCpuFraction, runService));

    Stats::Item* dataModelStep = createBoundChildItem(PROFILE_AT(workspace, 0x428));
    Stats::Item* workspaceStep = dataModelStep->createBoundChildItem(PROFILE_AT(workspace, 0x42c));
    Stats::Item* worldStep = workspaceStep->createBoundChildItem(PROFILE_AT(world, 0xfc));
    worldStep->createBoundChildItem(PROFILE_AT(world, 0x104));
    worldStep->createBoundChildItem(PROFILE_AT(world, 0x108));
    worldStep->createBoundChildItem(PROFILE_AT(world, 0x110));
    worldStep->createBoundChildItem(PROFILE_AT(world->getSleepStage(), 0x1e4));
    worldStep->createBoundChildItem(PROFILE_AT(world->getSleepStage(), 0x1e0));
    worldStep->createBoundChildItem(PROFILE_AT(world->getSleepStage(), 0x1e8));
    worldStep->createBoundChildItem(PROFILE_AT(&world->getKernel(), 0x20));
    dataModelStep->createBoundChildItem(PROFILE_AT(workspace, 0x430));
    dataModelStep->createBoundChildItem(PROFILE_AT(workspace, 0x434));
    dataModelStep->createBoundChildItem(PROFILE_AT(workspace, 0x438));

    Stats::Item* w = createChildItem("World");
    w->createChildItem<int>("Primitives", boost::bind(&World::getNumPrimitives, world));
    w->createChildItem<int>("Joints", boost::bind(&World::getNumJoints, world));
    w->createChildItem<int>("Contacts", boost::bind(&World::getNumContacts, world));
    Stats::Item* contacts = createChildItem("Contacts");
    contacts->createChildItem<int>("CtctStageCtcts", boost::bind(&World::getMetric, world, IWorldStage::NUM_CONTACTSTAGE_CONTACTS));
    contacts->createChildItem<int>("SteppingCtcts", boost::bind(&World::getMetric, world, IWorldStage::NUM_STEPPING_CONTACTS));
    contacts->createChildItem<int>("TouchingCtcts", boost::bind(&World::getMetric, world, IWorldStage::NUM_TOUCHING_CONTACTS));
    contacts->createChildItem<int>("MaxTreeDepth", boost::bind(&World::getMetric, world, IWorldStage::MAX_TREE_DEPTH));
    contacts->createChildItem<int>("# link(p)", boost::bind(&World::getNumLinkCalls, world));
    contacts->createChildItem<int>("Hash Nodes Out", boost::bind(&World::getNumHashNodes, world));
    contacts->createChildItem<int>("Max Bucket Size", boost::bind(&World::getMaxBucketSize, world));

    Stats::Item* kernelItem = createChildItem("Kernel");
    const Kernel& kernel = world->getKernel();
    kernelItem->createChildItem<int>("SolverIterations", boost::bind(&Kernel::fakeDeceptiveSolverIterations, &kernel));
    kernelItem->createChildItem<int>("MatrixSize", boost::bind(&Kernel::fakeDeceptiveMatrixSize, &kernel));
    kernelItem->createChildItem<int>("Bodies", boost::bind(&Kernel::numBodies, &kernel));
    kernelItem->createChildItem<int>("Constraints", boost::bind(&Kernel::numConnectors, &kernel));
    kernelItem->createChildItem<int>("Points", boost::bind(&Kernel::numPoints, &kernel));

    Stats::Item* file = createChildItem("File Operations");
    file->createChildItem<double>("Total Load Time", boost::bind(&Workspace::getStatsFileTimeTotal, workspace));
    file->createChildItem<double>("SyncHttpGet Time", boost::bind(&Workspace::getStatsSyncHttpGetTime, workspace));
    file->createChildItem<double>("XML Load Time", boost::bind(&Workspace::getStatsXMLLoadTime, workspace));
    file->createChildItem<double>("Join All Time", boost::bind(&Workspace::getStatsJoinAllTime, workspace));
}
#undef PROFILE_AT
}

int statsFunctionSize(){return sizeof(boost::function0<double>);}
int statsFunctionAlign(){return __alignof(boost::function0<double>);}
int statsBufferSize(){return sizeof(boost::detail::function::function_buffer);}
int statsBufferAlign(){return __alignof(boost::detail::function::function_buffer);}
int statsWorldMemberSize(){return sizeof(int (RBX::World::*)()const);}
int statsWorkspaceMemberSize(){return sizeof(double(RBX::Workspace::*)()const);}
