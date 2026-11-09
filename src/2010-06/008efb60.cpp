// from server: 47% by atomic.potato
struct Inner {
    char pad0[4];
    int field4;
    char pad8[0x24];
    int field2c;
};

struct Arg {
    char pad0[0x24];
    int (__stdcall *vtbl24)(int);
};

struct Outer {
    char pad0[4];
    int field4;
    char pad8[8];
    void *field10;
    Inner *field18;
    void method(int *out, Arg *arg, int a, int b);
};

extern "C" void __stdcall sub_92a610(void *out, int val);

void Outer::method(int *out, Arg *arg, int a, int b)
{
    int local;
    sub_92a610(&local, this->field4);

    int v1 = arg->vtbl24(0);
    int v2 = arg->vtbl24(0);

    Inner *inner = this->field18;
    int flags = inner->field4 & 0xf00;

    if (flags != 0x200 || flags == 0x100 || flags == 0x300) {
        void **vt = *(void ***)this->field10;
        int (*fn)(void *, int, int *) = (int (*)(void *, int, int *))vt[1];
        fn(this->field10, 1, &local);
    } else if (flags == 0) {
        void **vt = *(void ***)this->field10;
        int (*fn)(void *, int, int *) = (int (*)(void *, int, int *))vt[0];
        fn(this->field10, 0, &local);
    }

    int v3 = arg->vtbl24(0);
    out[0] = v1;
    out[1] = v3;
}
