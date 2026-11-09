// from server: 75% by atomic.potato
extern "C" int fn_007b9450(void*);
extern "C" void fn_0082e370(void*, void*);

struct BallBlockContact
{
    int field24;
    int field28;
    void f(void*);
};

void BallBlockContact::f(void* arg)
{
    if (fn_007b9450(arg) == 10)
        field28 = 0;
    fn_0082e370((void*)field24, arg);
}
