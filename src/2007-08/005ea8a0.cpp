// from server: 100% by colin
struct S {
    char pad[0x294];
    int field;
    void f(int);
};

extern "C" void __stdcall helper_444710(int);

void S::f(int value)
{
    field = value;
    helper_444710(0x8c291c);
}
