// from server: 27% by atomic.potato
struct S_func_0042c120 {
    void* f();
};

struct S_func_004df0c0 {
    char pad0[4];
    void* (S_func_0042c120::*p)();
    void f();
};

void S_func_004df0c0::f()
{
    char c;
    S_func_0042c120 obj;
    obj.f();
    S_func_0042c120* q = (S_func_0042c120*)this;
    (q->*p)();
}
