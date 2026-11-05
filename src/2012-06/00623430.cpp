// from server: 89% by atomic.potato
extern "C" void *__cdecl fn_004d7940(void *, void *, void *);

struct WedgeBuilder
{
    void f();
};

void WedgeBuilder::f()
{
    void **begin = (void **)((char *)this + 4);
    void **end = (void **)((char *)this + 8);

    if (*begin != *end)
    {
        void *value = *end;
        *end = fn_004d7940(value, value, *begin);
    }
}
