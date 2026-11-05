// from server: 65% by atomic.potato
struct Inner {
    virtual double f(int);
};

struct Outer {
    char pad[0x28];
    Inner* inner;
    void method(int a, int* out);
};

extern "C" int __cdecl sub_6c1440(double);
extern "C" void __cdecl sub_52df50(int*, int*);

void Outer::method(int a, int* out) {
    double d = inner->f(a);
    int v = sub_6c1440(d);
    *out = v;
    sub_52df50(out + 1, (int*)&d);
}
