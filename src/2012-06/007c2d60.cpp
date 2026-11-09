// from server: 48% by atomic.potato
struct S
{
    int value;
    float f();
};

extern float g_value;
extern unsigned char g_flag;
extern float __fastcall helper(int);

float S::f()
{
    if (g_flag)
        return g_value;

    return helper(value);
}
