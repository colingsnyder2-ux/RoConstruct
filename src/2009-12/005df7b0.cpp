// from server: 81% by atomic.potato
struct Material
{
    char pad0[12];
    void* m_data;
    int m_count;
    int f();
};

int Material::f()
{
    if (m_count > 0 && *(volatile float*)((char*)m_data + 0x30) > 0.0f)
        return 1;
    return 0;
}
