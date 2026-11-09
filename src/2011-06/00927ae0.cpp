// from server: 58% by atomic.potato
extern "C" void Initialize(void*);

struct AdornRbxGfx
{
    unsigned char pad[4];
    unsigned short m_a;
    unsigned short m_b;
    unsigned char m_object[1];

    AdornRbxGfx* f();
};

AdornRbxGfx* AdornRbxGfx::f()
{
    m_b = 0;
    m_a = 0;
    Initialize((void*)&m_object[3]);
    return this;
}
