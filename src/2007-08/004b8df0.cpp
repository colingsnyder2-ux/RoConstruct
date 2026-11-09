// from server: 100% by tester
struct S_func_0060b220 {
    char pad0[40];
    int m_x;
    void f(int a1);
};

struct RakPeer {
    char pad0[8];
    unsigned short count;
    char pad1[0x22c - 0xa];
    char* array;
    char pad2[0x8c8 - 0x230];
    unsigned int value;
    void SetTimeout(unsigned int v);
};

void RakPeer::SetTimeout(unsigned int v) {
    value = v;
    unsigned short i = 0;
    if (count > 0) {
        do {
            S_func_0060b220* layer = (S_func_0060b220*)(array + i * 0x840 + 0x18);
            layer->f(value);
            i++;
        } while (i < count);
    }
}
