// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class ServiceProvider;
class Instance {
public:
    virtual void v0();
    virtual void v1();
    virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
    virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);
};
class ServiceProvider : public Instance {
public:
    virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);
};
void ServiceProvider::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
{
    instance->onServiceProvider(this, 0);
    Instance::onDescendentRemoving(instance);
}
}
