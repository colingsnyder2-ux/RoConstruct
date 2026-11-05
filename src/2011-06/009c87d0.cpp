// from server: 28% by atomic.potato
struct S {
    int f();
};

extern "C" void __cdecl sub_80b0ac();
extern "C" void std_string_destructor(void*);

int S::f()
{
    sub_80b0ac();
    std_string_destructor((char*)0);
    return 0;
}
