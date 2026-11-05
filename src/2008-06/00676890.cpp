// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct Object;
struct Context;

struct Ref {
    Object* p;
    Ref() : p(0) {}
    Ref(const Ref&);
    ~Ref();
};

struct Object {
    volatile long count;
    virtual void destroy(unsigned int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual Ref clone(Context*);
    void dispose();
};

struct Context {
    void draw(int, Ref);
};

struct S {
    void* vtable;
    Context* context;
    void f(int, Ref);
};

inline Ref::~Ref() {
    if (p && InterlockedDecrement(&p->count) == 0) {
        p->dispose();
        if (p)
            p->destroy(1);
    }
}

void S::f(int value, Ref object) {
    if (object.p)
        context->draw(value, object.p->clone(context));
    else
        context->draw(value, Ref());
}
