// from server: 88% by atomic.potato
extern "C" int __stdcall sub_005ccdd0(int, int);

struct ViewRbxGfx_008c3a60 {
    char pad0[4];
    int m_arg;
    char pad8[16];
    int m_value;
    int f();
};

int ViewRbxGfx_008c3a60::f()
{
    return sub_005ccdd0(m_arg, m_value);
}
