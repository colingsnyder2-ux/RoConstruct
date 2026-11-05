// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace RBX {
struct ServiceProvider {
    void update();
};

struct Instance {
    char padding[0x288];
    float value;

    void notify(void* descriptor);
    void setValue(float v);
};
}

struct Signal {
    void fire(const float* value, int flags);
};

struct Entry {
    char padding[0x10];
    Signal signal;
};

struct Registry {
    Entry* find(void* key);
};

extern Registry registry;
RBX::ServiceProvider* func_004651c0(RBX::Instance* p);

void RBX::Instance::setValue(float v)
{
    if (v != value) {
        value = v;
        notify(reinterpret_cast<void*>(0x97a980));
        Entry* entry = registry.find(padding + 0x14);
        if (entry)
            entry->signal.fire(&v, 0);
        ServiceProvider* provider = func_004651c0(this);
        if (provider)
            provider->update();
    }
}
