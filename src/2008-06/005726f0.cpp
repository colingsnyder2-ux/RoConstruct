// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX {
    class ServiceProvider;
}

struct Object {
    void attach(RBX::ServiceProvider*);
};

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    Object* object;
    Control* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    if (control)
        control->release();
}

namespace RBX {
    class Instance {
    public:
        virtual void slot0();
        virtual void slot1();
        virtual void slot2();
        virtual void slot3();
        virtual void slot4();
        virtual void slot5();
        virtual void slot6();
        virtual void slot7();
        virtual void slot8();
        virtual void slot9();
        virtual void slot10();
        virtual void slot11();
        virtual void slot12();

        char padding[256];
        Instance* parent;
    };

    class ServiceProvider : public Instance {
    public:
        virtual Shared find(void*);
    };
}

Object* findService(RBX::Instance* instance, void* key)
{
    while (instance) {
        RBX::ServiceProvider* provider =
            dynamic_cast<RBX::ServiceProvider*>(instance);
        if (provider) {
            Shared result = provider->find(key);
            if (result.object)
                result.object->attach(provider);
            return result.object;
        }
        instance = instance->parent;
    }
    return 0;
}
