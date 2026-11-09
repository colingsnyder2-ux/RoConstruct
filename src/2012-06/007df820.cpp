// from server: 66% by atomic.potato
extern "C" void Function_007dece0(void*, void*, int);

struct S
{
    void* f(void* p);
};

void* S::f(void* p)
{
    Function_007dece0((char*)this + 4, p, 0);
    return p;
}
