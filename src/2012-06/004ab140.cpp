// from server: 70% by atomic.potato
struct DxUserInput {
    char pad0[0x3c];
    int m_p;
    int f(int a, int b, int c);
};

struct Sub1 {
    int sub_4ab040(int*);
};

struct Sub2 {
    int sub_4ab0b0();
};

int DxUserInput::f(int a, int b, int c)
{
    int args[3];
    args[0] = a;
    args[1] = c;
    args[2] = b;
    ((Sub1*)(m_p + 0x22c))->sub_4ab040(args);
    ((Sub2*)m_p)->sub_4ab0b0();
    return 0;
}
