#pragma once
// >>> native-status (generated) -- do not edit >>>
// DataModel | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 6f95760f | roc native-status --write
#include "v8tree/Service.h"
#include "v8tree/VerbContainer.h"
#include "v8tree/IDataState.h"
#include "util/Evaluator.h"
#include <boost/shared_ptr.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <string>

namespace RBX {
class DataModel;
class LocalBackpack;
class Workspace;
class RunService;
class RunTransition;
class StarterPackService;
class GuiRoot;
class GuiTarget;
class IMetric;
class Selection;
extern char sDataModel[];

// Inactive candidate: RTTI, constructor and recovered 0057a1b0 source define
// these bases and members. Complete virtual methods and lifetimes remain open.
class DataModel : public DescribedNonCreatable<DataModel, ServiceProvider, sDataModel>,
                  public VerbContainer, public IDataState, public Evaluator,
                  public Listener<RunService, RunTransition> {
public:
    class Lock {
        boost::shared_ptr<boost::recursive_mutex> mutex;
        boost::recursive_mutex::scoped_lock* lock;
        void doLock(const DataModel*);
    public:
        explicit Lock(const DataModel*);
        explicit Lock(boost::shared_ptr<const DataModel>);
        ~Lock();
    };

    boost::shared_ptr<LocalBackpack> localBackpack;
    boost::shared_ptr<Workspace> workspace;
    boost::shared_ptr<RunService> runService;
    boost::shared_ptr<StarterPackService> starterPackService;
    boost::shared_ptr<GuiRoot> guiRoot;
    boost::shared_ptr<GuiRoot> guiHooks;
    GuiTarget* guiTarget;
    bool forceArrowCursor;
    std::string uiMessage;
    int drawId;
    IMetric* tempMetric;
    bool dirty;
    bool renderEnabled;
    boost::shared_ptr<boost::recursive_mutex> mutex;

    virtual void setDirty(bool value) { dirty = value; }
    virtual bool isDirty() const { return dirty; }
    Workspace* getWorkspace() const { return workspace.get(); }
    GuiRoot* getGuiRoot() const { return guiRoot.get(); }
    double getGameTime() const;
    double getFrameRate() const;
    double getDutyCycle() const;
    void clearContents();
    void initializeContents(bool);
    boost::shared_ptr<boost::recursive_mutex> getMutex() const;
    static boost::shared_ptr<boost::recursive_mutex> getMutex(Instance*);
    static boost::shared_ptr<DataModel> createDataModel(bool);
    static void closeDataModel(boost::shared_ptr<DataModel>, bool);
};
}
