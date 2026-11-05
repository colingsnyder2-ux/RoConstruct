// from server: 62% by atomic.potato
struct Inner {
    virtual void f();
};

struct Outer {
    char pad[0x1c];
    Inner* inner;

    void method(int a, int b);
    void sub_00602ab0();
};

struct Result {
    char pad0[4];
    int type;
    float value;
};



void Outer::method(int a, int b)
{
    Inner* p = inner;
    void** vt = *(void***)p;
    void (*fn)(Inner*, int) = (void (*)(Inner*, int))vt[2];
    float r;
    fn(p, a);
    Result* res = (Result*)((char*)this + 0x10);
    sub_00602ab0();
    res->value = r;
    res->type = 7;
}
