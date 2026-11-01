// from server: 100% by colin
struct ChatEnter {
    char pad0[0xec];
    int m_field_ec;
    void sub_556900();
    void sub_541B00(int*);
    void f(int* p);
};

void ChatEnter::f(int* p)
{
    if (*p == m_field_ec)
        sub_556900();
    sub_541B00(p);
}
