// from server: 90% by atomic.potato
struct GeometryService
{
    char pad0[368];
    int m_170;
    int m_174;
    int m_178;
    void f(int *out);
};

void GeometryService::f(int *out)
{
    out[0] = m_170;
    out[1] = m_174;
    out[2] = m_178;
}
