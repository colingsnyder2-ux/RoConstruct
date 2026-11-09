// from server: 30% by atomic.potato
extern "C" void __cdecl sub_0080b0ac();
extern "C" void basic_string_destructor(void *);

struct S
{
    void f();
};

void S::f()
{
    sub_0080b0ac();
    basic_string_destructor((void *)0);
}
