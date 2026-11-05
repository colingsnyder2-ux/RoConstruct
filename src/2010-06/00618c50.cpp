// from server: 88% by atomic.potato
struct S
{
    char pad[8];
    int off8;
    int offc;
    int off10;
    void (__thiscall *fn)(void*, float**);

    void f(void* a, float* out);
};

void S::f(void* a, float* out)
{
    char* p = (char*)a;
    if (p)
        p -= 0x1c;
    else
        p = 0;
    int i = *(int*)((char*)this + 0x10);
    int off = *(int*)(p + 0xb4);
    int c = *(int*)(off + i) + *(int*)((char*)this + 0xc);
    void (__thiscall *fn)(void*, float**) = *(void (__thiscall **)(void*, float**))((char*)this + 8);
    float* r;
    fn((char*)p + c + 0xb4, &r);
    out[0] = r[0];
    out[1] = r[1];
    out[2] = r[2];
}
