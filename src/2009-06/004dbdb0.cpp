// from server: 25% by atomic.potato
struct Inner {
    void f();
};

struct Outer {
    char pad0[0x1d0];
    Inner inner;
    char pad1[0x18];
    int field1ec;
    char pad2[0x4];
    int field1d4;
    int run(int);
};

extern "C" void __stdcall sub_7052b0(void*, void*);
extern "C" void __stdcall sub_705300(void*);
extern "C" void __stdcall sub_4dbd10(void*, void*, int, int, int, int, int);

void Inner::f()
{
    sub_705300(this);
}

int Outer::run(int arg)
{
    char buf[0x10];
    sub_7052b0(&this->inner, buf);
    int a = this->field1ec;
    int b = this->field1d4;
    int c = *(int*)a;
    sub_4dbd10(buf, (void*)0x4da910, b, a, c, b, arg);
    sub_705300(buf);
    return 1;
}
