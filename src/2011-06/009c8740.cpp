// from server: 40% by atomic.potato
extern "C" void __cdecl sub_0080b0ac();
extern "C" void std_basic_string_destructor(void*);

struct S
{
    void f();
};

void S::f()
{
    sub_0080b0ac();
    {
        char local[80];
        std_basic_string_destructor(local);
    }
}
