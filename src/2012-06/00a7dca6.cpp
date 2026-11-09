// from server: 61% by atomic.potato
extern "C" void __cdecl sub_00a814d5(int);

extern "C" void __cdecl sub_00e085ec(const char*, float);

struct S
{
    void f(const char*, float);
};

void S::f(const char* text, float value)
{
    sub_00a814d5(1);
    sub_00e085ec(text, value);
}
