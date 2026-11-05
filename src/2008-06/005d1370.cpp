// from server: 100% by king_originala
namespace RBX {
    class Instance;
    class ServiceProvider {
    public:
        void notify();
    };
}

RBX::ServiceProvider* __cdecl func_00491e50(RBX::Instance*);

struct Signal {
    void invoke(char*);
};

struct LookupResult {
    char padding[0x10];
    Signal signal;
};

struct Registry {
    LookupResult* find(void*);
};

extern Registry registry;

struct HopperBin {
    char padding[0x1a0];
    int state;
    bool active;

    void deactivate();
};

void HopperBin::deactivate()
{
    if (active) {
        if (state == 0) {
            LookupResult* result = registry.find((char*)this + 0x14);
            if (result) {
                char token;
                result->signal.invoke(&token);
            }
        }

        active = false;
        RBX::ServiceProvider* provider =
            func_00491e50((RBX::Instance*)this);
        if (provider)
            provider->notify();
    }
}
