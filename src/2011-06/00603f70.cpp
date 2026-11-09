// from server: 100% by atomic.potato
int g_SetGridToOneFifth = 0;

struct SetGridToOneFifth
{
    void __stdcall f();
};

void __stdcall SetGridToOneFifth::f()
{
    g_SetGridToOneFifth = 1;
}
