// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
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
    int doWork();
};

}

int func_007226b0(RBX::Instance* p)
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
                return t->doWork();
        }
    }
    return 0;
}
