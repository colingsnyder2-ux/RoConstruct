// from server: 58% by atomic.potato
struct S
{
    void f(float, float);
};

extern "C" float __cdecl sub_006fe450(float);
extern "C" void sub_00701780(void*, float);

void S::f(float a, float b)
{
    float x = sub_006fe450(b);
    sub_00701780((void*)0x00c22600, x);
}
