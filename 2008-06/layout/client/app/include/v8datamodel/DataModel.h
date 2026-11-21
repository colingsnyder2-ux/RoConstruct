#pragma once
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
class ContentId;
class GuiEvent;
class GuiResponse;
extern char sDataModel[];

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

    // INFERRED: 0057ad70 donor destructor and DataModel RTTI/vtable evidence.
    virtual ~DataModel();
    virtual void setDirty(bool value) { dirty = value; }
    virtual bool isDirty() const { return dirty; }
    // INFERRED: 00575d90 signature in the authentic DataModel declaration.
    virtual std::string evaluate(const std::string& valueName) const;
    Workspace* getWorkspace() const { return workspace.get(); }
    GuiRoot* getGuiRoot() const { return guiRoot.get(); }
    double getGameTime() const;
    double getFrameRate() const;
    double getDutyCycle() const;
    void clearContents();
    // INFERRED: 00579c10 authentic save(ContentId) declaration and call shape.
    void save(ContentId contentId);
    // INFERRED: 00579c10 passes this ? getContentProvider() : 0 as the first argument of the
    ContentProvider* getContentProvider();
    void initializeContents(bool);
    boost::shared_ptr<boost::recursive_mutex> getMutex() const;
    static boost::shared_ptr<boost::recursive_mutex> getMutex(Instance*);
    static boost::shared_ptr<DataModel> createDataModel(bool);
    static void closeDataModel(boost::shared_ptr<DataModel>, bool);
private:
    // INFERRED: 00575890 analog and authentic private processAccelerators declaration.
    GuiResponse processAccelerators(const GuiEvent& event);
protected:
    // INFERRED: 0057b630 target vtable slot and authentic onChildChanged signature.
    virtual void onChildChanged(Instance* instance, const PropertyChanged& event);
};
}
