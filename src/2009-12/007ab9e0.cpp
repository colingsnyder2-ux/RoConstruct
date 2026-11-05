// from server: 62% by atomic.potato
extern "C" double __cdecl sub_007ab930();

float g_009c0efc;

struct S
{
    unsigned char f();
};

unsigned char S::f()
{
    double value = sub_007ab930();
    return value > g_009c0efc ? 1 : 0;
}
