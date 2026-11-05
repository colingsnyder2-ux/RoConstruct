// from server: 65% by atomic.potato
struct T4_00691960 {
    char pad[0x18];
    int m_18;
    int m_1c;
    int m_20;
    void f_00691960(int, int*);
};

void T4_00691960::f_00691960(int a, int* b)
{
    T4_00691960* p;
    if (a != 0)
        p = (T4_00691960*)((char*)a - 0x1c);
    else
        p = 0;
    int idx = *b;
    int off = *(int*)((char*)p + 0x94);
    int val = *(int*)(off + m_20);
    val += m_1c;
    void (*fn)(int) = *(void(**)(int))((char*)this + 0x18);
    fn((int)((char*)p + 0x94 + val));
}
