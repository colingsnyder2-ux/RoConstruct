// from server: 32% by tester
struct Sub1 {
    void f();
};

struct Sub2 {
    void f();
};

struct S {
    int pad0;
    Sub2 sub2;
    int pad10;
    int pad14;
    Sub1 sub1;
    void destroy();
};

void S::destroy()
{
    *(int*)this = 0x79f754;
    sub1.f();
    sub2.f();
    *(int*)this = 0x797984;
}
