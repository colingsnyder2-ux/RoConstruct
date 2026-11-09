// from server: 63% by atomic.potato
struct S
{
    int pad;
    int a;
    int b;
};

extern "C" void* __cdecl operator_new(unsigned int);

void* func_004f58e0(S* p)
{
    void* q = operator_new(12);
    if (q == 0)
        return 0;
    *(int*)q = 0xA7B430;
    *(int*)((char*)q + 4) = p->a;
    *(int*)((char*)q + 8) = p->b;
    return q;
}
