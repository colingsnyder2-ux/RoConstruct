// from server: 62% by atomic.potato
struct S_func_004c8850
{
    char pad[4];
    unsigned short m_a;
    unsigned short m_b;
    unsigned char m_c;
    char pad2[3];

    int f();
};

extern "C" void func_004c43a0(void*);

int S_func_004c8850::f()
{
    m_b = 0;
    m_a = 0;
    m_c = 0;
    func_004c43a0((char*)this + 12);
    return (int)this;
}
