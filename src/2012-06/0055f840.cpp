// from server: 90% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    *(int *)this = 0xB73EAC;
    *((int *)this + 1) = 0xB73EA0;
    *((int *)this + 6) = 0xB73E94;
    *((int *)this + 7) = 0xB73E88;
}
