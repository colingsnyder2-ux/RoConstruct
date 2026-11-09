// from server: 75% by atomic.potato
extern "C" void __cdecl sub_7F539A();
extern "C" void __cdecl sub_7F3B0C();

struct S
{
    void f();
};

void S::f()
{
    sub_7F539A();
    sub_7F3B0C();
}
