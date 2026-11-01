// from server: 66% by atomic.potato
extern "C" __declspec(dllimport) void __stdcall _invalid_parameter_noinfo();

struct S {
    char pad0[0xc];
    int m0c;
    int m10;
    int f(int arg);
};

int S::f(int arg)
{
    float best = *(float*)0xa1fb98;
    int count = (m10 - m0c) / 40;
    unsigned int i = 0;
    int off = 0;
    int result = 0;
    if (count != 0) {
        do {
            if (i >= (unsigned int)count)
                _invalid_parameter_noinfo();
            float* p = (float*)(m0c + off);
            float v = p[2] * *(float*)(arg + 4)
                    + p[3] * *(float*)(arg + 8)
                    + p[1] * *(float*)(arg + 0);
            if (v > best) {
                best = v;
                result = (int)p;
            }
            count = (m10 - m0c) / 40;
            i++;
            off += 40;
        } while (i < (unsigned int)count);
    }
    return result;
}
