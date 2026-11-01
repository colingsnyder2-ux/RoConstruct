#pragma once
#include "v8tree/Instance.h"
#include <map>

namespace RBX {
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
    std::vector<boost::shared_ptr<Instance> > serviceArray;
    std::map<const Name*, boost::shared_ptr<Instance> > serviceMap;
};
}
