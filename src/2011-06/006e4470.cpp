// from server: 100% by atomic.potato
extern "C" void __cdecl sub_6e3950();
extern void (__cdecl *g_func_6e465c)(void *);
extern void *g_data_6e4660;
extern void *g_data_6e4664;

struct S
{
    void f();
    char reserved[0x14];
    void *value;
};

void S::f()
{
    sub_6e3950();
    value = g_data_6e4664;
    value = g_data_6e4660;
    g_func_6e465c(&value);
}
