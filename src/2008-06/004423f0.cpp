// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Base {
    char padding[0x90];
};

struct Listener {
    void bind(Base* value);
};

struct Source {
    char padding[0xc4];
    Listener listener;
};

struct Shared {
    Source* object;
    Control* control;
    ~Shared();
};

__forceinline Shared::~Shared()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Helper {
    void update(Source* source);
};

struct Prefix {
    char padding[0x188];
};

struct TextureItem : Prefix, Base {
    Helper helper;
    void update(Shared value);
};

void TextureItem::update(Shared value)
{
    helper.update(value.object);
    Base* base = this;
    if (value.object)
        value.object->listener.bind(base);
}
