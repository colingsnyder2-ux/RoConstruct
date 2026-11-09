// from server: 85% by atomic.potato
struct Humanoid
{
    int f();
};

extern "C" int func_006e32e0(Humanoid *);

int Humanoid::f()
{
    return func_006e32e0((Humanoid *)((char *)this - 324)) != 0;
}
