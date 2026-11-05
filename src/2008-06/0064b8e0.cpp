// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_58e17a8beb809e4a.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <vector>
#include <G3D/Array.h>
#include <boost/scoped_ptr.hpp>

namespace RBX {
class World;
class Assembly;
class Contact;
class Joint;
class Edge;
namespace Profiling {
class CodeProfiler {
public:
    CodeProfiler(const char* name);
    ~CodeProfiler();
    char data[0xc048];
};
}

class IStage {
public:
    virtual ~IStage() {}
};

class IWorldStage : public IStage {
protected:
    IStage* upstream;
    IStage* downstream;
    World* world;
public:
    IWorldStage(IStage* upstream, IStage* downstream, World* world)
        : upstream(upstream), downstream(downstream), world(world)
    {
    }
    virtual ~IWorldStage() {}
};

class SimJobStage : public IWorldStage {
public:
    SimJobStage(IStage* upstream, World* world);
    char pad[0x2c - 0x10];
};

class SleepStage : public IWorldStage {
    std::vector<Assembly*> v0;
    std::vector<Assembly*> v1;
    std::vector<Assembly*> v2;
    std::vector<Assembly*> v3;
    std::vector<Assembly*> v4;
    std::vector<Assembly*> v5;
    std::vector<Assembly*> v6;
    std::vector<Assembly*> v7;
    int numContactsInStage;
    int numContactsInKernel;
    bool throttling;
    int uiStepId;
    std::set<Assembly*> recursiveWakePending;
    std::set<Assembly*> wakePending;
    std::set<Assembly*> awake;
    std::set<Assembly*> sleepingChecking;
    std::set<Assembly*> sleepingDeeply;
    std::set<Assembly*> s5;
    G3D::Array<Contact*> steppingContacts;
    G3D::Array<Contact*> touchingContacts;
    std::set<Joint*> steppingJoints;
    int count;
    bool externalBodyForceAdded;
public:
    boost::scoped_ptr<Profiling::CodeProfiler> profilingCollision;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingWake;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingSleep;
    SleepStage(IStage* upstream, World* world);
    virtual ~SleepStage();
};

SleepStage::SleepStage(IStage* upstream, World* world)
    : IWorldStage(upstream, new SimJobStage(this, world), world),
      numContactsInStage(0), numContactsInKernel(0), throttling(false), uiStepId(-1),
      count(0), externalBodyForceAdded(false),
      profilingCollision(new Profiling::CodeProfiler("Collision")),
      profilingWake(new Profiling::CodeProfiler("Wake")),
      profilingSleep(new Profiling::CodeProfiler("Sleep"))
{
}
}
