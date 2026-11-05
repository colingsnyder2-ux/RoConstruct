// from server: 100% by tajop
namespace RBX {

class Instance {
public:
    virtual ~Instance();
    char pad[0x34];
    Instance* parent;
    Instance* getRoot();
};

class ServiceProvider : public Instance {
public:
    virtual ~ServiceProvider();
};

}

RBX::ServiceProvider* func_004a01f0(RBX::Instance* p)
{
    if (p) {
        RBX::Instance* r = p->parent;
        if (r) {
            RBX::Instance* g = r->parent;
            if (g)
                r = g->getRoot();
        } else {
            r = p;
        }
        if (r) {
            RBX::ServiceProvider* t = dynamic_cast<RBX::ServiceProvider*>(r);
            if (t)
                return t;
        }
    }
    return 0;
}
