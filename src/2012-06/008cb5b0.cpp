// from server: 91% by atomic.potato
extern "C" void sub_005366e0(void *);

struct EventDesc
{
    void f(void *);
};

void EventDesc::f(void *p)
{
    char *v = (char *)p;
    if (v)
        v -= 0x1c;
    else
        v = 0;

    int x = *(int *)(v + 0x84);
    x = *(int *)(x + *(int *)((char *)this + 0x34));
    x += *(int *)((char *)this + 0x30);

    sub_005366e0(v + x + 0x84);
}
