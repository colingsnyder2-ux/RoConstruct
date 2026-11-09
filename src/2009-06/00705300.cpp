// from server: 100% by why2
extern "C" long (__stdcall *InterlockedExchange)(long volatile *Target, long Value);

struct S_func_00705300 {
    void f();
};

void S_func_00705300::f()
{
    long *p = *(long **)this;
    InterlockedExchange(p, 0);
}
