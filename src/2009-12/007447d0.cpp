// from server: 97% by atomic.potato
extern "C" void __cdecl sub_40C080(void *);

struct S
{
    void f(void *);
};

void S::f(void *value)
{
    *(void **)((char *)this + 0x1bc) = value;
    sub_40C080((void *)0xb96e38);
}
