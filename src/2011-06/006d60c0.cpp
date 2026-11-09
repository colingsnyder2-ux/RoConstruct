// from server: 43% by atomic.potato
struct Motor6D
{
    char pad[180];
    void* m_p;
    void Set(float value);
};

void Motor6D::Set(float value)
{
    float* p = (float*)((char*)m_p + 208);
    if (value != *p)
        *p = value;
}
