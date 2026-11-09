// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_9513e0431bc416b8.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>

namespace RBX {
class Instance;
struct PropertyChanged {};
struct ChildAdded {};
struct ChildRemoved {};

template<typename Class, typename Event>
class __declspec(novtable) Listener
{
protected:
    virtual void onEvent(const Class*, Event) = 0;
    virtual ~Listener() {}
};

template<typename Class, typename Event>
class Notifier
{
public:
    void removeListener(Listener<Class, Event>* listener) const;
};

class Instance
{
public:
    char pad0[0x24];
    Notifier<Instance, ChildAdded> childAddedNotifier;
    char pad1[0x44 - 0x25];
    Notifier<Instance, ChildRemoved> childRemovedNotifier;
    char pad2[0xc4 - 0x45];
    Notifier<Instance, PropertyChanged> propertyChangedNotifier;
};

class DataModel
{
public:
    class scoped_write_request
    {
        void* a; void* b; void* c;
    public:
        scoped_write_request(boost::shared_ptr<DataModel> dataModel);
        ~scoped_write_request();
    };
};
class Game : public DataModel {};
}

class CRobloxTreeCtrlNode;

class CRobloxTreeCtrl
{
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual boost::shared_ptr<RBX::Game> getDataModel();
    virtual void v86();
    virtual void v87();
    virtual void onNodeDeleted(CRobloxTreeCtrlNode* node);
    char pad[0x98 - 4];
    std::map<RBX::Instance*, CRobloxTreeCtrlNode*> nodes;
    char pad2[0xc4 - 0x98 - sizeof(std::map<RBX::Instance*, CRobloxTreeCtrlNode*>)];
    boost::mutex mutex;
};

class CRobloxTreeCtrlNode
    : public RBX::Listener<RBX::Instance, RBX::PropertyChanged>
    , public RBX::Listener<RBX::Instance, RBX::ChildAdded>
    , public RBX::Listener<RBX::Instance, RBX::ChildRemoved>
{
    boost::shared_ptr<RBX::Instance> instance;
    std::set<RBX::Instance*> children;
    std::set<RBX::Instance*> set2;
    void* item;
    CRobloxTreeCtrl* tree;
    CRobloxTreeCtrlNode* parent;
    std::set<RBX::Instance*> set3;
public:
    virtual void onEvent(const RBX::Instance*, RBX::PropertyChanged);
    virtual void onEvent(const RBX::Instance*, RBX::ChildAdded);
    virtual void onEvent(const RBX::Instance*, RBX::ChildRemoved);
    ~CRobloxTreeCtrlNode();
};

CRobloxTreeCtrlNode::~CRobloxTreeCtrlNode()
{
    {
        boost::mutex::scoped_lock lock(tree->mutex);
        if (parent)
            parent->children.erase(instance.get());
        tree->onNodeDeleted(this);
        tree->nodes.erase(instance.get());
    }
    RBX::DataModel::scoped_write_request request(tree->getDataModel());
    instance->propertyChangedNotifier.removeListener(this);
    instance->childAddedNotifier.removeListener(this);
    instance->childRemovedNotifier.removeListener(this);
}
