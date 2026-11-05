// from server: 52% by atomic.potato
struct Inner {
    virtual float f();
};

struct Outer {
    char pad[0x28];
    Inner* inner;
    void* method(float* out, int a);
};

extern "C" void __cdecl sub_744220(float* out, int a);

void* Outer::method(float* out, int a) {
    float tmp = inner->f();
    *out = tmp;
    sub_744220(out, a);

    return this;
}
