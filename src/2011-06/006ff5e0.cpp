// from server: 90% by atomic.potato
struct GeometryService_006ff5e0 {
    char pad0[364];
    int m_16c;
    int m_170;
    int m_174;
    void f(int* out);
};

void GeometryService_006ff5e0::f(int* out)
{
    out[0] = m_16c;
    out[1] = m_170;
    out[2] = m_174;
}
