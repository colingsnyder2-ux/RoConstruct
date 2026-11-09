// from server: 85% by atomic.potato
struct Inner {
    char pad0[0x10];
    int a;
    int b;
};

struct Outer {
    char pad0[0x1cb8];
    void* field;
    void f(int* out, Inner* in);
};

extern "C" void __stdcall sub_51a320(void* p);

void Outer::f(int* out, Inner* in) {
    if (in != 0) {
        sub_51a320(field);
        out[1] = in->a;
        out[2] = in->b;
        *(char*)out = 1;
    } else {
        *(char*)out = 0;
    }
}
