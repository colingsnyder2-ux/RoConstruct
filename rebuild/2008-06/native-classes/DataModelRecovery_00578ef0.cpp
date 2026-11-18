// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include "v8datamodel/DataModel.h"
#include "util/RunStateOwner.h"

// Recovery views for EXTERNAL call targets only. RBX::DataModel itself is the
// authentic header class below. Names of external methods are provisional;
// identity/references are proven by the prover against the original image.
namespace {
struct WorkspaceView {
    void setMouseCommand(void*);
    void clearMouseCommand();
    void setBoundCommand(void*);
};
struct InstanceView {
    void clear();
    void reset();
    void stop();
    void finish();
};
struct ScriptView {
    // INFERRED: target passes LEA of +0x14 as the first dispatcher argument.
    char pad[0x14];
    int dispatchTag;
    void finish();
};
struct DispatcherView {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void dispatch(void*, const bool&);
};
struct DataModelViews {
    InstanceView* getFirst();
    InstanceView* getSecond();
    InstanceView* getThird();
    InstanceView* getFourth();
    ScriptView* getLast();
};
extern DispatcherView* dispatcher;
}

namespace RBX {
void DataModel::clearContents()
{
    ((WorkspaceView*)workspace.get())->setMouseCommand(0);
    ((WorkspaceView*)workspace.get())->clearMouseCommand();
    ((WorkspaceView*)workspace.get())->setBoundCommand(0);
    ((InstanceView*)starterPackService.get())->clear();

    DataModelViews* self = (DataModelViews*)this;
    if (InstanceView* p = self->getFirst())
        p->clear();
    if (InstanceView* p = self->getSecond())
        p->reset();
    if (InstanceView* p = self->getThird())
        p->stop();
    if (InstanceView* p = self->getFourth())
        p->clear();
    if (ScriptView* p = self->getLast())
    {
        p->finish();
        struct Pair { void* v; bool f; } pr = { &p->dispatchTag, false };
        void* value = pr.v;
        bool flag = pr.f;
        dispatcher->dispatch(value, flag);
    }
}

DataModel::~DataModel()
{
    if (runService)
        runService->Notifier<RunService, RunTransition>::removeListener(this);
}
}
