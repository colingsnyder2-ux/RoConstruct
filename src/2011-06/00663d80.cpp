// from server: 33% by atomic.potato
struct CoreScript {
    float x;
    float y;
    void normalize(float* out);
};

extern float g_00a63b14;
extern "C" void __stdcall sub_0053b3d0(float* out, float len);

void CoreScript::normalize(float* out)
{
    float len = x * x + y * y;
    if (len != g_00a63b14) {
        sub_0053b3d0(out, len);
    } else {
        out[0] = x;
        out[1] = y;
    }
}
