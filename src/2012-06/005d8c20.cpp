// from server: 35% by atomic.potato
struct S_func_005d8c20 {
    char pad[0x58];
    float m_58;
    float m_5c;
    float m_60;
    int m_64;
    int m_68;
    void f(float* out, int a, int b);
};

void S_func_005d8c20::f(float* out, int a, int b)
{
    bool b58 = m_58 != 0.0f;
    bool b60 = m_60 != 0.0f;
    bool b5c = m_5c != 0.0f;
    int v64 = 1;
    int v68 = 1;
    out[0] = m_58;
    out[1] = 1;
    out[2] = 1;
    if (b60) {
        v64 = m_64;
        v68 = m_68;
        if (b58) {
            if (b5c) {
                v64 += 6;
                v68 += 6;
            } else {
                v64 += 2;
                v68 += 2;
            }
        }
    } else if (b58) {
        if (b5c) {
            v64 += 6;
            v68 += 6;
        } else {
            v64 += 2;
            v68 += 2;
        }
    }
    out[1] = v64;
    out[2] = v68;
}
