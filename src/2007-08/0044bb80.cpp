// from server: 100% by colin
struct CRobloxControlColorSelector {
    char pad[0xc0];
    int m_x;
    int m_y;
    void f(int* out, int a);
};

void CRobloxControlColorSelector::f(int* out, int a)
{
    int q = a / 8;
    int r = a % 8;
    int x = m_x + r * 32 + 2;
    int y = m_y + q * 32 + 2;
    out[0] = x;
    out[1] = y;
    out[2] = x + 32;
    out[3] = y + 32;
}
