// from server: 46% by atomic.potato
struct S {
    float value;
    short angle;
    void f(void* out);
};

extern const float g_mask[4];

void S::f(void* out)
{
    float v = value;
    short a = angle;
    v = v * g_mask[0];
    a = (short)-a;
    *(float*)out = v;
    *(short*)((char*)out + 4) = a;
}
