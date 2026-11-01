// from server: 100% by tester
struct S {
    char pad[0x54];
    int m54;
    void setFlag(bool b);
};

void S::setFlag(bool b)
{
    m54 = (m54 & ~0x10) | (b ? 0x10 : 0);
}
