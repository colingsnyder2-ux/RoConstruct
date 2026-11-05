// from server: 56% by atomic.potato
extern "C" void __cdecl sub_483A00();
extern "C" void __cdecl sub_7A89B2(void*, const char*);

struct S
{
    void f();
};

void S::f()
{
    sub_483A00();

    char buffer[80];
    sub_7A89B2(buffer, "D$ P");
}
