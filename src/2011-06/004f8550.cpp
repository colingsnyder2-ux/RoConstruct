// from server: 52% by atomic.potato
typedef void *(*Call1)(void *);
typedef void *(*Call2)(void *, void *);

extern "C" void *Call_004f6f00(void *);
extern "C" void *Call_004f17c0(void *, void *);

struct S
{
    void f();
};

void S::f()
{
    void *value;
    value = Call_004f6f00(0);
    Call_004f17c0(value, this);
}
