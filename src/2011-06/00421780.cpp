// from server: 100% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    char* p = *(char**)this;
    if (p)
        *p = *((char*)this + 4);
}
