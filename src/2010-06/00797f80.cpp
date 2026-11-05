// from server: 48% by atomic.potato
struct Inner {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
};

struct Outer {
    void method(int);
};

extern "C" void __stdcall sub_4116b0(Inner*, int, int, int, int, int, int, int, int);
extern "C" void __stdcall sub_797e60(Outer*, int, Inner*);

void Outer::method(int arg) {
    Inner local;
    local.a = -1;
    local.b = -1;
    local.c = -2;
    local.d = -2;
    local.e = 0;
    local.f = 0x7fffffff;
    *((char*)&local + 0x20) = 1;
    sub_4116b0(&local, 0, 0, 0, 0, 0, 0, 0, 0);
    sub_797e60(this, arg, &local);
}
