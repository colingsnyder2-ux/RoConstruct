// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Sig { void fire(); };

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

    ((Sig*)(v + x + 0x84))->fire();
}
