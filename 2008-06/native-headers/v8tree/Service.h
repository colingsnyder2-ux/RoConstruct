#pragma once
#include "v8tree/Instance.h"
#include <map>

namespace RBX {
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
class __declspec(novtable) ServiceProvider :
    public DescribedNonCreatable<ServiceProvider, Instance, sServiceProvider>,
    public Notifier<ServiceProvider, Closing>,
    public Notifier<ServiceProvider, ServiceAdded>,
    public Notifier<ServiceProvider, ServiceRemoving> {
public:
    static const ServiceProvider* findServiceProvider(const Instance*);
    mutable std::vector<boost::shared_ptr<Instance> > serviceArray;
    std::map<const Name*, boost::shared_ptr<Instance> > serviceMap;
    boost::shared_ptr<Instance> findServiceByClassName(const Name&) const;
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
