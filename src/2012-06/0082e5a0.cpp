// from server: 89% by atomic.potato
struct S
{
    int field24;
    int field28;
    void f(void* value);
};

extern "C" int __fastcall G1_func_007b9450(void*);
extern "C" void __fastcall G1_func_0082e200(int, void*);

void S::f(void* value)
{
    if (G1_func_007b9450(value) == 10)
        field28 = (int)value;
    G1_func_0082e200(field24, value);
}
