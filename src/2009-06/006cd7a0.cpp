// from server: 100% by atomic.potato
struct RBX_AxisMoveTool {
    int m0;
    int m4;
    int m8;
    int m12;
    void sub_006cd7a0(int a, int b);
};

extern "C" bool __cdecl func_0063c8b0(int *p);

void RBX_AxisMoveTool::sub_006cd7a0(int a, int b)
{
    int tmp[2];
    tmp[0] = a;
    tmp[1] = b;
    if (!func_0063c8b0(tmp)) {
        int *p = &m8;
        if (p) {
            p[0] = tmp[0];
            p[1] = tmp[1];
        }
        m0 = 0xa231cc;
    } else {
        m0 = 0;
    }
}
