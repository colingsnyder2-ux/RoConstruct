// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Signal {
    void fire(float*, int);
};

struct Connection {
    char padding[0x10];
    Signal signal;
};

struct Registry {
    Connection* find(void*);
};

extern Registry registry;
extern char property;

namespace RBX {
    class Instance;
    class ServiceProvider {
    public:
        void update();
    };
}

RBX::ServiceProvider* __cdecl func_004651c0(RBX::Instance*);

struct Lighting {
    char prefix[0x14];
    char identity[0x210];
    float value;

    void notify(const void*);
    void setValue(float);
};

void Lighting::setValue(float v)
{
    if (v != value) {
        value = v;
        notify(&property);
        Connection* connection = registry.find(identity);
        if (connection)
            connection->signal.fire(&v, 0);
        RBX::ServiceProvider* provider =
            func_004651c0(reinterpret_cast<RBX::Instance*>(this));
        if (provider)
            provider->update();
    }
}
