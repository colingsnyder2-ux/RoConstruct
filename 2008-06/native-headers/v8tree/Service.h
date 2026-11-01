#pragma once
#include "v8tree/Instance.h"
#include <map>

namespace RBX {
class Service {};
class Closing;
struct ServiceAdded;
struct ServiceRemoving;
extern const char* sServiceProvider;

// Original RTTI and 00568bf0 establish the three notifier bases. Existing
// source supplies the service vector/map types; behavioral ABI remains open.
class __declspec(novtable) ServiceProvider :
    public DescribedNonCreatable<ServiceProvider, Instance, &sServiceProvider>,
    public Notifier<ServiceProvider, Closing>,
    public Notifier<ServiceProvider, ServiceAdded>,
    public Notifier<ServiceProvider, ServiceRemoving> {
public:
    mutable std::vector<boost::shared_ptr<Instance> > serviceArray;
    std::map<const Name*, boost::shared_ptr<Instance> > serviceMap;
    boost::shared_ptr<Instance> findServiceByClassName(const Name&) const;
    static size_t newIndex();
    template<class Class> static size_t doGetClassIndex();
    template<class Class> static void callDoGetClassIndex();
    template<class Class> static size_t getClassIndex();
    template<class Class> Class* find() const;
    template<class Class> Class* create() const;
};

// Layout recovered from the existing ServiceClient declaration. Method bodies
// require the native service-creation path and are intentionally unresolved.
template<class T>
class ServiceClient {
    Instance* context;
    mutable boost::shared_ptr<T> service;
public:
    explicit ServiceClient(Instance*);
    bool isNull() const;
    operator T*();
    operator const T*() const;
    T* operator->();
    const T* operator->() const;
};
}
