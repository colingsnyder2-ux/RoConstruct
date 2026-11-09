// from server: 56% by atomic.potato
struct S
{
    int f();
};

extern "C" void * __cdecl sub_4430F0(void *);
extern "C" int sub_A426B0(void *);
extern "C" void sub_A42E08(void *);

int S::f()
{
    void *p = sub_4430F0((void *)&p);
    int result = sub_A426B0(p);
    sub_A42E08((void *)&p);
    return result;
}
