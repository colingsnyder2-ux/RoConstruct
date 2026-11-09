// from server: 69% by atomic.potato
struct S_func_006fc420
{
    unsigned char padding[5];
    unsigned char field5;
    void* f(void* a, void* b);
};

void* sub_006fc1e0(void*, void*, void*);

void* S_func_006fc420::f(void* a, void* b)
{
    if (field5)
        return sub_006fc1e0(this, b, a);

    ((unsigned long*)a)[0] = 0;
    ((unsigned long*)a)[1] = 0;
    ((unsigned long*)a)[2] = 0;
    ((unsigned long*)a)[3] = 0;
    return 0;
}
