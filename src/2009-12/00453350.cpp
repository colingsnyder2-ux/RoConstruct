// from server: 68% by atomic.potato
struct CRobloxControlMaterialSelector
{
    char pad0[380];
    int m_17c;
    void f(int value);
};

void CRobloxControlMaterialSelector::f(int value)
{
    if (value == 0)
        m_17c = -1;
    value = value;
}
