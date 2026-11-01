// from server: 100% by atomic.potato
extern "C" int __stdcall sub_007f3e3c(void *);

struct CChatPrompt
{
    int f(void *);
};

int CChatPrompt::f(void *p)
{
    if (!sub_007f3e3c(p))
        return 0;
    *(unsigned int *)((char *)p + 0x20) =
        (*(unsigned int *)((char *)p + 0x20) & 0xffcfff7fU) | 0x08000000U;
    return 1;
}
