// from server: 26% by atomic.potato
struct S
{
    void* get_523e90();
    int call_7e7f30(void*, double);
    int f(void*, void*);
};

void* S::get_523e90()
{
    return 0;
}

int S::call_7e7f30(void*, double)
{
    return 0;
}

int S::f(void* a, void* b)
{
    void* p = get_523e90();
    double value = *(float*)((char*)p + 0x104);
    call_7e7f30(b, value);
    return (int)b;
}
