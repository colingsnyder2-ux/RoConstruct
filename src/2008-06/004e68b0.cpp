// from server: 100% by colin
// from server: 97% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern const float upperLimit;
extern const float lowerLimit;

struct Ref {
    virtual ~Ref();
    volatile long references;
    void release();
};

struct Ptr {
    Ref* p;
    Ptr(Ref* value);
    ~Ptr();
    void clear();
};

inline Ptr::Ptr(Ref* value) : p(value)
{
    if (p)
        InterlockedIncrement(&p->references);
}

inline void Ptr::clear()
{
    if (p) {
        if (InterlockedDecrement(&p->references) == 0) {
            p->release();
            if (p)
                delete p;
        }
        p = 0;
    }
}

inline Ptr::~Ptr()
{
    clear();
}

struct Model {
    char padding[0x1c8];
    int state;
};

struct Handler {
    virtual void update(const Ptr&, bool);
};

struct Holder {
    int padding;
    Handler* handler;
};

struct S : Ref {
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void setValue(float);
    virtual float getValue();

    char padding[0xb4];
    Model* model;
    int unused;
    Ptr pending;
    bool active;
    char tailPadding[7];
    Holder* holder;

    void f();
};

void S::f()
{
    if (!model)
        return;

    pending.clear();
    active = true;

    {
        Ptr self(this);
        Holder* h = holder;
        Handler* handler = h->handler;
        handler->update(self, model->state == 0);
    }

    if (model->state != 0) {
        if (getValue() < upperLimit)
            setValue(upperLimit);
    } else {
        if (getValue() < lowerLimit)
            setValue(0.0f);
    }
}
