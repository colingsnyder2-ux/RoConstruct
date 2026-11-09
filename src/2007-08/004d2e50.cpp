// from server: 33% by colin
struct Sub {
    int f0;
    void destroy();
};

struct S {
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
    Sub sub;
    void destroy();
};

extern "C" void __stdcall sub_destroy(Sub* p);

void S::destroy()
{
    f0 = 0x79f15c;
    --*(int*)0x8bfbdc;
    sub.f0 = 0x79f13c;
    sub_destroy(&sub);
    sub.f0 = 0x79f010;
    f0 = 0x797984;
}
