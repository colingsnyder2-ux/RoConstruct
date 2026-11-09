// from server: 43% by atomic.potato
struct Inner {
    virtual void f();
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    float get(int);
};

extern "C" void __cdecl sub_6504b0(float*, float*);

float Outer::get(int a) {
    float tmp;
    Inner* p = inner;
    void** vt = *(void***)p;
    void (*fn)(Inner*, int, float*) = (void (*)(Inner*, int, float*))vt[2];
    fn(p, a, &tmp);
    float result;
    sub_6504b0(&result, &tmp);
    return result;
}
