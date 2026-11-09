// from server: 100% by atomic.potato
extern "C" int __stdcall func_00926478();

struct S_func_00804780 {
    char pad[32];
    int m_value;
    int f();
};

int S_func_00804780::f()
{
    if (m_value != 0 && (func_00926478() & 0x402000) != 0)
        return 1;
    return 0;
}
