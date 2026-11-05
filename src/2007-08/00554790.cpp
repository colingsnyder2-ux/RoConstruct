// from server: 100% by colin
struct Instance {
    void* vtable;
};

struct ServiceProvider {
    void addService(Instance* service);
    void onServiceProvider(Instance* service);
};

void ServiceProvider::onServiceProvider(Instance* service) {
    addService(service);
    void** vtbl = *(void***)service;
    typedef void (__thiscall *Fn)(Instance*, int, ServiceProvider*);
    Fn fn = (Fn)vtbl[0x34 / 4];
    fn(service, 0, this);
}
