// from server: 91% by atomic.potato
struct S
{
    void *get();
};

extern "C" void *__cdecl sub_6e6650();

void *S::get()
{
    void *p = sub_6e6650();
    if (p)
    {
        p = *(void **)((char *)p + 0x168);
        p = *(void **)((char *)p + 0xf4);
    }
    if (p)
        return *(void **)((char *)p + 0x2c);
    return 0;
}
