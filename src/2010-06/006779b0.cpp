// from server: 69% by atomic.potato
struct Guid
{
    int m_a;
    int m_b;
    Guid& operator=(const Guid& value);
};

struct Geometry
{
    char pad0[132];
    Guid m_guid;
    char m_initialized;
    void f(Guid* value);
};

void Geometry::f(Guid* value)
{
    m_guid = *value;
    m_initialized = 1;
}
