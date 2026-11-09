// from server: 71% by atomic.potato
struct S
{
    void *f();
    float x;
    float y;
};

extern "C" void *__cdecl func_0080a05e(S *, int);

void *S::f()
{
    void *p = func_0080a05e(this, 12);
    if (p != 0)
    {
        *(int *)p = 0xA7B324;
        *(float *)((char *)p + 4) = x;
        *(float *)((char *)p + 8) = y;
    }
    return p;
}
