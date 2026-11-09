// from server: 80% by atomic.potato
struct CSHA1 {
    char pad0[0x1c];
    int field1c;
    int field20;
    int field24;
    int field28;
    bool method(int, int);
};

bool CSHA1::method(int a, int b) {
    if (field1c == 0)
        return false;
    int v28 = field28;
    int v24 = field24;
    int v20 = field20;
    extern int __cdecl sub_573f30(int*, int, int, int, int, int, int, int);
    sub_573f30(&field1c, 1, v20, v28, v24, a, v28, b);
    return true;
}
