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
class XmlState;
class Name;
class RaiseDescendentAdded2;
struct ChildAdded
{
public:
	const boost::shared_ptr<Instance> child;

public:
	ChildAdded(const ChildAdded&);
	ChildAdded(Instance* child)
		: child(shared_from(child))
	{
	}
private:
	ChildAdded& operator=(const ChildAdded&);
};

struct ChildRemoved
{
public:
	const boost::shared_ptr<Instance> child;

public:
	ChildRemoved(const ChildRemoved&);
	ChildRemoved(Instance* child)
		: child(shared_from(child))
	{
	}
private:
	ChildRemoved& operator=(const ChildRemoved&);
};
struct DescendantAdded;
struct DescendantRemoving;
struct AncestorChanged {
    Instance* child;
    Instance* oldParent;
    Instance* newParent;
    AncestorChanged(Instance* child, Instance* oldParent, Instance* newParent)
        : child(child), oldParent(oldParent), newParent(newParent) {}
};
class PropertyChanged;
extern const char sInstance[];

// Native hierarchy from RTTI and the existing 004b9bd0 recovered source.
// Inactive until every virtual body, member lifetime and dependent ABI is proven.
class Instance : public boost::enable_shared_from_this<Instance>,
                 public GuidItem<Instance>,
                 public AbstractFactoryProduct<Instance>,
                 public Reflection::Described<Instance, sInstance, Reflection::DescribedBase>,
                 public Debugable,
                 public Notifier<Instance, ChildAdded>,
                 public Notifier<Instance, ChildRemoved>,
                 public Notifier<Instance, DescendantAdded>,
                 public Notifier<Instance, DescendantRemoving>,
                 public Notifier<Instance, AncestorChanged>,
                 public Notifier<Instance, PropertyChanged>,
                 public boost::noncopyable {
    friend class RaiseDescendentAdded2;
public:
    static Reflection::BoundProp<bool, 1> propArchivable;
    static const Reflection::RefPropDescriptor<Instance, Instance> propParent;
    static const Reflection::PropDescriptor<Instance, std::string> desc_Name;
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> event_childAdded;
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> event_childRemoved;
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> event_descendentAdded;
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> event_descendentRemoving;
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)> event_ancestryChanged;
    static Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)> event_propertyChanged;
    static Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>, const Reflection::PropertyDescriptor*)> event_itemChanged;
    Instance();
    explicit Instance(const char*);
    virtual ~Instance();
    virtual void setName(const std::string&);
    virtual bool askAddChild(const Instance*) const;
    virtual bool askSetParent(const Instance*) const;
    virtual void onAddListener(Listener<Instance, ChildAdded>*) const;
    virtual void onAddListener(Listener<Instance, DescendantAdded>*) const;
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
    Instance* getParent() const { return parent; }
    const Instance* getRootAncestor() const { return parent ? parent->getRootAncestor() : this; }
    Instance* getRootAncestor() { return parent ? parent->getRootAncestor() : this; }
    bool isAncestorOf(const Instance* descendent) const {
        if (!descendent) return false;
        Instance* ancestor = descendent->parent;
        if (ancestor == this) return true;
        return isAncestorOf(ancestor);
    }
    bool isDescendentOf(const Instance*) const; // 00422ae0
    // 00423700; name provisional
    bool canAcceptChildren(std::vector<boost::shared_ptr<Instance> >::const_iterator,
                           std::vector<boost::shared_ptr<Instance> >::const_iterator);
    size_t numChildren() const
    {
        return children ? children->size() : 0;
    }
    const Instance* getChild(size_t i) const { return (*children)[i].get(); }
    Instance* getChild(size_t i) { return (*children)[i].get(); }
		template<typename Function>
		void visitDescendents(Function func) const
		{
			if (children)
			{
				boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>> c = children.read();
				std::vector<boost::shared_ptr<Instance>>::const_iterator end = c->end();
				std::vector<boost::shared_ptr<Instance>>::const_iterator iter = c->begin();

				for (; iter != end; iter++)
				{
					func(*iter);
					(*iter)->visitDescendents(func);
				}
			}
		}
    template<class Type> Type* findFirstChildOfType() const {
        if (children) {
            std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
            std::vector<boost::shared_ptr<Instance> >::const_iterator it = children->begin();
            for (; it != end; ++it) {
                if (Type* result = dynamic_cast<Type*>(it->get())) return result;
            }
        }
        return NULL;
    }
    template<class Function> void for_eachChild(Function func) const {
        if (children) {
            boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > values = children.read();
            std::vector<boost::shared_ptr<Instance> >::const_iterator end = values->end();
            std::vector<boost::shared_ptr<Instance> >::const_iterator it = values->begin();
            for (; it != end; ++it) func(it->get());
        }
    }
    template<class T> const T* getTypedParent() const { return rbx_static_cast<const T*>(parent); }
    template<class T> T* getTypedParent() { return rbx_static_cast<T*>(parent); }
    template<class T> const T* getTypedRoot() const {
        RBXASSERT(dynamic_cast<const T*>(this));
        const T* typedParent = dynamic_cast<const T*>(parent);
        return typedParent ? typedParent->getTypedRoot<T>() : static_cast<const T*>(this);
    }
    template<class T> const T* queryTypedParent() const { return dynamic_cast<T*>(parent); }
    template<class T> T* queryTypedParent() { return dynamic_cast<T*>(parent); }
    bool canAddChild(const Instance*) const;
    void setParent(Instance*);
    __declspec(noinline) bool contains(const Instance*) const;
    std::string getFullName() const;
    static void signalDescendentRemoving(const boost::shared_ptr<Instance>&, Instance*, Instance*);
    static void signalDescendentAdded(Instance*, Instance*, Instance*);
    void removeAllChildren();
    boost::shared_ptr<Instance> clone();  // ?clone@Instance@RBX@@QAE?AV?$shared_ptr@VInstance@RBX@@@boost@@XZ
    void remove();  // ?remove@Instance@RBX@@QAEXXZ
    struct AnchorAction { bool value; };  // provisional layout: nested struct passed by value below
    void applyAnchoredToChildren(AnchorAction);  // ?applyAnchoredToChildren@Instance@RBX@@QAEXUAnchorAction@12@@Z
    bool canSetParent(const Instance*) const; // 0041f390
    void raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor); // 0040db00
    std::string getClassNameStr() const;
    Instance* findFirstChildByName(const std::string&) const;
    Instance* findFirstChildByClassName(std::string) const; // 0046ae30; name provisional.
private:
    void readChild(const ::XmlElement*, IReferenceBinder&);
    void writeProperties(::XmlElement*) const;
public:
    void readChildren(const ::XmlElement*, IReferenceBinder&);
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
