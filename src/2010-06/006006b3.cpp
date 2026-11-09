// from server: 35% by atomic.potato
struct S
{
    void f(void*);
};

extern "C" void func_005a10c0(void*);

void S::f(void* p)
{
    func_005a10c0(this);
    *(int*)p = 0;
    *((int*)p + 1) = 0;
}
