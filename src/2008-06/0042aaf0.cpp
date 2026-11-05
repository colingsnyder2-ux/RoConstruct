// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


struct Object;

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    long strong;
    long weak;
    Object* object;
};

struct Weak {
    Object* object;
    Control* control;
};

struct Object {
    virtual ~Object();
    Weak weak;
};

struct Count {
    Control* control;
    Count(Object*);
    ~Count();
};

struct S {
    Object* object;
    Count count;
    S(Object*);
};

S::S(Object* p) : object(p), count(p)
{
    if (p) {
        Weak* w = &p->weak;
        if (w) {
            w->object = p;
            Control* c = count.control;
            if (c)
                _InterlockedIncrement(&c->weak);

            Control* old = w->control;
            if (old && _InterlockedDecrement(&old->weak) == 0)
                old->destroy();

            w->control = c;
        }
    }
}
