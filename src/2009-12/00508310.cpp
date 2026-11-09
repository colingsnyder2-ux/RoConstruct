// from server: 54% by atomic.potato
extern "C" void Function5064C0(void*, const char*);

struct S
{
    void f(char);
};

void S::f(char value)
{
    void* p = *(void**)this;
    if (p)
        Function5064C0(p, "T$ R");
}
