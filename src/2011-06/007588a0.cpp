// from server: 61% by atomic.potato
struct S_func_007588a0
{
    unsigned char m_padding[48];
    double m_value;
    void Set(float value, float factor);
};

struct S_func_004a79a0
{
    float m_scale;
    void Apply(float value);
};

void S_func_007588a0::Set(float value, float factor)
{
    m_value = 0.0;
    S_func_004a79a0* object = *(S_func_004a79a0**)((char*)this + 4);
    object->Apply(*(float*)((char*)object + 212) * factor);
}
