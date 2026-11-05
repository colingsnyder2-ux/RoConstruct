// from server: 70% by atomic.potato
struct S {
    int Get();
};

int S::Get()
{
    return *(int *)((char *)this + 0x830);
}
