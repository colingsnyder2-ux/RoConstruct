// from server: 68% by atomic.potato
struct S
{
    void Get();
};

extern "C" int Target(void *, int);

void S::Get()
{
    int value = *(int *)((char *)this + 0x90);
    Target((char *)this + 0x94, value);
}
