// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost { template<class T> class scoped_ptr { T* px; public: T& operator*() const { return *px; } T* get() const { return px; } }; }
namespace RBX {
class CodeProfiler;
namespace Profiling {
class Mark {
    char storage[24];
public:
    Mark(CodeProfiler&, bool);
    ~Mark();
};
}
class AssemblyList { char d[0x20]; };
class Contacts { char d[0x0c]; };
class SleepStage {
    char pad0[0xe0];
    AssemblyList recursiveWakePending;
    char wakePending[0xa0];
    Contacts steppingContacts;
    char touchingContacts[0x34];
    boost::scoped_ptr<CodeProfiler> profilingCollision;
    boost::scoped_ptr<CodeProfiler> profilingWake;
    boost::scoped_ptr<CodeProfiler> profilingSleep;

    void stepAssemblies(void*, int, int);
    void stepContacts(void*);
    void stepAssembliesAwake();
    void stepAssembliesSleepingChecking();
    void stepDownstream();
    void stepAssembliesRecursiveWakePending() { stepAssemblies(&recursiveWakePending, 8, 1); }
    void stepAssembliesWakePending() { stepAssemblies(wakePending, 0, 2); }
public:
    void stepWorld(int worldStepId);
};

void SleepStage::stepWorld(int worldStepId)
{
    {
        Profiling::Mark mark(*profilingWake, false);
        stepAssembliesRecursiveWakePending();
        stepAssembliesWakePending();
    }
    {
        Profiling::Mark mark(*profilingCollision, false);
        stepContacts(&steppingContacts);
        stepAssembliesRecursiveWakePending();
        stepAssembliesWakePending();
    }
    {
        Profiling::Mark mark(*profilingSleep, false);
        stepAssembliesAwake();
        if (worldStepId % 4 == 0)
            stepAssembliesSleepingChecking();
        stepAssembliesWakePending();
    }
    stepContacts(touchingContacts);
    stepAssembliesRecursiveWakePending();
    stepAssembliesWakePending();
    stepDownstream();
}
}
