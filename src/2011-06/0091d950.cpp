// from server: 81% by atomic.potato
struct ViewRbxGfx;

extern "C" int __stdcall sub_005f67a0(ViewRbxGfx*, int);

struct ViewRbxGfx
{
    char pad_0[12];
    ViewRbxGfx* m_p;
    char pad_10[16];
    int m_value;
    int f();
};

int ViewRbxGfx::f()
{
    return sub_005f67a0(m_p, m_value);
}
