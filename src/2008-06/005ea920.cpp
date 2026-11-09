// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_94b78efce9cfa189.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <set>
#include <boost/scoped_ptr.hpp>
#include "G3D/Array.h"

namespace RBX {

namespace Profiling {
class CodeProfiler {
public:
    CodeProfiler(const char* name);
    ~CodeProfiler();
    char data[0xc040];
    CodeProfiler* parent;
    int extra;
};
}

class World;
class Primitive;
class Joint;
class Kernel;
struct AutoJoin {};
struct AutoDestroy {};
struct AutoA {};
struct AutoB {};

template<class Source, class Event>
class Notifier {
public:
    Notifier();
    virtual ~Notifier();
    char data[0x1c];
};

class ContactManager {
public:
    ContactManager(World* world);
    char data[0x14];
};

class SleepStage;

class IStage {
public:
    enum StageType { SLEEP_STAGE = 5 };
    virtual ~IStage();
    virtual StageType getStageType();
    virtual void unused2();
    virtual Kernel* getKernel();
    IStage* upstream;
    IStage* downstream;
    IStage* findStage(StageType type) {
        IStage* s = this;
        while (s->getStageType() != type)
            s = s->downstream;
        return s;
    }
};

class SleepStage : public IStage {
public:
    char data[0x1e0 - 0xc];
    Profiling::CodeProfiler* profilingCollision;
    Profiling::CodeProfiler* profilingWake;
    Profiling::CodeProfiler* profilingSleep;
};

class Kernel {
public:
    char data[0x20];
    Profiling::CodeProfiler* profilingKernel;
};

class JointStage : public IStage {
public:
    JointStage(IStage* upstream, World* world);
    int extra;
};

class World : public Notifier<World, AutoJoin>, public Notifier<World, AutoDestroy>,
              public Notifier<World, AutoA>, public Notifier<World, AutoB> {
public:
    World();
    virtual ~World();
    SleepStage* getSleepStage() { return static_cast<SleepStage*>(jointStage->findStage(IStage::SLEEP_STAGE)); }
    Kernel* getKernel() const { return jointStage->getKernel(); }

    float throttle;
    ContactManager* contactManager;
    JointStage* jointStage;
    G3D::Array<Primitive*> touch;
    G3D::Array<Primitive*> touchOther;
    bool inStepCode;
    bool inJointNotification;
    int worldStepId;
    G3D::Array<Primitive*> primitives;
    G3D::Array<Primitive*> primitives2;
    std::set<Joint*> breakableJoints;
    int numJoints;
    int numContacts;
    int numLinkCalls;
    G3D::Array<Primitive*> tempPrimitives;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingWorldStep;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingPreStep;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingAssemblyStep;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingUiStep;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingPreStep8Inner;
    boost::scoped_ptr<Profiling::CodeProfiler> profilingBroadphase;
};

World::World()
    : throttle(100.0f),
      contactManager(new ContactManager(this)),
      jointStage(new JointStage(NULL, this)),
      inStepCode(false), inJointNotification(false), worldStepId(0),
      numJoints(0), numContacts(0), numLinkCalls(0),
      profilingWorldStep(new Profiling::CodeProfiler("World Step")),
      profilingPreStep(new Profiling::CodeProfiler("Pre Step")),
      profilingAssemblyStep(new Profiling::CodeProfiler("Assembly Step")),
      profilingUiStep(new Profiling::CodeProfiler("UI Step")),
      profilingPreStep8Inner(new Profiling::CodeProfiler("Pre Step 8 Inner")),
      profilingBroadphase(new Profiling::CodeProfiler("Broadphase"))
{
    profilingAssemblyStep->parent = profilingWorldStep.get();
    profilingUiStep->parent = profilingWorldStep.get();
    profilingPreStep->parent = profilingWorldStep.get();
    profilingPreStep8Inner->parent = profilingWorldStep.get();
    profilingBroadphase->parent = profilingWorldStep.get();

    getSleepStage()->profilingCollision->parent = profilingWorldStep.get();
    getSleepStage()->profilingWake->parent = profilingWorldStep.get();
    getSleepStage()->profilingSleep->parent = profilingWorldStep.get();

    getKernel()->profilingKernel->parent = profilingWorldStep.get();
}

}
