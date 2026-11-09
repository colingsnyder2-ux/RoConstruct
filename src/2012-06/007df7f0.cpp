// from server: 66% by atomic.potato
extern "C" void Function_007deb70(void*, void*, int);

struct S
{
    void* f(void*);
};

void* S::f(void* value)
{
    Function_007deb70((char*)this + 4, value, 0);
    return value;
}
