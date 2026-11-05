// from server: 67% by atomic.potato
struct Inner {
    virtual float f(int);
};

struct Outer {
    char pad[0x28];
    Inner* inner;
    void func(float, int);
};

struct Result {
    char pad[0x10];
    int field4;
    float field8;
};

extern "C" void __fastcall sub_6f1960(Result*);

void Outer::func(float a, int b) {
    float r = inner->f(b);
    Result* p = (Result*)((char*)this + 0x10);
    sub_6f1960(p);
    p->field8 = r;
    p->field4 = 7;
}
