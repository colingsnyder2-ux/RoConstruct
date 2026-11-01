// from server: 100% by tester
namespace RBX {
class Instance;
struct DescendentAdded {};

template<class Class, class Event>
class Listener;

template<class Class, class Event>
class Notifier
{
protected:
    virtual void onAddListener(Listener<Class, Event>* listener) const = 0;
};

class DescribedBase
{
    char data[0x60];
public:
    virtual ~DescribedBase();
};

class Instance : public DescribedBase, public Notifier<Instance, DescendentAdded>
{
    class RaiseDescendentAdded2
    {
        const Instance* instance;
        Listener<Instance, DescendentAdded>* listener;
    public:
        RaiseDescendentAdded2(const Instance* instance, Listener<Instance, DescendentAdded>* listener)
            : instance(instance), listener(listener)
        {
        }
    };

    template<class Func>
    void for_eachChild(Func func) const;

protected:
    virtual void onAddListener(Listener<Instance, DescendentAdded>* listener) const;
};

void Instance::onAddListener(Listener<Instance, DescendentAdded>* listener) const
{
    for_eachChild(RaiseDescendentAdded2(this, listener));
}
}
