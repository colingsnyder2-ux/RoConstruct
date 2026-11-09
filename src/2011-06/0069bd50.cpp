// from server: 57% by atomic.potato
extern "C" void std_string_copy(void *, const void *);
extern "C" void call_004c0720(void *);

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    char local[28];
    *(void **)(local + 32) = local;
    std_string_copy(local, (char *)this + 0x90);
    call_004c0720((char *)this + 0xac);
}
