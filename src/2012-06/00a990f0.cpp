// from server: 43% by atomic.potato
extern "C" void __cdecl sub_00983144();
extern "C" void std_string_destructor(void*);

struct S
{
    void f();
};

void S::f()
{
    sub_00983144();
    void* p = (void*)((char*)this - 0x50);
    std_string_destructor(p);
}
