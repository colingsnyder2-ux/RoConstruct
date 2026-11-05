// from server: 42% by atomic.potato
struct CVideoStream
{
    void *p;
    int f(void **out);
};

extern "C" void *__cdecl operator_new(unsigned int size);

int CVideoStream::f(void **out)
{
    if (out == 0)
        return (int)0x80004003;

    CVideoStream *v = (CVideoStream *)operator_new(0x14);
    if (v == 0)
    {
        *out = 0;
        return (int)0x8007000e;
    }

    v->p = (char *)this - 0xc;
    *(int *)((char *)v + 0) = 0xb64118;
    *(int *)((char *)v + 4) = 0;
    *(int *)((char *)v + 0x10) = 1;

    int *a = (int *)((char *)v->p + 0xc);
    int *b = *(int **)a;
    ((void (__thiscall *)(int *, int *))*(int **)((char *)b + 4))(b, a);

    int *c = *(int **)((char *)v + 8);
    int *d = *(int **)c;
    *(int *)((char *)v + 0xc) = ((int (__thiscall *)(int *))*(int **)((char *)d + 0x10))(c);

    *out = v;
    return 0;
}
