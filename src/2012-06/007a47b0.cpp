// from server: 59% by atomic.potato
struct S {
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    int f(int a, int b);
};

int S::f(int a, int b) {
    S* p = (a != 0) ? (S*)((char*)a - 0x1c) : 0;
    int v = *(int*)b;
    int idx = m20;
    int off = *(int*)((char*)p + 0x84);
    int val = *(int*)(off + idx);
    val += m1c;
    int (*fn)(int) = (int (*)(int))m18;
    return fn((int)((char*)p + 0x84 + val));
}
