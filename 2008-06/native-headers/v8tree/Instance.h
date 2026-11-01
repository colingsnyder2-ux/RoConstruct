#pragma once
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include "util/GuidItem.h"
#include "util/Object.h"
#include "util/Events.h"
#include "util/Association.h"
#include "util/Utilities.h"
#include "util/Debug.h"
#include "reflection/reflection.h"

class XmlElement;

namespace RBX {
class Instance;
class ServiceProvider;
class IReferenceBinder;
class Name;
struct ChildAdded;
struct ChildRemoved;
struct DescendantAdded;
struct DescendantRemoving;
struct AncestorChanged;
class PropertyChanged;
extern const char* sInstance;

// Native hierarchy from RTTI and the existing 004b9bd0 recovered source.
// Inactive until every virtual body, member lifetime and dependent ABI is proven.
class Instance : public GuidItem<Instance>,
                 public AbstractFactoryProduct<Instance>,
                 public Reflection::Described<Instance, &sInstance, Reflection::DescribedBase>,
                 public Debugable,
                 public Notifier<Instance, ChildAdded>,
                 public Notifier<Instance, ChildRemoved>,
                 public Notifier<Instance, DescendantAdded>,
                 public Notifier<Instance, DescendantRemoving>,
                 public Notifier<Instance, AncestorChanged>,
                 public Notifier<Instance, PropertyChanged>,
                 public boost::enable_shared_from_this<Instance>,
                 public boost::noncopyable {
public:
    virtual ~Instance();
    virtual void setName(const std::string&);
    virtual bool askAddChild(const Instance*) const;
    virtual bool askSetParent(const Instance*) const;
    virtual void onAncestorChanged(const AncestorChanged&);
    virtual void onDescendentAdded(Instance*);
    virtual void onDescendentRemoving(const boost::shared_ptr<Instance>&);
    virtual void onChildAdded(Instance*);
    virtual void onChildRemoving(Instance*);
    virtual void onChildRemoved(Instance*);
    virtual void onLastChildRemoved();
    virtual void readProperty(const XmlElement*, IReferenceBinder&);
    virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
    virtual boost::shared_ptr<Instance> createChild(const Name&);
    const std::string& getName() const { return name; }
    void setParent(Instance*);
    void writeChildren(::XmlElement*);
    virtual XmlElement* write();
    virtual void onChildChanged(Instance*, const PropertyChanged&);

    Association<Instance> assoc;
    Instance* parent;
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > children;
    std::string name;
    bool archivable;
};
}
