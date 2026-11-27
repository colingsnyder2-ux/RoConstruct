// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class ServiceProvider;
class Instance;
struct InstancePtr { Instance* px; void* pn; Instance* operator->() const { return px; } };
class Instance {
public:
    virtual ~Instance();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
    virtual void onDescendentRemoving(const InstancePtr& instance);
};
class ServiceProvider : public Instance {
public:
    virtual void onDescendentRemoving(const InstancePtr& instance);
};
void ServiceProvider::onDescendentRemoving(const InstancePtr& instance)
{
    instance->onServiceProvider(this, 0);
    Instance::onDescendentRemoving(instance);
}
}