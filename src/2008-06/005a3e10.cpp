// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_80b3e5af91e8d8fc.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance { public: virtual ~Instance(); };
class IRenderable { public: virtual ~IRenderable(); };
class Selection {
public:
    void clearSelection();
    void addToSelection(Instance* i);
};
template<class T> class ServiceClient {
public:
    Instance* provider;
    boost::shared_ptr<T> service;
    ServiceClient(Instance* p) : provider(p) {}
    T* get(bool create);
};
typedef std::vector<boost::shared_ptr<Instance> > Instances;
struct ChildHolder { Instances list; };
bool isLocked(Instance* i);
class Workspace : public Instance {
public:
    char pad[0x104];
    ChildHolder* children;
    unsigned int numChildren() const;
    void selectAll();
};
void Workspace::selectAll()
{
    ServiceClient<Selection> selection(this);
    selection.get(true)->clearSelection();
    for (unsigned int i = 0; i < numChildren(); ++i) {
        Instance* child = children->list[i].get();
        if (dynamic_cast<IRenderable*>(child) && !isLocked(child))
            selection.get(true)->addToSelection(child);
    }
}
}
