// =============================================================================
// Service.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8tree/Service.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Instance.h"
#include <map>

namespace RBX
{
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
};

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
