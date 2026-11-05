// from server: 71% by atomic.potato
struct S
{
    int field_168;
    void f(int value);
};

extern "C" void __stdcall sub_66c600(S *, int);
extern "C" void __stdcall sub_6a3080(int *, int);

void S::f(int value)
{
    sub_66c600(this, value);
    sub_6a3080(&field_168, 2);
}
