// from server: 48% by atomic.potato
struct S
{
    void *Get();
};

void *S::Get()
{
    void *p = *((void **)((char *)this - 8));
    return (*(void *(**)(void *))(*(unsigned long *)p + 8))(p);
}
