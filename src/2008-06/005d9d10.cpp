// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Signal {};

namespace RBX {
    class Instance {
    public:
        virtual void placeholder();
    };

    class PartInstance : public Instance {
    public:
        char padding[0x224];
        Signal signal;
    };
}

struct Control {
    virtual void placeholder();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct SharedInstance {
    RBX::Instance* object;
    Control* control;

    ~SharedInstance();
};

inline SharedInstance::~SharedInstance()
{
    Control* c = control;
    if (c) {
        if (_InterlockedDecrement(&c->strong) == 0) {
            c->dispose();
            if (_InterlockedDecrement(&c->weak) == 0)
                c->destroy();
        }
    }
}

struct Listener {
    void connect(Signal* const&);
};

void update(SharedInstance instance, Listener* listener)
{
    RBX::PartInstance* part =
        dynamic_cast<RBX::PartInstance*>(instance.object);
    if (part) {
        Signal* signal = &part->signal;
        listener->connect(signal);
    }
}
