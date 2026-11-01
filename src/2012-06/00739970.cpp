// from server: 67% by Intel
extern "C" void __stdcall G1_func_00684200(int, int);

struct StarterGuiService
{
    int f(int);
};

int StarterGuiService::f(int arg)
{
    if (arg != 0)
    {
        int v = *(int *)((char *)this + 0x94);
        G1_func_00684200(0, v);
    }
    return arg;
}
