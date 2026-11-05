// from server: 100% by tester
struct RakPeer {
    char pad[0x538];
    unsigned char m_field228;
    void func(int, int);
};

void RakPeer::func(int arg1, int arg2)
{
    unsigned int v = m_field228;
    if (arg1 == 0) {
        *(int*)arg2 = v;
        return;
    }
    int* p = (int*)arg2;
    if (*p > (int)v)
        *p = v;
    int n = *p;
    if (n > 0) {
        extern void __cdecl sub_630d4c(int, int, int);
        sub_630d4c(arg1, (int)(this->pad + 0x438), n);
    }
}
