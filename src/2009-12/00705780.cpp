// from server: 41% by atomic.potato
struct S {
    char pad0[8];
    int f();
};

extern "C" void __stdcall sub_703960(int, int, int);
extern "C" void __stdcall sub_98b6e4(int);

int S::f() {
    char buf[12];
    int a = 1;
    char c = 0;
    sub_703960(*(int*)((char*)this + 8), (int)&c, (int)&a);
    sub_98b6e4((int)&buf[8]);
    sub_98b6e4((int)&buf[0]);
    return 0;
}
