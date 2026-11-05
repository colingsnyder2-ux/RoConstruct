// from server: 48% by atomic.potato
extern "C" float* __cdecl func_005f6f90();

struct S_func_00657140 {
    float* m_out;
    int f(float* out);
};

int S_func_00657140::f(float* out)
{
    float* p = func_005f6f90();
    out[0] = p[0];
    out[1] = p[1];
    out[2] = p[2];
    out[3] = 0.0f;
    return 0;
}
