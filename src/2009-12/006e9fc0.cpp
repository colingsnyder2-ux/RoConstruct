// from server: 75% by atomic.potato
struct Humanoid
{
    void f(int, void *);
};

extern "C" void G1_func_007a5c10(void *, int, void *);
extern "C" void G1_func_006e8ae0(void *);

void Humanoid::f(int value, void *object)
{
    G1_func_007a5c10((char *)this + 0x16c, value, object);
    if (object)
        G1_func_006e8ae0(object);
}
