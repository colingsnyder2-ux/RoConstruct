// from server: 71% by atomic.potato
struct Inner {
    char pad[0x9c];
    int field_9c;
    int field_a0;
    void method_59f900(int*, int*);
};

struct Outer {
    char pad[0x9c];
    Inner inner;
    int method_5a5930(int);
};

extern "C" void __stdcall sub_5a58e0(int);

int Outer::method_5a5930(int arg) {
    int local1;
    int local2;
    inner.method_59f900(&local1, &local2);
    if (local1 != inner.field_a0) {
        int* p = (int*)local1;
        int v = p[4];
        sub_5a58e0(v);
    }
    return arg;
}
