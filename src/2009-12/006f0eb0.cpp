// from server: 58% by atomic.potato
struct RBX_Primitive {
    void get(float *out);
};

extern float g_9db608;
extern float g_9db60c;

void RBX_Primitive::get(float *out)
{
    float c = *reinterpret_cast<float *>(reinterpret_cast<char *>(this) + 0xa4);
    float a = *reinterpret_cast<float *>(reinterpret_cast<char *>(this) + 0x9c);
    out[2] = c;
    out[0] = a * g_9db60c;
    out[1] = *reinterpret_cast<float *>(reinterpret_cast<char *>(this) + 0xa0) * g_9db608;
}
