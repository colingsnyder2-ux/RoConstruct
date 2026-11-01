// from server: 100% by king_originala
namespace RBX {
class Script;
class ServiceProvider;

class Instance {
public:
    virtual ~Instance();
    char pad[0x100];
    Instance* next;

    void setParent(Instance*);
};

class IScriptOwner {
public:
    virtual IScriptOwner* getOwner(Script*) = 0;
    virtual void attach(Script*, ServiceProvider*) = 0;
    virtual void detach(Script*) = 0;
};

class ServiceProvider : public Instance {
public:
    void registerScript(Script*);
};

class Script : public Instance {
public:
    char gap[0x54];
    IScriptOwner* owner;

    void f(Instance*);
};
}

RBX::ServiceProvider* func_00586910(RBX::Instance*);

void RBX::Script::f(Instance* parent)
{
    Instance::setParent(parent);

    Instance* p = next;
    IScriptOwner* found = 0;
    while (p) {
        IScriptOwner* candidate = dynamic_cast<IScriptOwner*>(p);
        if (candidate) {
            found = candidate->getOwner(this);
            if (found)
                break;
        }
        p = p->next;
    }

    if (found != owner) {
        if (owner)
            owner->detach(this);

        owner = found;
        ServiceProvider* provider = func_00586910(this);
        if (provider) {
            provider->registerScript(this);
            if (owner)
                owner->attach(this, provider);
        }
    }
}
