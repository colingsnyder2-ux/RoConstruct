// from server: 32% by atomic.potato
extern "C" void __cdecl sub_4125D0();
extern "C" void __cdecl sub_6CAB60();
extern "C" void __cdecl sub_9831F5();

extern unsigned char g_00e36f54;
extern unsigned char g_00e36d70;

struct S_00760640 {
    void f_00760640();
};

void S_00760640::f_00760640()
{
    if (!(g_00e36f54 & 1)) {
        g_00e36f54 |= 1;
        sub_4125D0();
        sub_6CAB60();
        sub_9831F5();
    }
}
