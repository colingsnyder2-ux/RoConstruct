// from server: 100% by tester
namespace RBX {
struct ExtentsChanged {};

template<class Class, class Event>
class Notifier
{
    void* listeners;
public:
    void raise(Event event) const;
};

class ModelInstance
{
    char data[0x340];
protected:
    virtual void onExtentsChanged() const;
};

class Workspace : public ModelInstance, public Notifier<Workspace, ExtentsChanged>
{
protected:
    virtual void onExtentsChanged() const;
};

void Workspace::onExtentsChanged() const
{
    ModelInstance::onExtentsChanged();
    Notifier<Workspace, ExtentsChanged>::raise(ExtentsChanged());
}
}
