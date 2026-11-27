#pragma once
#include "v8tree/Instance.h"
#include <map>

namespace RBX {
namespace Reflection { template<class Class, typename Signature, int N> class BoundFuncDesc; }
class Service {};
class Closing;
// Event payloads, copied from the SDK declarations (the copy constructors are defined elsewhere).
struct ServiceAdded {
    const boost::shared_ptr<Instance> service;
    ServiceAdded(const ServiceAdded&);
private:
    ServiceAdded& operator=(const ServiceAdded&);
};
struct ServiceRemoving {
    const boost::shared_ptr<Instance> service;
    ServiceRemoving(const ServiceRemoving&);
private:
    ServiceRemoving& operator=(const ServiceRemoving&);
};
extern char sServiceProvider[];

// Original RTTI and 00568bf0 establish the three notifier bases. Existing
// source supplies the service vector/map types; behavioral ABI remains open.
class ServiceProvider :
    public DescribedNonCreatable<ServiceProvider, Instance, sServiceProvider>,
    public Notifier<ServiceProvider, Closing>,
    public Notifier<ServiceProvider, ServiceAdded>,
    public Notifier<ServiceProvider, ServiceRemoving> {
public:
    static const ServiceProvider* findServiceProvider(const Instance*);
    virtual bool askAddChild(const Instance* instance) const;   // INFERRED: 00575240 vtable slot 2 override (__RTDynamicCast to Service)
    mutable std::vector<boost::shared_ptr<Instance> > serviceArray;
    std::map<const Name*, boost::shared_ptr<Instance> > serviceMap;
    boost::shared_ptr<Instance> findServiceByClassName(const Name&) const;
private:
    boost::shared_ptr<Instance> findServiceByClassNameString(std::string name);   // 005729c0 (registry symbol)
    // Lua `game:GetService("X")` / `game:service("X")` (initializers 007f33e0 / 007f33b0: objects 00974ce0 / 00974d28;
    // donor tools/rbxgs Client/App/v8tree/Service.cpp line 9). Defined in ServiceFunctionDescriptors.cpp.
    static Reflection::BoundFuncDesc<ServiceProvider, boost::shared_ptr<Instance>(std::string), 1> func_GetService;
    static Reflection::BoundFuncDesc<ServiceProvider, boost::shared_ptr<Instance>(std::string), 1> func_service;
public:
    static Instance* create(Instance* context, const Name&);
    static size_t newIndex();
    template<class Class> static size_t doGetClassIndex();
    template<class Class> static void callDoGetClassIndex();
    template<class Class> static size_t getClassIndex();
    template<class Class> Class* find() const;
    template<class Class> static Class* find(const Instance* context);
    template<class Class> static Class* find(const ServiceProvider* serviceProvider) { return serviceProvider ? serviceProvider->find<Class>() : 0; }
    template<class Class> Class* create() const;
    template<class Class> static Class* create(const Instance* context);
    template<class Class> static Class* create(const ServiceProvider* provider) {
        return provider ? provider->create<Class>() : NULL;
    }
public:
	ServiceProvider(void);   // INFERRED: ??0ServiceProvider@RBX@@QAE@XZ (header gap, header_gap_fill.py)
protected:
	void clearServices(void);   // INFERRED: ?clearServices@ServiceProvider@RBX@@IAEXXZ (header gap, header_gap_fill.py)
	// INFERRED: 005726a0/005726c0/00572ca0/00572b40/00572bc0/00572e40 vtable overrides (slots 5-8, 13 + Notifier<ServiceAdded> slot 1)
	virtual void onDescendentAdded(Instance* instance);
	virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);
	virtual void onChildAdded(Instance* child);
	virtual void onChildRemoving(Instance* child);
	virtual void onAddListener(Listener<ServiceProvider, ServiceAdded>* listener) const;
	virtual boost::shared_ptr<Instance> createChild(const Name& className);
};

// Layout recovered from the existing ServiceClient declaration. Method bodies
// require the native service-creation path and are intentionally unresolved.
template<class T>
class ServiceClient {
    Instance* context;
    mutable boost::shared_ptr<T> service;
public:
    explicit ServiceClient(Instance* value) : context(value) {}
    bool isNull() const;
    operator T*();
    operator const T*() const;
    T* operator->() { return createService(true); }
    const T* operator->() const { return createService(true); }
private:
    __declspec(noinline) T* createService(bool) const {
        if (service == NULL) service = shared_from<T>(ServiceProvider::create<T>(context));
        return service.get();
    }
};
}
