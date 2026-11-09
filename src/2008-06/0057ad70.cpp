// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll App/roc_datamodel_dtor_2008.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Service.h"
#include "v8tree/Verb.h"
#include "util/RunStateOwner.h"
#include <boost/shared_ptr.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <string>

namespace RBX {
class LocalBackpack; class Workspace; class StarterPackService; class GuiRoot; class GuiTarget; class IMetric;
extern const char sDataModel[];

class __declspec(novtable) IDataState {
public:
    virtual void setDirty(bool) = 0;
    virtual bool isDirty() const = 0;
};
class __declspec(novtable) Evaluator {
public:
    virtual std::string evaluate(const std::string&) const = 0;
};

class DataModel : public DescribedNonCreatable<DataModel, ServiceProvider, sDataModel>,
                  public VerbContainer,
                  public IDataState,
                  public Evaluator,
                  public Listener<RunService, RunTransition>
{
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
    boost::shared_ptr<boost::recursive_mutex> mutex;
public:
    virtual ~DataModel();
    virtual void setDirty(bool);
    virtual bool isDirty() const;
    virtual std::string evaluate(const std::string&) const;
    virtual void onEvent(const RunService*, RunTransition);
};

DataModel::~DataModel()
{
    if (runService)
        runService->Notifier<RunService, RunTransition>::removeListener(this);
}
}
