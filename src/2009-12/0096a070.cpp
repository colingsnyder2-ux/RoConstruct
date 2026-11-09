// from server: 83% by atomic.potato
typedef float Float32;

extern volatile Float32 g_009b2384;
extern volatile Float32 g_009af2fc;
extern volatile Float32 g_00b7ce08;
extern volatile Float32 g_00b7ce0c;
extern volatile Float32 g_00b7ce10;
extern volatile Float32 g_00b7ce14;

struct S
{
    void f();
};

void S::f()
{
    g_00b7ce08 = g_009b2384;
    g_00b7ce0c = g_009b2384;
    g_00b7ce10 = g_009b2384;
    g_00b7ce14 = g_009af2fc;
}
