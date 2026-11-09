// from server: 31% by atomic.potato
extern "C" {
    void __stdcall G1_func_009ea40c(void*);
    void __stdcall G1_func_009ea400(void*);
}

struct Inner {
    char pad[0x1c];
    int field_1c;
};

struct Outer {
    char pad[4];
    void* vtbl;
    int field_1c;
};

struct S {
    void* vtbl;
    void* (__thiscall *func4)(void*, void*);
    Outer* method(Inner* arg, int a, int b);
};

Outer* S::method(Inner* arg, int a, int b)
{
    Inner* p = arg;
    if (p != 0) {
        p = (Inner*)((char*)p - 0x1c);
        if (p != 0) {
            p = (Inner*)((char*)p + 0x2c0);
        } else {
            p = 0;
        }
    } else {
        p = 0;
    }

    Inner* tmp = 0;
    Inner* result = (Inner*)this->func4(this, &tmp);

    Outer* out = (Outer*)a;
    G1_func_009ea40c(result);
    out->field_1c = result->field_1c;
    G1_func_009ea400(&tmp);
    return out;
}
