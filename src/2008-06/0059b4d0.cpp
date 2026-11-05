// from server: 100% by tester
namespace RBX {
struct CanAggregateChanged
{
    bool canAggregate;
    CanAggregateChanged(bool canAggregate) : canAggregate(canAggregate) {}
};

template<class Class, class Event>
class Listener;

template<class Class, class Event>
class Notifier
{
    void* listeners;
protected:
    virtual void onAddListener(Listener<Class, Event>* listener) const {}
public:
    void raise(Event event) const;
};

class Instance
{
    char data[0x14];
public:
    virtual ~Instance();
};

class IPrimitiveOwner
{
    char data[0x8];
public:
    virtual void onCanAggregateChanged(bool canAggregate) = 0;
};

class IRenderable
{
    char data[0x4];
public:
    virtual ~IRenderable();
    void shouldRenderSetDirty();
};

class PartInstance : public Notifier<PartInstance, CanAggregateChanged>,
                     public Instance,
                     public IPrimitiveOwner,
                     public IRenderable
{
public:
    virtual void onCanAggregateChanged(bool canAggregate);
};

void PartInstance::onCanAggregateChanged(bool canAggregate)
{
    Notifier<PartInstance, CanAggregateChanged>::raise(canAggregate);
    shouldRenderSetDirty();
}
}
