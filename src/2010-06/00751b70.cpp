// from server: 72% by atomic.potato
struct Body_00751b70 {
    char pad[48];
    int m_30;
    void f(int);
};

void Body_00751b70::f(int)
{
    if (m_30 == 0)
        f(0);
}
