// from server: 77% by atomic.potato
struct StopCommand
{
    char pad[16];
    void *f();
};

extern "C" void *__cdecl sym(StopCommand *, int);

void *StopCommand::f()
{
    void *p = sym((StopCommand *)((char *)this + 16), 1);
    return *(int *)((char *)p + 168) == 1 ? (void *)1 : 0;
}
