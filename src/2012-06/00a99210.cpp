// from server: 43% by atomic.potato
extern "C" void __cdecl sub_983144();
extern "C" void std_basic_string_destructor(void *);

struct S
{
    void f();
};

void S::f()
{
    sub_983144();
    std_basic_string_destructor((void *)((char *)this - 0x50));
}
