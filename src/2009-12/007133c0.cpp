// from server: 53% by atomic.potato
struct S {
    char pad[0x10];
    int (__stdcall *fn)(float, float, float);
    int offset;
    int method(int, float*);
};

int S::method(int a, float* b)
{
    S* p;
    if (a != 0)
        p = (S*)((char*)a - 0x1c);
    else
        p = 0;

    float x = b[0];
    float y = b[1];
    float z = b[2];

    return ((int (__stdcall *)(float, float, float))((char*)p->fn + p->offset))(x, y, z);
}
