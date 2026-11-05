// from server: 71% by atomic.potato
typedef void (__thiscall *F150)(void *);

struct S
{
    void f150();
    char pad[0x50];
    unsigned char flag;
    void f();
};

void S::f()
{
    f150();
    if (flag)
        f150();
}
