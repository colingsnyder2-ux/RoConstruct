// from server: 57% by atomic.potato
struct Handles
{
    char pad0[0x194];
    int m_state;
    int f();
};

int Handles::f()
{
    switch (m_state)
    {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    default:
        return 0;
    }
}
