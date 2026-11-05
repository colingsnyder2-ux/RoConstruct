// from server: 100% by colin
struct S {
    unsigned char pad[0x144];
    int m_val;
    void method(int arg);
    void helper();
};

void S::method(int arg)
{
    if (m_val != arg) {
        m_val = arg;
        helper();
    }
}
