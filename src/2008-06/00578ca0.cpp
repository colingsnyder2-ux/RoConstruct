// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_espclaude_4e0b061628ffee6c.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Array.h>
#include <G3D/Vector4.h>
#include <stddef.h>
extern bool enabled;

struct Settings
{
    G3D::Array<G3D::Vector4> values;
    bool first;
    bool second;
};

namespace Profiling {
struct CodeProfiler;
class Mark {
    CodeProfiler& section;
    Mark* enclosingMark;
    bool frameTick;
    double startTime;
public:
    Mark(CodeProfiler&, bool);
    ~Mark();
};
}
template<class T> struct scoped_ptr { T* ptr; T* get() const { return ptr; } T& operator*() const { return *ptr; } T* operator->() const { return ptr; } };
template<class T> struct shared_ptr { T* px; void* pn; T* operator->() const { return px; } T* get() const { return px; } };

struct Workspace
{
    char padding[0x42c];
    scoped_ptr<Profiling::CodeProfiler> profileWorkspaceStep;
    scoped_ptr<Profiling::CodeProfiler> profileWorkspaceIdle;
    scoped_ptr<Profiling::CodeProfiler> profileRunServiceStepped;
    scoped_ptr<Profiling::CodeProfiler> profileRunServiceHeartbeat;
    float step(float, Settings&);
    void idle();
};

struct RunService
{
    char padding[0x1b4];
    int runState;
    bool isRunState() const { return runState == 1; }
    void raiseStepped(float);
    void raiseHeartbeat(float);
};

struct DataModel
{
    char padding[0x204];
    shared_ptr<Workspace> workspace;
    shared_ptr<RunService> runService;

    void getRenderSettings(Settings&);
    void step(float);
    static const Settings& defaultSettings();
};

extern unsigned int __cdecl getRunMode(DataModel*);

void DataModel::step(float timeInterval)
{
    unsigned int mode = getRunMode(this);
    bool simulate = false;
    switch (mode)
    {
    case 0:
    case 3:
    case 4:
        simulate = runService->isRunState();
        break;
    case 1:
    case 2:
        simulate = enabled;
        break;
    }

    Settings settings = defaultSettings();
    if (enabled)
        getRenderSettings(settings);

    if (simulate)
    {
        {
            Profiling::Mark mark = Profiling::Mark(*workspace->profileWorkspaceStep, true);
            workspace->step(timeInterval, settings);
        }
        {
            Profiling::Mark mark = Profiling::Mark(*workspace->profileRunServiceStepped, true);
            runService->raiseStepped(timeInterval);
        }
    }
    else
    {
        Profiling::Mark mark = Profiling::Mark(*workspace->profileWorkspaceIdle, true);
        workspace->idle();
    }

    {
        Profiling::Mark mark = Profiling::Mark(*workspace->profileRunServiceHeartbeat, true);
        runService->raiseHeartbeat(timeInterval);
    }
}
