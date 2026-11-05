// from server: 45% by atomic.potato
struct Tool {
    char pad0[0x30];
    float m[3][3];
    void getRow(int i, float* out);
    void setRow(int i, const float* in);
    void func_005f9740();
};

extern float g_00a1d6c0;
extern float g_00a0c610;
extern float g_00a1f624;

void Tool::func_005f9740()
{
    int i;
    float v[3];
    for (i = 0; i < 3; ++i) {
        getRow(i, v);
        if (g_00a1d6c0 > v[0]*v[0] + v[1]*v[1] + v[2]*v[2]) {
            v[0] = 0.0f;
            v[1] = g_00a0c610;
            v[2] = 0.0f;
            setRow(0, v);
            v[0] = g_00a1f624;
            v[1] = 0.0f;
            v[2] = 0.0f;
            setRow(1, v);
            v[0] = 0.0f;
            v[1] = 0.0f;
            v[2] = g_00a0c610;
            setRow(2, v);
            return;
        }
    }
}
