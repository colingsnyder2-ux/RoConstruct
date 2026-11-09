// from server: 100% by tester
struct S_func_008f1e70 {
    char pad[16];
    int m_a;
    int m_b;
    int f(int x);
};

int S_func_008f1e70::f(int x)
{
    int edx;
    if (x != 0) {
        edx = x - 8;
    } else {
        edx = 0;
    }
    int eax = *(int*)((char*)this - 16);
    if (edx == eax) {
        eax = *(int*)((char*)this - 12);
    }
    if (eax != 0) {
        return eax + 8;
    }
    return 0;
}
