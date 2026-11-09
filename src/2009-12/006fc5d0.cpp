// from server: 57% by atomic.potato
extern "C" void sub_6fc490(void*, void*, void*, void*);

struct S
{
    void f(void*);
};

void S::f(void* arg)
{
    void* a;
    void* b = arg;
    void* c = (void*)0x6fbfd0;
    sub_6fc490((char*)this - 0x98, &a, c, b);
}
