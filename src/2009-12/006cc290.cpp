// from server: 61% by atomic.potato
struct S {
    char pad[0x18];
    int field18;
    int field1c;
    int field20;
    void method(int, int);
};

void S::method(int a, int b) {
    S* p = (S*)a;
    if (p != 0) {
        p = (S*)((char*)p - 0x1c);
    } else {
        p = 0;
    }
    int* q = (int*)b;
    int v1 = q[1];
    int v2 = q[0];
    int idx = this->field20;
    int* arr = (int*)((char*)p + 0x98);
    int val = *(int*)((char*)arr + idx);
    val += this->field1c;
    void (*fn)(int, int) = (void (*)(int, int))this->field18;
    fn(val, v2);
}
