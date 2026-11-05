// from server: 42% by atomic.potato
extern "C" void __cdecl sub_0080b0ac();
extern "C" void std_basic_string_destructor(void*);

struct S
{
    int f();
};

int S::f()
{
    sub_0080b0ac();
    char local[0x40];
    std_basic_string_destructor(local);
    return 0;
}
