// from server: 59% by atomic.potato
extern "C" void BasicStringCopy(void *, void *);

struct Backpack
{
    char pad0[172];
    void *m_string;
    int m_value;
    Backpack *f(Backpack *);
};

Backpack *Backpack::f(Backpack *value)
{
    BasicStringCopy(value, (char *)this + 172);
    value->m_value = ((Backpack *)((char *)this + 172))->m_value;
    return value;
}
