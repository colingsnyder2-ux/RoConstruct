// from server: 100% by king_originala
struct Handle {
    void* object;
    void* control;
    void release();
};

struct Context {
    char padding[0x138];
    unsigned char enabled;
};

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char pad[0x100];
        Instance* next;
    };

    class ServiceProvider : public Instance {
    public:
        ServiceProvider* finish();
        void acquire(Handle* result, void* property);
    };
}

extern unsigned char disabled;
RBX::ServiceProvider* func_00465210(RBX::Instance* p);

struct S : RBX::Instance {
    char padding[0x38];
    char property[0x25];
    unsigned char flags;

    Context* context();
    void update();
};

void S::update()
{
    if (disabled)
        return;
    if (flags & 4)
        return;
    if (!context()->enabled)
        return;

    RBX::ServiceProvider* provider = func_00465210(this);
    if (provider) {
        Handle result;
        provider->acquire(&result, property);
        result.release();
    }
}
