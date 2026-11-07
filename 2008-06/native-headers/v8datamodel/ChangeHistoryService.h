#pragma once
// >>> native-status (generated) -- do not edit >>>
// ChangeHistoryService | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 3896e01f | roc native-status --write
#include "v8tree/Service.h"
#include <boost/signals/connection.hpp>
#include <list>
#include <string>
namespace RBX {
class HistoryRecord;
extern char sChangeHistoryService[];
// Original 004150d0 allocates 0x1a4; 0058ab90 and RTTI establish bases and fields.
// Candidate remains inactive until its constructor and destructor are both verified.
class ChangeHistoryService : public DescribedCreatable<ChangeHistoryService, Instance, sChangeHistoryService>,
                             public Service {
public:
    Instance* context; // 0058c620: recorded event source; ownership unverified.
    HistoryRecord* current;
    std::list<HistoryRecord*> history;
    std::list<HistoryRecord*>::iterator forward;
    std::list<HistoryRecord*>::iterator backward;
    bool playing;
    bool enabled;
    boost::signals::scoped_connection connectionAdded;
    boost::signals::scoped_connection connectionRemoved;
    boost::signals::scoped_connection connectionChanged;
    ChangeHistoryService();
    virtual ~ChangeHistoryService();
    virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
    virtual void onHistoryAdded(boost::shared_ptr<Instance>);
    virtual void onHistoryRemoving(boost::shared_ptr<Instance>);
    virtual void onHistoryChanged(boost::shared_ptr<Instance>, const Reflection::PropertyDescriptor*);
    void setEnabled(bool);
    void start();
    void commit(const char*);
    void prepare();
    void mergeFirst();
    void reset();
    void unplay();
    void play();
    bool queryUnplay(std::string&, int);
    bool queryPlay(std::string&, int);
    void initializeBase();
};
}
