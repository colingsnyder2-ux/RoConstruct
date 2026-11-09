// from server: 79% by atomic.potato
struct Weld
{
    int v0;
    int v1;
    int v6;
    int v7;
    int v32;
    void Init();
};

extern "C" void __cdecl G1_func_00811a80();

void Weld::Init()
{
    v0 = 0xbc65cc;
    v1 = 0xbc65c0;
    v6 = 0xbc65b4;
    v7 = 0xbc65a8;
    v32 = 0xbc657c;
    G1_func_00811a80();
}
