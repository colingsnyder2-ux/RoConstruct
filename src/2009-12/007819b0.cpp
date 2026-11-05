// from server: 97% by atomic.potato
struct S
{
    char padding[36];
    int member24;
    char member20;

    void member();
};

extern "C" void __cdecl G1_func_00782eb0(void *);
extern "C" void __cdecl G1_func_00782960(void *);

void S::member()
{
    if (member24 != 0)
        G1_func_00782eb0((char *)this + 8);
    G1_func_00782960((char *)this + 8);
    member20 = 0;
}
