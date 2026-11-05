// from server: 35% by atomic.potato
struct S
{
    void* f(void*);
    void* v;
};

extern "C" void* G1_func_00664640(S*, void*);

void* S::f(void* arg)
{
    G1_func_00664640(this, arg);
    return 0;
}
