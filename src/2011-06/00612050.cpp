// from server: 90% by atomic.potato
struct S
{
    S* f(void*);
    int pad[7];
};

extern "C" void sub_64fce0(S*, void*);

S* S::f(void* arg)
{
    sub_64fce0(this, arg);
    pad[6] = *(int*)((char*)&arg + 16);
    return this;
}
